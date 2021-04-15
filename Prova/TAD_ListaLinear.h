#ifndef LISTA_TAD_H
#define LISTA_TAD_H

/*------------------------------------------*/
/* tipos de dados                           */
/*------------------------------------------*/
typedef struct noh  Noh;
typedef Noh*        pNoh;

/* descritor da lista */
typedef struct dLista  DLista;
typedef DLista*        pDLista;
/*typedef struct fornecedor Fornecedor;
typedef Fornecedor* pFornecedor;*/

/* 3 tipos que representam ponteiros para função */
typedef int   (*FuncaoComparacao)(void *, void *);
typedef void  (*FuncaoImpressao) (void *);
typedef void* (*FuncaoAlocacao)  (void *);
typedef void  (*FuncaoLiberacao) (void *);
typedef int   (*FuncaoPredicado) (void *);

/*------------------------------------------*/
/* operacoes                                */
/*------------------------------------------*/
pDLista  criarLista    ();
void     incluirInfo   (pDLista, void *);
int      excluirInfo   (pDLista, void *, FuncaoComparacao);
int      excluirInfoLiberando (pDLista, void *, FuncaoComparacao, FuncaoLiberacao);
/* o retorno int indica a posicao da informacao procurada dentro da lista*/
int      contemInfo    (pDLista, void *, FuncaoComparacao);
void     imprimirLista (pDLista, FuncaoImpressao);
/*-------------*/
void     destruirLista (pDLista);
void     destruirListaLiberando (pDLista, FuncaoLiberacao);

pDLista  duplicarLista (pDLista, FuncaoAlocacao);
/* o parametro int estabelece a posicao da lista onde a divisao deve acontecer */
pDLista  dividirLista  (pDLista, int);




#endif

