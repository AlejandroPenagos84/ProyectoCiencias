#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"


class ControlDAO;
class Controlador
{
    Vista vista;
    ControlDAO* controlDao;

public:
    Controlador();
    void MostrarMenu();
};

#endif
