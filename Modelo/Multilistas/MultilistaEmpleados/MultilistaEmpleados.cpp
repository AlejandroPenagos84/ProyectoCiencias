#include "MultilistaEmpleados.h"
#include "iostream"
#include <utility>

/**
 * @brief Constructor de la clase MultilistaEmpleados.
 *
 * Este constructor inicializa los arreglos, cabeceras y árboles necesarios
 * para la organización de empleados en la multilista.
 *
 * @param max Tamaño máximo de los arreglos.
 */
MultilistaEmpleados::MultilistaEmpleados(int max) {
    // Se inicializa el arreglo que va contener los empleados
    empleados = new Empleado[max];

    // Se inicializan los arreglos que serán las cabeceras por cada atributo
    CSexo = new Cabecera<char>[2];
    CActividadLaboral = new Cabecera<std::string>[max];
    CCiudadNacimiento = new Cabecera<std::string>[max];
    CBarrio = new Cabecera<std::string>[max];
    CSucursal = new Cabecera<std::string>[max];
    CNumeroHijos = new Cabecera<std::string>[4];
    CEdad = new Cabecera<std::string>[5];

    // Inicializar Posicion Libre
    posLibre = 0;

    //Inicializar Size
    size = 0;

    // Inicializar Indices
    indiceActividadLaboral = 0;
    indiceCiudadNacimiento = 0;
    indiceBarrio = 0;
    indiceSucursal = 0;

    //Inicializar Arreglos
    //Cabecera para organizar por sezo
    CSexo[0] = {'M', -1};
    CSexo[1] = {'F', -1};

    //Cabecera para organizar los atributos que tengan string
    CActividadLaboral[0] = {"", -1};
    CCiudadNacimiento[0] = {"", -1};
    CBarrio[0] = {"", -1};
    CSucursal[0] = {"", -1};

    //Cabecera para organizar por numero de hijos
    CNumeroHijos[0] = {"Sin Hijos", -1};
    CNumeroHijos[1] = {"1 a 2", -1};
    CNumeroHijos[2] = {"3 a 4", -1};
    CNumeroHijos[3] = {"Mas de 4", -1};

    //Cabecera para edad
    CEdad[0] = {"18 a 24", -1};
    CEdad[1] = {"25 a 35", -1};
    CEdad[2] = {"36 a 45", -1};
    CEdad[3] = {"46 a 60", -1};
    CEdad[4] = {"Mas de 60", -1};

    //Inicializar Sentinelas

    // Inicializar Arboles
    arbolActividad = new RBTree<std::string, int>();
    arbolCiudadNacimiento = new RBTree<std::string, int>();
    arbolBarrio = new RBTree<std::string, int>();
    arbolSucursales = new RBTree<std::string, int>();
}

/**
 * @brief Agrega un empleado a la multilista e invoca los métodos privados para organizar los datos.
 *
 * @param nombre Nombre del empleado.
 * @param apellido Apellido del empleado.
 * @param tipoIdentificacion Tipo de identificación del empleado.
 * @param numIdentificacion Número de identificación del empleado.
 * @param sexo Género del empleado.
 * @param telefonoCelular Número de teléfono celular del empleado.
 * @param telefonoFijo Número de teléfono fijo del empleado.
 * @param email Correo electrónico del empleado.
 * @param ciudadNacimiento Ciudad de nacimiento del empleado.
 * @param paisNacimiento País de nacimiento del empleado.
 * @param ciudadResidencia Ciudad de residencia del empleado.
 * @param direccion Dirección del empleado.
 * @param tieneHijos Indicador de si el empleado tiene hijos.
 * @param actividadLaboral Actividad laboral del empleado.
 * @param sucursalTrabajo Sucursal de trabajo del empleado.
 * @param barrio Barrio de residencia del empleado.
 * @param numHijos Número de hijos del empleado.
 * @param fechaNacimiento Fecha de nacimiento del empleado.
 */
