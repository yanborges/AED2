/* Daniela Mika Yamaji
RA: 769686
Engenharia de Computação*/

#include <stdio.h>
#include <stdlib.h>
// #include <values.h>

const int INF = __INT_MAX__/2;

typedef struct grafo
{
    int **A, v, e;

} *grafo;

grafo inicializa (int n){ // ok
    int i, j;
    grafo g = malloc(sizeof*g);
    (*g).v = n;
    (*g).e = 0;
    (*g).A = malloc(n*sizeof(int*));
    for (i = 0; i < n; i++)
        (*g).A[i] = malloc(n*sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++){
            if (i != j)
                (*g).A[i][j] = INF;
            else 
                (*g).A[i][j] = 0;
        }
    return g;
    
}

void insere(grafo g, int aresta){ // ok
    int peso, a, b;
    for (int i = 0; i < aresta; i++){
        //printf("a b peso: ");
        scanf("%d %d %d", &a, &b, &peso);
        if ((*g).A[a][b] == INF){ 
            (*g).A[a][b] = peso;
            (*g).e++;
        }
    }
}

grafo libera(grafo g){ // ok
    for (int i = 0; i < (*g).v; i++){
        free((*g).A[i]);
        (*g).A[i] = NULL;
    }
    free((*g).A);
    (*g).A = NULL;
    free(g);
    return NULL;
}

void menor(grafo g, int n){
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((*g).A[i][j] > (*g).A[i][k] + (*g).A[k][j])
                    (*g).A[i][j] = (*g).A[i][k] + (*g).A[k][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (i == 0 && j == n - 1)
            printf("%d\n", (*g).A[i][j]);
    }
    
}


int main(){
    int v, aresta;
    //printf("vertices e arestas: ");
    scanf("%d %d", &v, &aresta);
    grafo G = inicializa(v);
    insere(G, aresta);
    menor(G, v);
    libera(G);

}