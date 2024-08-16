#include "gacha.hpp"
#include <iostream>
#include "menu_gacha.hpp"

/*

    Fragmento del enunciado: Implementar un main.cpp sencillo que les permita
    mostrar por pantalla el resultado de los saltos y verificar la salida del
    archivo, a modo de prueba.

*/
int main() {

    gacha gacha;
    
    menu menu(" Un salto", " Salto x10"," Salto debug n veces", " Exportar saltos");
    menu.menu_opciones(&gacha);

    return 0;
}