# linkedList
L'esempio mostra una serie di funzioni per manipolare le linked list;

Gli esempi sono stati sviluppati secondo due modalità:
- Iterativa;
- Ricorsiva;

Vengono presentati quattro tipi di Linked List:
1. Liste linkate semplici;
1. Liste doppiamente linkate;
1. Liste doppiamente linkate;
1. Liste doppiamente linkate con elemento fittizio(Circolari);

Le funzioni presenti sono:

- Inserisci elementi in testa;
- Inserisci elementi in coda;
- Inserisci elementi in ordine;
- Ordina la lista in ordine crescente;
- Ordina la lista in ordine decrescente;
- Stampa la lista;
- Cerca elemento;
- Elimina elemento;
- Elimina l'intera lista;

Le funzioni ricorsive saranno svolte cercando di mantenere la stessa linea di quelle utilizzate per l'esempio iterativo.

Per tale motivo l'esempio ricorsivo sarà ripresentato cercando di migliorare tali funzioni.

Nell'esempio ricorsivo come algoritmo di ordinamento é stato utilizzato il Quick Sort.

## Indice

1. [Introduzione](#introduzione)
    1. [Puntatori](#puntatori)
    1. [Record](#record)
1. [Linkedlist vs Array di record](#linkedlist-vs-array-di-record)
1. [Tipi di linkedlist](#tipi-di-linkedlist)
    1. [Linkedlist semplici](#linkedlist-semplici)
    1. [Linkedlist doppiamente concatenta](#linkedlist-doppiamente-concatenate)
    1. [Linkedlist circolari](#linkedlist-circolari)
1. [Operazioni sulle linkedList](#operazioni-sulle-linkedlist)

## Introduzione

Per poter utilizzare correttamente le liste(`linkedlist`), occorre saper utilizzare i `puntatori` e le strutture(`record`). Le linkedlist, sono il frutto di una combinazione di puntatori e record. A causa della loro flessibilità e facilità su alcune operazioni di gestione, rappresentano una struttura molto importante in alcuni ambiti;

### Puntatori

I puntatori, essenzialmente possono essere considarti come delle normali variabili, il cui contenuto però è costituito da un indirizzo di memoria. Una variabile puntatore, può puntare unicamente ad una variabile che concorda con il tipo del puntatore stesso;

```c
float c = 2.5;
int *p = &c;
```
Tale codice, risulta essere errato, in quanto un puntatore di tipo intero, non può puntare ad una variabile di tipo float. Il codice corretto sarebbe stato:

```c
float c = 2.5;
float *p = &c;
```
Non si può assegnare un valore ad un puntatore, a meno che esso non sia:
- Il valore `NULL`;
- Un indirizzo di memoria di una variabile o struttura, mediante l'operatore `&`;
- A seguito di un'operazione di allocazione dinamica della memoria;

Gli operatori fondamentali dei puntatori sono essenzialmente due, l'operatore `*` e l'operatore `&`

Operatore | Nome | Funzione
--------- | ---- | ---------
 `*` | Deferenziazione | Svolge una duplice funzione, in primo luogo serve a definire un puntatore; Serve inoltre ad accedere al valore della variabile puntata;
 `&` | Indirizzo | L'operatore unario end, serve a recuperare l'indirizzo di memoria di una variabile;

 &Egrave; da ritenersi sbalgiato, considerare il risultato dell'operatore unario `&` come valore della variabile. Il valore restituito da tale operatore, rappresenta l'indirizzo di memoria della variabile e non il valore da essa contenuta;
 Inoltre, l'operatore di deferenziazione, risulta essere l'opposto dell'operatore indirizzo, per tale motivo se si assegna al puntatore `P`, l'indirizzo di memoria della variabile `A`, l'operazione di deferenziazione sul puntatore P, restituirà il valore contenuto dalla variabile A.

 ```c
 int a = 4;
 int *p;
 p = &a;
 *p == a;
 ```
Non è detto però che sia vero il contrario, infatti se si assegna a `*p` il valore della variabile `a`, il valore di p non sarà `&a`

```c
int a = 4;
int *p;
*p = a;
p != &a;
```
Anche quando si utilizzano gli array, inconsapevolmente si sta utilizzando un pontatore. Il nome di un array, non è altro che un puntatore, il quale punta al primo elemento dell'array.

Inoltre, dal momento che il contenuto di un puntatore, non è altro che l'indirizzo di memoria della variabile puntata, durante le operazioni di input, il puntatore non va indicato nella forma `&P`, ma va indicato come `P`.

```c
int a = 0;
int *P = &a;

    scanf("%i\n",p);
```
In tal caso, il valore in input verrà assegnato alla variabile a; Durante un'operazione di output invece, la variabile puntatore verrà indicata come `*p` per poter stampare il contenuto della variabile a;

### Record

## Linkedlist vs Array di record


## Tipi di linkedlist

### Linkedlist semplici

### Linkedlist doppiamente concatenate

### Linkedlist circolari

### Operazioni sulle linkedlist
