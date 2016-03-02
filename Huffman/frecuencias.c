#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long * obtener_frecuencias(char * nombre_fichero)
{
	//Aqui se declaran la variables a usar
	FILE * fichero;
	long * tabla = calloc(256, sizeof(long));
	int C;

	fichero=fopen(nombre_fichero, "r");
	
	//Aunque C es un char lo declaramos cono entero para usarlo como indice.
	while(feof(fichero)==0){
		C=fgetc(fichero);
		tabla[C]=tabla[C] + 1;
	}

	fclose(fichero);
	return tabla;
}