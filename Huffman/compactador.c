#include "compactador.h"
#include "frecuencias.h"
#include "heap.h"
#include "tipos.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int iguales(long * tabla, long * tabla2){
	int i;
	for(i=0;i<256;i++){
		if(tabla[i]!=tabla2[i]){
			i=500;
		}
	}
	if(i==500){
		return -1;
	} else{
		return 1;
	}
}

int comprimir(char *nombre_fichero){
	long * tabla = obtener_frecuencias(nombre_fichero);
	int i;
	printf("Aqui\n");
	struct heap * monticulo = iniciar_heap();
	for(i=0; i<256; i++){
		if(tabla[i]!=0){
			struct arbol * arbolz = malloc(sizeof(struct arbol));
			arbolz -> apariciones = tabla[i];
			arbolz -> elemento = i;
			monticulo = insertar_heap(monticulo, arbolz);
		}
	}

	while((monticulo -> tamanyo) > 0){
		struct arbol * arb = borrar_heap(monticulo);
		printf("El elemento %c aparece %ld\n", arb -> elemento, arb -> apariciones);
	}

	struct arbol * huff = huffman(tabla);

	return 0;
}