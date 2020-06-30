/*
 * Bicicleta.c
 *
 *  Created on: 29 jun. 2020
 *      Author: franc
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Bicicleta.h"
#include "parser.h"
#include <time.h>

bicicleta* newBicicleta()
{
    bicicleta* aux;
    aux=(bicicleta*)malloc(sizeof(bicicleta));
    return aux;
}

bicicleta* newParametros(char* id_bike,char* nombre, char* tipo, char* tiempo)
{
	bicicleta* biciAux = NULL;
	biciAux = newBicicleta();
	setbuf(stdout, NULL);

    if(biciAux!= NULL)
    {
        set_id_bike(biciAux,atoi(id_bike));
        set_nombre(biciAux,nombre);
        set_tipo(biciAux,atoi(tipo));
        set_tiempo(biciAux,atoi(tiempo));
    }
    return biciAux;
}

int set_id_bike(bicicleta* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->id_bike = dato;
        set=0;
    }
    return set;
}

int set_nombre(bicicleta* this, char dato[])
{
    int set=-1;
    if(this!=NULL)
    {
    strcpy(this->nombre,dato);
    set=0;
    }
    return set;
}

int set_tipo(bicicleta* this, char dato[])
{
    int set=-1;
    if(this!=NULL)
    {
        strcpy(this->tipo,dato);
        set=0;
    }
    return set;

}

int set_tiempo(bicicleta* this, int dato)
{
    int set=-1;
    if(this!=NULL)
    {
        this->tiempo=dato;
        set=0;
    }
    return set;
}

int get_id_bike(bicicleta* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL){
        *id = this->id_bike;
        retorno = 0;
    }
    return retorno;
}

int get_nombre(bicicleta* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL){
        strncpy(nombre, this->nombre, 50);
        retorno = 0;
    }
    return retorno;
}

int get_tipo(bicicleta* this, char* tipo)
{
    int retorno = -1;
    if(this != NULL && tipo != NULL){
        strncpy(tipo, this->tipo, 50);
        retorno = 0;
    }
    return retorno;
}

int get_tiempo(bicicleta* this, int* tiempo)
{
    int retorno = -1;
	if( this != NULL && tiempo != NULL)
	{
		*tiempo = this->tiempo;
		retorno = 0;
	}
	return retorno;
}



int printOne(bicicleta* this)
{
    int retorno = -1;
	int auxId;
	char auxNombre[50];
	char auxTipo[10];
	int auxTiempo;

	if(this != NULL)
	{
		if(!get_id_bike(this,&auxId)&&
		 !get_nombre(this,auxNombre)&&
		 !get_tipo(this,auxTipo)&&
		 !get_tiempo(this,&auxTiempo))
		{
			printf("%-3.3d   %-40.40s   %-10.10s   %d   \n",auxId,auxNombre,auxTipo,auxTiempo);
			retorno = 0;
		}

	}
	return retorno;
}

int printAllBikes (LinkedList* pBicicletas)
{
	bicicleta* auxBicicleta;
	int i;
	int retorno = -1;
	printf("\n****************************************Bicicletas*******************************************\n\n");
	if(pBicicletas != NULL)
	{
		printf("ID\tNOMBRE\t\t\t\t TIPO\t      TIEMPO\n");
		for(i = 0; i< ll_len(pBicicletas);i++)
		{
			auxBicicleta = (bicicleta*)ll_get(pBicicletas,i);
			if(auxBicicleta != NULL)
			{
				printOne(auxBicicleta);
				retorno = 0;
			}
		}
	}
	return retorno;
}


int getRandom(){

	int aleatorio;

	aleatorio = rand() % 71 + 50;

	return aleatorio;
}

