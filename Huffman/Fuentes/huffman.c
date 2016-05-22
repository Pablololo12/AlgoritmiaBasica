/**
 *
 * Fichero: huffman.c
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Obtención de códigos
 */

#include "tipos.h"
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>

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

struct arbol * huffman(struct heap * heap){

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
