#Definición de ficheros

CC = gcc
CFLAGS = -g -Wall -O3

#Definición de los ficheros
SRC = main.c comparador.c comparador.h
OBJ = main.o comparador.o

#Reglas
all: $(OBJ)
	$(CC) $(CFLAGS) -o main $(OBJ)

clean:
	$(RM) $(OBJ) main
