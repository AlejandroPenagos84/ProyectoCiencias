#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Estructura para almacenar la información de los hijos
struct Hijo {
    string nombre;
    int edad;
};

// Estructura para almacenar la información de un empleado
struct Empleado {
    string nombre;
    string apellido;
    string tipoIdentificacion;
    string numeroIdentificacion;
    char sexo;
    string telefonoCelular;
    string telefonoFijo;
    string email;
    string fechaNacimiento;
    string ciudadNacimiento;
    string paisNacimiento;
    string ciudadResidencia;
    string direccion;
    string barrio;
    string actividadLaboral;
    char tieneHijos;
    int numeroHijos;
    vector<Hijo> hijos;
    string sucursalTrabajo;
};

// Estructura para almacenar la información de una sucursal
struct Sucursal {
    string nombre;
    string direccion;
    string barrio;
    string nombreGerente;
};

// Función para capturar la información de un empleado
Empleado capturarInformacionEmpleado() {
    Empleado empleado;

    // Captura de datos básicos del empleado
    cout << "Nombre: ";
    getline(cin, empleado.nombre);

    cout << "Apellido: ";
    getline(cin, empleado.apellido);

    cout << "Tipo de identificación (Cédula de ciudadanía, cédula de extranjería o tarjeta de identidad): ";
    getline(cin, empleado.tipoIdentificacion);

    cout << "Número de identificación: ";
    getline(cin, empleado.numeroIdentificacion);

    cout << "Sexo (F/M): ";
    cin >> empleado.sexo;

    cout << "Teléfono celular: ";
    cin >> empleado.telefonoCelular;

    cout << "Teléfono fijo: ";
    cin >> empleado.telefonoFijo;

    cout << "Email: ";
    cin >> empleado.email;

    cout << "Fecha de Nacimiento (DD/MM/AAAA): ";
    cin >> empleado.fechaNacimiento;

    cout << "Ciudad de Nacimiento: ";
    cin >> empleado.ciudadNacimiento;

    cout << "País de Nacimiento: ";
    cin >> empleado.paisNacimiento;

    cout << "Ciudad de Residencia: ";
    cin >> empleado.ciudadResidencia;

    cin.ignore(); // Limpiar el buffer del teclado

    cout << "Dirección: ";
    getline(cin, empleado.direccion);

    cout << "Barrio: ";
    getline(cin, empleado.barrio);

    cout << "Actividad laboral (Artes, ciencias sociales, ingenierías, áreas de la salud, otros): ";
    getline(cin, empleado.actividadLaboral);

    cout << "¿Tiene hijos? (S/N): ";
    cin >> empleado.tieneHijos;

    // Captura de información de los hijos si el empleado tiene hijos
    if (empleado.tieneHijos == 'S' || empleado.tieneHijos == 's') {
        cout << "Número de hijos: ";
        cin >> empleado.numeroHijos;

        cin.ignore(); // Limpiar el buffer del teclado

        for (int i = 0; i < empleado.numeroHijos; ++i) {
            Hijo hijo;
            cout << "Nombre del hijo " << i + 1 << ": ";
            getline(cin, hijo.nombre);

            cout << "Edad del hijo " << i + 1 << ": ";
            cin >> hijo.edad;

            cin.ignore(); // Limpiar el buffer del teclado

            empleado.hijos.push_back(hijo);
        }
    }

    // Captura de la sucursal en la que trabaja el empleado
    cout << "Nombre de la sucursal en la que trabaja: ";
    getline(cin, empleado.sucursalTrabajo);

    return empleado;
}

// Función para capturar la información de una sucursal
Sucursal capturarInformacionSucursal() {
    Sucursal sucursal;

    // Captura de datos básicos de la sucursal
    cout << "Nombre de la sucursal: ";
    getline(cin, sucursal.nombre);

    cout << "Dirección de la sucursal: ";
    getline(cin, sucursal.direccion);

    cout << "Barrio de la sucursal: ";
    getline(cin, sucursal.barrio);

    cout << "Nombre del gerente de la sucursal: ";
    getline(cin, sucursal.nombreGerente);

    return sucursal;
}

int main() {
    // Capturar información de empleados
    int numEmpleados;
    cout << "Ingrese el número de empleados: ";
    cin >> numEmpleados;
    cin.ignore(); // Limpiar el buffer del teclado

    vector<Empleado> empleados;
    for (int i = 0; i < numEmpleados; ++i) {
        cout << "\nCapturando información del empleado " << i + 1 << ":\n";
        empleados.push_back(capturarInformacionEmpleado());
    }

    // Capturar información de sucursales
    int numSucursales;
    cout << "\nIngrese el número de sucursales: ";
    cin >> numSucursales;
    cin.ignore(); // Limpiar el buffer del teclado

    vector<Sucursal> sucursales;
    for (int i = 0; i < numSucursales; ++i) {
        cout << "\nCapturando información de la sucursal " << i + 1 << ":\n";
        sucursales.push_back(capturarInformacionSucursal());
    }

  

    return 0;
}

