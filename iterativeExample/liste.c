/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
/*
crea un nodo e setta il next a NULL
*/
struct nodo *creaNodo(int x){
    struct nodo *tmp = (struct nodo *) malloc(sizeof(struct nodo));
    tmp -> k = x;
    tmp -> next = NULL;
    return tmp;
}
/*
aggiunge un elemento in testa alla lista, sia che essa sia vuota sia che abbia altri elementi
*/
struct nodo *addTesta(struct nodo *top,int x){
    struct nodo *tmp = NULL;
    if(top == NULL){
       top = creaNodo(x);
    }
    else{
        tmp = creaNodo(x);
        tmp -> next = top;
        top = tmp;
    }
    return top;
}
/*
aggiunge un elemento in coda alla lista, sia che la lista sia vuota sia che abbia altri elementi
*/
struct nodo *addCoda(struct nodo *top,int x){
    struct nodo *tmp = NULL;
    if(top == NULL){
        top = creaNodo(x);
    }
    else{
        tmp = top;
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = creaNodo(x);
    }
    return top;
}
/*
aggiunge un elemento in ordine all'interno della lista, sia che essa sia vuota sia che contenga altri elementi
*/
struct nodo *addInMezzo(struct nodo *top,int k){
    struct nodo *tmp = creaNodo(k);
    struct nodo *pre = NULL;

    if(top == NULL){
        top = tmp;
    }
    else if (top->k > k) {
        tmp->next = top;
        top = tmp;
    }
    else{
        pre = top;
        while(pre->next != NULL && pre->next->k<k){
            pre = pre->next;
        }
        tmp->next = pre->next;
        pre->next = tmp;
    }
    return top;
}

/*
La funzione cancella tutti gli elementi di una lista
*/
struct nodo *liberaMemoria(struct nodo *top){
    struct nodo *suc = NULL;
    while(top != NULL){
        suc = top->next;
        free(top);
        top = suc;
    }
    return top;
}
/*
stampa una lista semplice
*/
void stampaLista(struct nodo *top){
    if(top == NULL){
        printf("La lista e' vuota;\n\n");
    }
    else{
        printf("La lista e':\n");

        while(top != NULL){
            printf("%5d",top->k);
            top = top->next;
        }
        printf("\n\n");
    }
}
/*
ordina una lista in ordine crescente, creando una nuva lista semplice
dopo la creazione della nuova lista, elimina la precedente e restituisce la nuova lista in ordine crescente
*/
struct nodo *ordinaCrescente(struct nodo *lista){
    struct nodo *tmp = NULL;
    struct nodo *pre = NULL;
    struct nodo *top = NULL;

    while(lista != NULL){
        tmp = creaNodo(lista->k);
        if(top == NULL){
            top = tmp;
        }
        else if (top->k > lista->k) {
            tmp->next = top;
            top = tmp;
        }
        else{
            pre = top;
            while(pre->next != NULL && pre->next->k<lista->k){
                pre = pre->next;
            }
            tmp->next = pre->next;
            pre->next = tmp;
        }
        lista = lista->next;
    }
    liberaMemoria(lista);
    lista = top;
    return lista;
}
/*
ordina una lista in ordine decrescente, creando una nuva lista semplice
dopo la creazione della nuova lista, elimina la precedente e restituisce la nuova lista in ordine decrescente
*/
struct nodo *ordinaDecrescente(struct nodo *lista){
    struct nodo *tmp = NULL;
    struct nodo *pre = NULL;
    struct nodo *top = NULL;

    while(lista != NULL){
        tmp = creaNodo(lista->k);
        if(top == NULL){
            top = tmp;
        }
        else if (top->k < lista->k) {
            tmp->next = top;
            top = tmp;
        }
        else{
            pre = top;
            while(pre->next != NULL && pre->next->k>lista->k){
                pre = pre->next;
            }
            tmp->next = pre->next;
            pre->next = tmp;
        }
        lista = lista->next;
    }
    liberaMemoria(lista);
    lista = top;
    return lista;
}
/*
cerca un elemento all'interno della stampaLista
    restituisce 0 se l'elemento non è presente nella stampaLista;
        1 se l'elemento è presente nella lista;
*/
int cercaElemento(struct nodo *top,int k){
    int trovato = 0;

    while(top->next!=NULL){
        if(top->k==k) trovato = 1;
        top = top->next;
    }
    return trovato;
}
/*
cancella un elemento e tutte le sue ripetizioni all'interno di una lista
*/
struct nodo *cancellaElemento(struct nodo *lista, int k){
    struct nodo *suc = lista;
    struct nodo *pre = NULL;

    while(suc != NULL && suc->k == k){
        pre = suc;
        suc = suc->next;
        free(pre);
    }
    lista = suc;
    if(lista != NULL){
        pre = lista->next;
        while(suc != NULL){
            if(suc->k==k){
                pre->next = suc->next;
                free(suc);
                suc = pre->next;
            }
            else{
                pre = suc;
                suc = pre->next;
            }
        }
    }
    return lista;
}
