#include "tipos.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

struct arbol * huffman(long * frecuencia){

	struct heap * heap = iniciar_heap();

	int i;
	for (i = 0; i<256; i++){
		if (frecuencia[i] != 0){
			struct arbol * arbol = malloc(sizeof(struct arbol));
			arbol -> elemento = i;
			arbol -> apariciones = frecuencia[i];
			arbol -> hijo_i = NULL;
			arbol -> hijo_d = NULL;
			heap = insertar_heap(heap, arbol);
		}
	}

	struct arbol * arbolx;
	struct arbol * arboly;
	while ((heap -> tamanyo) > 1){
		arbolx = borrar_heap(heap);
		arboly = borrar_heap(heap);
			
		struct arbol * arbolz = malloc(sizeof(struct arbol));
		arbolz -> apariciones = (arbolx -> apariciones) + (arboly -> apariciones);
		arbolz -> hijo_i = arbolx;
		arbolz -> hijo_d = arboly;
		heap = insertar_heap(heap, arbolz);
	}

	arbolx = borrar_heap(heap);
	free(heap);
	return arbolx;
}