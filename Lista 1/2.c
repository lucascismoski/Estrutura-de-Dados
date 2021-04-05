#include <stdio.h>
#include <stdbool.h>
#include "lcfl.h"

bool eh_perfeito(int *numero){
    int *aux = (int *) malloc(sizeof(int));
    int *i   = (int *) malloc(sizeof(int));
    *aux = 0;

    for(*i=1; *i<*numero; *i = *i + 1){
        if(*numero%*i==0){
            *aux += *i;
        }
    }

    /*free(aux); deveria dar um free aq, mas zicaria meu retorno.
    Como o exercicio pede pra fazer apenas com ponteiro n tem outra forma..
    Não vejo necessidade de usar ponteiro nessa função.*/
    free(i);

    return *aux == *numero;
}

int main(){
    int *num = (int *) malloc(sizeof(int));

    printf("Digite um numero inteiro para verificar se eh perfeito: ");
    scanf("%d", num);

    if (eh_perfeito(num)){
        printf("O numero %d eh perfeito!", *num);
    }else{
        printf("O numero %d nao eh perfeito.", *num);
    }

    free(num);

    printaCopyRight();

    return 0;
}
