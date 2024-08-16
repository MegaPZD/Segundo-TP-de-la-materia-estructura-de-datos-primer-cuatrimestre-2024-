#include "visualizador_gacha.hpp"
#include "gacha.hpp"
#include <fstream>

bool visualizador::preguntar_mostrar(){

    char respuesta = NO;

    do{
        std::cout << "¿Desea ver los resultados de los saltos? (Si = S, No = N): ";
        std::cin >> respuesta;
        std::cout << "\n";
    }while(respuesta != SI && respuesta != NO);

    return respuesta == SI;

}

void visualizador::mostrar(gacha* gacha, size_t n_saltos, size_t respuesta){

    if (respuesta < EXPLORTAR_SALTOS){
        vector<salto> v(gacha->generar_salto_multiple(n_saltos));

        if(visualizador::preguntar_mostrar()){
            std::cout << "\n __________________________________________________________________________________________________\n\n\n";

            for(size_t i = 0; i < v.tamanio(); i++){
                    std::cout << "   " << v[i] << "\n\n";
            }
            std::cout << " __________________________________________________________________________________________________\n";

        }

    } else if(respuesta == EXPLORTAR_SALTOS){

        gacha->exportar_saltos();

        std::ifstream registro("registro.csv");

        if(registro.is_open()){

            std::cout << "Se ha actualizado el archivo 'registro.csv'\n";
            
        } else {
            std::cout << "Por algun motivo, no se pudo crear el archivo necesario para la ejecución de este metodo.\nAlgunos motivos podrian ser:\n\tSe haya borrado el archivo en medio de la ejecución\n\tNo se tienen los permisos para modificar la carpeta donde se ejecuta ese programa\n\tNo hay espacio suficiente en memoria para agregar este archivo\n";
        }
        registro.close();
}
}
