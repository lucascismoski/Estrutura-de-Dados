#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaLinear/Lista.h"
#include "Utils.h"

int ehMaior(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;

    if (*p1 > *p2){
        //printf("\nretornando 1: %d e %d", *p1, *p2);
        return 1;
    } else {
        //printf("\nretornando 0: %d e %d", *p1, *p2);
        return 0;
    }
}

void imprimeInteiros (void *info){
    printf("[%d] ", *((int*)info));
}

void imprimirFila(pDFila pd, FuncaoImpressao pfi){
    imprimirLista(pd->pdLista, pfi);
}

struct Par {
    int num1;
    int num2;
};

struct Par* alocaPar (int num1, int num2){
    struct Par *pd = (struct Par *) malloc(sizeof(struct Par));
    pd->num1 = num1;
    pd->num2 = num2;

    return pd;
};

void imprimePar (void *info){
    struct Par *pd = (struct Par *) info;
    printf("[%d][%d] ", pd->num1,pd->num2);
}

pDLista NGE (pDFila fila, FuncaoComparacao pfc){
    pDLista lista = criarLista();

    pNoh aux;
    pNoh aux2;
    aux = fila->pdLista->primeiro;

    while(aux != NULL){
        //printf("\nteste 1");
        int *maiorNumeroHolder = (int *) malloc(sizeof(int));
        int *numeroAtual = (int *) malloc(sizeof(int));

        *maiorNumeroHolder = -1;
        *numeroAtual = *((int*)aux->info);

        aux2 = aux;

        while(aux2 != NULL){
            //printf("\nteste 2");
            if (pfc(aux2->info, numeroAtual) == 1) {
                maiorNumeroHolder = aux2->info;
                break;
            } ;

           aux2 = aux2->prox;
        }

        incluirInfo(lista, alocaPar(*numeroAtual, *maiorNumeroHolder));

        aux = aux->prox;
    }

    return lista;
}

void main(){
    pDFila fila;
    pDLista lista;

    FuncaoComparacao funcaoComparacao = &ehMaior;
    FuncaoImpressao funcaoImprimirFila = &imprimeInteiros;
    FuncaoImpressao funcaoImprimirLista = &imprimePar;

    fila = criarFila();
    enfileirarInfo(fila, alocaInt(4));
    enfileirarInfo(fila, alocaInt(5));
    enfileirarInfo(fila, alocaInt(2));
    enfileirarInfo(fila, alocaInt(25));

    printf("Fila enviada......: ");
    imprimirFila(fila, funcaoImprimirFila);

    lista = NGE (fila, funcaoComparacao);

    printf("\nLista retornada...: ");
    imprimirLista(lista, funcaoImprimirLista);


    printf("\n##O nosso lema eh ousadia e alegria");
}
