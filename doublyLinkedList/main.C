/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

void stampaMenu();

int main(){
    struct nodo *lista = NULL;
    lista = (struct nodo *)malloc(sizeof(struct nodo));
    lista->data = 0;
    lista->next = lista;
    lista->prev = lista;

    stampaMenu();

    lista = liberaMemoria(lista->next);
    free(lista);
    return 0;
}

void stampaMenu(){
    printf("\t===== MENU =====\n");
}
