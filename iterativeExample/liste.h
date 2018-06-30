/*
Raffaele Sarracino
*/
#ifndef LISTE_LIB_H
#define LISTE_LIB_H

struct nodo{
    int k;
    struct nodo *next;
};
//crea un semplice nodo
struct nodo *creaNodo(int);
//aggiunge un elemento in testa
struct nodo *addTesta(struct nodo*,int);
//aggiunge un elemento in coda
struct nodo *addCoda(struct nodo*,int);
//aggiunge un elemento in mezzo alla lista
struct nodo *addInMezzo(struct nodo*,int);
struct nodo *addInMezzoMultiplo(struct nodo*,int);
//cancella tutti gli elementi della liste e libera la memoria
struct nodo *liberaMemoria(struct nodo*);
struct nodo *addTestaMultiplo(struct nodo*,int);
struct nodo *addCodaMultiplo(struct nodo *,int);
//odina la lista in ordine crescente
struct nodo *ordinaCrescente(struct nodo *);
//ordina una lista in ordine ordinaDecrescente
struct nodo *ordinaDecrescente(struct nodo *);
//cancella un singolo elemento e tutte le sue ripetizioni
struct nodo *cancellaElemento(struct nodo *,int);


int cercaElemento(struct nodo *,int);
void stampaLista(struct nodo *);

#endif
