#include "lcfl.h"

int main(){
    int *num = (int *) malloc(sizeof(int));
    void *p1;
    float *soma = (float *) malloc(sizeof(float));

    *((float*)soma) = 0;



    printf("Selecione um tipo de dado para o primeiro numero. [1] Inteiro (Default), [2] Real: ");
    scanf("%d", num);

    if (*num = 2) {
        p1 = malloc(sizeof(float));

        printf("Digite um valor para o primeiro numero: ");
        scanf("%f", p1);

        *soma += *((float*)p1);

        free((float*)p1);
    } else {
        p1 = malloc(sizeof(int));

        printf("Digite um valor para o primeiro numero: ");
        scanf("%d", p1);

        *soma += *((int*)p1);

        free((int*)p1);
    }




    printf("Selecione um tipo de dado para o segundo numero. [1] Inteiro (Default), [2] Real: ");
    scanf("%d", num);

    if (*num = 2) {
        p1 = malloc(sizeof(float));

        printf("Digite um valor para o segundo numero: ");
        scanf("%f", p1);

        *soma += *((float*)p1);

        free((float*)p1);
    } else {
        p1 = malloc(sizeof(int));

        printf("Digite um valor para o segundo numero: ");
        scanf("%d", p1);

        *soma += *((int*)p1);

        free((int*)p1);
    }



    printf("Soma: %.2f", *soma);

    free(num);
    free(soma);

    printaCopyRight();
}
