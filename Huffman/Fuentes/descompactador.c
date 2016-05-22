/**
 *
 * Fichero: descompactador.c
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Descompresion de un fichero
 */

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
	// Se elimina la extensión .huf
	fichero[strlen(fichero)-4]='\0';
	escritura=fopen(fichero, "w");

	int tamanyo = 0;
	int i;
	unsigned int total = 0;
	// Se leen el tamanyo de monticulo y el del fichero original
	fread(&total, sizeof(unsigned int), 1, lectura);
	fread(&tamanyo, sizeof(int), 1, lectura);

	struct heap * monticulo = iniciar_heap();
	monticulo -> tamanyo = tamanyo;

	for(i=1; i<=tamanyo; i++){
		struct arbol * arbol = malloc(sizeof(struct arbol));

		char elemento;
		unsigned int frecuencia;
		fread(&elemento,sizeof(char),1, lectura);
		fread(&frecuencia,sizeof(unsigned int),1, lectura);
		arbol -> elemento = elemento;
		arbol -> apariciones = frecuencia;
		arbol -> hijo_i = NULL;
		arbol -> hijo_d = NULL;
		(monticulo->elemento)[i]=arbol;
	}

	struct arbol * huff = huffman(monticulo);
	struct arbol * arbolAux = huff;

	char buffer[TAM_BUFF];
	Bites bites;
	int leido=0;
	do{
		leido = fread(buffer,sizeof(char),TAM_BUFF,lectura);
		for(i=0; i<leido;i++){

			bites.letra = buffer[i];

			if(bites.bits.bit_7!=0){
				arbolAux = arbolAux -> hijo_d;
			} else{
				arbolAux = arbolAux -> hijo_i;
			}
			if((arbolAux -> hijo_d)==NULL){
				if(total > 0)fwrite(&(arbolAux -> elemento), sizeof(char), 1, escritura);
				arbolAux=huff;
				total--;
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
		}

	}while(leido>=1 && total>0);


	return 0;
}
