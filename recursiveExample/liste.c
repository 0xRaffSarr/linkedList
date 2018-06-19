#include <stdio.h>
#include <stdlib.h>

#include "liste.h"
/*
Crea un semplice nodo.
Ri chiede come parametri solo il valore int da inizializzare;
*/
struct nodo *creaNodo(int k){
    struct nodo *tmp = (struct nodo*) malloc(sizeof(struct nodo));
    tmp->k = k;
    tmp->next = NULL;
    return tmp;
}
/*
La funzione aggiunge un elemento in testa alla lista, sia che essa sia vuota, sia
che essa sia falsa;
*/
struct nodo *addTesta(struct nodo *top,int k){
    struct nodo *tmp = NULL;
    if(top == NULL){
        top = creaNodo(k);
    }
    else{
        tmp = creaNodo(k);
        tmp->next = top;
        top = tmp;
    }
    return top;
}
/*
La funzione rapprenseta una falsa ricorsione o meglio una ricorsione in coda per inserire più elementi in testa
*/
struct nodo *addTestaMultiplo(struct nodo *top,int n){
    int x = 0;
    if(n>0){
        scanf("%d",&x);
        top = addTesta(top,x);
        top = addTestaMultiplo(top,n-1);
    }
    return top;
}
/*
Aggiunge un elemento in coda
*/
struct nodo *addCoda(struct nodo* top,int k){
    struct nodo *tmp = NULL;

    if(top == NULL){
        top = creaNodo(k);
    }
    else{
        tmp = addCoda(top->next,k);
        top->next = tmp;
    }
    return top;
}
/*
La funzione rapprenseta una falsa ricorsione o meglio una ricorsione in coda per inserire più elementi in coda
*/
struct nodo *addCodaMultiplo(struct nodo *top,int n){
    int x = 0;
    if(n>0){
        scanf("%d",&x);
        top = addCoda(top,x);
        top = addCodaMultiplo(top,n-1);
    }
    return top;
}
/*
La funzione aggiunge un elemento in ordine all'interno della lista
*/
struct nodo *addInMezzo(struct nodo *top,int k){
    struct nodo *pre = top;
    struct nodo *tmp = NULL;

    if(top == NULL){
        top = creaNodo(k);
    }
    else if(top->k > k){
         tmp = creaNodo(k);
         tmp->next = top;
         top = tmp;
    }
    else if(pre->next != NULL && pre->next->k<k){
        pre = addInMezzo(pre->next,k);
    }
    else{
        tmp = creaNodo(k);
        tmp->next = pre->next;
        pre->next = tmp;
    }
    return top;
}
/*
La funzione rapprenseta una falsa ricorsione o meglio una ricorsione in coda per inserire più elementi in mezzo alla lista
*/
struct nodo *addInMezzoMultiplo(struct nodo *top,int n){
    int x = 0;
    if(n>0){
        scanf("%d",&x);
        top = addInMezzo(top,x);
        top = addInMezzoMultiplo(top,n-1);
    }
    return top;
}
/*
La funzione elimina tutti gli elementi della lista
*/
struct nodo *liberaMemoria(struct nodo *top){
    if(top!=NULL){
        top->next = liberaMemoria(top->next);
        free(top);
    }
    return NULL;
}


struct nodo *ordinaCrescente(struct nodo *top){

}


struct nodo *ordinaDecrescente(struct nodo *top){

}
/*
La funzione cancella un elemento e tutte le sue ripetizioni
*/
struct nodo *cancellaElemento(struct nodo *top,int k){
    struct nodo *tmp = NULL;

    if(top!=NULL && top->k==k){
        tmp = top->next;
        free(top);
        top = tmp;
        if(top!=NULL){
            top = cancellaElemento(top,k);
        }
    }
    else if(top!=NULL && top->next!=NULL){
        top->next = cancellaElemento(top->next,k);
    }

    return top;
}
/*
cerca un elemento e restituisce:
    0 se l'elemento non viene trovato
    1 se l'elemento viene trovato
*/
int cercaElemento(struct nodo *top,int k){
    int found = 0;
    if(top != NULL){
        if(top->k == k){
            found = 1;
        }
        else{
            found = cercaElemento(top->next,k);
        }
    }
    return found;
}
/*
La funzione stampa tutti gli elementi della lista
*/
void stampaLista(struct nodo *top){
    if(top == NULL){
        printf("La lista e' vuota;\n\n");
    }
    else{
            printf("%5d",top->k);
            if(top->next!=NULL) stampaLista(top->next);
        }
}
