#include "lcfl.h"
#include "Lista.h"
#include "Utils.h"

void main(){
    pDLista minhaLista;


    /*void *num1 = malloc(sizeof(int));
    void *num2 = malloc(sizeof(int));

    (*(int*)num1) = 10;
    (*(int*)num2) = 20;*/

   /* printf("Pai ta on: ");
    scanf("%d", &i);*/

    minhaLista = criarLista();

    void *funcaoImprimir = &imprimeInt;

    /*incluirInfo(minhaLista, num1);
    incluirInfo(minhaLista, num2);*/

    incluirInfo(minhaLista, alocaInt(5));
    incluirInfo(minhaLista, alocaInt(10));
    incluirInfoInicio(minhaLista, alocaInt(30));
    incluirInfo(minhaLista, alocaInt(27));
    incluirInfo(minhaLista, alocaInt(62));
    incluirInfoMeio(minhaLista, alocaInt(98), 3);
    //30 - 5 - 98 - 10 - 27 - 62

    imprimirLista(minhaLista, funcaoImprimir);
}
