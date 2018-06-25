#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

/*
Verifica se la lista in questione è vuota oppure no;
Restituisce 0 se la lista non è vuota 1 se la lista è vuota;
*/
int isEmpty(struct nodo *lista){
    int res = 0;
    if(lista->next == lista) res = 1;
}

//Crea una lista contenente unicamente il valore sentinella
struct nodo *creaLista(){
    struct nodo *sentinella = NULL;
    sentinella = (struct nodo *)malloc(sizeof(struct nodo));
    sentinella->prev = sentinella;
    sentinella->next = sentinella;
    return sentinella;
}

//Stampa una lista circolare
void stampaLista(struct nodo *lista){
    struct nodo *tmp = lista;

    while(tmp!=lista){
        printf("%4d",tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}
