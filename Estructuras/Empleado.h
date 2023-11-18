#ifndef EMPLEADO_H
#define EMPLEADO_H
#include "Hijo.h"           // Incluye el archivo de encabezado "Hijo.h" para utilizar la estructura Hijo.
#include "../Librerias/List.h"  // Incluye el archivo de encabezado "List.h" ubicado en un directorio superior para trabajar con listas.

struct Empleado {
    int pk;
    int fk;

    std::string nombre;
    std::string apellido;
    std::string tipoIdentificacion;
    std::string numIdentificacion;
    char sexo;
    std::string telefonoCelular;
    std::string telefonoFijo;
    std::string email;
    std::string fechaNacimiento;
    std::string ciudadNacimiento;
    std::string paisNacimiento;
    std::string ciudadResidencia;
    std::string direccion;
    std::string barrio;
    std::string profesion;
    char tieneHijos;
    std::string actividadLaboral;
    int numHijos;
    List<Hijo> hijos;  // Utiliza una lista de hijos (definida en "List.h") para almacenar la información de los hijos.
    std::string sucursalTrabajo;
};

#endif 

