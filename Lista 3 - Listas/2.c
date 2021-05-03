#include "lcfl.h"
#include "Lista.h"
#include "Utils.h"

void main(){
    pDLista minhaLista;
    void *funcaoImprimir = &imprimeInt;

    minhaLista = criarLista();

    incluirInfo(minhaLista, alocaInt(5));
    incluirInfo(minhaLista, alocaInt(10));
    incluirInfoInicio(minhaLista, alocaInt(30));
    incluirInfo(minhaLista, alocaInt(27));
    incluirInfo(minhaLista, alocaInt(62));
    incluirInfoMeio(minhaLista, alocaInt(98), 3);
    //30 - 5 - 98 - 10 - 27 - 62

    imprimirLista(minhaLista, funcaoImprimir);
}
