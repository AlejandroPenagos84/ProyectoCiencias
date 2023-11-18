//
// Created by Alejandro Penagos on 17/11/2023.
//

#ifndef PROYECTO_CIENCIAS_CIUDAD_H
#define PROYECTO_CIENCIAS_CIUDAD_H
#include "iostream"
#include "../Librerias/List.h"
#include "Sucursal.h"

struct Ciudad
{
    int id;
    std::string nombre;
    List<Sucursal> sucursales;
};
#endif //PROYECTO_CIENCIAS_CIUDAD_H
