#ifndef HUFFMAN_H
#define HUFFMAN_H

struct codigo * obtener_codigos(struct arbol *);
struct arbol * huffman2(struct heap *);
struct arbol * huffman(long *);

#endif