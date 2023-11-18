#ifndef PROYECTO_CIENCIAS_PAIS_H
#define PROYECTO_CIENCIAS_PAIS_H
#include "../Librerias/List.h"
#include "Ciudad.h"
#include <iostream>

struct Pais
{
    int id;
    std::string nombre;
    List<Ciudad> ciudades;
};
#endif //PROYECTO_CIENCIAS_PAIS_H
