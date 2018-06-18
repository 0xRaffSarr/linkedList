#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct nodo *creaNodo(int k){
    struct nodo *tmp = (struct nodo*) malloc(sizeof(struct nodo));
    tmp->k = k;
    tmp->next = NULL;

    return tmp;
}
