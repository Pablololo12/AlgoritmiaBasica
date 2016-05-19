#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char* insertar (char *string, int pos, char c){
    int len = strlen(string);
	char *aux = (char *) malloc(sizeof(char) * (len + 1));
    int i = 0;
    for (; i < pos; i++) aux[i] = string[i];
    aux[i] = c;
    for (; i < len; i++) aux[i + 1] = string[i];
    return aux;
}

int main(int argc, char **argv)
{
    int s = strlen(argv[1]);
	char *string = (char *) malloc(sizeof(char) * s);
	strcpy(string, argv[1]);
	
	unsigned int C[s][s];// = (unsigned int [][]) malloc(s * s * sizeof(unsigned int));
	unsigned char camino[s][s];
	
	int i = s - 1;
	for (; i >= 0; i--){
	    C[i][i] = 0;
	    int j = i + 1;
	    for (; j < s ; j++){
	        unsigned int min = C[i+1][j-1];
	        camino[i][j] = 0;
            //C(i,j) = min (C(i+1, j-1), 1 + C(i+1, j), 1 + C(i, j-1))
	        if (string[i] != string[j]){ //los caracteres de los extremos se intercambian
	            min++;
	            camino[i][j] = 1;
	            //printf("El caracter %d (%c) se cambia por %c\n", j, string[j], string[i]);
	        }
	        if (min > 1 + C[i+1][j]){ //se añade una caracter igual al extremo izquierdo en la derecha
	            min = 1 + C[i+1][j];
	            camino[i][j] = 2;
	            //printf("Se añade el caracter %c despues del caracter %d (%c)\n", string[i], j, string[j]);
	        }  else if (min > 1 + C[i][j-1]){//se añade una caracter igual al extremo derecho en la izquierda
	            min = 1 + C[i][j-1];
	            camino[i][j] = 3;
	            //printf("Se añade el caracter %c antes del caracter %d (%c)\n", string[j], i, string[i]);
	        }
	        C[i][j] = min;
	       /** printf("\ncoste %d en c[%d][%d] con camino %d\n", C[i][j], i, j, camino[i][j]);
	        printf("coste camino 0: %d\n", C[i+1][j+1]);
	        printf("coste camino 1: %d\n", C[i+1][j+1] + 1);
	        printf("coste camino 2: %d\n", C[i+1][j] + 1);
	        printf("coste camino 0: %d\n", C[i][j-1] + 1);*/
	        //printf("\n\n");
	    }
	}
	
	int j;
	
	
	printf("Matriz de coste: \n");
	printf("     ");
	for (j = 0; j < s; j++){
	    printf(" %4d", j);
	}
	printf("\n");
	printf("     ");
	for (j = 0; j < s; j++){
	    printf(" ----");
	}
	printf("\n");
	for (i = 0; i < s; i++){
	    printf(" %3d|", i);
	    for (j = 0; j < s; j++){
	        if (j > i){
	            printf(" %4d", C[i][j]);
	        } else {
	            printf(" %4d", 0);
	        }
	    }
	    printf("\n");
	}
	
	printf("\nMatriz de caminos: \n");
	printf("     ");
	for (j = 0; j < s; j++){
	    printf(" %4d", j);
	}
	printf("\n");
	printf("     ");
	for (j = 0; j < s; j++){
	    printf(" ----");
	}
	printf("\n");
	for (i = 0; i < s; i++){
	    printf(" %3d|", i);
	    for (j = 0; j < s; j++){
	        if (j > i){
	            printf(" %4d", camino[i][j]);
	        } else {
	            printf(" %4d", 0);
	        }
	    }
	    printf("\n");
	}
	
	i = 0;
	j = s-1;
	int prefijos = 0;
	printf("\nNúmero minimo: %d\n", C[i][j]);
	printf("Cadena original -> %s\n", string);
	while (i != j){
	    if (camino[i][j] == 0){
	        i++;
	        j--;
	    } else if (camino[i][j] == 1){
	        string[j + prefijos] = string[i + prefijos];
	        printf("Cambiar el caracter %d por %c -> %s\n", j + 1 + prefijos, string[j + prefijos], string);
	        i++;
	        j--;
	    } else if (camino[i][j] == 2){
	        char *aux = insertar(string, j+1, string[i]);
	        free(string);
	        string = aux;
	        printf("Añadir caracter %c en pos %d -> %s\n", string[i+prefijos], j + 1 + prefijos, string);
	        i++;
	    } else if (camino[i][j] == 3){
	        char *aux = insertar(string, i + prefijos, string[j]);
	        free(string);
	        string = aux;
	        printf("Añadir caracter %c en pos %d -> %s\n", string[j+prefijos+1], prefijos + i + 1, string);
	        prefijos++;
	        j--;
	    }
	}
}
/**
C(i,j) = min (C(i+1, j-1), 1 + C(i+1, j), 1 + C(i, j-1))

0123
x012
xx01
xxx0
alohola
*/
