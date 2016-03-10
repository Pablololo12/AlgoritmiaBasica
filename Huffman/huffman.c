#include "tipos.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>


void muestra_arbol (struct arbol * arbol, int profundidad){
	if (arbol -> hijo_d == NULL){
		int i;
		for (i = 0; i < profundidad; i++){
			printf("   ");
		}
		printf("%c, %u\n", arbol -> elemento, arbol -> apariciones);
	} else {
		muestra_arbol(arbol -> hijo_d, profundidad + 1);

		int i;
		for (i = 0; i < profundidad; i++){
			printf("   ");
		}
		printf("%u\n", arbol -> apariciones);

		muestra_arbol(arbol -> hijo_i, profundidad + 1);
	}
}

int obtener_codigos_aux(struct arbol * tree, struct codigo * codes, unsigned int cod, unsigned int tam){
	if(tree -> hijo_i == NULL && tree -> hijo_d == NULL){
		unsigned char caracter = tree -> elemento;
		codes[(unsigned int)caracter].tamanyo=tam;
		codes[(unsigned int)caracter].cod=cod;
		return 0;
	} else{
		obtener_codigos_aux(tree -> hijo_i, codes, cod<<1, ++tam);
		obtener_codigos_aux(tree -> hijo_d, codes, (cod<<1)|1, tam);
		return 0;
	}
}

struct codigo * obtener_codigos(struct arbol * tree){
	struct codigo * codes = calloc(256,sizeof(struct codigo));
	obtener_codigos_aux(tree -> hijo_i, codes, 0, 1);
	obtener_codigos_aux(tree -> hijo_d, codes, 1, 1);
	return codes;
}

int recorrer_arbol_aux(struct arbol * tree){
	if(tree -> hijo_i == NULL && tree -> hijo_d == NULL){
		printf("Nodo hoja: %c valor: %d\n", tree->elemento, tree->apariciones);
		return 0;
	} else{
		printf("Nodo valor: %d\n", tree->apariciones);
		recorrer_arbol_aux(tree->hijo_i);
		recorrer_arbol_aux(tree->hijo_d);
		return 0;
	}
}

int recorrer_arbol(struct arbol * tree){
	printf("Mostrando arbol\n");
	printf("Soy la raiz con tamanyo: %d\n", tree -> apariciones);
	recorrer_arbol_aux(tree->hijo_i);
	recorrer_arbol_aux(tree->hijo_d);
	return 0;
}

struct arbol * huffman2(struct heap * heap){

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
	//recorrer_arbol(arbolx);
	return arbolx;
}

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
	//recorrer_arbol(arbolx);
	return arbolx;
}