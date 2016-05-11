#include <stdio.h>
#include <string.h>
#include "comparador.h"

int min(int x, int y, int z){
    if(x <= y && x <= z) return x;
    else if(y <= x && y <= z) return y;
    else return z;
}

int res(char * cada, char * cadb, int i, int j, int **  T, int cuenta){
    int k;
    if(i==0){
        printf("Numero minimo: %d\n", cuenta+j);
        for(k=1;k<=j;k++) printf("Anyadir %c en el lugar %d\n",cadb[k-1],k);
    } else if(j==0){
        printf("Numero minimo: %d\n", cuenta+i);
        for(k=1;k<=i;k++) printf("Borrar car.nº %d\n",k);
    } else{
        switch (T[i][j]) {
            case BORRAR:
                res(cada,cadb,i-1,j,T,++cuenta);
                printf("Borrar car.nº%d\n",i);
                break;
            case INSERTAR:
                res(cada,cadb,i,j-1,T,++cuenta);
                printf("Insertar car.nº%d de B tras la posicion %d\n",j,i);
                break;
            case SUSTITUIR:
                res(cada,cadb,i-1,j-1,T,++cuenta);
                printf("Sustituir car.nº%d de A por nº %d de B\n",i,j);
                break;
            case NADA:
                res(cada,cadb,i-1,j-1,T,cuenta);
                break;
        }
    }
    return 0;
}

int comparar(char * cada, char * cadb, int ** C, int ** T, int n, int m){
    int i,j,x,y,z,aux;
    for(i=0; i<n; i++) C[i][0]=i;
    for(j=0; j<m; j++) C[0][j]=j;
    for(i=1; i<n; i++){
        for(j=1; j<m; j++){
            x = C[i-1][j]+1;
            y = C[i][j-1]+1;
            if(cada[i-1] == cadb[j-1]) z = C[i-1][j-1];
            else z = C[i-1][j-1]+1;
            aux=min(x,y,z);
            C[i][j]=aux;
            if(aux == x) T[i][j]=BORRAR;
            else if(aux == y) T[i][j]=INSERTAR;
            else if(aux == z && (cada[i-1] == cadb[j-1])) T[i][j] = NADA;
            else T[i][j] = SUSTITUIR;
        }
    }
    return 0;
}
