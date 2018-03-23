//
// Created by ASUS on 3/21/2018.
//

#ifndef ULTIMOTRABAJOCLASE_FERRETERIA_H
#define ULTIMOTRABAJOCLASE_FERRETERIA_H


struct Ferreteria {
    int registro;
    char nombre[50];
    int cantidad;
    double costo;
};

void crearArchivo();
void registrarHerramientas();
void consultarHerramientas();
int buscarHerramienta(int);
#endif //ULTIMOTRABAJOCLASE_FERRETERIA_H
