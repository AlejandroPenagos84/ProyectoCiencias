#ifndef SUCURSAL_H
#define SUCURSAL_H
#include "iostream"
#include "../Librerias/List.h"
#include "Empleado.h"

struct Sucursal{
    std::string nombre;
    std::string direccion;
    std::string barrio;
    std::string nombreGerente;
    List<Empleado> empleados;
};

#endif //PCIENCIAS_SUCURSAL_H

