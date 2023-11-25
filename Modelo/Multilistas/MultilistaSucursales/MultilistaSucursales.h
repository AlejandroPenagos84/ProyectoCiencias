#ifndef MULTILISTASUCURSALES_H
#define MULTILISTASUCURSALES_H

#include "../../Estructuras/Sucursal.h"

/**
 * @brief Clase MultilistaSucursales
 *
 * Maneja la lógica para almacenar una lista de sucursales dentro de cada ciudad.
 */
class MultilistaSucursales {

private:
    /**
     * @brief Arreglo de sucursales
     */
    Sucursal *sucursales;

    /**
     * @brief Posición libre actual en el arreglo de sucursales.
     */
    int posLibre;

    /**
     * @brief Tamaño actual del arreglo de sucursales.
     */
    int size;

public:
    /**
     * @brief Constructor de la clase.
     *
     * @param max Tamaño máximo del arreglo de sucursales.
     */
    explicit MultilistaSucursales(int max);

    /**
     * @brief Agrega una sucursal a la multilista.
     *
     * @param nombre Nombre de la sucursal.
     * @param direccion Dirección de la sucursal.
     * @param barrio Barrio de la sucursal.
     * @param nombreGerente Nombre del gerente de la sucursal.
     */
    void AgregarSucursal(std::string nombre,
                         std::string direccion,
                         std::string barrio,
                         std::string nombreGerente);

    /**
     * @brief Elimina una sucursal de la multilista.
     *
     * @param indiceArray Índice en el arreglo de sucursales a eliminar.
     */
    void EliminarSucursal(int indiceArray);

    /**
     * @brief Modifica una sucursal en la multilista.
     *
     * @param num Número de la propiedad a modificar.
     * @param nuevoDato Nuevo valor para la propiedad.
     * @param indiceArray Índice en el arreglo de sucursales a modificar.
     */
    void ModificarSucursal(int num, std::string nuevoDato, int indiceArray);

    /**
     * @brief Obtiene una sucursal del arreglo.
     *
     * @param indiceArray Índice en el arreglo de sucursales.
     * @return La sucursal en la posición especificada.
     */
    Sucursal getSucursal(int indiceArray);

};

#endif
