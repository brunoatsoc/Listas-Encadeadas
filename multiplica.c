#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;    
}Lista;

void imprimeLista(Lista *lista);
void inicializaLista(Lista *lista);
void inserirFim(Lista *lista, int dado);
void multiplica(Lista *lista, int m);

int main(void){
    Lista lista;

    inicializaLista(&lista);

    inserirFim(&lista, 14);
    inserirFim(&lista, 1);
    inserirFim(&lista, 100);
    inserirFim(&lista, 15);
    inserirFim(&lista, 0);
    inserirFim(&lista, 18);

    multiplica(&lista, 2);

    imprimeLista(&lista);

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

void multiplica(Lista *lista, int m){
    No *ptr = lista->inicio;

    while(ptr != NULL){
        ptr->dado = (ptr->dado) * m;
        ptr = ptr->proximo;
    }
}