//Biblioteca
#include <stdlib.h>
#include <stdio.h>

//struct do heap 
typedef struct elem {
    int chave; // vamos guardar dist aqui
    int conteudo; // vamos guardar o vértice aqui
} Elem;

//Prototipaçao Heap e dijkstra
void troca(Elem *a, Elem *b);
void troca_pos(int *a, int *b);
void sobeHeap(Elem v[], int pos_v[], int pos_elem_v);
int insereHeap(Elem v[], int pos_v[], int m, Elem x);
void desceHeap(Elem v[], int pos_v[], int m, int pos_elem_v);
int removeHeap(Elem v[], int pos_v[], int m, Elem *px);
void atualizaHeap(Elem v[], int pos_v[], Elem x);