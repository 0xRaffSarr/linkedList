/*
Raffaele Sarracino
*/
#ifndef LISTE_LIB_H
#define LISTE_LIB_H

struct nodo{
    int data;
    struct nodo *next;
    struct nodo *prev;
};

struct nodo *creaNodo(int);
struct nodo *liberaMemoria(struct nodo *);

#endif
