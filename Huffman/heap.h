
#ifndef HEAP_H
#define HEAP_H

struct heap * iniciar_heap();
struct heap * insertar_heap(struct heap *, char, int);
struct arbol * borrar_heap(struct heap *);
#endif