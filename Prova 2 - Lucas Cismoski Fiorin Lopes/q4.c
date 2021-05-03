#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "ListaLinear/Lista.h"
#include "Utils.h"
#include "Pilha.h"
#include <string.h>

char bemFormada(char sequencia[300]){
    int i = 0;
    int countE = 0;
    int countD = 0;
    int tamanho = strlen(sequencia);

    for (i=0;i<tamanho;i++){
        if ( sequencia[i] == 'E' ){
            countE = countE + 1;
        } else if ( sequencia[i] == 'D' ) {
            countD = countD + 1;
        }

        if (countD > countE){
            return 'N';
        }
    }
    return 'S';
}


void main(){
    char string[300] = "NULL";

    printf ("Digite a sequencia: ");
    scanf("%s", &string);

    printf("Resultado: %c\n", bemFormada(string));

    printf("##O nosso lema eh ousadia e alegria");
}
