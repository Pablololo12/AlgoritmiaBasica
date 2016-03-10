
#ifndef TIPOS_H
#define TIPOS_H

#define TAM_BUFF 256

struct arbol{
	unsigned char elemento;
	unsigned int apariciones;
	struct arbol *hijo_d;
	struct arbol *hijo_i;
};

struct heap{
	int tamanyo;
	struct arbol ** elemento;
};

struct codigo{
	int tamanyo;
	unsigned int cod;
};

typedef union
{
	struct
	{
	unsigned char bit_0:1;
	unsigned char bit_1:1;
	unsigned char bit_2:1;
	unsigned char bit_3:1;
	unsigned char bit_4:1;
	unsigned char bit_5:1;
	unsigned char bit_6:1;
	unsigned char bit_7:1;
	}bits;
	unsigned char letra;
}Bites;
#endif