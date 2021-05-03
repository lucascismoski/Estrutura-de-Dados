#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

/* ---------------------------------------- */
/* tipo de dado INT */
/* ---------------------------------------- */
int comparaInt(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;
    return *p2 - *p1;
}

int comparaInt2(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;

    if (*p2 == *p1) {
        return 0;
    } else {
        return 1;
    }
}
/* ---------------------------------------- */
void imprimeInt(void *info){
   int *pi = (int *) info;
   printf("%d - ", *pi);
}
/* ---------------------------------------- */
void* alocaInfoInt(void* info){
   int *pi = (int *) malloc(sizeof(int));
   *pi = *((int*)info);
   return pi;
}
/* ---------------------------------------- */
int* alocaInt(int n){
   int *pi = (int *) malloc(sizeof(int));
   *pi = n;
   return pi;
}

void liberaMemoriaInt(void *info){
    free((int*)info);
}

int ehMaior(void *info1, void *info2){
    int *p1 = (int *) info1;
    int *p2 = (int *) info2;

    return *p1 > *p2;
}

void* maiorElemento(pDLista pd, void *maiorAtual, FuncaoComparacao fc){
    pNoh atual = malloc(sizeof(Noh));

    atual = pd->primeiro;

    if (atual == NULL){
        return maiorAtual;
    } else {
         if ( fc(atual->info, maiorAtual) ){
            maiorAtual = atual->info;
        }

        pd->primeiro = atual->prox;

        maiorElemento(pd, maiorAtual, fc);
    }
}

int mod (int x, int y){
    if (x < y){
        return x;
    } else {
        return mod(x-y, y);
    }
}

void* divisivelPorCinco(void *info){
    int *p1 = (int *) info;

    if ( mod(*p1, 5) == 0 ) {
        return 1;
    } else {
        return 0;
    }
}

#endif /* UTILS_H */
