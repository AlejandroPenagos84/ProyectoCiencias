#include "Controlador.h"

Controlador::Controlador() {
    controlDao = new ControlDAO(this);
}

void Controlador::MostrarMenu() {
    vista.MenuGlobal();
}

void Controlador::PrimeraConsulta() {
    int numPais = vista.MostrarElementos(multilistaPaises->getElementos(),
                                         multilistaPaises->getSize());
    Pais auxPais = multilistaPaises->getPais(numPais);

    int numCiudad = vista.MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);

    int numSucursal = vista.MostrarElementos(auxCiudad.sucursales->getElementos(), auxCiudad.sucursales->getSize());
    Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(numSucursal);

    int *arregloValidaciones = new int[5];

    for (int i = 0; i < auxSucursal.empleados->getNumEmpleados(); i++) {
        Empleado auxEmpleado = auxSucursal.empleados->getEmpleado(i);
        if (auxEmpleado.estado) {
            if (auxEmpleado.tieneHijos == 'N') arregloValidaciones[0]++;
            else {
                for (int k = 0; k < 4; k++) {
                    if (auxEmpleado.hijos->getCabecera()[k].indice != -1) {
                        arregloValidaciones[k + 1]++;
                    }
                }
            }
        }
    }
    vista.MenuPrimeraConsulta(arregloValidaciones);
    delete[] arregloValidaciones;
}

void Controlador::SegundaConsulta() {
    int auxNumRango = vista.MenuMostrarRangosNumHijos();

    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista.Imprimir(auxPais.nombre);

        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista.Imprimir(auxCiudad.nombre);

            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucusal = auxCiudad.sucursales->getSucursal(k);

                int indiceC = auxSucusal.empleados->getArreglosRangoHijos()[auxNumRango].indice;

                while (indiceC - 1) {
                    vista.Imprimir((auxSucusal.empleados->getEmpleado(indiceC).nombre));
                    vista.Imprimir((auxSucusal.empleados->getEmpleado(indiceC).apellido));
                    indiceC = (auxSucusal.empleados->getEmpleado(indiceC).sigNumHijos);
                }
            }
        }
    }
}

