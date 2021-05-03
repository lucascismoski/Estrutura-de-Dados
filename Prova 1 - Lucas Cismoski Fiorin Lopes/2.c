#include <stdio.h>
#include "Lista.h"
#include "Utils.h"

pDLista split(pDLista pListaOriginal, FuncaoPredicado fp, FuncaoComparacao fc)
{
    pDLista pNovaLista = criarLista();

    pNoh atual = pListaOriginal->primeiro;
    pNoh prox;

    while(atual != NULL){
        prox = atual->prox;

        if (fp(atual->info) == 1) {
            incluirInfo(pNovaLista, atual->info);
            excluirInfo(pListaOriginal, atual->info, fc);
        }

        atual = prox;
    }

    return pNovaLista;
}


void main(){
    pDLista minhaLista;

    FuncaoImpressao  funcaoImprimir   = &imprimeInt;
    FuncaoComparacao funcaoComparacao = &comparaInt;
    FuncaoLiberacao  funcaoLiberacao  = &liberaMemoriaInt;
    FuncaoPredicado  funcaoPredicado  = &divisivelPorCinco;

    minhaLista = criarLista();
    incluirInfo(minhaLista, alocaInt(5));
    incluirInfo(minhaLista, alocaInt(62));
    incluirInfo(minhaLista, alocaInt(10));
    incluirInfo(minhaLista, alocaInt(27));
    incluirInfo(minhaLista, alocaInt(31));
    incluirInfo(minhaLista, alocaInt(15));


    imprimirLista(minhaLista, funcaoImprimir);

    pDLista listaGerada = split(minhaLista, funcaoPredicado, funcaoComparacao);

    printf("\n---LISTA ANTIGA---\n");
    imprimirLista(minhaLista, funcaoImprimir);

    printf("\n---NOVA LISTA GERADA---\n");
    imprimirLista(listaGerada, funcaoImprimir);

}
