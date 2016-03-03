#include "tipos.h"
#ifndef HEAP_H
#define HEAP_H

struct heap * iniciar_heap();
struct heap * insertar_heap(struct heap *, struct arbol *);
struct arbol * borrar_heap(struct heap *);
#endif