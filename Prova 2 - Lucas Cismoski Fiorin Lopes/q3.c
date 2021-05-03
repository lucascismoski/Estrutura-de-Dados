#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaLinear/Lista.h"
#include "Utils.h"
#include "Pilha.h"

void imprimeInteiros (void *info){
    printf("[%d] ", *((int*)info));
}

void imprimirPilha(pDPilha pd, FuncaoImpressao pfi){
    imprimirLista(pd->pdLista, pfi);
}

void troca (pDPilha pilha, int pos){
    int cont=1;
    pNoh atual, ant, atual2;
    void *aux;


    atual = pilha->pdLista->primeiro;
    ant   = NULL;

    while(atual->prox != NULL && cont < pos){
       ant   = atual;
       atual = atual->prox;
       cont++;
    }

    aux = atual->info;
    atual2 = pilha->pdLista->ultimo;
    atual->info = atual2->info;
    atual2->info = aux;

    /*pensei em fazer algo mais elaborado, mas o tempo tava acabando e estourou uns erros...
    vou fazer o feijão com arroz q funciona*/
}



void main(){
    pDPilha pilha;
    pilha = criarPilha();

    FuncaoImpressao funcaoImprimir = &imprimeInteiros;

    empilharInfo(pilha, alocaInt(1));
    empilharInfo(pilha, alocaInt(2));
    empilharInfo(pilha, alocaInt(3));
    empilharInfo(pilha, alocaInt(4));
    empilharInfo(pilha, alocaInt(5));
    empilharInfo(pilha, alocaInt(6));
    empilharInfo(pilha, alocaInt(7));
    empilharInfo(pilha, alocaInt(8));
    empilharInfo(pilha, alocaInt(9));

    printf("Antes......: ");
    imprimirPilha(pilha, funcaoImprimir);

    printf("\nDepois.....: ");
    troca(pilha, 5);
    imprimirPilha(pilha, funcaoImprimir);

    printf("\n##O nosso lema eh ousadia e alegria");
}
