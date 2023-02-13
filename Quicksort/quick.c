#include <stdlib.h>
#include <stdio.h>

//gcc -Wall -pedantic -Wno-unused-result -O2 quick.c -o quick

//Prototipagem das funçoes 
void troca (double *v, double *j);
int separa(double v[], int p, int r);
void quickSortR(double v[], int p, int r);
void testeQuick();


#define MAX 100

int main()
{
    char file_name[MAX];
    double **v, limiar;
    int n, k, i, j;
    FILE *entrada;
    int outlier = 0; //Conta numeros de outliers 

    scanf("%s", file_name);
    entrada = fopen(file_name, "r");

    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo!\n");
        exit(EXIT_FAILURE);
    }

    fscanf(entrada, "%d %d %lf", &n, &k, &limiar);
    v = (double **)malloc(n * sizeof(double *));
    for (i = 0; i < n; i++)
    {
        v[i] = (double *)malloc(n * sizeof(double));
        for (j = 0; j < n; j++)
            fscanf(entrada, "%lf", &v[i][j]);
    }
    fclose(entrada);

    for (i = 0; i < n; i++){
        quickSortR(v[i], 0, n-1);
        
        if (v[i][k+1] > limiar)
            outlier++;
    }
    
    printf("%d", outlier);
    
    for (i = 0; i < n; i++)
        free(v[i]);
    free(v);

    return 0;
}


void troca (double *v, double *j){
    double aux = *v;
    *v = *j;
    *j = aux; 
}

int separa(double v[], int p, int r) {
    int i, j, c = v[r]; // c é o pivô
    i = p;

    for (j = p; j < r; j++)
        if (v[j] <= c) {
            troca(&v[i], &v[j]);
            i++;
        }

    troca(&v[i], &v[r]);
    return i;
}

void quickSortR(double v[], int p, int r) {
    while (p < r) {              // se vetor corrente tem mais de um elemento
        int i = separa(v, p, r); // i é posição do pivô após separação
        quickSortR(v, p, i - 1);
        p = i + 1;
    }
}
