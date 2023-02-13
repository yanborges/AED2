//Biblioteca
#include <stdlib.h>
#include <stdio.h>

//struct do grafo ponderado
typedef struct noh Noh; 
struct noh {
    int rotulo;
    int custo;
    Noh *prox;
};

//struct do vetor apontando pro grafo
typedef struct grafo {
 Noh ** A ;
 int n ; // número de vértices
 int m ; // número de arestas/arcos
} *Grafo; 

//Prototipação Grafos
Grafo inicializaGrafo ( int n, int m );
void insereArcoGrafo ( Grafo G , int v , int w, int custo );
void insereArcoNaoSeguroGrafo ( Grafo G , int v , int w, int custo );
void imprimeGrafo ( Grafo G );
Grafo liberaGrafo ( Grafo G ); 
void lerGrafo();