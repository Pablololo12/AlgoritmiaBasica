#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_BUFF 128
char buffer[TAM_BUFF];

long * obtener_frecuencias2(char * nombre_fichero)
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

long * obtener_frecuencias(char * nombre_fichero)
{
	//Aqui se declaran la variables a usar
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	long * tabla = calloc(256, sizeof(long));

	fichero=fopen(nombre_fichero, "r");

	int leido = 0;
	
	do{
		leido = fread(buffer, 1, TAM_BUFF, fichero);
		int i;
		for(i=0; i<leido; i++){
			//printf("%c\n", buffer[i]);
			/*if(buffer[i] != EOF){
				tabla[buffer[i]] = tabla[buffer[i]] + 1;
			} else{
				i=TAM_BUFF;
			}*/
			tabla[buffer[i]] = tabla[buffer[i]] + 1;
		}
	}while(leido==TAM_BUFF);

	fclose(fichero);
	return tabla;
}