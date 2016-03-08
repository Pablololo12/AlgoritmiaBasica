
#ifndef TIPOS_H
#define TIPOS_H

#define TAM_BUFF 256

struct arbol{
	char elemento;
	long apariciones;
	struct arbol *hijo_d;
	struct arbol *hijo_i;
};

struct heap{
	int tamanyo;
	struct arbol ** elemento;
};

struct codigo{
	int tamanyo;
	long cod;
};

typedef struct{
	unsigned bit_0:1;
	unsigned bit_1:1;
	unsigned bit_2:1;
	unsigned bit_3:1;
	unsigned bit_4:1;
	unsigned bit_5:1;
	unsigned bit_6:1;
	unsigned bit_7:1;
}bites;
#endif