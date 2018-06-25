/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

void stampaMenu();

int main(){
    char op = 'x';
    int dim = 0,i = 0,x = 0;
    struct nodo *lista = NULL;
    lista = (struct nodo *)malloc(sizeof(struct nodo));
    lista->data = 0;
    lista->next = lista;
    lista->prev = lista;

    while(op != 'z'){
        stampaMenu();
        printf("\tScegli l'iperazione da eseguire: ");
        scanf("\n%c",&op);

        switch (op) {
            case 'a':{
                printf("Inserisci il numero di elementi: ");
                scanf("%d",&dim);
                for(i=0;i<dim;i++){
                    scanf("%d",&x);
                    lista = insInTesta(lista,x);
                }
                break;
            }
        }
    }

    lista = liberaMemoria(lista->next);
    free(lista);
    return 0;
}

void stampaMenu(){
    printf("\t===== MENU =====\n");
    printf("\ta)Inserisci elementi in testa;\n");
    printf("\tb)Inserisci elementi in coda;\n");

    printf("\tz)Termina programma;\n");
}
