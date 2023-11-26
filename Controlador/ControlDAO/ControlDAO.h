#ifndef CONTROLDAO_H
#define CONTROLDAO_H
#include "../Controlador.h"
#include "fstream"
#include <vector>


class Controlador;

class ControlDAO {
private:
    Controlador* control;

    // Con los arboles buscaré los indices segun la llave primaria
    RBTree<int,int>* paisesLlaveP;
    RBTree<int,int>* ciudadesLlaveP;
    RBTree<int,int>* sucursalesLlaveP;
    RBTree<int,int>* empleadosLlaveP;
    RBTree<int,int>* hijosLlaveP;//ESTE CREO QUE NO ES NECESARIO

    //Arboles con llaves secundarias y los datos completos
    RBTree<int,Hijo>* hijosLlaveF;
    RBTree<int,Empleado>* empleadosLlaveF;
    RBTree<int, Sucursal>* sucurcalesLlaveF;
    RBTree<int,Ciudad>* ciudadesLlaveF;
    RBTree<int,Pais>* paises;
public:
    RBTree<int, Pais> *getPaises() const;

private:
    int pos;
public:

    explicit ControlDAO(Controlador* ctrl);
    void LeerHijosDAO(const std::string &filename);
    void LeerEmpleadosDAO(const std::string &filename);
    void LeerSucursalesDAO(const std::string &filename);
    void LeerCiudadesDAO(const std::string &filename);
    void LeerPaisesDAO(const std::string &filename);

    RBTree<int, int> *getPaisesLlaveP() const;

    RBTree<int, int> *getCiudadesLlaveP() const;

    RBTree<int, int> *getSucursalesLlaveP() const;

    RBTree<int, int> *getEmpleadosLlaveP() const;

    RBTree<int, int> *getHijosLlaveP() const;

    RBTree<int, Hijo> *getHijosLlaveF() const;

    RBTree<int, Empleado> *getEmpleadosLlaveF() const;

    RBTree<int, Sucursal> *getSucurcalesLlaveF() const;

    RBTree<int, Ciudad> *getCiudadesLlaveF() const;

    // Metodos Para el Archivo de Hijos
    void AgregarHijoDAO();

    void EliminarHijoDAO();

    void ModificarHijoDAO();

    // Metodos Para el Archivo de Empleados
    void AgregarEmpleadoDAO();

    void EliminarEmpleadoDAO();

    void ModificarEmpleadoDAO();


    //Metodos para el archivo de sucursales
    void AgregarSucursalDAO();

    void EliminarSucursalDAO();

    void ModificarSucursalDAO();


    // Metodo para el archivo de Ciudades
    void AgregarCiudadDAO();

    void EliminarCiudadDAO();

    void ModificarCiudadDAO();


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