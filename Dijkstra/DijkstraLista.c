//NÃO ESTA FUNCIONANDO DIREITO
//2 DE 5 CASO DE TESTES FUNCIOANDO

//Aluno: Yan Gimenez Borges
//RA: 769826
//Matéria: AED2
 
//gcc -Wall -pedantic -O2 -Wno-unused-result -O2 DijkstraLista.c -o DijkstraLista

//Biblioteca
#include <stdlib.h>
#include <stdio.h>

const int INF = __INT_MAX__/2;


//struct da lista do grafo 
typedef struct noh Noh; 
struct noh {
    int rotulo;
    int custo;
    Noh *prox;
};

//struct do grafo
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

void Dijkstra(Grafo G, int origem, int *dist, int *pred);

int main()
{
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    int dist[n], pred[n];

    Grafo G = inicializaGrafo(n, m);
    lerGrafo(G);
    //imprimeGrafo(G);
    Dijkstra(G, 0, dist, pred);
    printf("%d\n", dist[n-1]);

    liberaGrafo(G);

    return 0;
}

void Dijkstra ( Grafo G , int origem , int * dist , int * pred ) {
    int i , *R ;
    int v , w , custo , tam_R , min_dist ;
    Noh *p ;
    // inicializando distâncias e predecessores
    for ( i = 0 ; i < G -> n ; i ++) {
        dist [ i ] = INF;
        pred [ i ] = - 1 ;
    }
    dist [ origem ] = 0 ;
    // inicializando conjunto de vértices "resolvidos" R
    R = malloc ( G -> n * sizeof( int ));
    for ( i = 0 ; i < G -> n ; i ++)
        R [ i ] = 0 ;
    tam_R = 0 ;
    // enquanto não encontrar o caminho mínimo para todo vértice
    while ( tam_R < G -> n ) {
    // buscando vértice v em V \ R que minimiza dist[v]
        min_dist = INF ;
        v = - 1 ;
        for ( i = 0 ; i <= G -> n ; i ++)
            if ( R [ i ] == 0 && dist [ i ] < min_dist ) {
                v = i ;
                min_dist = dist [ i ];
            }
        // adicionando v a R e atualizando o conjunto R
        R [ v ] = 1 ; tam_R ++;
        // percorrendo lista com vizinhos de v
        for ( p = G -> A [ v ]; p != NULL; p = p -> prox ) {
            w = p -> rotulo ;
            custo = p -> custo ;
            // e atualizando as distâncias e predecessores quando for o caso
            if ( R [ w ] == 0 && dist [ w ] > dist [ v ] + custo ) {
                dist [ w ] = dist [ v ] + custo ;
                pred [ w ] = v ;
            }
        }
    }
    free ( R );
} 

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