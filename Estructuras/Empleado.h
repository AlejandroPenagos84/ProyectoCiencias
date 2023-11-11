#ifndef EMPLEADO_H
#define EMPLEADO_H

#include "Fecha.h"          // Incluye el archivo de encabezado "Fecha.h" para utilizar la estructura Fecha.
#include "Hijo.h"           // Incluye el archivo de encabezado "Hijo.h" para utilizar la estructura Hijo.
#include "../Librerias/List.h"  // Incluye el archivo de encabezado "List.h" ubicado en un directorio superior para trabajar con listas.

struct Empleado {
    std::string nombre;
    std::string apellido;
    std::string tipoIdentificacion;
    int numIdentificacion;
    std::string sexo;
    std::string telefonoCelular;
    std::string telefonoFijo;
    std::string email;
    Fecha fechaNacimiento;
    std::string ciudadNacimiento;
    std::string paisDeNacimiento;
    std::string ciudadResidencia;
    std::string direccion;
    std::string barrio;
    std::string profesion;
    std::string tieneHijos;
    int numHijos;
    List<Hijo> hijos;  // Utiliza una lista de hijos (definida en "List.h") para almacenar la información de los hijos.
    std::string nomSucursal;
};

#endif 

