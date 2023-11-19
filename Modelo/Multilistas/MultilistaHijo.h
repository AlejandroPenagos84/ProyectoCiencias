
#ifndef MULTILISTAHIJO_H
#define MULTILISTAHIJO_H
#include "../Estructuras/Hijo.h"
#include "../Librerias/Cabecera.h"
#include<string>

class MultilistaHijo {
    private:
        Hijo* hijos;
        int posLibre;
        Cabecera<std::string>* CEdad;

    public:
        explicit MultilistaHijo(int);
        void AgregarHijo(Hijo);
        void ImprimirEdad(int,int);

    private:
        void OrganizarEdad();

};


#endif
