#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <iostream>
#include "Nodo.h"

using namespace std;

class Arbol
{
    private:
        //Atributos:
        Nodo * Raiz;
    public:
        Arbol();
        bool agregar(int Dato);
        void mostrar();
        bool existe(int Dato);
        void borrarDato(int Dato);
        bool borrarTodo();
};

#endif // ARBOL_H_INCLUDED
