
void incluirInfo(pDLista pd, void *info){
    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }
    /* aloca memoria para guardar a nova info */
    pNoh pNovo = malloc(sizeof(Noh));

    /* guarda a informa��o no campo "info" do novo noh alocado */
    pNovo->info = info;
    /* como a nova info ficar na �ltima posicao da lista,
       n�o ter� pr�ximo */
    pNovo->prox = NULL;

    /* salva a referencia ao ultimo noh da lista antes de atualizar o descritor */
    pNoh auxUltimo  = pd->ultimo;
    /* o novo noh ser� identificado como �ltimo da lista pelo descritor */
    pd->ultimo      = pNovo;
    /* a lista tem mais um noh */
    pd->quantidade++;

    /* Se o novo noh � o �nico da lista, o descritor
       precisa atualizar tamb�m o ponteiro para o primeiro noh da lista */
    if (pd->primeiro == NULL)
        pd->primeiro = pNovo;
    else{
        /* se n�o for o �nico da lista, coloc�-o no final da lista */
        auxUltimo->prox = pNovo;
    }
}

void incluirInfoInicio(pDLista pd, void *info){
    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }

    pNoh pNovo = malloc(sizeof(Noh));

    pNovo->info = info;

    pNovo->prox = pd->primeiro;

    pd->primeiro = pNovo;

    pd->quantidade++;
}

void incluirInfoMeio(pDLista pd, void *info, int index){
    if (pd == NULL){
        printf("Lista nao existe ainda, nao eh possivel incluir!");
        return;
    }

    int i;

    pNoh pNovo = malloc(sizeof(Noh));
    pNovo->info = info;

    pNoh nohAux2;

    pNoh nohAux;
    nohAux = pd->primeiro;

    for(i=1;i<index-1;i++){
       nohAux = nohAux->prox;
    }

    nohAux2 = nohAux->prox;

    pNovo->prox = nohAux2;

    nohAux->prox= pNovo;

    pd->quantidade++;
}
