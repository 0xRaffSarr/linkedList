/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"


struct nodo *creaLista(int k){
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;
    tmp->next = NULL;
    tmp->prev = NULL;
    return tmp;
}
