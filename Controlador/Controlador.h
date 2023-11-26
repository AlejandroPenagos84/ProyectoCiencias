#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"
#include "../Librerias/ColasPrioridad.h"

class ControlDAO;
class Controlador
{
    Vista vista;
    ControlDAO* controlDao;

public:
    MultilistaPaises* multilistaPaises = new MultilistaPaises(40);
    Controlador();
    void MostrarMenu();
    void PrimeraConsulta();
    void SegundaConsulta();
    void CuartaConsulta();

};

#endif
