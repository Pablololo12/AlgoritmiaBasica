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

void imprimirMatrices (unsigned int **C, int s){
    int j, i;
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
	            printf(" %4d", C[j][i]);
	        } else {
	            printf(" %4d", 0);
	        }
	    }
	    printf("\n");
	}
}

int main(int argc, char **argv)
{
    int s = strlen(argv[1]);
	char *string = (char *) malloc(sizeof(char) * s);
	strcpy(string, argv[1]);
	
	unsigned int **C = malloc(sizeof(unsigned int *) * s);
	int i;
	for(i=0; i<s; i++) C[i] = calloc(s ,sizeof(unsigned int));
	//C[i][j] es el coste de hacer palindromo la cadena string(i...j)
	//C[j][i] es el camino óptimo
	
	i = s - 1;
	for (; i >= 0; i--){
	    C[i][i] = 0;
	    int j = i + 1;
	    for (; j < s ; j++){
	        unsigned int min;
	        min = (i+1<j-1)? C[i+1][j-1]: 0;
	        C[j][i] = 0;
	        if (string[i] != string[j]){ //los caracteres de los extremos se intercambian
	            min++;
	            C[j][i] = 1;
    	    }
	        if (min > 1 + C[i+1][j]){ //se añade una caracter igual al extremo izquierdo en la derecha
	            min = 1 + C[i+1][j];
	            C[j][i] = 2;
	        }  else if (min > 1 + C[i][j-1]){//se añade una caracter igual al extremo derecho en la izquierda
	            min = 1 + C[i][j-1];
	            C[j][i] = 3;
	        }
	        C[i][j] = min;
	    }
	}
	
	//imprimirMatrices(C, s);
	
	int j;
	i = 0;
	j = s-1;
	int prefijos = 0;
	printf("\nNúmero minimo: %d\n", C[i][j]);
	printf("Cadena original -> %s\n", string);
	while (i < j){
	    if (C[j][i] == 0){
	        i++;
	        j--;
	    } else if (C[j][i] == 1){
	        string[j + prefijos] = string[i + prefijos];
	        printf("Cambiar el caracter %d por %c -> %s\n", j + 1 + prefijos, string[j + prefijos], string);
	        i++;
	        j--;
	    } else if (C[j][i] == 2){
	        char *aux = insertar(string, j+1, string[i]);
	        free(string);
	        string = aux;
	        printf("Añadir caracter %c en pos %d -> %s\n", string[i+prefijos], j + 1 + prefijos, string);
	        i++;
	    } else if (C[j][i] == 3){
	        char *aux = insertar(string, i + prefijos, string[j]);
	        free(string);
	        string = aux;
	        printf("Añadir caracter %c en pos %d -> %s\n", string[j+prefijos+1], prefijos + i + 1, string);
	        prefijos++;
	        j--;
	    }
	}
}
