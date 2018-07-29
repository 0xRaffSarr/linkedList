/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"


struct nodo *creaNodo(int k){
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}

void insInTesta(struct nodo *lista,int k){
    struct nodo *tmp = creaNodo(k);
    struct nodo *top = NULL;

    if(lista == NULL){
        lista = tmp;
    }
    else{
        top = lista;
        while(top != NULL && top->data < k){
            top = top->next;
        }
        tmp->next = top->next;
        tmp->prev = top;
        top->next = tmp;
        tmp->next->prev = tmp;
    }
    lista = top;
}


//Inserisce un elemento in coda alla lista o in testa se la lista è vuota
void insInCoda(struct nodo *a,int b){};
//inserisce un elemento in ordine oppure in testa se la lista è vuota
void insInOrdine(struct nodo *a,int b){};
//Stampa una lista circolare
void stampaLista(struct nodo *lista){
    if(lista == NULL){
        printf("\tLa lista è vuota;\n");
    }
    else{
        while(lista != NULL){
            printf("%d ",lista->data);
            lista = lista->next;
        }
        printf("\n");
    }
};
//canella l'intera lista tranne l'elemento sentinella
void cancellaLista(struct nodo *a){};
//cancella un elemento e le sue ripetiozioni
void cancellaElemento(struct nodo*a,int b){};
//ordina una lista in ordine crescente
void ordinaCrescente(struct nodo*a){};
//ordina una lista in ordine crescente
void ordinaDecrescente(struct nodo*a){};
//cerca un elemento nella lista
int cercaElemento(struct nodo *a,int b){};
