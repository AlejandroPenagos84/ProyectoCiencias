#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"

class ControlDAO;
class Controlador
{
    Vista vista;
    ControlDAO* controlDao;

public:
    MultilistaPaises* multilistaPaises = new MultilistaPaises(40);
    Controlador();
    void MostrarMenu();
    void Consulta1();

};

#endif
