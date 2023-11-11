#ifndef HIJO_H
#define HIJO_H

#include "Fecha.h"    // Incluye el archivo de encabezado "Fecha.h" para utilizar la estructura Fecha.
#include <iostream>   // Incluye la biblioteca iostream para trabajar con entrada y salida estándar.

struct Hijo {
    std::string nombre;      // Almacena el nombre del hijo.
    Fecha fechaNacimiento;  // Almacena la fecha de nacimiento del hijo, utilizando la estructura Fecha definida en "Fecha.h".
};

#endif //PCIENCIAS_HIJO_H
