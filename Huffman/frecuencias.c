#include "frecuencias.h"
#include "tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char buffer[8];

/*long * obtener_frecuencias(char * nombre_fichero)
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
}*/

long * obtener_frecuencias(char * nombre_fichero)
{
	//Aqui se declaran la variables a usar
	FILE * fichero;
	//Se usa calloc porque inicializa a 0
	long * tabla = calloc(256, sizeof(long));

	fichero=fopen(nombre_fichero, "r");
	
	//Aunque C es un char lo declaramos cono entero para usarlo como indice.
	while(fgets(buffer, 8, fichero)!=NULL){
		unsigned int uno = buffer[0];
		unsigned int dos = buffer[1];
		int tres = buffer[2];
		int cuatro = buffer[3];
		int cinco = buffer[4];
		int seis = buffer[5];
		int siete = buffer[6];
		int ocho = buffer[7];
		printf("%d %d %d %d %d %d %d %d\n",uno, dos, tres,cuatro,cinco,seis,siete,ocho);
		tabla[uno] = tabla [uno] + 1;
		tabla[dos] = tabla [dos] + 1;
		tabla[tres] = tabla [tres] + 1;
		tabla[cuatro] = tabla [cuatro] + 1;
		tabla[cinco] = tabla [cinco] + 1;
		tabla[seis] = tabla [seis] + 1;
		tabla[siete] = tabla [siete] + 1;
		tabla[ocho] = tabla [ocho] + 1;
	}

	fclose(fichero);
	return tabla;
}