#ifndef HIJO_H
#define HIJO_H

struct Hijo {
    std::string nombre;
    std::string fechaNacimiento;
    int edad = calcularEdad(obtenerFechaDesdeString(fechaNacimiento));

    int sigEdad{-1};
};
#endif //PCIENCIAS_HIJO_H
