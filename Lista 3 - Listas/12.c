#include "lcfl.h"
#include "Lista.h"
#include "Utils.h"


/*typedef struct contato Contato;
typedef Contato* pContato;*/

/*struct contato {
    char nome;
    char telefone;
};*/

struct Fornecedor {
    char nome[300];
    char cidade[50];
    //struct contato *c;
};

struct Fornecedor* alocaFornecedor(char nome[], char cidade[]){
    struct Fornecedor *pd = (struct Fornecedor *) malloc(sizeof(struct Fornecedor));
    strcpy(pd->nome, nome);
    strcpy(pd->cidade, cidade);
    return pd;
};

void imprimeFornecedor(void *info){
    struct Fornecedor *pd = (struct Fornecedor *) info;
    printf("\nNome: %s", pd->nome);
    printf("\nCidade: %s", pd->cidade);
}

void main(){
    pDLista minhaLista;

    FuncaoImpressao funcaoImprimir = &imprimeFornecedor;

    minhaLista = criarLista();

    incluirInfo(minhaLista, alocaFornecedor("Lucas", "Medianeira"));
    incluirInfo(minhaLista, alocaFornecedor("Gabriel", "Cascavel"));

    printf("aaaaaa");

    imprimirLista(minhaLista, funcaoImprimir);
}
