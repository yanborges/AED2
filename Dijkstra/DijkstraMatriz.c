// Aluno: Yan Gimenez Borges
// RA: 769826
// AED2 Eng comp;

//gcc -Wall -pedantic -O2 -Wno-unused-result DijkstraMatriz.c -o DijkstraMatriz

#include <stdio.h>
#include <stdlib.h>

const int INF = __INT_MAX__/2;

typedef struct grafo{
    int **A;
    int vertice;
    int aresta;
} *Grafo;

Grafo inicializaGrafo (int n);
void insereArcoGrafo(Grafo G, int aresta);
Grafo liberaGrafo(Grafo G);
void menorCaminho(Grafo G, int n);

int main(){
    int vertice, aresta;
    scanf("%d %d", &vertice, &aresta);
    Grafo G = inicializaGrafo(vertice);
    insereArcoGrafo(G, aresta);
    menorCaminho(G, vertice);
    liberaGrafo(G);
}

Grafo inicializaGrafo (int n){ // ok
    int i, j;
    Grafo G = malloc(sizeof*G);
    G->vertice = n;
    G->aresta = 0;
    G->A = malloc(n*sizeof(int*));
    for (i = 0; i < n; i++)
        G->A[i] = malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            if (i != j)
                G->A[i][j] = INF;
            else 
                G->A[i][j] = 0;
        }
    return G;
    
}

void insereArcoGrafo(Grafo G, int aresta){ // ok
    int peso, i, j;
    for (int k = 0; k < aresta; k++){
        //printf("a b peso: ");
        scanf("%d %d %d", &i, &j, &peso);
        if (G->A[i][j] == INF){ 
            G->A[i][j] = peso;
            G->aresta++;
        }
    }
}

Grafo liberaGrafo(Grafo G){ // ok
    for (int i = 0; i < G->vertice; i++){
        free(G->A[i]);
        G->A[i] = NULL;
    }
    free(G->A);
    G->A = NULL;
    free(G);
    return NULL;
}

void menorCaminho(Grafo G, int n){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (G->A[i][j] > G->A[i][k] + G->A[k][j])
                    G->A[i][j] = G->A[i][k] + G->A[k][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (i == 0 && j == n - 1)
            printf("%d\n", G->A[i][j]);
    }
}


