cmake_minimum_required(VERSION 3.26)
project(ProyectoCiencias)

set(CMAKE_CXX_STANDARD 14)

include_directories(Controlador)
include_directories(Librerias)
include_directories(Modelo/Estructuras)
include_directories(Modelo/Multilistas/MultilistaCiudades)
include_directories(Modelo/Multilistas/MultilistaEmpleados)
include_directories(Modelo/Multilistas/MultilistaHijos)
include_directories(Modelo/Multilistas/MultilistaPaises)
include_directories(Modelo/Multilistas/MultilistaSucursales)
include_directories(Vista)

add_executable(ProyectoCiencias
        Controlador/Controlador.cpp
        Controlador/Controlador.h
        Librerias/Arbol.h
        Librerias/Cabecera.h
        Librerias/Cola.h
        Librerias/Pila.h
        Modelo/Estructuras/Ciudad.h
        Modelo/Estructuras/Empleado.h
        Modelo/Estructuras/Hijo.h
        Modelo/Estructuras/Pais.h
        Modelo/Estructuras/Sucursal.h
        Modelo/Multilistas/MultilistaCiudades/MultilistaCiudad.cpp
        Modelo/Multilistas/MultilistaCiudades/MultilistaCiudad.h
        Modelo/Multilistas/MultilistaEmpleados/Imprimir.cpp
        Modelo/Multilistas/MultilistaEmpleados/Modificar.cpp
        Modelo/Multilistas/MultilistaEmpleados/MultilistaEmpleados.cpp
        Modelo/Multilistas/MultilistaEmpleados/MultilistaEmpleados.h
        Modelo/Multilistas/MultilistaEmpleados/Organizar.cpp
        Modelo/Multilistas/MultilistaHijos/MultilistaHijo.cpp
        Modelo/Multilistas/MultilistaHijos/MultilistaHijo.h
        Modelo/Multilistas/MultilistaPaises/MultilistaPaises.cpp
        Modelo/Multilistas/MultilistaPaises/MultilistaPaises.h
        Modelo/Multilistas/MultilistaSucursales/MultilistaSucursales.cpp
        Modelo/Multilistas/MultilistaSucursales/MultilistaSucursales.h
        Vista/Formulario.cpp
        Vista/Formulario.h
        Vista/Vista.cpp
        Vista/Vista.h
        main.cpp
        Controlador/ControlDAO/ControlDAO.h
        Controlador/ControlDAO/ControlDAO.cpp
        Modelo/Estructuras/Edad.h
        Modelo/Estructuras/Edad.h
)
