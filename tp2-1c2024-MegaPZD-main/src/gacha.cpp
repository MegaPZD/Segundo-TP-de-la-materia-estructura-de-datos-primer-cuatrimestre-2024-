#include "gacha.hpp"
#include "generador_salto.hpp"
#include <random>
#include <iostream>
#include <fstream>
#include <cstdio>

int gacha::generador_probabilidad_salto_aleatorio(){

    // Configurar un generador de números aleatorios
    std::random_device rd;  // Obtener una semilla aleatoria de un dispositivo de hardware
    std::mt19937 gen(rd()); // Inicializar el generador con la semilla

    int numero_aleatorio;

    std::uniform_int_distribution<int> probabilidad(1, 100);
    numero_aleatorio = probabilidad(gen);

    return numero_aleatorio;
    
}

gacha::gacha(){

    vector<salto> historial_saltos;
    contador_pity_5_estrellas = 0;
    contador_pity_4_estrellas = 0;
    saltos_salvados_en_archivo = 0;

}

salto gacha::generar_salto(){

    int probabilidad = gacha::generador_probabilidad_salto_aleatorio();
    generador_salto salto_generado;
    salto salto_unitario;
    bool salto_realizado = false;

    if(contador_pity_5_estrellas == PITY_90){
        salto_realizado = true;
        salto_unitario = salto_generado.generar_salto_5_estrellas();
        contador_pity_5_estrellas = 0;
    } else if(contador_pity_4_estrellas == PITY_10){
        salto_realizado = true;
        salto_unitario = salto_generado.generar_salto_4_estrellas();
        contador_pity_4_estrellas = 0;
        contador_pity_5_estrellas++;
    }

    if(salto_realizado == false){
        if(probabilidad == PROBA_5_ESTRELLAS){
            salto_unitario = salto_generado.generar_salto_5_estrellas();
            contador_pity_5_estrellas = 0;
            contador_pity_4_estrellas++;
        } else if(probabilidad > PROBA_4_ESTRELLAS_BAJA && probabilidad < PROBA_4_ESTRELLAS_ALTA){
            salto_unitario = salto_generado.generar_salto_4_estrellas();
            contador_pity_4_estrellas = 0;
            contador_pity_5_estrellas++;
        } else{
            salto_unitario = salto_generado.generar_salto_3_estrellas();
            contador_pity_5_estrellas++;
            contador_pity_4_estrellas++;
        }
    }

    historial_saltos.alta(salto_unitario, historial_saltos.tamanio());
    return salto_unitario;
    
}

vector<salto> gacha::generar_salto_multiple(){
    vector<salto> v;
    for(int i = 0; i < SALTO_MULTI_PREDETERMINADO; i++){
        v.alta(gacha::generar_salto());
    }
    return v;
}

vector<salto> gacha::generar_salto_multiple(size_t cantidad){
    vector<salto> v;
    size_t i = 0;
    while(i < cantidad){
        v.alta(gacha::generar_salto());
        i++;
    }
    return v;
}

void gacha::exportar_saltos(){

    std::fstream registro("registro.csv", std::ios::out | std::ios::app);

    for(size_t i = saltos_salvados_en_archivo; i < historial_saltos.tamanio(); i++){
        registro << historial_saltos[i] << std::endl;
    }

    saltos_salvados_en_archivo = historial_saltos.tamanio();

    registro.close();

}