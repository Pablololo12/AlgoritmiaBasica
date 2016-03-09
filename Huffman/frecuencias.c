#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long * obtener_frecuencias(char * nombre_fichero)
{
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	long * tabla = calloc(257, sizeof(long));
	unsigned char * buffer = calloc(TAM_BUFF, 1);

	fichero=fopen(nombre_fichero, "r");

	int leido = 0;
	long total = 0;
	do{
		leido = fread(buffer, 1, TAM_BUFF, fichero);
		total += leido;
		int i;
		for(i=0; i<leido; i++){
			tabla[(unsigned int)buffer[i]] = tabla[(unsigned int)buffer[i]] + 1;
		}
	}while(leido==TAM_BUFF);
	printf("Con el ? el indice devuelve: %lx\n",tabla[0xd8]);
	tabla[256]=total;
	free(buffer);
	fclose(fichero);
	return tabla;
}