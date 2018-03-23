#include <iostream>
#include <conio.h>
#include "Ferreteria.h"
using namespace std;

int main() {
    int opc;
    do{
        cout<< " *** F E R R E T E R I A *** "<<endl;
    cout<<"1. Crear Archivo"<<endl;
    cout<<"2. Registrar Herramienta"<<endl;
    cout<<"3. Consultar Archivo"<<endl;
    cout<<"4. Buscar Herramienta"<<endl;
    cout<<"Ingrese la opcion:";
    cin>>opc;
    switch(opc) {
        case 1:
            crearArchivo();
            break;
        case 2:
            registrarHerramientas();
            break;
        case 3:
            consultarHerramientas();
            break;
        case 4:
            int cod;
            cout<<"Codigo de registro:";
            cin>>cod;
            buscarHerramienta(cod);
            break;
    }
        }while(opc!=-1);
}