#include <stdio.h>
#include "Lista.h"
#include "Utils.h"


int pow(int base, int expoente){
    if(expoente == 0)
        return 1;
    else {
        int acc = base;
        expoente--;
        while(expoente > 0){
            acc = acc * base;
            expoente--;
        }
        return acc;
    }
}

struct Inteiros {
    int coeficiente;
    int base;
    int expoente;
};

void imprimeInteiros (void *info){
    struct Inteiros *pd = (struct Inteiros *) info;
    printf("[%d] [%d] [%d] - ", pd->coeficiente,pd->base,pd->expoente);
}

struct Inteiros* alocaInteiros (int coeficiente, int base, int expoente){
    struct Inteiros *pd = (struct Inteiros *) malloc(sizeof(struct Inteiros));
    pd->coeficiente = coeficiente;
    pd->base = base;
    pd->expoente = expoente;
    return pd;
};

int decompoeInteiros(pDLista *pd, int valorAtual, int expoente){
    if (valorAtual != 0) {
        int resto = valorAtual%(10*(int)pow(10,expoente));
        valorAtual = valorAtual - resto;
        incluirInfoInicio(pd, alocaInteiros(resto/(int)pow(10,expoente), 10, expoente));

        decompoeInteiros(pd, valorAtual, expoente+1);
    }

}

void main(){
    pDLista minhaLista;

    FuncaoImpressao funcaoImprimir = &imprimeInteiros;

    minhaLista = criarLista();

    decompoeInteiros(minhaLista, 7352, 0);

    imprimirLista(minhaLista, funcaoImprimir);
}
