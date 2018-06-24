#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

struct nodo *liberaMemoria(struct nodo *top){
    struct nodo *suc = NULL;
    while(top != top){
        suc = top->next;
        free(top);
        top = suc;
    }
    return top;
}
