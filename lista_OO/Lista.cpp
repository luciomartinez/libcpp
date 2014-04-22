#include "Lista.h"

/** @brief Constructor Lista
  *
  * @todo: Inicializa el Puntero en NULL
  */
 Lista::Lista()
{
    lista = NULL;
}

/** @brief obtenerNombre
  *
  * @todo: document this function
  */
string Lista::obtenerNombre(int DNI)
{
    Nodo * aux = this->buscarNodo(DNI);
    if (aux!=NULL)
        return aux->getNombre();
    else
        return "";
}



/** @brief agregar
        Agrega un nuevo Nodo a la lista;
        cada nuevo nodo se agrega al principio de la lista
        haciendo de esta una cola LIFO;
        el nodo mas viejo en haberse ingresado sera el primero en salir;

        Este metodo retorna los siguientes valores:
            -1 si los datos ingresados no son validos
            0 si ya existia otro registro con el DNI ingresado
            1 si se agregan los datos exitosamente
  *
  * @todo: nothing.
  */
int Lista::agregar(int DNI, string Nombre)
{
    //Se verifica que los datos ingresados sean validos
    if (DNI<1 || DNI>99999999 || Nombre=="" || Nombre.length()>99) return -1;
    //Se comprueba que no exista un registro con el mismo DNI
    if (this->buscarNodo(DNI)!=NULL) return 0;

    Nodo * NuevoNodo;
    NuevoNodo = new Nodo(DNI, Nombre);
    if (lista==NULL) {
        lista = NuevoNodo;
    } else {
        NuevoNodo->setSiguiente(lista);
        lista=NuevoNodo;
    }
    return 1;
}

/** @brief mostrar
  *
  * @todo: Muestra el valor que almacena cada Nodo que contiene This
  */
void Lista::mostrar()
{
    Nodo * aux = lista;
    if (aux == NULL){
        cout <<"\nERROR: La lista esta vacia!"<<endl;
    } else {
        for (unsigned i=1; aux!=NULL; aux = aux->getSiguiente(), i++){
            cout <<"Registro N°"<<i<<": "<<endl;
            cout <<"    DNI: "<< aux->getDNI()<<"."<<endl;
            cout <<"    Nombre: "<< aux->getNombre()<<".\n"<<endl;
        }
        cout <<"FIN"<<endl;
    }
}


/** @brief cantidadNodos
  *
  * @todo: Retorna la Cantidad de Nodos que contiene This
  */
int Lista::cantidadNodos()
{
    Nodo * aux = this->lista;
    int Res=0;
    while (aux != NULL) {
        Res++;
        aux = aux->getSiguiente();
    }
    return Res;
}


/** @brief buscarNodo
  *
  * @todo: document this function
  */
Nodo * Lista::buscarNodo(int DNI)
{
    Nodo *aux = lista;
    while (aux!=NULL && aux->getDNI()!=DNI) {
        aux = aux->getSiguiente();
    }
    return aux;
}



/** @brief existeNodo
  *
  * @todo: document this function
  */
bool Lista::existeNodo(int DNI)
{
    return (this->buscarNodo(DNI)!=NULL) ? true : false;
    /*
    if (this.buscarNodo(DNI) != NULL)
        return true;
    else
        return false;
    */
}


/** @brief borrarNodo
        Se quitara el Nodo que contenga This cuyo valor almacenado
        sea igual a la variable pasada por parámetro
  *
  * @todo: make it work!
  */
void Lista::borrarNodo(int DNI)
{
    Nodo *actual = lista;
    if (lista != NULL) {
        if (lista->getDNI() == DNI) {
            Nodo * aux = lista->getSiguiente();
            delete lista;
            lista = aux;
        } else {
            Nodo *anterior=lista;
            while (actual!=NULL && actual->getDNI()!=DNI) {
                anterior=actual;
                actual = actual->getSiguiente();
            }
            if (actual != NULL) {
                anterior->setSiguiente(actual->getSiguiente());
                delete actual;
            }
        }
    }
}

/** @brief borrarLista
        Libera toda el espacio en memoria que ocupa This,
        por supuesto, se pierde toda su información y es inicializa el Puntero en NULL,
        al llamar al método este pide una confirmación de la acción;
  *
  * @todo: nothing.
  */
void Lista::borrarLista()
{
    string Res = "";
    cout <<"\nEsta seguro que desa borrar toda la lista? Para confirmar ingrese 1 (UNO) --> ";
    cin >>Res;
    if (Res == "1")
    {
        while (lista!=NULL)
        {
            Nodo * aux = lista;
            lista = lista->getSiguiente();
            delete aux;
        }
    }
}

