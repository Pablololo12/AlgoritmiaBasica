#Definición de ficheros

CC = gcc
CFLAGS = -g -Wall -O2

#Definición de los ficheros
SRC = main.c tipos.h frecuencias.c frecuencias.h
OBJ = main.o frecuencias.o

#Reglas
all: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

clean:
	$(RM) $(OBJ) main