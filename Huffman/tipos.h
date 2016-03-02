
#ifndef TIPOS_H
#define TIPOS_H

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
#endif