/**
 *
 * Fichero: heap.h
 * Autores: Mario Arcega 679192 y Pablo Hernández 616923
 * Descripción: Fichero de cabecera
 */

#include "tipos.h"
#ifndef HEAP_H
#define HEAP_H

struct heap * iniciar_heap();
struct heap * insertar_heap(struct heap *, struct arbol *);
struct arbol * borrar_heap(struct heap *);
#endif
