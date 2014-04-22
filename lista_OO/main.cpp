#include <iostream>
#include <string>
#include "stdlib.h"
#include "Lista.h"

using namespace std;



void IngresarRegistros(Lista * dada){
    system("cls");
    cout <<"Ingrese el DNI de la persona: ";
    string DNI = "";
    cin >>DNI;
    cout <<"\nIngrese el nombre de la persona: ";
    string Nombre = "";
    cin >>Nombre;
    //Envia el DNI convertido desde string a entero int
    switch (dada->agregar(atoi(DNI.c_str()),Nombre)){
        case -1:
            cout <<"\n\nERROR: no se han registrado los datos ingresados."<<endl;
            cout <<"Compruebe que sean validos."<<endl;
            system("pause");
            break;
        case 0:
            cout <<"\n\nERROR: no se han registrado los datos ingresados."<<endl;
            cout <<"Ya existia un registro con el DNI ingresado.";
            system("pause");
            break;
        case 1:
            cout <<"\n\nRegistro agregado exitosamente!"<<endl;
            cout <<"Desea registrar otra persona?\ns/n --> ";
            string respuesta;
            cin >>respuesta;
            if (respuesta == "s") IngresarRegistros(dada);
            break;
    }
    system("cls");
}

void QuitarRegistro(Lista * dada){
    system("cls");
    cout <<"Ingrese el DNI de la persona que desea sacar del sistema: ";
    string DNI = "";
    cin >>DNI;
    int aux = atoi(DNI.c_str());
    if (dada->existeNodo(aux)){
        cout <<"\n\nEsta seguro que desea quitar a '"<<dada->obtenerNombre(aux)<<"' del sistema?"<<endl;
        cout <<"Ingrese 1 (UNO) para confirmar --> ";
        string Respuesta;
        cin >>Respuesta;
        if (Respuesta == "1"){
            dada->borrarNodo(aux);
            cout <<"\n\nRegistro eliminado exitosamente."<<endl;
        } else {
            cout <<"\n\nNo se ha modificado ningun registro."<<endl;
        }
    } else {
        cout <<"No se ha encontrado un registro que coincida con el ";
        cout <<"DNI ingresado."<<endl;
    }
    system("pause");
    system("cls");
}

int main()
{
    Lista dada;

    IngresarRegistros(&dada);
    dada.borrarLista();

    dada.mostrar();

    return 0;
}
