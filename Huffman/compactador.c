#include "compactador.h"
#include "frecuencias.h"
#include "heap.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprimir(char * nombre_fichero){

	long * tabla = obtener_frecuencias(nombre_fichero);
	//Bluce para debuggear y comprobar que cuenta bien
	int i;
	printf("Aqui\n");
	/*for(i=0; i<256; i++){
		printf("Letra %c : %ld \n", i, tabla[i]);
	}*/

	struct heap * monticulo = iniciar_heap();
	for(i=0; i<256; i++){
		if(tabla[i]!=0){
				printf("Aqui4\n");
			struct arbol * arbolz = malloc(sizeof(struct arbol));
			arbolz -> apariciones = tabla[i];
			arbolz -> elemento = i;
			monticulo = insertar_heap(monticulo, arbolz);
		}
	}
	printf("Aqui2\n");
	//Con free se libera el espacio
	//free(tabla);

	for(i=0; i<(monticulo -> tamanyo); i++){
		printf("Elemento %c aparece %ld \n", (monticulo -> elemento)[i]->elemento,(monticulo -> elemento)[i]->apariciones);
	}
	printf("Aqui3\n");

	while((monticulo -> tamanyo) > 0){
		/*struct arbol * arb = (monticulo -> elemento)[1];
		monticulo = borrar_heap(monticulo);*/
		struct arbol * arb = borrar_heap(monticulo);
		printf("El elemento %c aparece %ld\n", arb -> elemento, arb -> apariciones);
	}

	return 0;
}