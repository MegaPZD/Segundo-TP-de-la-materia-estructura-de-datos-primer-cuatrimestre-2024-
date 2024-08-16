#ifndef __MENU__
#define __MENU__

#include <string>
#include <iostream>
#include "gacha.hpp"
#include "visualizador_gacha.hpp"

const size_t SALIR = 5;
const size_t SALTO_PREDETERNADO = 1;

using namespace std;

template<typename T>
class menu{

private:
    T opcion_salto, opcion_x10, opcion_debug, opcion_exportar;

    /*
    
        Pre: El usuario solo podrá ingresar numeros enteros positivos (size_t).
        Post: Retorna un numero entero del 1 al 5 (inclusive) que el usuario
        haya seleccionado.

    */
    size_t seleccion_opcion();

public:

    //constructor
    menu(T salto, T salto_x10, T saltos_debug, T exportar_saltos);

    /*

        Pre: 
        Post: Muestra un menu por pantalla y prepara al gacha para la realización
        de uno de sus metodos, segun la seleccion del usuario en seleccion_opcion()
        se realizará un metodo o se finalizará el programa.

    */
    void menu_opciones(gacha* gacha);

};

template<typename T>
menu<T>::menu(T salto, T saltos_x10, T saltos_debug, T exportar_saltos){

    opcion_salto = salto;
    opcion_x10 = saltos_x10;
    opcion_debug = saltos_debug;
    opcion_exportar = exportar_saltos;

}

template<typename T>
size_t menu<T>::seleccion_opcion(){

    size_t respuesta = SALIR;

    do{
        
        cout << " __________________________________________________________________________________________________\n";
        cout << "|                                 |                                                                |\n";
        cout << "|-----------------------------    |                                                                |\n";
        cout << "|Evento de salto de personaje|    |                                                                |\n";
        cout << "|-----------------------------    |                                                                |\n";
        cout << "|                                 |                                                                |\n";
        cout << "| Un personaje 5 estrellas o más  |                                                                |\n";
        cout << "| garantizado en 90 saltos        |                                                                |\n";
        cout << "|                                 |                                                                |\n";
        cout << "| Un personaje 4 estrellas o mas  |                                                                |\n";
        cout << "| garantizado cada 10 saltos      |                                                                |\n";
        cout << "|                                 |                                                                |\n";
        cout << "|                                 |                                                                |\n";
        cout << "|                                 |                                                                |\n";
        cout << "| SALIR = " << SALIR << "  " << opcion_exportar << " = 4 |\t       " << opcion_debug << " = 3" << opcion_salto << " = 1" << opcion_x10 << " = 2 |\n";
        cout << "|__________________________________________________________________________________________________|\n";

        std::cout << "\n    Su respuesta es: ";
        cin >> respuesta;
        std::cout << "\n";

        if(respuesta > SALIR || respuesta == 0){
            cout << "ERROR, numero no valido. Ingrese nuevamente" << endl;
        }

    }while(respuesta > SALIR);
    system("clear");

    return respuesta;

}

template<typename T>
void menu<T>::menu_opciones(gacha* gacha){
    
    size_t respuesta = seleccion_opcion();
    size_t saltos = SALTO_PREDETERNADO;
    while(respuesta != SALIR){

        if(respuesta == 1){
            visualizador::mostrar(gacha,SALTO_PREDETERNADO,respuesta);   
        } else if(respuesta == 2){
            visualizador::mostrar(gacha,SALTO_MULTI_PREDETERMINADO,respuesta);    
        } else if(respuesta == 3){
            cout << "Ingrese el numero de saltos que quiera realizar: ";
            cin >> saltos;
            system("clear");
            visualizador::mostrar(gacha,saltos,respuesta);   
        } else if(respuesta == 4){
            visualizador::mostrar(gacha,0,respuesta); 
        }

        respuesta = seleccion_opcion();
    
    }

}

#endif