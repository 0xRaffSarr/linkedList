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
    struct nodo *lista = creaLista();

    while(op != 'z'){
        stampaMenu();
        printf("\tScegli l'iperazione da eseguire: ");
        scanf("\n%c",&op);

        switch(op){
            case 'a':{
                printf("Inserisci il numero di elementi da inserire: ");
                scanf("%d",&dim);

                for(i=0;i<dim;i++){
                    scanf("%d",&x);
                    insInTesta(lista,x);
                }

                break;
            }
            case 'b':{
                printf("Inserisci il numero di elementi da inserire: ");
                scanf("%d",&dim);

                for(i=0;i<dim;i++){
                    scanf("%d",&x);
                    insInCoda(lista,x);
                }

                break;
            }
            case 'f':{
                stampaLista(lista);
                break;
            }
        }
    }
    return 0;
}

void stampaMenu(){
    printf("\t===== MENU =====\n");
    printf("\ta)Inserisci elementi in testa;\n");
    printf("\tb)Inserisci elementi in coda;\n");
    printf("\tf)Stampa lista;\n");
    printf("\tz)Termina programma;\n");
}
