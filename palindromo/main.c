#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "comparador.h"

int main(int argc, char **argv)
{
	if(argc==2){
		//comprimir(argv[2]);
	} else if(argc==3){
		int n = strlen(argv[1]);
		int m = strlen(argv[2]);
		int i;
		
		int ** C = malloc(sizeof(int*)*n);
		for(i=0; i<n; i++) C[i] = calloc(m,sizeof(int));
		int ** T = malloc(sizeof(int*)*n);
		for(i=0; i<n; i++) T[i] = calloc(m,sizeof(int));

		comparar(argv[1], argv[2], C, T, n, m);
	}
	else{
		printf("Error en los parametros.\n"
		"Se debe introducir una cadena de texto\n");
	}
	return 0;
}
