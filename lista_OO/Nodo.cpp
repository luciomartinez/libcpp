#include "Nodo.h"

/** @brief Constructor de Nodo
  *
  * @todo: Guarda en memoria un nuevo Nodo
    Al invocarlo se permite declarar el valor
    que almacenara en Dato, por defecto es CERO 0;
  */
Nodo::Nodo()
{
    this->dni = 0;
    this->nombre = "";
    this->ste = NULL;
}
Nodo::Nodo(int DNI, string Nombre)
{
    this->dni = DNI;
    this->nombre = Nombre;
    this->ste=NULL;
}

/** @brief getDNI
  *
  * @todo: Retorna el valor del Dato que contiene This
  */
int Nodo::getDNI()
{
    return this->dni;
}

/** @brief getNombre
  *
  * @todo: document this function
  */
string Nodo::getNombre()
{
    return this->nombre;
}




/** @brief setNombre
  *
  * @todo: nothing.
  */
void Nodo::setNombre(string Nombre)
{
    this->nombre = Nombre;
}


/** @brief setSiguiente
        Modifica la dirección de memoria a la cual apunta This
  *
  * @todo: nothing.
  */
void Nodo::setSiguiente(Nodo * Siguiente)
{
    this->ste = Siguiente;
}

/** @brief setDNI
        Modifica el valor del DNI que contiene This
  *
  * @todo: nothing.
  */
void Nodo::setDNI(int DNI)
{
    this->dni = DNI;
}

/** @brief getSiguiente
        Retorna la dirección de memoria a la cual apunta This
  *
  * @todo: nothing.
  */
Nodo* Nodo::getSiguiente()
{
    return this->ste;
}
