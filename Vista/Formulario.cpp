#include "Formulario.h"
#include <iostream>

void Formulario::capturarInfoHijos(Empleado& empleado)
{
    for (int i = 0; i < empleado.numHijos; ++i) {
        Hijo hijo;
        std::cout << "Nombre del hijo " << i + 1 << ": ";
        getline(std::cin, hijo.nombre);

        std::cout << "Fecha del hijo (DD/MM/AAAA): ";
        std::cin>>hijo.fechaNacimiento;

        std::cin.ignore(); // Limpiar el buffer del teclado

        empleado.hijos.addLast(hijo);
    }
}

Empleado Formulario::capturarInfoEmpleado()
{
    Empleado empleado;

    // Captura de datos básicos del empleado
    std::cout << "Nombre: ";
    std::getline(std::cin, empleado.nombre);

    std::cout << "Apellido: ";
    std::getline(std::cin, empleado.apellido);

    std::cout << "Tipo de identificación (Cédula de ciudadanía, cédula de extranjería o tarjeta de identidad): ";
    std::getline(std::cin, empleado.tipoIdentificacion);

    std::cout << "Número de identificación: ";
    std::getline(std::cin, empleado.numIdentificacion);

    std::cout << "Sexo (F/M): ";
    std::cin >> empleado.sexo;

    std::cout << "Teléfono celular: ";
    std::cin >> empleado.telefonoCelular;

    std::cout << "Teléfono fijo: ";
    std::cin >> empleado.telefonoFijo;

    std::cout << "Email: ";
    std::cin >> empleado.email;

    std::cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
    std::cin >> empleado.fechaNacimiento;

    std::cout << "Ciudad de Nacimiento: ";
    std::cin >> empleado.ciudadNacimiento;

    std::cout << "País de Nacimiento: ";
    std::cin >> empleado.paisNacimiento;

    std::cout << "Ciudad de Residencia: ";
    std::cin >> empleado.ciudadResidencia;

    std::cin.ignore(); // Limpiar el buffer del teclado

    std::cout << "Dirección: ";
    std::getline(std::cin, empleado.direccion);

    std::cout << "Barrio: ";
    std::getline(std::cin, empleado.barrio);

    std::cout << "Actividad laboral (Artes, ciencias sociales, ingenierías, áreas de la salud, otros): ";
    std::getline(std::cin, empleado.actividadLaboral);

    std::cout << "¿Tiene hijos? (S/N): ";
    std::cin >> empleado.tieneHijos;

    // Captura de información de los hijos si el empleado tiene hijos
    if (empleado.tieneHijos == 'S' || empleado.tieneHijos == 's') {
        std::cout << "Número de hijos: ";
        std::cin >> empleado.numHijos;

        std::cin.ignore(); // Limpiar el buffer del teclado

        capturarInfoHijos(empleado);
    }

    // Captura de la sucursal en la que trabaja el empleado
    std::cout << "Nombre de la sucursal en la que trabaja: ";
    getline(std::cin, empleado.sucursalTrabajo);

    return empleado;
}

// Función para capturar la información de una sucursal
Sucursal Formulario::capturarInformacionSucursal() {
    Sucursal sucursal;

    // Captura de datos básicos de la sucursal
    std::cout << "Nombre de la sucursal: ";
    getline(std::cin, sucursal.nombre);

    std::cout << "Dirección de la sucursal: ";
    getline(std::cin, sucursal.direccion);

    std::cout << "Barrio de la sucursal: ";
    getline(std::cin, sucursal.barrio);

    std::cout << "Nombre del gerente de la sucursal: ";
    getline(std::cin, sucursal.nombreGerente);

    return sucursal;
}
