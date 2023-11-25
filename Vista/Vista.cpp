#include "Vista.h"
// Configurar según la localización del sistema

Vista::Vista()
{

}

void Vista::MenuGlobal() {
    while (true) {
        switch (MostrarMenu()) {
            default:
                std::cout << "Opcion no valida" << std::endl;
                break; // Agrega un break aquí para salir del switch

            case 1:
                IngresarDatos();
                break;

            case 2:
                std::cout << "CONSULTARR: " << std::endl; // Temporal
                break;

            case 3:
                // Aquí se pondría todo para que copie lo que está dentro de los archivos
                return; // Utiliza 'return' para salir del método y, por lo tanto, del bucle
        }
    }
}

int Vista::MostrarMenu() {
    int num;
    std::cout<<"Sucursales"<<std::endl;
    std::cout<<"\t1. Ingresar nuevos datos: "<<std::endl;
    std::cout<<"\t2. Consultar: "<<std::endl;
    std::cout<<"\t3. Salir: "<<std::endl;
    std::cout<<"Ingresa una opción: ";

    std::cin>>num;
    return num;
}

void Vista::IngresarDatos()
{
    int numEmpleados;
    std::cout << "Ingrese el número de empleados: ";
    std::cin >> numEmpleados;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Empleado> empleados;
    for (int i = 0; i < numEmpleados; ++i) {
        std::cout << "\nCapturando información del empleado " << i + 1 << ":\n";
        //empleados.addLast(formulario.capturarInfoEmpleado());
    }

    // Capturar información de sucursales
    int numSucursales;
    std::cout << "\nIngrese el número de sucursales: ";
    std::cin >> numSucursales;
    std::cin.ignore(); // Limpiar el buffer del teclado

    //List<Sucursal> sucursales;
    for (int i = 0; i < numSucursales; ++i) {
        std::cout << "\nCapturando información de la sucursal " << i + 1 << ":\n";
        //sucursales.addLast(formulario.capturarInformacionSucursal());
    }
}


void Vista::MenuConsultas()
{
    std::cout<<"Consultas"<<std::endl;

    std::cout<<"\t1. Número total de personas que trabajan en una sucursal\n"
               "clasificados en rangos de edades "<<std::endl;

    std::cout<<"\t2. Listado de los nombres y apellidos de aquellos que tienen  \n"
               "un número de hijos dado : "<<std::endl;

    std::cout<<"\t3. Nombre y apellidos de las personas que viven en una ciudad dada: "<<std::endl;

    std::cout<<"\t4. Número de sucursales en las que trabaja un número de personas superior a\n"
               " un número dado"<<std::endl;

    std::cout<<"\t5. Obtener el número de hombres y el número de hombres y mujeres"<<std::endl;

    std::cout<<"\t6. Lista de trabajadores de de edad dada"<<std::endl;

    std::cout<<"\t7. Salir"<<std::endl;

    std::cout<<"Ingresa una opción: ";
}

void Vista::MenuPrimeraConsulta()
{
    
}