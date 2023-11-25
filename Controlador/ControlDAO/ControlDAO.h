#ifndef PROYECTOCIENCIAS_CONTROLDAO_H
#define PROYECTOCIENCIAS_CONTROLDAO_H
#include "Controlador.h"

class ControlDAO {
private:
    Controlador* controlador;
public :
    explicit ControlDAO(Controlador* controlador);

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
};


#endif //PROYECTOCIENCIAS_CONTROLDAO_H
