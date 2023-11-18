#ifndef VISTA_H
#define VISTA_H
#include <iostream>
#include "Formulario.h"
#include "../Librerias/List.h"

class Vista
{
private:
    Formulario formulario;

public:
    Vista();
    int MostrarMenu();
    void IngresarDatos();
    void MenuGlobal();
};

#endif
