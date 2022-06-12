#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

void inserirFim(Lista *lista, int dado);
void inicializaLista(Lista *lista);
void imprimeLista(Lista *lista);
int numeroDeElementos(Lista *lista);

int main(void){
    Lista lista;

    inicializaLista(&lista);

    inserirFim(&lista, 34);
    inserirFim(&lista, 12);
    inserirFim(&lista, 101);
    inserirFim(&lista, 46);

    imprimeLista(&lista);

    printf("O número de elementos da lista é: %d\n", numeroDeElementos(&lista));

    return 0;
}

void inserirFim(Lista *lista, int dado){
    No *ptr, *novoNo = (No*)malloc(sizeof(No));

    novoNo->dado = dado;
    novoNo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novoNo;
    }else{
        ptr = lista->inicio;

        while(ptr->proximo != NULL){
            ptr = ptr->proximo;
        }
        ptr->proximo = novoNo;
    }
}

void inicializaLista(Lista *lista){
    lista->inicio = NULL;
}

void imprimeLista(Lista *lista){
    No *ptr = lista->inicio;

    while(ptr != NULL){
        printf("%d\n", ptr->dado);
        ptr = ptr->proximo;
    }
}

int numeroDeElementos(Lista *lista){
    int i = 0;
    No *ptr = lista->inicio;

    while(ptr != NULL){
        i++;
        ptr = ptr->proximo;
    }

    return i;
}