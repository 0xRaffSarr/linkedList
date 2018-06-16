/*
Raffaele Sarracino
*/
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

void stampaMenu();

int main(){
    struct nodo *lista = NULL;
    int i = 0,dim = 0;
    char c = 0;

    while(c!='z'){
        dim = 0;
        stampaMenu();
        printf("Sceli un operazione da eseguire: ");
        scanf("\n%c",&c);
        printf("\n\n");
        switch(c){
            case 'a':{
                while(dim<=0){
                    printf("Inserisci il numero di elementi da inserire: ");
                    scanf("%d",&dim);
                }
                lista = addTestaMultiplo(lista,dim);
                break;
            }
            case 'b':{
                while(dim<=0){
                    printf("Inserisci il numero di elementi da inserire: ");
                    scanf("%d",&dim);
                }
                lista = addCodaMultiplo(lista,dim);
                break;
            }
            case 'c':
                {
                    printf("Ordina gli elementi in ordine crescente...\n");
                    lista = ordinaCrescente(lista);
                    printf("Il vettore e' stato ordinato.\n");

                    stampaLista(lista);
                    break;
                }
            case 'd':
                {
                    printf("Ordina gli elementi in ordine decrescente...\n");
                    lista = ordinaDecrescente(lista);
                    printf("Il vettore e' stato ordinato.\n");

                    stampaLista(lista);
                    break;
                }
            case 'e':{
                stampaLista(lista);
                break;
            }
            case 'f':{
                printf("Inserisci l'elemento da cercare: ");
                scanf("%d",&i);

                if(cercaElemento(lista,i)){
                    printf("\n\nL'elemento cercato e' presente nella lista;\n");
                }
                else{
                    printf("\n\nL'elemento cercato non e' presente nella lista;\n");
                }
                break;
            }
            case 'g':{
                printf("Inserisci l'elemento da cancellare: ");
                scanf("%d",&i);

                lista = cancellaElemento(lista,i);

                break;
            }
            case 'h':{
                printf("\n\nElimino gli elementi della lista...\n");
                lista = liberaMemoria(lista);
                if(lista==NULL){
                    printf("La lista e' stata eliminta;\n");
                }
                else{
                    printf("Errore durante l'eliminazione della lista;\n");
                }
                break;
            }
        }
    }

    liberaMemoria(lista);
    //system("pause");
    return 0;
}

void stampaMenu(){
    printf("\n======MENU======\n");
    printf("a)Inserisci elementi in testa;\n");
    printf("b)Inserisci elementi in coda;\n");
    printf("c)Ordina la lista in ordine crescente\n");
    printf("d)Ordina la lista in ordine decrescente;\n");
    printf("e)Stampa la lista;\n");
    printf("f)Cerca elemento;\n");
    printf("g)Elimina elemento;\n");
    printf("h)Elimina l'intera lista;\n");
    printf("z)Termina il programma;\n");
}
