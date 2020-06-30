#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Bicicleta.h"
#include "parser.h"
#include <time.h>

int getRandom(void);

int main()
{
	srand(time(NULL));
	LinkedList* bicicleta;

	bicicleta = ll_newLinkedList();
	//LinkedList* listaArticulos = ll_newLinkedList();



	int opcion=0;
	    do
	    {
	        printf("\n1- Cargar archivo");
	        printf("\n2- Imprimir lista");
	        printf("\n3- Asignar tiempos");
	        printf("\n4- Filtrar por tipo");
	        printf("\n5- Mostrar posiciones");
	        printf("\n6- Guardar posiciones");
	        printf("\n7- Salir");
	        printf("\nIngrese una opcion: ");
	        scanf("%d",&opcion);

	        switch(opcion)
	        {
	        case 1:
	            controller_loadFromText("bicicletas.csv",bicicleta);
                break;
	        case 2:
	            printAllBikes(bicicleta);
	            break;
            case 3:
                asignarTiempos(bicicleta);
                break;

            case 6:
                if(!controller_saveAsText("bicis.csv", bicicleta))
				printf("\nArchivo guardado!\n");
				else
				printf("\nNo se pudo guardar el archivo\n");
                break;
	        }
	        system("pause");
	        //system("cls");
	    }while(opcion!=7);
	    return 0;

	/*startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort */

    return 0;
}

















