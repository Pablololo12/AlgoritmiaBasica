#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFF 16
char buffer[TAM_BUFF];

long * obtener_frecuencias(char * nombre_fichero)
{
	//Aqui se declaran la variables a usar
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
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

long * obtener_frecuencias2(char * nombre_fichero)
{
	//Aqui se declaran la variables a usar
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	long * tabla = calloc(256, sizeof(long));

	fichero=fopen(nombre_fichero, "r");
	
	//Aunque C es un char lo declaramos cono entero para usarlo como indice.
	while(fgets(buffer, TAM_BUFF, fichero)!=NULL){
		int i;
		for(i=0; i<TAM_BUFF; i++){
			//printf("%c\n", buffer[i]);
			if(buffer[i]!=0){
				tabla[buffer[i]] = tabla[buffer[i]] + 1;
			} else{
				i=8;
			}
		}
	}

	fclose(fichero);
	return tabla;
}