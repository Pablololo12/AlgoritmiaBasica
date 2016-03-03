#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct heap * iniciar_heap(){
	struct heap * monticulo = malloc(sizeof(struct heap));
	monticulo -> tamanyo = 0;
	monticulo -> elemento = malloc(257*sizeof(struct arbol));
	
	struct arbol * tree = malloc(sizeof(struct arbol));;
	tree -> apariciones = -1;
	(monticulo -> elemento)[0] = tree;
	return monticulo;
}

struct heap * insertar_heap(struct heap * monticulo, struct arbol * tree){

	//Primero incrementamos el tamayo e insertamos el elemento al final
	monticulo -> tamanyo = 1 + monticulo -> tamanyo;
	(monticulo -> elemento)[(monticulo -> tamanyo)] = tree;

	int i = monticulo -> tamanyo;

	while(((monticulo -> elemento)[i/2] -> apariciones) > (tree -> apariciones)){
		(monticulo -> elemento)[i] = (monticulo -> elemento)[i/2];
		i = i/2;
	}

	(monticulo -> elemento)[i] = tree;
	
	return monticulo;
}

struct arbol * borrar_heap(struct heap * monticulo){
	
	struct arbol * min_tree = (monticulo -> elemento)[1];
	struct arbol * ultimo_elemento = (monticulo -> elemento)[(monticulo -> tamanyo)];

	monticulo -> tamanyo = (monticulo -> tamanyo) - 1;
	int tamanyo = monticulo -> tamanyo;

	int actual;
	int hijo;

	for(actual = 1; actual*2 <= tamanyo; actual = hijo){
		hijo = actual*2;
		if(hijo != tamanyo && ((monticulo -> elemento)[hijo+1]->apariciones) < ((monticulo -> elemento)[hijo]->apariciones)){
			hijo = hijo + 1;
		}

		if((ultimo_elemento -> apariciones) > ((monticulo -> elemento)[hijo]->apariciones)){
			(monticulo -> elemento)[actual]=(monticulo -> elemento)[hijo];
		} else{
			break;
		}
	}
	(monticulo -> elemento)[actual] = ultimo_elemento;
	return min_tree;
}