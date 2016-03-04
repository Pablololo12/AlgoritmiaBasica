
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
#endif