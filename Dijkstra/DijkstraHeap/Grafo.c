//Biblioteca
#include <stdlib.h>
#include <stdio.h>
#include "Grafo.h"


void lerGrafo(Grafo G){
    int v, w, peso;
 
    for (int i = 0; i < G -> m; i++){
        scanf("%d %d %d", &v, &w, &peso);
        insereArcoGrafo(G, v, w, peso);
    }
}

void imprimeGrafo(Grafo G){
    int i;
    Noh *p;
    printf("%d %d\n", G->n, G->m);
    for (i = 0; i < G->n; i++){
        printf("%d\n\n", i);
        for (p = G->A[i]; p != NULL; p = p->prox)
            printf("%2d -- %d\n", p->rotulo, p->custo);
        printf("\n");
    }
}

Grafo inicializaGrafo ( int n, int m ) {
    int i ;
    Grafo G = malloc (sizeof * G );
    G -> n = n ;
    G -> m = m ;
    G -> A = malloc ( n * sizeof( Noh *));
    for ( i = 0 ; i < n ; i ++)
        G -> A [i] = NULL ;
    return G ;
}
/* Insere arco v-w no grafo G, supondo que v e w são inteiros
distintos entre 0 e n-1. Se grafo já tem arco v-w, não faz nada. */
void insereArcoGrafo ( Grafo G , int v , int w, int custo ) {
    Noh * p ;
    for ( p = G -> A [v]; p != NULL ; p = p -> prox )
        if ( p -> rotulo == w )
            return ;
    p = malloc (sizeof( Noh ));
    p -> rotulo = w ;
    p -> custo = custo;
    p -> prox = G -> A [v];
    G -> A [v] = p ;
}
// Versão da insereArcoGrafo() que não testa se v-w já está presente
void insereArcoNaoSeguroGrafo ( Grafo G , int v , int w, int custo ) {
    Noh * p ;
    p = malloc (sizeof( Noh ));
    p -> rotulo = w ;
    p -> custo = custo;
    p -> prox = G -> A [v];
    G -> A [v]  = p ;
} 

// Libera a memória alocada para o grafo G e devolve NULL.
Grafo liberaGrafo ( Grafo G ) {
    int i ;
    Noh * p ;
    for ( i = 0 ; i < G -> n ; i ++) {
        p = G -> A [ i ];
        while ( p != NULL ) {
            G -> A [ i ] = p ;
            p = p -> prox ;
            free ( G -> A [ i ]);
        }
        G -> A [ i ] = NULL ;
    }
    free ( G -> A );
    G -> A = NULL;
    free ( G );
    return NULL ;
} 
