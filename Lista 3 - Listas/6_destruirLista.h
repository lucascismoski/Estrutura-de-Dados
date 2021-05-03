void destruirListaRecursiva(pNoh atual){
    if (atual == NULL)
        return;
    destruirListaRecursiva(atual->prox);
    free(atual);
}

void destruirListaRecursivaLiberando(pNoh atual, FuncaoLiberacao pfl){
    if (atual == NULL)
        return;
    pfl(atual->info);
    destruirListaRecursivaLiberando(atual->prox, pfl);
    free(atual);
}

/* -------------------------------------*/
void destruirLista(pDLista pd){

   destruirListaRecursiva(pd->primeiro);
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

void destruirListaLiberando(pDLista pd, FuncaoLiberacao pfl){

   destruirListaRecursivaLiberando(pd->primeiro, pfl);
   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

/* -------------------------------------*/
void destruirListaNaoRecursivo(pDLista pd){

    pNoh atual;
    atual = pd->primeiro;

    while(atual != NULL){
       pNoh aux = atual->prox;
       free(atual);
       atual = aux;
    }

   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}

void destruirListaNaoRecursivoLib(pDLista pd, FuncaoLiberacao pfl){

    pNoh atual;
    atual = pd->primeiro;

    while(atual != NULL){
       pNoh aux = atual->prox;
       pfl(atual->info);
       free(atual);
       atual = aux;
    }

   pd->primeiro   = NULL;
   pd->ultimo     = NULL;
   pd->quantidade = 0;
}








