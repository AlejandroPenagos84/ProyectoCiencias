#ifndef HIJO_H
#define HIJO_H
#include "Edad.h"
#include <string>

struct Hijo
{
    int pk{};
    int fk;
    std::string nombre{};
    std::string fechaNacimiento{"21/05/2005"};
    bool estado{true};
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));

    int sigEdad{-1};

    Hijo():nombre(), fechaNacimiento("21/05/2005"){}

    Hijo(std::string nombre, std::string fechaNacimiento)
        : nombre(std::move(nombre)), fechaNacimiento(std::move(fechaNacimiento))
    {
        // Supongo que calcularEdad y obtenerFechaDesdeString están definidas
        edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));
    }

};
#endif
