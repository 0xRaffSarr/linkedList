#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct nodo *insInTesta(struct nodo *lista,int k){
    struct nodo *tmp = (struct nodo *)malloc(sizeof(struct nodo));
    tmp->data = k;
    tmp->next = lista->next;
    tmp->prev = lista;
    //(lista->next)->next = tmp;
    lista->next = tmp;
    return lista;
}
