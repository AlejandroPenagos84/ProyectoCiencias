#include "MultilistaSucursales.h"

MultilistaSucursales::MultilistaSucursales(int max) {
    // Inicializar el arreglo de sucursales
    sucursales = new Sucursal[max];

    posLibre = 0;
    size = 0;
}

void MultilistaSucursales::AgregarSucursal(std::string nombre,
                                           std::string direccion,
                                           std::string barrio,
                                           std::string nombreGerente) {
    /**
     * @brief Agrega una nueva sucursal a la multilista.
     *
     * @param nombre Nombre de la sucursal.
     * @param direccion Dirección de la sucursal.
     * @param barrio Barrio de la sucursal.
     * @param nombreGerente Nombre del gerente de la sucursal.
     */

    Sucursal sucursal(nombre, direccion, barrio, nombreGerente);

    // Crear una nueva multilista de empleados para la sucursal
    sucursal.empleados = new MultilistaEmpleados(40);

    // Agregar la sucursal al arreglo
    sucursales[posLibre] = sucursal;

    // Actualizar el índice libre y el tamaño
    posLibre++;
    size++;
}

void MultilistaSucursales::EliminarSucursal(int indiceArray) {
    /**
     * @brief Elimina una sucursal de la multilista.
     *
     * @param indiceArray Índice en el arreglo de sucursales a eliminar.
     */

    sucursales[indiceArray].estado = false;
    size--;
}

void MultilistaSucursales::ModificarSucursal(int num, std::string nuevoDato, int indiceArray) {
    /**
     * @brief Modifica una propiedad específica de una sucursal en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de sucursales a modificar.
     */

    switch (num) {
        case 1:
            sucursales[indiceArray].nombre = std::move(nuevoDato);
            break;
        case 2:
            sucursales[indiceArray].direccion = std::move(nuevoDato);
            break;
        case 3:
            sucursales[indiceArray].barrio = std::move(nuevoDato);
            break;
        case 4:
            sucursales[indiceArray].nombreGerente = std::move(nuevoDato);
            break;
        default:
            break;
    }
}

Sucursal MultilistaSucursales::getSucursal(int indiceArray) {
    /**
     * @brief Obtiene una sucursal del arreglo.
     *
     * @param indiceArray Índice en el arreglo de sucursales.
     * @return La sucursal en la posición especificada.
     */

    return sucursales[indiceArray];
}
