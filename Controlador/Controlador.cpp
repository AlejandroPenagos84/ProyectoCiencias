#include "Controlador.h"


Controlador::Controlador()
{
    controlDao = new ControlDAO(this);
}

void Controlador::MostrarMenu()
{
    vista.MenuGlobal();
}

void Controlador::PrimeraConsulta()
{
    int numPais = vista.MostrarElementos(multilistaPaises->getElementos(),
                                         multilistaPaises->getSize());
    Pais auxPais = multilistaPaises->getPais(numPais);

    int numCiudad = vista.MostrarElementos(auxPais.ciudades->getElementos(),auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);

    int numSucursal = vista.MostrarElementos(auxCiudad.sucursales->getElementos(), auxCiudad.sucursales->getSize());
    Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(numSucursal);

    int* arregloValidaciones = new int[5];

    for(int i = 0; i < auxSucursal.empleados->getNumEmpleados();i++)
    {
        Empleado auxEmpleado = auxSucursal.empleados->getEmpleado(i);
        if(auxEmpleado.tieneHijos == 'N') arregloValidaciones[0]++;
        else{
            for(int k = 0; k < 4; k++)
            {
                if(auxEmpleado.hijos->getCabecera()[k].indice != -1){
                    arregloValidaciones[k+1]++;
                }
            }
        }
    }
}