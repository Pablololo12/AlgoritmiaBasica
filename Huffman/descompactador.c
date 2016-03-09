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
	FILE * escritura;

	lectura=fopen(fichero, "r");
	fichero[strlen(fichero)-4]='\0';
	escritura=fopen(fichero, "w");

	struct heap * monticulo = malloc(sizeof(struct heap));
	monticulo -> tamanyo = 0;
	monticulo -> elemento = malloc(257*sizeof(struct arbol));
	int tamanyo = 0;
	int i;
	char buff = 0x00;
	long apar = 0;
	fread(&tamanyo, sizeof(int), 1, lectura);
	monticulo -> tamanyo = tamanyo;
	for(i=1; i<=tamanyo; i++){
		struct arbol * arbolz = calloc(1, sizeof(struct arbol));
		fread(&arbolz->elemento,sizeof(char),1, lectura);
		fread(&arbolz->apariciones,sizeof(long),1, lectura);
		fread(&arbolz->elemento,sizeof(char),1, lectura);
		fread(&arbolz->apariciones,sizeof(long),1, lectura);
		insertar_heap(monticulo, arbolz);
	}

	struct heap * monticulo = iniciar_heap();

	printf("La información empieza en %ld\n", ftell(lectura));

	struct arbol * huff = huffman2(monticulo);
	struct arbol * arbolAux = huff;

	muestra_arbol(huff, 0);

	char buffer[1];
	int leido=0;
	do{
		leido = fread(buffer,sizeof(char),1,lectura);
		char c1 = (*buffer) & 0x80;
		char c2 = (*buffer) & 0x40;
		char c3 = (*buffer) & 0x20;
		char c4 = (*buffer) & 0x10;
		char c5 = (*buffer) & 0x08;
		char c6 = (*buffer) & 0x04;
		char c7 = (*buffer) & 0x02;
		char c8 = (*buffer) & 0x01;
		if(c1!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("%c\n",(arbolAux -> elemento));
		}

		if(c2!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

		if(c3!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

		if(c4!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
			printf("%c\n",(arbolAux -> elemento));
		}

		if(c5!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

		if(c6!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

		if(c7!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

		if(c8!=0){
			arbolAux = arbolAux -> hijo_d;
			printf("1");
		} else{
			arbolAux = arbolAux -> hijo_i;
			printf("0");
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			printf("\n");
		}

	}while(leido>=1);


	return 0;
}