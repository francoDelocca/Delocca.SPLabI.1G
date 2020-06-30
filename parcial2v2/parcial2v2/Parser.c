#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Bicicleta.h"

int parserFromText(FILE* pFile , LinkedList* bicicleta)
{
    bicicleta* pBicicleta;
	char id[10];
	char nombre[50];
	char tipo[10];
	char tiempo[7];

	int flag = 0;
	int retorno = -1;

	do
	{	//flag == 0 porque tiene titulo
		if(flag == 0)
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo);
			flag = 1;
		}
		if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,tipo,tiempo)==4)
		{
			//printf("%s-%s-%s-%s-%s\n",id,articulo,medida,precio,rubro);
			if (flag != 0)
				pBicicleta = newParametros(id,nombre,tipo,tiempo);

			if(pBicicleta != NULL && flag != 0)
			{
				ll_add(bicicleta,pBicicleta);
				retorno = 0;
			}
		}
		else
			break;
	}while(feof(pFile)==0);
    return retorno;
}

