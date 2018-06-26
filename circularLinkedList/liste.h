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

//verifica se la lista è vuota oppure no, usata per semplicità
int isEmpty(struct nodo *);
//Crea una lista costituita unicamente dal valore sentinella
struct nodo *creaLista();
//Inserisce un elemento in testa alla lista
void insInTesta(struct nodo *,int );
//Inserisce un elemento in coda alla lista o in testa se la lista è vuota
void insInCoda(struct nodo *,int);
//inserisce un elemento in ordine oppure in testa se la lista è vuota
void insInOrdine(struct nodo *,int);
//Stampa una lista circolare
void stampaLista(struct nodo *);
//canella l'intera lista tranne l'elemento sentinella
void cancellaLista(struct nodo *);
//cancella un elemento e le sue ripetiozioni
void cancellaElemento(struct nodo*,int);
//ordina una lista in ordine crescente
void ordinaCrescente(struct nodo*);
//ordina una lista in ordine crescente
void ordinaDecrescente(struct nodo*);

#endif
