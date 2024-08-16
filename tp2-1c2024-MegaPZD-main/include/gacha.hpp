#ifndef AYED_TP2_1C2024_GACHA_HPP
#define AYED_TP2_1C2024_GACHA_HPP

#include "salto.hpp"
#include "vector.hpp"
#include "generador_salto.hpp"
#include <fstream>

const int PITY_90 = 89;
const int PITY_10 = 9;
const int PROBA_5_ESTRELLAS = 1;
const int PROBA_4_ESTRELLAS_BAJA = 1;
const int PROBA_4_ESTRELLAS_ALTA = 12;
const int SALTO_MULTI_PREDETERMINADO = 10;

class gacha {
private:

    vector<salto> historial_saltos;
    int contador_pity_5_estrellas;
    int contador_pity_4_estrellas;
    size_t saltos_salvados_en_archivo;

    /*
    
    Post: Simula la probabilidad de un salto del gacha. Ejemplo un 4 estrellas
    tiene un 10% de optenerse en un salto, esto en esta simulación equivale 
    retornar a un numero (int) entre 2 y 11 (inclusive) de los 1 al 100 que
    el generador de numeros aleatorios maneja, lo que equivale a un 1/10 (10%).


    */
    int generador_probabilidad_salto_aleatorio();

public:

    //generador
    gacha();

    /*
    
    Post: Retorna un salto generado dando prioridad al sistema de "Pity",
    si no se esta en condición de pity se realizaran los saltos mediante la
     simulación de probabilidad de generador_probabilidad_salto_aleatorio() donde:
    [5 ESTRELLAS] = 1/100 (1%)
    [4 ESTRELLAS] = 10/100 (10%)
    [3 ESTRELLAS] = 89/100 (89%)
    y [PITY]:
    [5 ESTRELLAS] = 90 saltos (Ejemplo: salto 0 a 89) sin que salga un 5 estrellas
    [4 ESTRELLAS] = 10 saltos (Ejemplo: salto 0 a 9) sin que salga un 4 estrellas
    [CASO BORDE] = el pity 5 estrellas o el de 4 coinciden se le da prioridad al
    de 5 y el de 4  estrellas de realizará en el salto 91.
    
    */
    salto generar_salto();

    /*
    
        Post: Equivale a diez (10) saltos realizados por generar_salto().
        Retorna un vector de 10 saltos (vector<salto>)
    
    */
    vector<salto> generar_salto_multiple();

    /*
    
        Post: Equivale a n saltos realizados por generar_salto().
        Retorna un vector de n saltos (vector<salto>)
    
    */
    vector<salto> generar_salto_multiple(size_t cantidad);

    /*
    
        Post: Guarda a modo de registro todos los saltos realizados en un
        archivo llamado 'registro.csv' consiguiendo que los saltos se guarden
        aun finalizada la ejecución del programa.
        Si el archivo 'registro.csv' no esta creado lo crea y si este ya tiene
        contenido la agrega (NO la sobrescribe).

    */
    void exportar_saltos();
};

#endif