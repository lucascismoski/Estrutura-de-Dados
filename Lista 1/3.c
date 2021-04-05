#include <stdio.h>
#include "lcfl.h"

int recebe_numeros(int *num_componentes, int *n){
    int *i = (int *) malloc(sizeof(int));
    int *maior_num = (int *) malloc(sizeof(int));
    int *aux = (int *) malloc(sizeof(int));

    *maior_num = 0;

    for(*i=0; *i<*num_componentes; *i=*i+1){
        printf("Digite o numero %d: ", *i+1);
        scanf("%d", aux);

        *(n+*i) = *((int*)aux);

        if( *(n+*i) > *maior_num ){
            *maior_num = *(n+*i);
        }
    }

    free(i);
    free(aux);
    //free(maior_num);

    return *maior_num;
}

void main(){
    int *num_componentes = (int *) malloc(sizeof(int));

    printf("Digite a quantidade de numeros para alocar: ");
    scanf("%d", num_componentes);

    void *n = malloc(sizeof(int) * *num_componentes);

    *num_componentes = recebe_numeros(num_componentes, n);
    printf("Maior numero: %d", *num_componentes);

    free(num_componentes);
    free(n);

    printaCopyRight();

    return 0;
}
