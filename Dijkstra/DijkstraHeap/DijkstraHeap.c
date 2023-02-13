//Aluno: Yan Gimenez Borges
//Matéria: AED2

// gcc -Wall -pedantic -O2 -Wno-unused-result -O2 DijkstraHeap.c -o DijkstraHeap
//.\Dijkstra para utilizar 

//Biblioteca
#include <stdlib.h>
#include <stdio.h>
#include "Heap.c"
#include "Grafo.c"


void DijkstraHeap(Grafo G, int origem, int *dist, int *pred);

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int dist[n], pred[n];
    Grafo G = inicializaGrafo(n, m);
    lerGrafo(G);
    DijkstraHeap(G, 0, dist, pred);
    printf("%d\n", dist[n-1]);
    liberaGrafo(G);
    return 0;
}

//Dijkstra
void DijkstraHeap(Grafo G, int origem, int *dist, int *pred) {
    int i, *pos_H;
    Elem *H, elem_aux;
    int v, w, custo, tam_H;
    Noh *p;

    // inicializando distancias e predecessores
    for (i = 0; i < G->n; i++) {
        dist[i] = __INT_MAX__;
        pred[i] = -1;
    }
    dist[origem] = 0;

    // criando um min heap em H com vetor de posições pos_H
    H = malloc(G->n * sizeof(Elem));
    pos_H = malloc(G->n * sizeof(int));
    for (i = 0; i < G->n; i++) {
        H[i].chave = dist[i]; // chave é a "distância" do vértice
        H[i].conteudo = i; // conteudo é o rótulo do vértice
        pos_H[i] = i; // vértice i começa na posição i do heap H
    }

    troca(&H[0], &H[origem]); // coloca origem no início do heap H
    troca_pos(&pos_H[0], &pos_H[origem]); // atualiza posição dos vértices
    tam_H = G->n;

    // enquanto não encontrar o caminho mínimo para todo vértice
    while (tam_H > 0) {
    // buscando vértice v que minimiza dist[v]
        tam_H = removeHeap(H, pos_H, tam_H, &elem_aux);
        v = elem_aux.conteudo;
        // percorrendo lista com vizinhos de v
        p = G->A[v];
        while (p != NULL) {
            w = p->rotulo;
            custo = p->custo;
            // e atualizando as distâncias e predecessores quando for o caso
            if (dist[w] > dist[v] + custo) {
                dist[w] = dist[v] + custo;
                pred[w] = v;
                elem_aux.chave = dist[w];
                elem_aux.conteudo = w;
                atualizaHeap(H, pos_H, elem_aux);
            }
            p = p->prox;
        }
    }
    free(H);
    free(pos_H);
}



