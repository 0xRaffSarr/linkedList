/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct nodo *creaNodo(int x){
    struct nodo *tmp = (struct nodo *) malloc(sizeof(struct nodo));
    tmp -> k = x;
    tmp -> next = NULL;
    return tmp;
}


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


struct nodo *addInMezzo(struct nodo *top,int k){

}


/*struct nodo *liberaMemoria(struct nodo *top){
    if(top != NULL){
        top ->next = liberaMemoria(top->next);
        free(top);
    }
    return NULL;
}*/


struct nodo *liberaMemoria(struct nodo *top){
    struct nodo *suc = NULL;
    while(top != NULL){
        suc = top->next;
        free(top);
        top = suc;
    }
    return top;
}


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


struct nodo *addTestaMultiplo(struct nodo *top, int  n){
    int i = 0, x = 0;
    struct nodo *tmp = top;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        tmp = addTesta(tmp,x);
    }
    return tmp;
}


struct nodo *addCodaMultiplo(struct nodo *top, int  n){
    int i = 0, x = 0;
    struct nodo *tmp = top;
    for(i=0;i<n;i++){
        scanf("%d",&x);
        tmp = addCoda(tmp,x);
    }
    return tmp;
}

struct nodo *ordinaCrescente(struct nodo *top){
    struct nodo *tmp = NULL;
    struct nodo *rmp = top;

    while(rmp != NULL){
        tmp = rmp;
        while(tmp != NULL){
            if(rmp->k>tmp->k){
                rmp->k += tmp->k;
                tmp->k = rmp->k - tmp->k;
                rmp->k = rmp->k - tmp->k;
            }
            tmp = tmp->next;
        }
        rmp = rmp->next;
    }
    return top;
}


struct nodo *ordinaDecrescente(struct nodo *top){
    struct nodo *tmp = NULL;
    struct nodo *rmp = top;

    while(rmp != NULL){
        tmp = rmp;
        while(tmp != NULL){
            if(rmp->k<tmp->k){
                rmp->k += tmp->k;
                tmp->k = rmp->k - tmp->k;
                rmp->k = rmp->k - tmp->k;
            }
            tmp = tmp->next;
        }
        rmp = rmp->next;
    }
    return top;
}


int cercaElemento(struct nodo *top,int k){
    int trovato = 0;

    while(top->next!=NULL){
        if(top->k==k) trovato = 1;
        top = top->next;
    }
    return trovato;
}

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