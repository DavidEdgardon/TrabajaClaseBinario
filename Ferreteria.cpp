//
// Created by ASUS on 3/21/2018.
//

#include "Ferreteria.h"
#include <fstream>
#include <iostream>
#include <cstring>

using namespace std;

void crearArchivo(){
    ofstream archivoOut("ferreteria.dat", ios::out | ios::app | ios::binary);
    if(!archivoOut) {
        cout << "Error al intentar abrir el archivo ferreteria.dat";
        return;
    }
    archivoOut.seekp(0, ios::end); //ubicarse al final del archivo
    for(int i=0;i<=100;i++){

        Ferreteria blanco;
        blanco.registro=-1;
        strcpy(blanco.nombre, " ");
        blanco.cantidad=-1;
        blanco.costo=0;

     archivoOut.write(reinterpret_cast<const char *>(&blanco), sizeof(Ferreteria));
    }
    archivoOut.close();
}

void registrarHerramientas(){
    ofstream archivoOut("ferreteria.dat", ios::out | ios::app | ios::binary);
    if(!archivoOut){
        cout<<"Error al intentar abrir el archivo ferreteria.dat";
        return;
    }
    archivoOut.seekp(0, ios::beg); //ubicarse al final del archivo
    cout<<" \n\n *** R E G I S T R O  D E  H E R R A M I E N T A S *** \n\n";
    int opc=0;
    do{
        Ferreteria nuevo;

            cout << "Ingrese el numero de registro: ";
            cin >> nuevo.registro;
            cout << "Ingrese el nombre de la herramienta: ";
            cin >> nuevo.nombre;
            cout << "Ingrese la cantidad en inventario: ";
            cin >> nuevo.cantidad;
            cout << "Ingrese el costo (-1 si no tiene): ";
            cin >> nuevo.costo;

            archivoOut.write(reinterpret_cast<const char *>(&nuevo), sizeof(Ferreteria));

            cout << "Registro Guardado!\n\n";

        cout<<"Desea agregar nuevo registro? (-1 para salir):";
        cin>>opc;
    }while(opc!=-1);

    archivoOut.close();
}

void consultarHerramientas(){
    ifstream archivoIn("ferreteria.dat",ios::in | ios::binary);
    if(!archivoIn){
        cout<<"Error al intentar abrir el archivo ferreteria.dat";
        return;
    }
    archivoIn.seekg(0, ios::beg); //ubicarse al final del archivo
    cout<<" \n\n *** C O N S U L T A  D E  H E R R A M I E N T A S *** \n\n";
    Ferreteria actual;
    //LEEMOS EL PRIMER REGISTRO
    archivoIn.read(reinterpret_cast<char *>(&actual), sizeof(Ferreteria));

    while(!archivoIn.eof()) { //eof regresa la pos final del archivo
            cout << "Registro: " << actual.registro << "\nNombre: " << actual.nombre << "\nCantidad: " << actual.cantidad
                 << "\nCosto: " << actual.costo<<endl;
        cout<<"-------------------------"<<endl;
     }
    archivoIn.close();
}

int buscarHerramienta(int regis){
    ifstream archivoFerreteria("ferreteria.dat", ios::in | ios::binary);
    if(!archivoFerreteria){
        cout<<"Error en abrir el archivo empleado.dat"<<endl;
        return -1;
    }
    int posicion=0;
    Ferreteria buscar;
    archivoFerreteria.seekg(0, ios::end);
    archivoFerreteria.read(reinterpret_cast<char *>(&buscar), sizeof(Ferreteria));
    while(!archivoFerreteria.eof()){
        if(buscar.registro== regis){
            archivoFerreteria.close();
            return posicion;
        }
        posicion++;
        archivoFerreteria.read(reinterpret_cast< char *>(&buscar), sizeof(Ferreteria));
        archivoFerreteria.close();
        return -1;
    }
}

