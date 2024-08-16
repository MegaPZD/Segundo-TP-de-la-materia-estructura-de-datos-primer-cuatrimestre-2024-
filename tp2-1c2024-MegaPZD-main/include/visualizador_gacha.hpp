#ifndef __VISUALIZADOR__
#define __VISUALIZADOR__

#include "gacha.hpp"
#include <cstdlib>

const size_t EXPLORTAR_SALTOS = 4;
const char SI = 'S';
const char NO = 'N';

class visualizador{

public:

/*

    Post: Pregunta al usuario si quiere mostrar el resultado de los saltos.

*/
    static bool preguntar_mostrar();

/*

    Pre: Respuesta debe ser menor o igual a 4.
    Post: Muestra por pantalla en resultado de las operaciones de los metodos
    de la clase gacha.

*/
    static void mostrar(gacha* gacha, size_t n_saltos, size_t respuesta);
};

#endif
