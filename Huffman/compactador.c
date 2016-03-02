#include "compactador.h"
#include "frecuencias.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprimir(char * nombre_fichero){

	long * tabla = obtener_frecuencias(nombre_fichero);
	//Bluce para debuggear y comprobar que cuenta bien
	int i;
	for(i=0; i<256; i++){
		printf("Letra %c : %ld \n", i, tabla[i]);
	}
	//Con free se libera el espacio
	free(tabla);

	return 0;
}