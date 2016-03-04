#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFF 256
char buffer[TAM_BUFF];

long * obtener_frecuencias(char * nombre_fichero)
{
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	long * tabla = calloc(256, sizeof(long));

	fichero=fopen(nombre_fichero, "r");

	int leido = 0;
	
	do{
		leido = fread(buffer, 1, TAM_BUFF, fichero);
		int i;
		for(i=0; i<leido; i++){
			tabla[(int)buffer[i]] = tabla[(int)buffer[i]] + 1;
		}
	}while(leido==TAM_BUFF);

	fclose(fichero);
	return tabla;
}