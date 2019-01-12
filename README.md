# Linked List
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
    1. [Struct](#struct)
1. [Linked List vs Array](#linked-list-vs-array)
1. [Tipi di Linked List](#tipi-di-linked-list)
    1. [Linked List semplici](#linked-list-semplici)
    1. [Linked List doppiamente concatenta](#linked-list-doppiamente-concatenate)
    1. [Linked List circolari](#linked-list-circolari)
1. [Operazioni sulle Linked List](#operazioni-sulle-linked-list)

## Introduzione

Per poter utilizzare correttamente le liste(`Linked List`), occorre saper utilizzare i `puntatori` e le struct ( `record` ). Le linked list, sono il frutto di una combinazione di puntatori e record. A causa della loro flessibilità e facilità su alcune operazioni di gestione, rappresentano una struttura molto importante in alcuni ambiti;

### Puntatori

I puntatori, essenzialmente possono essere considerti come delle normali variabili, il cui contenuto però è costituito da un indirizzo di memoria.

`<tipo> *<nomeVariabile>`

Una variabile puntatore, può puntare unicamente ad una variabile che concorda con il tipo del puntatore stesso;

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
- Un indirizzo di memoria di una variabile o struct, mediante l'operatore `&`;
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
Anche quando si utilizzano gli array, inconsapevolmente si sta utilizzando un pontatore. Il nome di un array, non è altro che un puntatore, il quale punta al primo elemento dell'array. Quando si accede ad un elemento dell'array, tramite il suo indice, non facciamo altro che eseguire un'operazione di deferenziazione su un puntatore che punta ad una locazione di memoria dove è contenuto il valore desiderato. La stessa operazione, che facciamo mediante l'indicazione dell'indice dell'array, può essere fatta anche attraverso l'utilizzo dell'algebra dei puntatori:

```c
int A[10] = {0,1,2,3,4,5,6,7,8,9};
int i = 0;
    for(i=0;i<10;i++){
        printf("A[%i] = %i\n",i,A[i] );
    }

    /* Potremmo scrivere in modo simile */

    for(i=0;i<10;i++){
        printf("A[%i] = %i\n",i, * (A+i) );
    }
```
La forma `(A+i)`, presuppone che l'indice `i`, come avviene anche per gli array, sia un valore intero;

Inoltre, dal momento che il contenuto di un puntatore, non è altro che l'indirizzo di memoria della variabile puntata, durante le operazioni di input, il puntatore non va indicato nella forma `&P`, ma va indicato come `P`.

```c
int a = 0;
int *P = &a;

    scanf("%i\n",p);
```
In tal caso, il valore in input verrà assegnato alla variabile a; Durante un'operazione di output invece, la variabile puntatore verrà indicata come `*p` per poter stampare il contenuto della variabile a.

La dichiarazione di un puntatore, comporta l'allocazione di memoria per la variabile puntatore, ma non per la variabile puntata.

### Struct

Gli `struct`, conosciuti anche come `record`, sono un tipo di struttura dati, che
permette di contenere dati di diversa natura. Attraverso l'utilizzo di una
struct, possiamo definire un elenco di variabili, anche di tipo diverso, che possono
essere raggruppate in un unico blocco di memoria e accessibili con un singolo puntatore.

Nel linguaggio **C**, una struct fa direttamente riferimento ad un blocco contiguo di memoria fisica.

```c
    struct [nomeStruct]{
        Member definition;
        Member definition;
        .................
        Member definition;
    }[Una o pi&ugrave; variabili];
```
Una struct pu&ograve; essere dichiarata in varie parti del corpo del codice e in vari modi. Se la dichiaro
all'interno del main o all'interno di una procedura, essa sar&agrave; visibile solo all'interno del suo scope.
Una struct pu&ograve; essere dichiarata come tipo unico, oppure andare a costituire un nuovo tipo di variabile
essa stessa.
```c
    struct {
        char nome[10];
        char cognome[10];
        int eta;
    } persona;
```
In questo caso, abbiamo dichiarato una variabile di tipo struct che ha come nome `persona`, nel caso in cui, ci serve un altra variabile dello stesso tipo, dovremmo riscrivere l'intero codice.
```c
    struct persona {
        char nome[10];
        char cognome[10];
        int eta;
    };
```
In questo secondo caso, non abbiamo dichiarato nessuna nuova variabile, ma abbiamo definito solo un nuovo tipo di variabile, che se definito all'esterno delle funzioni, e quindi con scope `globale`, potremmo facilmente dichiarare
nuove variabili di quel tipo, ovunque esse servono, all'interno del nostro codice.

In tal caso, la dichiarazione di una variabile di tipo `persona` avviene attraverso la sintassi
```c
    struct persona padre;
    struct persona figlio;
```
L'accesso alle singole varibili della struct avviene in due modi diversi, a seconda di come la struct viene utilizzata. Nel caso del semplice utilizzo della struct, oppure quando la si utilizza come un array, l'accesso avviene mediante la `Dot notation`, ovvero attraverso l'operatore `.`;
```c
    padre.nome = "Mario";
    padre.cognome = "Rossi";
    padre.eta = 40;
```
Non &egrave; possibile definire struct ricorsive, ovvero struct che contengono la stessa struct
```c
struct persona {
    char nome[10];
    char cognome[10];
    int eta;
    struct persona F;
    /* Ciò rappesenta un errore, a meno che F non sia un puntatore ad un'altra struct dello stesso tipo*/
};
```
&Egrave; tuttavia possibile inserire all'interno di una struct, altre struct di diversa natura;

La definizione di una struct, non comporta allocazione di memoria. L'allocazione della memoria avverra solo a seguito della dichiarazione della variabile di tipo struct:

```c
    struct persona {
        char nome[10];
        char cognome[10];
        int eta;
    };
    /* non ho ancora allocato memoria per la variabile interessata */

    struct persona padre; //ho allocato memoria per la variabile padre, di tipo persona
```
L'utilizzo delle struct, permette di poter definire pi&ugrave; informazioni le quali saranno contenute tutte in un unico contenitore. In tal caso per&ograve; ogni variabile di tipo struct, in memoria avr&agrave; un peso che è equivalente alla somma del peso delle singole tipologie di tipi che la compongono.

Un classico esempio del perch&egrave; si rende conveniente l'utilizzo delle strutture, &egrave; quello di una rubrica. Si pensi di voler memorizzare per ogni contatto:
    - Nome
    - Cognome
    - Cellulare
nel caso in cui non ci fossero le strutture, dovremmo andare ad utilizzare e quindi gestire, tre variabili completamente separate ed indipendenti l'una dall'altra. Con le struct, invece possiamo creare un tipo di variabile che andr&agrave; a contenere tutte le informazioni che ci interessano;

```c
struct contatto{
    char nome[32];
    char cognome[32];
    char telefono[11]; //i numeri telefonici conviene gestirli come stringhe;
}
```

## Linked List vs Array
Le struct, possono essere utilizzate anche come array, ottenendo cosi un `array di struct`. A tal punto viene da chiedersi perch&egrave; introdurre le liste, se possiamo utilizzare gli array per ottenere il medesimo risultato?

In effetti entrambe le implementazioni consentono di ottenere gli stessi risultati, ma con metodologie differenti e, nel caso delle linked list, risultano facilitate le operazioni di inserimento e di rimozione dei vari oggetti che compongono la lista.
Entrambe le metodologie possiedono tuttavia sia pro che contro.

Tipo | Pro | Contro
---- | --- | ------
Array | L'accesso ai singoli elementi sella lista pu&ograve; avvenire in modo diretto o sequenziale, indicando l'indice dell'elemento. | Nelle operazioni di inserimento e rimozione degli elementi, per posizionarli occorre spesso eseguire un'opeazione di shift sugli elementi gi&agrave; presenti;
Array | - | Il numero massimo di oggetti che possono essere inseriti, deve essere stabilito in precedenza, sin dal momento della compilazione del software;
Linked List | Nelle operazioni di inserimento o rimozione dei singoli elementi, non occorre eseguire alcuna operazione di shift sugli elementi già presenti, ma solo cambiare i puntatori agli elementi successivi e precedenti; | L'accesso ai singoli elementi non pu&ograve; avvennire in modo diretto, ma solo in modo sequenziale;
Linked List | - | Non &egrave; necessario stabilire un numero massimo di elementi, infatti tale valore &egrave; strettamente legato alla memoria disponibile sulla macchina, in cui &egrave; in esecuzione il programma;

Le linked list, sono anpiamente utilizzate proprio per la loro facilità di gestione, nonostante la realizzazione pu&ograve; risultare a prima vista pi&ugrave; ardua, la gestione ne risulta pi&ugrave; facile; prendendo come esempio una semplice rubrica, contenente nome e numero di telefono per ogni contatto, con una stuttura del genere:

```c
struct contatto{
    char nome[32];
    char telefono[11]; //i numeri telefonici conviene gestirli come stringhe;
}
```
Andando a gestirla come array, abbiamo che, nel caso in cui vogliamo inserire un nuovo contatto, pensando di avere alti contatti gi&agrave; presenti, per mantenere i contatti nel giusto ordine alfabetico, nel caso in cui il contatto deve essere inserito nel mezzo della lista, occorre individuare la giusta posizione, spostare di una posizione, tutti gli elementi da quel punto in poi e infine, inserire il nuovo contatto. Tale situazione verrebbe a verificarsi anche nel caso in cui l'elemento deve essere aggiunto in testa alla lista.

Gestendo invece la rubrica come linked list, sempre nel caso in cui il nuovo contatto va inserito in mezzo alla lista, occorrer&agrave; individuare la giusta posizione, creare il nuvo elemento, e successivamente modificare i puntatori dell'emento precedente, dell'elemento appena creato e, se necessario dell'elemento successivo. Senza eseguire alcuna operazione di shift.

## Tipi di Linked List
Si possono individuare vari tipi di linked list, ognuna delle quali, presenta alcune caratteristiche differenti; Tuttavia esse presentano le medesime caratteristiche. Per l'utilizzo delle linked list, occorre necessariamente, poter individuare tre cose che risultano essere fondamenti:
- Quale sia il primo elemento della lista;
- Quale sia l'elemento successivo;
- L'ultimo elemento della lista;

*In particolar modo, il primo elemento della lista, deve sempre essere conosciuto in precedenza.*

### Linked List semplici

### Linked List doppiamente concatenate

### Linked List circolari

### Operazioni sulle Linked List
