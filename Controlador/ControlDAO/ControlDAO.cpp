#include "ControlDAO.h"

ControlDAO::ControlDAO(Controlador *ctrl) : control(ctrl)
{
    posLibre = 0;
}

void ControlDAO::LeerTodoDAO()
{
    control->multilistaPaises;
}