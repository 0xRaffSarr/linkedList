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
//Aggiunge un elemento in testa alla lista;
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
    return lista;
}
//Aggiunge un elemento in coda alla nLista
struct nodo *insInCoda(struct nodo *lista,int k){
    struct nodo *tmp = creaNodo(k);
    struct nodo *top = lista;

    if(isEmpty(lista)){
        lista = tmp;
    }
    else{
        while(top->next != NULL){
            top = top->next;
        }
        tmp->prev = top;
        top->next = tmp;
    }
    return lista;
}
//inserisce un elemento in ordine oppure in testa se la lista è vuota
struct nodo *insInOrdine(struct nodo *lista,int k){
    struct nodo *tmp = creaNodo(k);
    struct nodo *pre = NULL;

    if(isEmpty(lista)){
        lista = tmp;
    }
    else if(lista->data > k){
        tmp->next = lista;
        tmp->prev = lista->prev;
        lista->prev = tmp;
        lista = tmp;
    }
    else{
        pre = lista;
        while(pre->next != NULL && pre->next->data < k){
            pre = pre->next;
        }
        tmp->prev = pre;
        tmp->next = pre->next;
        if(pre->next != NULL){
            pre->next->prev = tmp;
        }
        pre->next = tmp;
    }
    return lista;
}
//Stampa una lista doppiamente linkata
void stampaLista(struct nodo *lista){
    if(lista == NULL){
        printf("\tLa lista è vuota;\n");
    }
    else{
        while(lista != NULL){
            printf("%4d",lista->data);
            lista = lista->next;
        }
        printf("\n");
    }
}
//canella l'intera lista
struct nodo *cancellaLista(struct nodo *lista){
    struct nodo *suc = NULL;
    while(lista != NULL){
        suc = lista->next;
        free(lista);
        lista = suc;
    }
    return lista;
};
//cancella un elemento e le sue ripetiozioni
struct nodo *cancellaElemento(struct nodo*lista,int k){
    struct nodo *tmp = NULL;
    struct nodo *elem = NULL;
    while (lista!=NULL && lista->data == k) {
        tmp = lista->next;
        free(lista);
        if(tmp != NULL){
            tmp->prev = NULL;
        }
        lista = tmp;
    }

    if(lista != NULL){
        tmp = lista->next;
        while(tmp!=NULL){
            if(tmp->data == k){
                elem = tmp;
                tmp->prev->next = tmp->next;
                if(tmp->next != NULL){
                    tmp->next->prev = tmp->prev;
                }
                free(elem);
            }
            tmp = tmp->next;
        }
    }
    return lista;
}
//ordina una lista in ordine crescente
struct nodo *ordinaCrescente(struct nodo*lista){
    struct nodo *corr = lista;
    struct nodo *succ = NULL;
    struct nodo *tmp = NULL;

    while(corr != NULL){
        succ = corr->next;
        while(succ != NULL){
            if(corr->data > succ->data){
                if(corr->prev == NULL){ //rimuovo l'elemento dalla posizione attuale ma non lo cancello, se in testa
                    tmp = corr;
                    corr = corr->next;
                    corr->prev = NULL;
                    lista = corr;
                }
                else{ //rimuovo l'elemento dalla posizione attuale ma non lo cancello, se in mezzo alla lista
                    tmp = corr;
                    corr->prev->next = tmp->next;
                    tmp->next->prev = tmp->prev;
                    corr = corr->next;
                }
                /*
                Inserisco ora l'elemento nella posizione giusta, ovvero dopo succ
                */
                tmp->next = succ->next;
                if(succ->next != NULL){ //se vi è un altro elemento dopo succ setto il suo prev
                    succ->next->prev = tmp;
                }
                tmp->prev = succ;
                succ->next = tmp;
            }
            succ = succ->next;
        }
        corr = corr->next;
    }
    return lista;
}
//ordina una lista in ordine crescente
void ordinaDecrescente(struct nodo*a){};
//cerca un elemento nella lista
int cercaElemento(struct nodo *a,int b){};
