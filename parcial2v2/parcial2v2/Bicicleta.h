/*
 * Bicicleta.h
 *
 *  Created on: 29 jun. 2020
 *      Author: franc
 */

#ifndef BICICLETA_H_
#define BICICLETA_H_

#include "LinkedList.h"

typedef struct
{
    int id_bike;
    char nombre[50];
    char tipo[50];
    int tiempo;

}bicicleta;

bicicleta* newBicicleta();
bicicleta* newParametros(char* id_bike,char* nombre, char* tipo, char* tiempo);

int set_id_bike(bicicleta* this, int dato);
int get_id_bike(bicicleta* this, int* id);

int set_nombre(bicicleta* this, char dato[]);
int get_nombre(bicicleta* this, char* nombre);

int set_tipo(bicicleta* this, char dato[]);
int get_tipo(bicicleta* this, char* tipo);

int set_tiempo(bicicleta* this, int dato);
int get_tiempo(bicicleta* this, int* tiempo);

int printOne(bicicleta* this);
int printAllBikes(LinkedList* bicicleta);

/*void asignarTiempos(bicicleta* pBicicletas);
void meterTiempos(bicicleta* this);*/

#endif /* BICICLETA_H_ */

