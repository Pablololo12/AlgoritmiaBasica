#Definición de ficheros

CC = gcc
CFLAGS = -g -Wall -O3

#Definición de los ficheros
SRC = Fuentes/main.c Fuentes/tipos.h Fuentes/frecuencias.c Fuentes/frecuencias.h Fuentes/compactador.c Fuentes/compactador.h Fuentes/heap.h Fuentes/heap.c Fuentes/huffman.c Fuentes/huffman.h Fuentes/descompactador.h Fuentes/descompactador.c
OBJ = Fuentes/main.o Fuentes/frecuencias.o Fuentes/compactador.o Fuentes/heap.o Fuentes/huffman.o Fuentes/descompactador.o

#Reglas
all: $(OBJ)
	$(CC) $(CFLAGS) -o huf $(OBJ)

clean:
	$(RM) $(OBJ) huf
