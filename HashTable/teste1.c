#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef char Chave;
typedef int Valor;



//dbj2 hash
unsigned long hash(Chave *chave, long M) {
    unsigned long hash = 5381;
    int c;

    while ((c = *chave++))
        hash = (((hash << 5) + hash) - 13*c) % M; 
    return hash;
}


int main(){
    char nome[11];
    long resultado;
    char saida = '0';
    do {
    scanf("%s", nome);
    resultado = hash(nome,100000004);
    if (resultado > 100000004 || resultado < 0){
        printf("ERRO\n");
        printf("%ld\n", resultado);
    }
    else 
        printf("%ld\n",resultado);
    } while (strcmp(nome, &saida) != 0);


    // long resultado = hash(nome);
    // printf("%ld", resultado);
}