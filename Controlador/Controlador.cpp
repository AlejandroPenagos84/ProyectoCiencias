#include "Controlador.h"
#include "MultilistaPaises.h"

Controlador::Controlador()
{
    MultilistaPaises* paises = new MultilistaPaises(21);

}

void Controlador::MostrarMenu()
{
    vista.MenuGlobal();
}