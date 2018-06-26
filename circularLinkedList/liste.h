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
//Inserisce un elemento in coda alla creaLista
void insInCoda(struct nodo *,int);
//Stampa una lista circolare
void stampaLista(struct nodo *);
//canella l'intera lista tranne l'elemento sentinella
void cancellaLista(struct nodo *);
//cancella un elemento e le sue ripetiozioni
void cancellaElemento(struct nodo*,int);

#endif
