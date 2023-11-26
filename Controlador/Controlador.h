#ifndef CONTROLADOR_H
#define CONTROLADOR_H
#include "../Vista/Vista.h"
#include "../MultilistaPaises/MultilistaPaises.h"
#include "ControlDAO/ControlDAO.h"
#include<vector>

class ControlDAO;
class Controlador
{
    Vista vista;
    ControlDAO* controlDao;
    std::vector<Pais> paises;
    std::vector<Ciudad> ciudades;

public:
    MultilistaPaises* multilistaPaises;
    Controlador();
    void MostrarMenu();
    void PrimeraConsulta();
    void SegundaConsulta();
    void CuartaConsulta();

};

#endif
