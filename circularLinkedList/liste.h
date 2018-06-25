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
//Stampa una lista circolare
void stampaLista(struct nodo *);

#endif
