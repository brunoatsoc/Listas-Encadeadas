#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

int maior(Lista *lista);
void imprimeLista(Lista *lista);
void inserirFim(Lista *lista, int dado);
void inicializaLista(Lista *lista);

int main(void){
    Lista lista;

    inicializaLista(&lista);

    inserirFim(&lista, 5);
    inserirFim(&lista, 122);
    inserirFim(&lista, 25);

    imprimeLista(&lista);

    printf("O maior valor da lista é: %d\n", maior(&lista));

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

void imprimeLista(Lista *lista){
    No *ptr = lista->inicio;

    while(ptr != NULL){
        printf("%d\n", ptr->dado);
        ptr = ptr->proximo;
    }
}

void inicializaLista(Lista *lista){
    lista->inicio = NULL;
}

int maior(Lista *lista){
    No *ptr = lista->inicio;
    int maior = ptr->dado;

    while(ptr != NULL){
        if(ptr->dado > maior){
            maior = ptr->dado;
        }
        ptr = ptr->proximo;
    }

    return maior;
}