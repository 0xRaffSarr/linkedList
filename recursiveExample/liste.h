/*
Raffaele Sarracino
*/
#ifndef LISTE_LIB_H
#define LISTE_LIB_H

struct nodo{
    int k;
    struct nodo *next;
};

struct nodo *creaNodo(int);
struct nodo *addTesta(struct nodo*,int);
struct nodo *addCoda(struct nodo*,int);
struct nodo *liberaMemoria(struct nodo*);
struct nodo *addTestaMultiplo(struct nodo*,int);
struct nodo *addCodaMultiplo(struct nodo *,int);
struct nodo *ordinaCrescente(struct nodo *);
struct nodo *ordinaDecrescente(struct nodo *);
struct nodo *cancellaElemento(struct nodo *,int);


int cercaElemento(struct nodo *,int);
void stampaLista(struct nodo *);

#endif
