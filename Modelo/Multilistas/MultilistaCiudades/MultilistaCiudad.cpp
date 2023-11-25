#include "MultilistaCiudad.h"

MultilistaCiudad::MultilistaCiudad(int max) {
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de ciudades.
     */

    ciudades = new Ciudad[max];
    posLibre = 0;
    size = 0;
}

void MultilistaCiudad::AgregarCiudad(std::string nombre) {
    /**
     * @brief Agrega una ciudad a la multilista.
     *
     * @param nombre Nombre de la ciudad.
     */

    Ciudad ciudad(nombre);

    // Crear una nueva multilista de sucursales para la ciudad
    ciudad.sucursales = new MultilistaSucursales(20);

    // Incrementar posición libre y tamaño
    posLibre++;
    size++;
}

void MultilistaCiudad::EliminarCiudad(int indiceArray) {
    /**
     * @brief Elimina una ciudad de la multilista.
     *
     * @param indiceArray Índice en el arreglo de ciudades a eliminar.
     */

    ciudades[indiceArray].estado = false;
    size--;
}

void MultilistaCiudad::ModificarCiudad(int num, std::string nuevoDato, int indiceArray) {
    /**
     * @brief Modifica una ciudad en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de ciudades a modificar.
     */

    if (num == 1) {
        ciudades[indiceArray].nombre = nuevoDato;
    }
}

Ciudad MultilistaCiudad::getCiudad(int indiceArray) {
    /**
     * @brief Obtiene una ciudad del arreglo.
     *
     * @param indiceArray Índice en el arreglo de ciudades.
     * @return La ciudad en la posición especificada.
     */

    return ciudades[indiceArray];
}
