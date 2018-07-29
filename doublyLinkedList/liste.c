/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

//verifica se la lista è vuota oppure no, usata per semplicità
int isEmpty(struct nodo *lista){
    int r = 1;
    if(lista != NULL){
        r = 0;
    }
    return r;
};

//crea un nuovo elemento/nodo
struct nodo *creaNodo(int k){
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
//Aggiuunge un elemento in testa alla lista;
struct nodo *insInTesta(struct nodo *lista,int k){
    struct nodo *tmp = creaNodo(k);
    struct nodo *top = lista;

    if(isEmpty(lista)){
        lista = tmp;
    }
    else{
        tmp->prev = top->prev;
        tmp->next = top;
        top->prev = tmp;
        lista = tmp;

    }
    //return lista;
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
