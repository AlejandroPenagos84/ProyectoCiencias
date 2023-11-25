#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include "Formulario.h"


class Vista
{
private:
    Formulario formulario;

public:
    Vista();
    int MostrarMenu();
    void IngresarDatos();
    void MenuGlobal();
    void MenuConsultas();
    int MostrarElementos(std::string* arreglo, int tam);
    void MenuPrimeraConsulta(std::string* arregloPaises,
                             std::string* arregloCiudades,
                             std::string* arregloSucursales);


private:

};

#endif
