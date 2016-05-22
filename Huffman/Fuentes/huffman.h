/**
 *
 * Fichero: huffman.h
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Fichero de cabecera
 */

#ifndef HUFFMAN_H
#define HUFFMAN_H

struct codigo * obtener_codigos(struct arbol *);
struct arbol * huffman(struct heap *);

#endif
