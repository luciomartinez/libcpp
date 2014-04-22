#include <iostream>
#include "stdlib.h"
#include "RESOURCES/Arbol.h"

using namespace std;

/*
void IngresarNumeros(Arbol * Arbolito){
    system("cls");
    cout <<"Ingrese el dato: ";
    int dato;
    cin >>dato;
    //Envia el DNI convertido desde string a entero int
    if (Arbolito->agregar(dato)){
        cout <<"\n\nNumero agregado exitosamente!"<<endl;
        cout <<"Desea registrar otro numero?\ns/n --> ";
        string respuesta;
        cin >>respuesta;
        if (respuesta == "s") IngresarNumeros(Arbolito);
    }
    else
    {
        cout <<"\n\nERROR: no se han registrado el dato ingresado."<<endl;
        cout <<"Ya existia un registro con el numero ingresado.";
        system("pause");
    }
    system("cls");
}
*/


int main()
{
    Arbol Arbol1;


    Arbol1.agregar(2);
    Arbol1.agregar(1);
    Arbol1.agregar(3);

    Arbol1.borrarTodo();

    Arbol1.mostrar();

    return 0;
}
