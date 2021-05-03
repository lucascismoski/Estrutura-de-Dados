#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaLinear/Lista.h"
#include "Utils.h"

void imprimeInteiros (void *info){
    printf("[%d] ", *((int*)info));
}

void imprimirFila(pDFila pd, FuncaoImpressao pfi){
    imprimirLista(pd->pdLista, pfi);
}

pDFila fatoracaoPrima(int n){
    pDFila fila = criarFila();

    int i;
    int quociente = n;

    while (quociente != 1) {
        for (i=2;i<=quociente;i++){
            if((quociente%i) == 0){
                quociente = quociente/i;
                enfileirarInfo(fila, alocaInt(i));

                break;
            }
        }
    }

    return fila;
}

void main(){
    pDFila fila;

    FuncaoImpressao funcaoImprimirFila = &imprimeInteiros;

    fila = fatoracaoPrima(630);

    printf("Fila gerada......: ");
    imprimirFila(fila, funcaoImprimirFila);

    printf("\n##O nosso lema eh ousadia e alegria");
}