void MultilistaEmpleados::AgregarEmpleado(
        std::string nombre,
        std::string apellido,
        std::string tipoIdentificacion,
        std::string numIdentificacion,
        char sexo,
        std::string telefonoCelular,
        std::string telefonoFijo,
        std::string email,
        std::string ciudadNacimiento,
        std::string paisNacimiento,
        std::string ciudadResidencia,
        std::string direccion,
        char tieneHijos,
        std::string actividadLaboral,
        std::string sucursalTrabajo,
        std::string barrio,
        int numHijos,
        std::string fechaNacimiento) {

    Empleado empleado(
            std::move(nombre),
            std::move(apellido),
            std::move(tipoIdentificacion),
            std::move(numIdentificacion),
            sexo,
            std::move(telefonoCelular),
            std::move(telefonoFijo),
            std::move(email),
            std::move(ciudadNacimiento),
            std::move(paisNacimiento),
            std::move(ciudadResidencia),
            std::move(direccion),
            tieneHijos,
            std::move(actividadLaboral),
            std::move(sucursalTrabajo),
            std::move(barrio),
            numHijos,
            std::move(fechaNacimiento));

    empleado.hijos = new MultilistaHijo(numHijos);
    empleados[posLibre] = std::move(empleado);

    //Organizar Por Sexo
    OrganizarSexo(posLibre);

    //Organizar Actividad Laboral
    Reorganizar(
            arbolActividad,
            CActividadLaboral,
            &Empleado::actividadLaboral,
            indiceActividadLaboral,
            &Empleado::sigActividadLaboral,
            posLibre);

    //Organizar por ciudad de nacimiento
    Reorganizar(arbolCiudadNacimiento,
                CCiudadNacimiento,
                &Empleado::ciudadNacimiento,
                indiceCiudadNacimiento,
                &Empleado::sigCiudadNacimiento,
                posLibre);

    //Organizar por Barrio
    Reorganizar(arbolBarrio,
                CBarrio,
                &Empleado::barrio,
                indiceBarrio,
                &Empleado::sigBarrio,
                posLibre);

    //Organizar Por nombre De Sucursales
    Reorganizar(arbolSucursales,
                CSucursal,
                &Empleado::sucursalTrabajo,
                indiceSucursal,
                &Empleado::sigNombreSurcursal,
                posLibre);

    // Organizar Por Numero de Hijos
    OrganizarCategoria(CNumeroHijos,
                       posLibre,
                       &Empleado::sigNumHijos,
                       getCabeceraNumHijos(posLibre));

    //Organizar Por edad
    OrganizarCategoria(CEdad,
                       posLibre,
                       &Empleado::sigEdad,
                       getCabeceraEdad(posLibre));

    posLibre++;
    size++;
}

/**
 * @brief Elimina un empleado de la multilista.
 *
 * Este método marca el estado del empleado en la posición indicada como falso,
 * indicando que ha sido eliminado de la multilista.
 *
 * @param indiceArray Índice del empleado en el arreglo.
 */
void MultilistaEmpleados::Eliminar(int indiceArray) {
    empleados[indiceArray].estado = false;
    size--;
}

/**
 * @brief Obtiene el índice de la cabecera correspondiente al número de hijos de un empleado.
 *
 * Este método calcula el índice de la cabecera en la que debe ubicarse el empleado
 * en función de la cantidad de hijos que tenga.
 *
 * @param indiceArray Índice del empleado en el arreglo.
 * @return Índice de la cabecera correspondiente.
 */
int MultilistaEmpleados::getCabeceraNumHijos(int indiceArray) {
    int numHijos = empleados[indiceArray].numHijos;
    int indiceCabecera;

    if (numHijos == 0)
        indiceCabecera = 0;
    else if (numHijos <= 2)
        indiceCabecera = 1;
    else if (numHijos <= 4)
        indiceCabecera = 2;
    else
        indiceCabecera = 3;

    return indiceCabecera;
}

/**
 * @brief Obtiene el índice de la cabecera correspondiente a la edad de un empleado.
 *
 * Este método calcula el índice de la cabecera en la que debe ubicarse el empleado
 * en función de su edad.
 *
 * @param indiceArray Índice del empleado en el arreglo.
 * @return Índice de la cabecera correspondiente.
 */
int MultilistaEmpleados::getCabeceraEdad(int indiceArray) {
    int edad = empleados[indiceArray].edad;
    int indiceCabecera;

    if (edad >= 18 && edad <= 24)
        indiceCabecera = 0;
    else if (edad >= 25 && edad <= 35)
        indiceCabecera = 1;
    else if (edad >= 36 && edad <= 45)
        indiceCabecera = 2;
    else if (edad >= 46 && edad <= 60)
        indiceCabecera = 3;
    else
        indiceCabecera = 4;

    return indiceCabecera;
}

/**
 * @brief Obtiene el número total de empleados en la multilista.
 *
 * @return Número total de empleados en la multilista.
 */
int MultilistaEmpleados::getNumEmpleados(){ return size; }

/**
 * @brief Obtiene el objeto Empleado en la posición indicada del arreglo.
 *
 * @param indiceArray Índice del empleado en el arreglo.
 * @return Objeto Empleado en la posición indicada.
 */
Empleado MultilistaEmpleados::getEmpleado(int indiceArray) {
    return empleados[indiceArray];
}

Cabecera<std::string>* MultilistaEmpleados::getArreglosRangoHijos()
{
    return CNumeroHijos;
}
