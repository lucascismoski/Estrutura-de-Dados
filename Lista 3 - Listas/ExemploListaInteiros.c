#include <stdio.h>
#include "Utils.h"
#include "Lista.h"

int main(){
    pDLista pListaInt = criarLista();

    incluirInfo(pListaInt, alocaInt(5));
    incluirInfo(pListaInt, alocaInt(8));
    incluirInfo(pListaInt, alocaInt(6));

    printf("\nResultado da inclusao \n");
    imprimirLista(pListaInt, imprimeInt);

    int r;
    r = contemInfo(pListaInt, alocaInt(8), &comparaInt);
    if (r==0)
        printf("\n Informacao estah na lista!");
    else
        printf("\n Informacao NAO estah na lista!");


}
