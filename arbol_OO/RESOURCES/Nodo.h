#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>
using namespace std;

class Nodo
{
	private:
        //Atributos:
		int dato;
		Nodo * izq;
		Nodo * der;
		//Metodos:
		Nodo * extraerNodo(int Dato);
		Nodo * NMD();
		Nodo * NMI();
    public:
        //Constructor:
		Nodo();
		Nodo(int Dato);
		//GETs & SETs:
		void setDato(int Dato);
		void setIzquierdo(Nodo * Izquierdo);
		void setDerecho(Nodo * Derecho);
		int getDato();
		Nodo * getIzquierdo();
		Nodo * getDerecho();
		//Metodos:
        bool existeNodo(int Dato);
		Nodo * agregarOrd(int Dato);
        Nodo * borrarNodo(int Dato);
        Nodo * borrarTodo();
		void inorder();
};

#endif // NODO_H_INCLUDED
