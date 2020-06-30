#include <stdio.h>
#include <stdlib.h>

#include "Controller.h"
#include "Bicicleta.h"
#include "parser.h"

/** \brief Carga los datos de los articulos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param bicicleta LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* bicicleta)
{
	FILE* pFile;
	int retorno = -1;
	int retornoParser = -1;

	if( path != NULL && bicicleta != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile != NULL)
		{

			retornoParser= parserFromText(pFile,bicicleta);
			if(retornoParser == 0)
			{
				printf("\nLectura exitosa\n");
				retorno = 0;
			}
			else
				printf("\n Error en la lectura\n");
			//printf("\nRetorno parser: %d\n",retornoParser);
			fclose(pFile);
		}
		else
		{
			printf("El archivo no pudo ser leido\n");
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los articulos en el archivo mapeado.csv (modo texto).
 *
 * \param path char*
 * \param bicicletas LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* bicicletas)
{
	bicicleta* pAuxBicicleta;
	FILE* pNewFile;
	int retorno = -1;
	int auxId_bike;
	char auxNombre[50];
	char auxTipo[10];
	int auxTiempo;
	int i;

	if(path != NULL && bicicletas != NULL)
	{
		pNewFile = fopen(path,"w+");

		for(i = 0; i<ll_len(bicicletas); i++)
		{
			pAuxBicicleta = (bicicleta*)ll_get(bicicletas,i);

			if(pAuxBicicleta !=  NULL)
			{
			    get_id_bike(pAuxBicicleta, &auxId_bike);
			    get_nombre(pAuxBicicleta, auxNombre);
			    get_tipo(pAuxBicicleta, auxTipo);
			    get_tiempo(pAuxBicicleta, &auxTiempo);
				fprintf(pNewFile,"%d,%s,%s,%f.2,%d\n",auxId_bike,auxNombre,auxTipo,auxTiempo);
				retorno =0;
			}
		}
		fclose(pNewFile);
	}
    return retorno;
}

