#include <stdio.h>
#include <string.h>
#include "frecuencias.h"
#include "compactador.h"
#include "tipos.h"

int main(int argc, char **argv)
{
	if(strcmp(argv[1], "-c")==0){
		comprimir(argv[2]);
	}
	else if(strcmp(argv[1], "-d")==0){
		//descomprimir(argv[2]);
	}
	else{
		printf("Error de entrada\n");
	}
	return 0;
}