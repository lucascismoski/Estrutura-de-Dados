#include "lcfl.h"

int sucessor (int p_num) {
    return ++p_num;
};

int antecessor (int p_num) {
    return --p_num;
};

int soma (int x, int y) {
    if ( y == 0 ) {
        return x;
    }

    return soma(sucessor(x), antecessor(y));
}

void main(){
    int num1;
    int num2;

    printf("Digite o primeiro numero (somente positivos): ");
    scanf("%d", &num1);

    printf("Digite o segundo numero (somente positivos): ");
    scanf("%d", &num2);

    printf("Resultado: %d", soma(num1, num2));

    printaCopyRight();
}
