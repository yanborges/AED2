#include <stdio.h>
#include <stdlib.h>
#include <time.h>

clock_t stime, etime;
double cpu_time_used;

//Para compilar o programa em c:
//gcc -Wall -pedantic -O2 -Wno-unused-result twoSum_basico.c -o twoSum_basico

void imprime(int v[], int n){
    int i;
    for ( i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int twoSumBruteForce(int v[], int n, int alvo){
    int i,j;

    // testa todos os pares
    for (i = 0; i < n; i++){
        for (j = i + 1; j < n; j++){
            if (v[i] + v[j] == alvo)
                return 1;
        }
    }
    return 0;
}

int twoSumLinearSearch(int v[], int n, int alvo){
    int i, j, compl;

    for(i = 0; i < n; i++){
        compl = alvo - v[i];
        
        // busca linear pelo complemento
        for (j = i + 1; j < n; j++)
            if (v[j] == compl)
                return 1;   
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int i, n, achou;
    int *v;
    
    if (argc != 2){
        printf("Numero inncorreto de parametros. Tente \".\\twoSum_basico 10\" ");
        exit(0);
    }

    // Transforma string em int
    n = atoi(argv[1]);
    v = (int *)malloc(n * sizeof(int));

    // preenche o vetor com pares não negativos 
    for(i = 0; i < n; i++)
        v[i] = 2 * i;
    // imprime(v, n);
    // printf("\n");

    printf("Testando metodo twoSumBruteForce\n");
    stime = clock();
    achou = twoSumBruteForce(v, n, 9);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;
    if (achou == 1)
        printf("Encontrou um par que soma 9 em %lf segundos\n", cpu_time_used);
    else 
        printf("Não encontrou um par que soma 9 em %lf segundos\n", cpu_time_used);
    printf("\n");    
   

    printf("Testando metodo twoSumLinearSearch\n");
    stime = clock();
    achou = twoSumLinearSearch(v, n, 9);
    etime = clock();
    cpu_time_used = ((double)(etime-stime)) / CLOCKS_PER_SEC;
    if (achou == 1)
        printf("Encontrou um par que soma 9 em %lf segundos\n", cpu_time_used);
    else 
        printf("Não encontrou um par que soma 9 em %lf segundos\n", cpu_time_used);
    printf("\n");   


    return 0;
}
