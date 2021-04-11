#include "lcfl.h"

struct Pessoa{
    char nome[200];
    int idade;
};

void imprimeNomePessoa(struct Pessoa *p, int *index){
    printf("\n%s", (p+*index)->nome); //ou (*(p+*index)).nome), tanto faz
};

void verificaMenores18( struct Pessoa *p, int *numPessoas, void (*ptr)() ){
    int i;

    for(i=0; i<*numPessoas; i++) {
        if ( (p+i)->idade < 18 ){
            (*ptr) (p, &i);
        }
    }
}

int main(){
    int numPessoas;
    int i;

    printf("Informe a quantidade de pessoas para cadastrar: ");
    scanf("%d", &numPessoas);

    struct Pessoa p[numPessoas];

    for(i=0; i<numPessoas; i++) {
        strcpy(p[i].nome, "NULL");
        p[i].idade = 0;
    }

    for(i=0; i<numPessoas; i++) {
        printf("Digite nome da pessoa %d: ", i+1);
        scanf("%s%*c", &p[i].nome);
        printf("Digite a idade da pessoa %d: ", i+1);
        scanf("%d%*c", &p[i].idade);
    }

    void (*func)() = &imprimeNomePessoa;

    printf("\n#############Pessoas com menos de 18 anos de idade#############");
    verificaMenores18(p, &numPessoas, func);

    printf("\n");
    printaCopyRight();

    /*for(i=0; i<num_pessoas; i++) {
        imprimeNomePessoa(p, &i);
        printf(" \n O nome da pessoa %d é: %s ", i+1, p[i].nome);
        printf(" \n A idade da pessoa %d é: %d ", i+1, p[i].idade);
    }*/
}
