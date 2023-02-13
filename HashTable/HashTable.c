// Nome: Yan Gimenez Borges
// RA: 769826
// Curso: Engenharia de Computacao
// Algoritmos e Estrutura de Dados 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//gcc -Wall -Wno-unused-result -O2 -pedantic HashTable.c -o HashTable

typedef char Chave;
typedef int Valor;



typedef struct celTS {
    Chave chave[11];    //Nome da pessoa 
    Valor valor;        //Telefone 
    struct celTS *prox; //Apontador pra celula seguinte 
}CelTS;

static CelTS **tab = NULL;
static int nChaves = 0;
static unsigned long M; // tamanho da tabela

//Cria o vetor pra hash
void stInit(long max) {
    int h;
    M = max;
    nChaves = 0;
    tab = malloc(M * sizeof(CelTS *));
    for (h = 0; h < M; h++)
        tab[h] = NULL;    
}

//dbj2
unsigned long hash(Chave *chave, long M) {
    unsigned long hash = 5381;
    int c;

    while ((c = *chave++))
        hash = (((hash << 5) + hash) - 13*c) % M; 
    return hash;
}


//Funçao de busca
Valor stSearch(Chave *chave) {
    CelTS *p;
    unsigned long h = hash(chave, M);
    p = tab[h];

    while (p != NULL && strcmp(p->chave, chave) != 0)
        p = p->prox;
    if (p != NULL) // se encontrou devolve o valor
        return p->valor;   
    return -1; 
}

//Funçao de inserçao  
int stInsert(Chave *chave, Valor valor) { 
    CelTS *p;
    unsigned long h = hash(chave, M);
    p = tab[h];

    while (p != NULL && strcmp(p->chave, chave))
        p = p->prox;
    if (p == NULL) { // se não encontrou insere no início da lista
        p = malloc(sizeof(*p));
        strcpy(p->chave, chave);
        p->valor = valor; 
        nChaves += 1;
        p->prox = tab[h];
        tab[h] = p;
        return 1;
    }
    else { // (p != NULL) Encontrou a chave 
        return 0;
    }
}

//Funçao de ediçao 
int stEdit(Chave *chave, Valor valor){
    CelTS *p;
    unsigned long h = hash(chave, M);
    p = tab[h];  

    while (p != NULL && strcmp(p->chave, chave))
        p = p->prox;
    if (p != NULL){ //p->chave == chave 
        p->valor = valor;  //atualiza o valor do item 
        tab[h] = p;
        return 1; 
    }
    else { //Não achou a chave 
        return 0;    
    }     
}

//Funçao de Exclusao
int stDelete(Chave *chave) {
    CelTS *p, *aux;
    unsigned long h = hash(chave, M);
    p = tab[h];

    if (p == NULL) {// se lista esta vazia nao tem o que remover
        return 0;
    }
    if (strcmp(p->chave, chave) == 0) { // remoção na cabeça da lista
        tab[h] = p->prox;
        // free(p->chave);
        free(p);
        nChaves--;
        return 1;
    }
    // remoção no restante da lista
    while (p != NULL && strcmp((p->prox)->chave, chave) != 0)
        p = p->prox;
    if (p->prox != NULL) { // se o próximo é o valor por remover
        aux = p->prox;
        p->prox = aux->prox;
        // free(aux->chave);
        free(aux);
        nChaves--;
        return 1;
    }
    return 0;
}

//Funçao para excluir a tabela 
void stFree() {
    CelTS *p = NULL;
    CelTS *q = NULL;
    int h;

    for (h = 0; h < M; h++) { // libera cada lista
        p = tab[h];
        while (p != NULL) {
            q = p;
            p = p->prox;
            // free(q->chave); // liberando a chave (string) da célula
            free(q); // antes de liberar a célula
        }
    }   
    free(tab); // então libera a tabela
    tab = NULL;
    nChaves = 0;
}

int main()
{   
    stInit(10000004);

    char operador, nome[11];
    int telefone;
    
    do {
        scanf("%c", &operador);
        if (operador == 'P'){     //Busca
            scanf("%s", nome);
            int a = stSearch(nome);
            if (a != -1) 
                printf("Contatinho encontrado: telefone %d\n", a);
            else 
                printf("Contatinho nao encontrado\n");    
        }
        else if (operador == 'I'){  // Insercao
            scanf("%s", nome);
            scanf("%d", &telefone);
            int b = stInsert(nome, telefone);
            if (b == 0)
                printf("Contatinho ja inserido\n");    
        } 
        else if (operador == 'A'){  //Edicao
            scanf("%s", nome);
            scanf("%d", &telefone);
            int c = stEdit(nome, telefone);
            if (c == 0)
                printf("Operacao invalida: contatinho nao encontrado\n");
        }
        else if (operador == 'R'){  //Remocao
            scanf("%s", nome);
            int d = stDelete(nome);
            if (d == 0)
                printf("Operacao invalida: contatinho nao encontrado\n");
        }
    }while (operador != '0');

    stFree();

    return 0;
}

