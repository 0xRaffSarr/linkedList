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
Aggiungo un semplice elemento in testa alla lista, sia che essa sia vuota, sia
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

struct nodo *addTestaMultiplo(struct nodo *top,int n){
    int x = 0;
    if(n>0){
        scanf("%d",&x);
        top = addTesta(top,x);
        top = addTestaMultiplo(top,n-1);
    }
    return top;
}


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


struct nodo *addCodaMultiplo(struct nodo *top,int n){
    int x = 0;
    if(n>0){
        scanf("%d",&x);
        top = addCoda(top,x);
        top = addCodaMultiplo(top,n-1);
    }
    return top;
}


struct nodo *addInMezzo(struct nodo *top,int k){}
struct nodo *addInMezzoMultiplo(struct nodo *top,int k){}


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


struct nodo *cancellaElemento(struct nodo *top,int k){
    struct nodo *tmp = NULL;

    if(top!=NULL && top->k==k){
        tmp = top->next;
        printf("Eliminato %d\n",top->k);
        free(top);
        top = tmp;

        top = cancellaElemento(top,k);
        //return top->next;
    }
    else if(top->next!=NULL){
        top->next = cancellaElemento(top->next,k);
    }

    return top;
}


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


void stampaLista(struct nodo *top){
    if(top == NULL){
        printf("La lista e' vuota;\n\n");
    }
    else{
            printf("%5d",top->k);
            if(top->next!=NULL) stampaLista(top->next);
        }
}
