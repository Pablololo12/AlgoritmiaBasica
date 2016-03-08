#include "compactador.h"
#include "frecuencias.h"
#include "descompactador.h"
#include "heap.h"
#include "tipos.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int descomprimir(char * fichero){
	FILE * lectura;

	lectura=fopen(fichero, "r");

	struct heap * monticulo = iniciar_heap();
	int tamanyo = 0;
	int i;
	fread(&tamanyo, sizeof(int), 1, lectura);
	for(i=0; i<tamanyo; i++){
		struct arbol * arbolz = calloc(1, sizeof(struct arbol));
		fread(&arbolz->elemento,sizeof(char),1, lectura);
		fread(&arbolz->apariciones,sizeof(long),1, lectura);
		insertar_heap(monticulo, arbolz);
	}

	while((monticulo -> tamanyo) > 0){
		struct arbol * arbolz = borrar_heap(monticulo);
		printf("El elemento %c aparece %ld veces.\n", arbolz -> elemento, arbolz -> apariciones);
	}
	return 0;
}