//Biblioteca
#include <stdlib.h>
#include <stdio.h>
#include "Heap.h"

//heap
#define PAI(i) (i - 1) / 2
#define FILHO_ESQ(i) (2 * i + 1)
#define FILHO_DIR(i) (2 * i + 2)


void troca(Elem *a, Elem *b) {
    Elem aux = *a;
    *a = *b;
    *b = aux;
}
void troca_pos(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// sobe o elemento em v[pos_elem_v] até restaurar a prop. do heap
void sobeHeap(Elem v[], int pos_v[], int pos_elem_v) {
    int f = pos_elem_v;
    while (f > 0 && v[PAI(f)].chave > v[f].chave) {
        troca(&v[f], &v[PAI(f)]);
        troca_pos(&pos_v[v[f].conteudo], &pos_v[v[PAI(f)].conteudo]);
        f = PAI(f);
    }
}
int insereHeap(Elem v[], int pos_v[], int m, Elem x) {
    v[m] = x;
    sobeHeap(v, pos_v, m);
    return m + 1;
}
// desce o elemento em v[pos_elem_v] até restaurar a prop. do heap
void desceHeap(Elem v[], int pos_v[], int m, int pos_elem_v) {
    int p = pos_elem_v, f;
    while (FILHO_ESQ(p) < m && (v[FILHO_ESQ(p)].chave < v[p].chave
    || (FILHO_DIR(p) < m && v[FILHO_DIR(p)].chave < v[p].chave))) {
        f = FILHO_ESQ(p);
        if (FILHO_DIR(p) < m && v[FILHO_DIR(p)].chave < v[f].chave)
            f = FILHO_DIR(p);
        troca(&v[p], &v[f]);
        troca_pos(&pos_v[v[p].conteudo], &pos_v[v[f].conteudo]);
        p = f;
    }
}
int removeHeap(Elem v[], int pos_v[], int m, Elem *px) {
    *px = v[0];
    troca(&v[0], &v[m - 1]);
    troca_pos(&pos_v[v[0].conteudo], &pos_v[v[m - 1].conteudo]);
    desceHeap(v, pos_v, m, 0);
    return m - 1;
}
void atualizaHeap(Elem v[], int pos_v[], Elem x) {
    int pos_x_v = pos_v[x.conteudo]; // pega a posição de x em v
    v[pos_x_v].chave = x.chave; // atualiza a chave de x em v
    sobeHeap(v, pos_v, pos_x_v);
}