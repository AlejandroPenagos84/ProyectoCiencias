#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"
#include<vector>

class ControlDAO;
class Controlador
{
private:
    Vista vista;
    ControlDAO* controlDao;
    MultilistaPaises* multilistaPaises;

public:

    Controlador();
    void MostrarMenu();
    void PrimeraConsulta();
    void SegundaConsulta();
    //void CuartaConsulta();

};

#endif
