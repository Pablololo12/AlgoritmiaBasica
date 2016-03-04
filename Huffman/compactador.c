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

int escribir_aux(FILE * fich){

}

int escribir(struct codigo * codes, char *nombre_fichero){
	FILE * lectura;
	FILE * escritura;

	lectura=fopen(nombre_fichero, "r");
	escritura=fopen(nombre_fichero, "w");

	char * buffer = malloc(TAM_BUFF);

	int leido = 0;
	do{
		leido = fread(buffer, 1, TAM_BUFF, lectura);
		int i;
		for(i=0; i<leido; i++){
			//tabla[(int)buffer[i]] = tabla[(int)buffer[i]] + 1;
		}
	}while(leido==TAM_BUFF);
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

	struct arbol * huff = huffman(tabla);
	struct codigo * codes = obtener_codigos(huff);

	for(i=0; i<256; i++){
		if(codes[i].tamanyo!=0){
			printf("El caracter %c tiene el código %ld de tamanyo %d\n", i, codes[i].cod, codes[i].tamanyo);
		}
	}

	return 0;
}