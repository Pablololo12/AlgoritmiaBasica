/**
 *
 * Fichero: frecuencias.c
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Se obtienen las frecuencias de un fichero dado
 */

#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int * obtener_frecuencias(char * nombre_fichero)
{
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	unsigned int * tabla = calloc(257, sizeof(unsigned int));
	unsigned char * buffer = calloc(TAM_BUFF, 1);

	fichero=fopen(nombre_fichero, "r");

	int leido = 0;
	unsigned int total = 0;
	// Se recorre el fichero y se extraen las frecuencias
	do{
		leido = fread(buffer, 1, TAM_BUFF, fichero);
		total += leido;
		int i;
		for(i=0; i<leido; i++){
			tabla[(unsigned int)buffer[i]] = tabla[(unsigned int)buffer[i]] + 1;
		}
	}while(leido==TAM_BUFF);

	tabla[256]=total;
	free(buffer);
	fclose(fichero);
	return tabla;
}
