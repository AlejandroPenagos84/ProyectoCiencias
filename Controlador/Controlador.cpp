#include "Controlador.h"

Controlador::Controlador() {
    controlDao = new ControlDAO(this);

    multilistaPaises = new MultilistaPaises(18);

    controlDao->LeerHijosDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\hijos.csv)");
    controlDao->LeerEmpleadosDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\empleados.csv)");
    controlDao->LeerSucursalesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\sucursales.csv)");
    controlDao->LeerCiudadesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\ciudades.csv)");
    controlDao->LeerPaisesDAO(
            R"(C:\Users\Alejandro Penagos\Desktop\ProyectoCiencias\ProyectoCiencias\Archivos\paises.csv)");

    RBTree<int, Empleado> *arbolEmpleados = controlDao->getEmpleadosLlaveF();
    RBTree<int, Sucursal> *arbolSucursales = controlDao->getSucurcalesLlaveF();
    RBTree<int, Ciudad> *arbolCiudades = controlDao->getCiudadesLlaveF();
    RBTree<int, Pais> *arbolPaises = controlDao->getPaises();

    //Cola Con la Clave de los hijos
    Queue<Nodo<int, Hijo> *> colaHijosF = controlDao->getHijosLlaveF()->inorden();

    //Cola con la clave empleados
    Queue<Nodo<int, Empleado> *> colaEmpleadosF = controlDao->getEmpleadosLlaveF()->inorden();

    //Cola Sucursales
    Queue<Nodo<int, Sucursal> *> colaSucursalesF = controlDao->getSucurcalesLlaveF()->inorden();

    //Cola Ciudad
    Queue<Nodo<int, Ciudad> *> colaCiudadesF = controlDao->getCiudadesLlaveF()->inorden();

    //Cola Paises
    Queue<Nodo<int, Pais> *> colaPaisesF = controlDao->getPaises()->inorden();

    while (!colaHijosF.IsEmpty()) {
        if (arbolEmpleados->findNodo(colaHijosF.Front()->otroDato.fk) != nullptr) {
            // Busca el nodo con la llave foranea
            // recordando que la llave foranea en uno es la primaria en otro

            // Ya con el dato, le digo a la multilista de hijos de ese empleado que agregue
            // el hijo que esta en la cola
            arbolEmpleados->findNodo(colaHijosF.Front()->otroDato.fk)->otroDato.hijos->AgregarHijo(
                    colaHijosF.Dequeue()->otroDato);
        }
    }

    while (!colaEmpleadosF.IsEmpty()) {
        if (arbolSucursales->findNodo(colaEmpleadosF.Front()->otroDato.fk) != nullptr) {
            Empleado aux = colaEmpleadosF.Dequeue()->otroDato;
            (arbolSucursales->findNodo(aux.fk))->otroDato.empleados->AgregarEmpleado(aux);
        }
    }

    while (!colaSucursalesF.IsEmpty()) {
        if (arbolCiudades->findNodo(colaSucursalesF.Front()->otroDato.fk) != nullptr) {
            (arbolCiudades->findNodo(colaSucursalesF.Front()->otroDato.fk))->otroDato.sucursales->AgregarSucursal(
                    colaSucursalesF.Dequeue()->otroDato);
        }
    }

    while (!colaCiudadesF.IsEmpty()) {
        if (arbolPaises->findNodo(colaCiudadesF.Front()->otroDato.fk) != nullptr) {
            (arbolPaises->findNodo(colaCiudadesF.Front()->otroDato.fk))->otroDato.ciudades->AgregarCiudad(
                    colaCiudadesF.Dequeue()->otroDato);
        }
    }

    while (!colaPaisesF.IsEmpty()) {
        multilistaPaises->AgregarPais(colaPaisesF.Dequeue()->otroDato);
    }

}

void Controlador::PrimeraConsulta() {


    int numPais = vista.MostrarElementos(multilistaPaises->getElementos(),
                                         multilistaPaises->getSize());

    delete[] multilistaPaises->getElementos();

    Pais auxPais = multilistaPaises->getPais(numPais);

    int numCiudad = vista.MostrarElementos(auxPais.ciudades->getElementos(), auxPais.ciudades->getSize());
    Ciudad auxCiudad = auxPais.ciudades->getCiudad(numCiudad);

    auxPais.ciudades->getElementos();

    int numSucursal = vista.MostrarElementos(auxCiudad.sucursales->getElementos(), auxCiudad.sucursales->getSize());
    Sucursal auxSucursal = auxCiudad.sucursales->getSucursal(numSucursal);

    delete[] auxCiudad.sucursales->getElementos();
    int *arregloValidaciones = new int[5];

    for (int i = 0; i < 5; i++)
        arregloValidaciones[i] = 0;

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


void Controlador::MostrarMenu() {
    vista.MenuGlobal();
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

void Controlador::QuintaConsulta() {
    for (int i = 0; i < multilistaPaises->getSize(); i++) {
        Pais auxPais = multilistaPaises->getPais(i);
        vista.Imprimir("\t"+auxPais.nombre);
        for (int j = 0; j < auxPais.ciudades->getSize(); j++) {
            Ciudad auxCiudad = auxPais.ciudades->getCiudad(j);
            vista.Imprimir("\t\t"+auxCiudad.nombre);
            for (int k = 0; k < auxCiudad.sucursales->getSize(); k++) {
                Sucursal auxSucusal = auxCiudad.sucursales->getSucursal(k);

                std::string nombreSucursal = "\t\t\tNombre Sucursal "+ auxSucusal.nombre;
                std::string nombreSucursalG = "\t\t\tNombre Gerente "+ auxSucusal.nombreGerente;
                std::string numHombre = "\t\t\t\tNúmero de Hombres "+std::to_string(auxSucusal.empleados->getNumHombres());;
                std::string numMujeres = "\t\t\t\tNúmero de Mujeres "+ std::to_string(auxSucusal.empleados->getNumMujeres());

                vista.Imprimir(nombreSucursal);
                vista.Imprimir(nombreSucursalG);
                vista.Imprimir(numHombre);
                vista.Imprimir(numMujeres);
            }
        }
    }
}
