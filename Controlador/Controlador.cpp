#include "Controlador.h"
#include "ControlDAO/ControlDAO.h"

Controlador::Controlador()
{
    controlDao = new ControlDAO(this);
}

void Controlador::MostrarMenu()
{
    vista.MenuGlobal();
}