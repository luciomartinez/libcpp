#include "Arbol.h"

/** @brief Arbol
  *
  * @todo: document this function
  */
 Arbol::Arbol()
{
    Raiz = NULL;
}

/** @brief agregar
  *
  * @todo: document this function
  */
bool Arbol::agregar(int Dato)
{
    if (existe(Dato)) return false;
    if (Raiz == NULL)
    {
        Raiz = new Nodo(Dato);
    }
    else
    {
        Raiz->agregarOrd(Dato);
    }
    return true;
}



/** @brief existe
  *
  * @todo: document this function
  */
bool Arbol::existe(int Dato)
{
    return Raiz->existeNodo(Dato);
}




/** @brief mostrar
  *
  * @todo: document this function
  */
void Arbol::mostrar()
{
    cout <<"\n";
    if (Raiz != NULL) {
        Raiz->inorder();
        cout <<"\n";
    } else {
        cout <<"No se han encontrado registros para mostrar."<<endl;
    }
    cout <<"\n";
}

/** @brief borrarDato
  *
  * @todo: document this function
  */
void Arbol::borrarDato(int Dato)
{
    if (existe(Dato))
    {
        Raiz = Raiz->borrarNodo(Dato);
    }
    else
    {
        cout <<"\nNo se ha encontrado el numero ingresado en la lista."<<endl;
    }
}


/** @brief borrarTodo
  *
  * @todo: document this function
  */
bool Arbol::borrarTodo()
{
    bool resultado = false;
    string Res = "";
    cout <<"\nEsta seguro que desa borrar toda la informacion?"<<endl;
    cout <<"Para confirmar ingrese 1 (UNO) --> ";
    cin >>Res;
    if (Res == "1")
    {
        Raiz = Raiz->borrarTodo();
        if (Raiz==NULL) resultado = true;
    }
    else
    {
        cout <<"\n\nNo se ha modificado la informacion del sistema.";
        resultado = true;
    }
    return resultado;
}

