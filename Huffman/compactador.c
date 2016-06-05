/**
 *
 * Fichero: compactador.c
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Aqui es donde se realizan las principales funciones
 * 				del compresor.
 */

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

unsigned char buffer_escritura[TAM_BUFF];
unsigned int indice = 0;

int escribir_aux(FILE * fich, struct codigo * codes, unsigned char * buffer, int leido){

	int i;
	for(i=0; i<leido; i++){
		int tam=codes[(unsigned int)buffer[i]].tamanyo;
		unsigned int cod=codes[(unsigned int)buffer[i]].cod;
		int j;
		for(j=tam-1; j>=0; j--){
			caract |= ((cod >> j) << t);
			t--;
			if(t==-1){
				buffer_escritura[indice++]=caract;
				caract=0x00;
				t=7;
				if(indice >= TAM_BUFF){
					fwrite(&buffer_escritura,sizeof(unsigned char),TAM_BUFF,fich);
					indice=0;
				}
			}
		}
	}


	return 0;
}


int escribir(struct codigo * codes, FILE * lectura, FILE * escritura){
	unsigned char buffer[TAM_BUFF];
	// Se va leyendo en bloque del fichero y se llama a la función que escribe
	int leido = 0;
	do{
		leido = fread(buffer, 1, TAM_BUFF, lectura);
		escribir_aux(escritura, codes, buffer, leido);
	}while(leido==TAM_BUFF);

	//Se termina de escribir lo que se haya podido dejar sin escribir
	fwrite(&buffer_escritura,sizeof(unsigned char), indice, escritura);

	fwrite(&caract, 1, 1, escritura);

	return 0;
}

int comprimir(char *nombre_fichero){

	// Se obtienen las frecuencias de aparición
	unsigned int * tabla = obtener_frecuencias(nombre_fichero);
	int i;

	// Iniciamos el heap y lo poblamos.
	struct heap * monticulo = iniciar_heap();
	unsigned int total = tabla[256];
	for(i=0; i<256; i++){
		if(tabla[i]!=0){
			//Aqui se crea el arbol raiz para cada elemento
			struct arbol * arbolz = malloc(sizeof(struct arbol));
			arbolz -> apariciones = tabla[i];
			arbolz -> elemento = i;
			arbolz -> hijo_d = NULL;
			arbolz -> hijo_i = NULL;
			monticulo = insertar_heap(monticulo, arbolz);
		}
	}

	FILE * lectura;
	FILE * escritura;

	// Se abre tanto el fichero a leer como en el que se escribirá
	lectura=fopen(nombre_fichero, "r");
	char buf[256];
	snprintf(buf, sizeof(buf), "%s%s", nombre_fichero, ".huf");
	escritura=fopen(buf, "w");

	// Se escribe el tamanyo del heap y el tamanyo del fichero original
	fwrite(&total, sizeof(unsigned int), 1, escritura);
	fwrite(&monticulo->tamanyo, sizeof(unsigned int), 1, escritura);

	// Se recorre el monticulo y se escribe en el fichero
	for(i=1;i<=(monticulo->tamanyo);i++){
		struct arbol * arbolz = (monticulo->elemento)[i];
		fwrite(&arbolz->elemento,sizeof(char),1, escritura);
		fwrite(&arbolz->apariciones,sizeof(unsigned int),1,escritura);
	}

	// Se llama a la función que crea el arbol
	struct arbol * huff = huffman(monticulo);
	// Con el árbol extraemos los códigos
	struct codigo * codes = obtener_codigos(huff);
	// Por último se escribe en el fichero
	escribir(codes, lectura, escritura);

	return 0;
}
