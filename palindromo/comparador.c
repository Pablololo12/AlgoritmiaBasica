#include <stdio.h>
#include <string.h>
#include "comparador.h"

int min(int x, int y, int z){
    if(x <= y && x <= z) return x;
    else if(y <= x && y <= z) return y;
    else return z;
}

int comparar(char * cada, char * cadb, int ** C, int ** T, int n, int m){
    int i,j,x,y,z,aux;
    for(i=0; i<n; i++) C[i][0]=i;
    for(j=0; j<m; j++) C[0][j]=j;
    for(i=1; i<n; i++){
        for(j=1; j<m; j++){
            x = C[i-1][j]+1;
            y = C[i][j-1]+1;
            if(cada[i] == cadb[j]) z = C[i-1][j-1];
            else z = C[i-1][j-1]+1;
            aux=min(x,y,z);
            C[i][j]=aux;
            if(aux == x) T[i][j]=BORRAR;
            else if(aux == y) T[i][j]=INSERTAR;
            else if(aux == z && (cada[i] == cadb[j])) T[i][j] = NADA;
            else T[i][j] = SUSTITUIR;
        }
    }
    return 0;
}
