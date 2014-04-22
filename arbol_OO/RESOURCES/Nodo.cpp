#include "Nodo.h"

/** @brief Constructor de Nodo
  *
  * @todo: Guarda en memoria un nuevo Nodo
    Al invocarlo se permite declarar el valor
    que almacenara en Dato, por defecto es CERO 0;
  */
Nodo::Nodo()
{
    this->dato = 0;
    this->izq = NULL;
    this->der = NULL;
}
Nodo::Nodo(int Dato)
{
    this->dato = Dato;
    this->izq = NULL;
    this->der = NULL;
}

/** @brief getDato
  *
  * @todo: Retorna el valor del Dato que contiene This
  */
int Nodo::getDato()
{
    return this->dato;
}


/** @brief setDato
  *
  * @todo: Modifica el valor del Dato que contiene This
  */
void Nodo::setDato(int Dato)
{
    this->dato = Dato;
}

/** @brief setIzquierdo
  *
  * @todo: document this function
  */
void Nodo::setIzquierdo(Nodo * Izquierdo)
{
    this->izq = Izquierdo;
}

/** @brief getDerecho
  *
  * @todo: document this function
  */
Nodo* Nodo::getDerecho()
{
    return this->der;
}

/** @brief getIzquierdo
  *
  * @todo: document this function
  */
Nodo* Nodo::getIzquierdo()
{
    return this->izq;
}

/** @brief setDerecho
  *
  * @todo: document this function
  */
void Nodo::setDerecho(Nodo * Derecho)
{
    this->der = Derecho;
}


/*
    Metodos privados
*/

/** @brief extraerNodo
  *
  * @todo: document this function
  */
Nodo* Nodo::extraerNodo(int Dato)
{
    Nodo * Rta = NULL;
    if (this != NULL) {
        if (this->getDato() != Dato){
            Rta = this->getIzquierdo()->extraerNodo(Dato);
            if (Rta==NULL) Rta=this->getDerecho()->extraerNodo(Dato);
        } else {
            Rta = this;
            Rta->izq = NULL;
            Rta->der = NULL;
        }
    }
    return Rta;
}



/** @brief NMD
  *
  * @todo: document this function
  */
Nodo* Nodo::NMD()
{
	Nodo * Rta = this;
	if (this != NULL){
		if (this->getDerecho() != NULL){
			Rta = this->getDerecho()->NMD();
		} else {
			//Rta->setIzquierdo(NULL);
            //Rta->setDerecho(NULL);
		}
	}
	return Rta;
}



/** @brief NMI
  *
  * @todo: document this function
  */
Nodo* Nodo::NMI()
{
	Nodo * Rta = this;
	if (this != NULL){
		if (this->getIzquierdo() != NULL){
			Rta = this->getIzquierdo()->NMI();
		} else {
			//Rta->setIzquierdo(NULL);
            //Rta->setDerecho(NULL);
		}
	}
	return Rta;
}




/*
    Metodos publicos..
*/


/** @brief existeNodo
  *
  * @todo: document this function
  */
bool Nodo::existeNodo(int Dato)
{
    bool resultado = false;
    if (this!=NULL)
    {
        if (getDato() < Dato)
        {
            resultado = getDerecho()->existeNodo(Dato);
        }
        if (getDato() > Dato)
        {
            resultado = getIzquierdo()->existeNodo(Dato);
        }
        if (getDato() == Dato) resultado = true;
    }
    return resultado;
}



/** @brief inorder
  *
  * @todo: document this function
  */
void Nodo::inorder()
{
    if (getIzquierdo() != NULL) getIzquierdo()->inorder();
    std::cout <<"| "<<getDato()<<" |";
    if (getDerecho() != NULL) getDerecho()->inorder();
}

/** @brief borrarTodo
  *
  * @todo: document this function
  */
Nodo* Nodo::borrarTodo()
{
    if (getIzquierdo() != NULL) setIzquierdo(getIzquierdo()->borrarTodo());
    delete this;
    if (getDerecho() != NULL) setDerecho(getDerecho()->borrarTodo());
    return NULL;
}




/** @brief agregarOrdenado
  *
  * @todo: document this function
  */
Nodo* Nodo::agregarOrd(int Dato)
{
    Nodo* Rta = this;
    if (this == NULL)
    {
        Rta = new Nodo(Dato);
    }
    else
    {
        if (this->getDato() < Dato)
        {
            this->der = getDerecho()->agregarOrd(Dato);
        }
        else
        {
            this->izq = getIzquierdo()->agregarOrd(Dato);
        }
    }
    return Rta;
}


/** @brief borrarNodo
  *
  * @todo: document this function
  */
Nodo* Nodo::borrarNodo(int Dato)
{
    Nodo * Rta = this;
    if (getDato() == Dato)
    {
        //Se encontro el nodo a borrar
        if (getIzquierdo()==NULL || getDerecho()==NULL)
        {
            if (getIzquierdo()!=NULL)
                Rta = getIzquierdo();
             else
                Rta = getDerecho(); //Puede retornar NULL, pero funciona igual
            delete this;
        }
        else
        {
            //El nodo a borrar tiene 2 hojas (nodos hijos)
            //Respaldacion de datos antes de borrar el nodo contenedor de los mismos
            int aux = this->getIzquierdo()->NMD()->getDato();
            //int aux = this->getDerecho()->NMD()->getDato();
            //Se procede a borrar el nodo mas derecho (NMD) de la rama izquierda
            izq = this->getIzquierdo()->borrarNodo(aux);
            //der = this->getDerecho()->borrarNodo(aux);
            //Se asigna el valor guardado previamente
            this->setDato(aux);
        }
    }
    else
    {
        //Continua en la busqueda del nodo
        if (getDato() < Dato)
            setDerecho(getDerecho()->borrarNodo(Dato));
        else
            setIzquierdo(getIzquierdo()->borrarNodo(Dato));
    }
    return Rta;
}
