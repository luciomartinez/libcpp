#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include <iostream>

using namespace std;

class Nodo
{
	private:
		int dni;
		string nombre;
		Nodo * ste;
    public:
        //Constructores
		Nodo();
		Nodo(int DNI, string Nombre);
        //Metodos
		void setDNI(int DNI);
		void setNombre(string Nombre);
		void setSiguiente(Nodo * Siguiente);
		int getDNI();
		string getNombre();
		Nodo * getSiguiente();
};

#endif // NODO_H_INCLUDED
