#include "compactador.h"
#include "frecuencias.h"
#include "heap.h"
#include "tipos.h"
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

	return 0;
}

int comprimir2(char * nombre_fichero){

	long * tabla = obtener_frecuencias(nombre_fichero);
	long * tabla2 = obtener_frecuencias2(nombre_fichero);

	printf("Las tablas son: %d\n", iguales(tabla,tabla2));
	//Bluce para debuggear y comprobar que cuenta bien
	int i;
	/*for(i=0; i<256; i++){
		printf("Letra %c : %ld \n", i, tabla[i]);
	}*/

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
	printf("-----------------------\n\n\n");
	//free(monticulo);

	struct heap * monticulo2 = iniciar_heap();
	for(i=0; i<256; i++){
		if(tabla2[i]!=0){
			struct arbol * arbolz = malloc(sizeof(struct arbol));
			arbolz -> apariciones = tabla2[i];
			arbolz -> elemento = i;
			monticulo2 = insertar_heap(monticulo2, arbolz);
		}
	}

	while((monticulo2 -> tamanyo) > 0){
		struct arbol * arb = borrar_heap(monticulo2);
		printf("El elemento %c aparece %ld\n", arb -> elemento, arb -> apariciones);
	}


	return 0;
}