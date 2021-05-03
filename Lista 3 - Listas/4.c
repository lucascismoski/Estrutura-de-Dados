#include "lcfl.h"
#include "Lista.h"
#include "Utils.h"

void main(){
    pDLista minhaLista;

    FuncaoImpressao funcaoImprimir = &imprimeInt;
    FuncaoComparacao funcaoComparacao = &comparaInt;
    FuncaoLiberacao funcaoLiberar = &liberaMemoriaInt;

    int result;

    minhaLista = criarLista();

    incluirInfo(minhaLista, alocaInt(5));
    incluirInfo(minhaLista, alocaInt(10));
    //5 - 10 -

    incluirInfoInicio(minhaLista, alocaInt(30));
    //30 - 5 - 10

    incluirInfo(minhaLista, alocaInt(27));
    incluirInfo(minhaLista, alocaInt(62));
    //30 - 5 - 10 - 27 - 62

    incluirInfoMeio(minhaLista, alocaInt(98), 3);
    //30 - 5 - 98 - 10 - 27 - 62

    imprimirLista(minhaLista, funcaoImprimir);


    excluirInfoLiberando(minhaLista, alocaInt(27), funcaoComparacao, funcaoLiberar);
    printf("\n---Resultado da Exclusao---\n");
    imprimirLista(minhaLista, funcaoImprimir);

    destruirListaLiberando(minhaLista, funcaoLiberar);

    imprimirLista(minhaLista, funcaoImprimir);
}
