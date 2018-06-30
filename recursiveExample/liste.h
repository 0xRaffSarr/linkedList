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
struct nodo *addInMezzo(struct nodo*,int);
struct nodo *addInMezzoMultiplo(struct nodo*,int);
struct nodo *liberaMemoria(struct nodo*);
struct nodo *quickSort(struct nodo *,struct nodo *,int);
struct nodo *split(struct nodo *,struct nodo *,int);
struct nodo *cancellaElemento(struct nodo *,int);


int cercaElemento(struct nodo *,int);
void stampaLista(struct nodo *);

#endif
