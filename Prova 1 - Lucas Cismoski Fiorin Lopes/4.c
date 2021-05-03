#include <stdio.h>
#include "Lista.h"
#include "Utils.h"

void main(){
    pNoh maior = malloc(sizeof(Noh));

    pDLista minhaLista;

    FuncaoImpressao funcaoImprimir = &imprimeInt;
    FuncaoComparacao funcaoComparacao = &ehMaior;

    minhaLista = criarLista();
    incluirInfo(minhaLista, alocaInt(5));
    incluirInfo(minhaLista, alocaInt(62));
    incluirInfo(minhaLista, alocaInt(10));
    incluirInfo(minhaLista, alocaInt(27));

    imprimirLista(minhaLista, funcaoImprimir);

    maior = minhaLista->primeiro;

    maior->info = maiorElemento(minhaLista, maior->info, funcaoComparacao);

    printf("\nMaior elemento: %d", (*(int *)maior->info));
}
