#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "Nodo.h"

class Lista{
    private:
        Nodo *lista;
        Nodo * buscarNodo(int DNI);
    public:
        Lista();
        int agregar(int DNI, string Nombre);
        void mostrar();
        int cantidadNodos();
        string obtenerNombre(int DNI);
        bool existeNodo(int DNI);
        void borrarNodo(int DNI);
        void borrarLista();
};

#endif // LISTA_H_INCLUDED
