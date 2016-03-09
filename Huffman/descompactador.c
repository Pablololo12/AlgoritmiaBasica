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

	int tamanyo = 0;
	int i;
	long total = 0;

	fread(&total, sizeof(long), 1, lectura);
	fread(&tamanyo, sizeof(int), 1, lectura);

	struct heap * monticulo = iniciar_heap();
	monticulo -> tamanyo = tamanyo;
	printf("Aqui\n");

	for(i=1; i<=tamanyo; i++){
		struct arbol * arbol = malloc(sizeof(struct arbol));

		char elemento;
		long frecuencia;
		fread(&elemento,sizeof(char),1, lectura);
		fread(&frecuencia,sizeof(long),1, lectura);
		arbol -> elemento = elemento;
		arbol -> apariciones = frecuencia;
		arbol -> hijo_i = NULL;
		arbol -> hijo_d = NULL;
		(monticulo->elemento)[i]=arbol;
	}
	/*long * frecuencias = calloc(256, sizeof(long));
	for(i=0; i<tamanyo; i++){
		char elemento;
		long frecuencia;
		fread(&elemento,sizeof(char),1, lectura);
		fread(&frecuencia,sizeof(long),1, lectura);
		frecuencias[(int)elemento] = frecuencia;
	}*/


	printf("La información empieza en %ld\n", ftell(lectura));

	struct arbol * huff = huffman2(monticulo);
	printf("Aqui\n");
	struct arbol * arbolAux = huff;

	muestra_arbol(huff, 0);
	char buffer[1];
	Bites bites;
	int leido=0;
	do{
		leido = fread(&bites.letra,sizeof(char),1,lectura);
		/*char c1 = (*buffer) & 0x80;
		char c2 = (*buffer) & 0x40;
		char c3 = (*buffer) & 0x20;
		char c4 = (*buffer) & 0x10;
		char c5 = (*buffer) & 0x08;
		char c6 = (*buffer) & 0x04;
		char c7 = (*buffer) & 0x02;
		char c8 = (*buffer) & 0x01;*/
		if(bites.bits.bit_7!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			if(total > 0)total--;
			printf("%c\n",(arbolAux -> elemento));
		}

		if(bites.bits.bit_6!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

		if(bites.bits.bit_5!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

		if(bites.bits.bit_4!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
			printf("%c\n",(arbolAux -> elemento));
		}

		if(bites.bits.bit_3!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

		if(bites.bits.bit_2!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

		if(bites.bits.bit_1!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

		if(bites.bits.bit_0!=0){
			arbolAux = arbolAux -> hijo_d;
		} else{
			arbolAux = arbolAux -> hijo_i;
		}
		if((arbolAux -> hijo_d)==NULL){
			if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
			arbolAux=huff;
			total--;
		}

	}while(leido>=1 && total>0);


	return 0;
}