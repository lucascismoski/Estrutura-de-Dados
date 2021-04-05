#include <stdio.h>
#include "lcfl.h"

int main(){
    float *num1 = malloc(sizeof(float));
    float *num2 = malloc(sizeof(float));

    printf("Digite o primeiro numero real: ");
    scanf("%f", num1);

    printf("Digite o segundo numero real: ");
    scanf("%f", num2);

    printf("Soma dos dois numeros: %.2f", (*num1 + *num2));

    free(num1);
    free(num2);

    printaCopyRight();

    return 0;
}
