#include "compactador.h"
#include "frecuencias.h"
#include "heap.h"
#include "tipos.h"
#include "huffman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t=7;
unsigned char caract=0x00;

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

int escribir_aux(FILE * fich, struct codigo * codes, unsigned char * buffer, int leido){

	int i;
	for(i=0; i<leido; i++){
		int tam=codes[(unsigned int)buffer[i]].tamanyo;
		long cod=codes[(unsigned int)buffer[i]].cod;
		printf("Codigo: %ld tamanyo: %d indice: %c\n", cod, tam, buffer[i]);
		int j;
		for(j=tam-1; j>=0; j--){
			caract |= ((cod >> j) << t);
			t--;
			if(t==-1){
				fwrite(&caract, 1, 1, fich);
				//printf(" Escribe %x\n", caract);
				caract=0x00;
				t=7;
			}
		}
	}

	return 0;
}


int escribir(struct codigo * codes, char *nombre_fichero, struct heap * monticulo, long total){
	FILE * lectura;
	FILE * escritura;

	lectura=fopen(nombre_fichero, "r");
	char buf[256];
	snprintf(buf, sizeof(buf), "%s%s", nombre_fichero, ".huf");
	escritura=fopen(buf, "w");
	fwrite(&total, sizeof(long), 1, escritura);
	fwrite(&monticulo->tamanyo, sizeof(int), 1, escritura);
	/*while((monticulo -> tamanyo)>0){
		struct arbol * arbolz = borrar_heap(monticulo);
		fwrite(&arbolz->elemento,sizeof(char),1, escritura);
		fwrite(&arbolz->apariciones,sizeof(long),1,escritura);
		//printf("El elemento %c aparece %ld veces.\n", arbolz -> elemento, arbolz -> apariciones);

	}*/
	int i;
	for(i=1;i<=(monticulo->tamanyo);i++){
		struct arbol * arbolz = (monticulo->elemento)[i];
		fwrite(&arbolz->elemento,sizeof(char),1, escritura);
		fwrite(&arbolz->apariciones,sizeof(long),1,escritura);
	}
	printf("La información empieza en %ld\n", ftell(escritura));
	unsigned char * buffer = calloc(TAM_BUFF,1);

	int leido = 0;
	do{
		leido = fread(buffer, 1, TAM_BUFF, lectura);
		escribir_aux(escritura, codes, buffer, leido);
	}while(leido==TAM_BUFF);
	fwrite(&caract, 1, 1, escritura);

	return 0;
}

int comprimir(char *nombre_fichero){
	long * tabla = obtener_frecuencias(nombre_fichero);
	int i;
	struct heap * monticulo = iniciar_heap();
	long total = tabla[256];
	for(i=0; i<256; i++){
		if(tabla[i]!=0){
			struct arbol * arbolz = malloc(sizeof(struct arbol));
			arbolz -> apariciones = tabla[i];
			arbolz -> elemento = i;
			monticulo = insertar_heap(monticulo, arbolz);
		}
	}

	struct arbol * huff = huffman(tabla);
	muestra_arbol(huff, 0);
	struct codigo * codes = obtener_codigos(huff);

	escribir(codes, nombre_fichero, monticulo, total);

	/*for(i=0; i<256; i++){
		if(codes[i].tamanyo!=0){
			printf("El caracter %c tiene el código %ld de tamanyo %d\n", i, codes[i].cod, codes[i].tamanyo);
		}
	}*/

	return 0;
}