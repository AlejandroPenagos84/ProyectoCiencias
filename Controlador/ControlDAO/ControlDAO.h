#ifndef CONTROLDAO_H
#define CONTROLDAO_H
#include "../Controlador.h"
#include "fstream"

class Controlador;

class ControlDAO {
private:
    Controlador* control;
    size_t posLibre;

public:

    explicit ControlDAO(Controlador* ctrl);

    // Metodos Para el Archivo de Hijos
    void AgregarHijoDAO();

    void EliminarHijoDAO();

    void ModificarHijoDAO();

    void LeerHijosDAO();

    // Metodos Para el Archivo de Empleados
    void AgregarEmpleadoDAO();

    void EliminarEmpleadoDAO();

    void ModificarEmpleadoDAO();

    void LeerEmpleadosDAO();

    //Metodos para el archivo de sucursales
    void AgregarSucursalDAO();

    void EliminarSucursalDAO();

    void ModificarSucursalDAO();

    void LeerSucursalesDAO();

    // Metodo para el archivo de Ciudades
    void AgregarCiudadDAO();

    void EliminarCiudadDAO();

    void ModificarCiudadDAO();

    void LeerCiudadesDAO();

    //Metodos para el archivo de Ciudades
    void AgregarPaisDAO();

    void EliminarPaisDAO();

    void ModificarPaisDAO();

    void LeerPaisesDAO();

    // Metodo que se usará para leer y llenar todo el archivo
    void LeerTodoDAO();
};


#endif
/*

 */