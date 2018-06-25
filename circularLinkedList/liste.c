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

    /*if(isEmpty(lista)){
        printf("\tLa lista e' vuota;\n");
    }
    else{*/
        while(tmp!=lista){
            printf("%4d",tmp->data);
            tmp = tmp->next;
        }
        printf("\n");
    //}
}

/*
La procedura inserisce un elemento in testa sia che la lista sia vuota, sia che la lista abbia gia altri elementi
Viene utilizzata la funzione isEmpty per semplificare il controllo
*/
void insInTesta(struct nodo *lista,int k){
    struct nodo *top = NULL;
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;//inizializzo il valore del nuovo elemento

    if(isEmpty(lista)){
        lista->prev = tmp;
        lista->next = tmp;
        tmp->prev = lista;
        tmp->next = lista;
    }
    else{
        top = lista->next;
        top->prev = tmp;
        tmp->prev = lista;
        tmp->next = top;
        lista->next = tmp;
    }
}
