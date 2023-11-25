#include "Controlador.h"


Controlador::Controlador()
{
    controlDao = new ControlDAO(this);
}

void Controlador::MostrarMenu()
{
    vista.MenuGlobal();
}