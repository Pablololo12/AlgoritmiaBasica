#include "compactador.h"
#include "frecuencias.h"
#include "heap.h"
#include "tipos.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t=0;
char caract=0x00;

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

int escribir_aux(FILE * fich, struct codigo * codes, char * buffer, int leido){

	int i;
	for(i=0; i<leido; i++){
		struct codigo code = codes[(int)buffer[i]];
		int tam=code.tamanyo;
		long cod=code.cod;
		if((8-t)<tam){
			int offset = tam-t-1;
			caract=caract<<offset;
			char escrit = cod>>(tam-offset);
			caract = caract | escrit;
			fwrite(&caract, 1, 1, fich);
			cod = cod << (8-(tam-offset));
			caract = cod >> (8-(tam-offset));
			t=tam-offset;
		} else{
			caract=caract<<tam;
			caract = caract | cod;
			t = t + tam;
		}
	}

	return 0;
}

int escribir(struct codigo * codes, char *nombre_fichero, struct heap * monticulo){
	FILE * lectura;
	FILE * escritura;

	lectura=fopen(nombre_fichero, "r");
	char buf[256];
	snprintf(buf, sizeof(buf), "%s%s", nombre_fichero, ".huf");
	escritura=fopen(buf, "w");

	fwrite(&monticulo->tamanyo, sizeof(int), 1, escritura);
	while((monticulo -> tamanyo)>0){
		struct arbol * arbolz = borrar_heap(monticulo);
		fwrite(&arbolz->elemento,sizeof(char),1, escritura);
		fwrite(&arbolz->apariciones,sizeof(long),1,escritura);
		//printf("El elemento %c aparece %ld veces.\n", arbolz -> elemento, arbolz -> apariciones);

	}
	char * buffer = calloc(TAM_BUFF,1);

	int leido = 0;
	do{
		leido = fread(buffer, TAM_BUFF, 1, lectura);
		escribir_aux(escritura, codes, buffer, leido);
	}while(leido==TAM_BUFF);

	return 0;
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

	escribir(codes, nombre_fichero, monticulo);

	/*for(i=0; i<256; i++){
		if(codes[i].tamanyo!=0){
			printf("El caracter %c tiene el código %ld de tamanyo %d\n", i, codes[i].cod, codes[i].tamanyo);
		}
	}*/

	return 0;
}