#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

void inicializaLista(Lista *lista);
void imprimeLista(Lista *lista);
void lista1(Lista *lista, int dado);
void inverteLista(Lista *lista1, Lista *listaInvertida);

int main(void){
    Lista listaUm, listaInvertida;

    inicializaLista(&listaUm);
    inicializaLista(&listaInvertida);

    lista1(&listaUm, 100);
    lista1(&listaUm, 1);
    lista1(&listaUm, 2);
    lista1(&listaUm, 3);
    lista1(&listaUm, 4);
    lista1(&listaUm, 5);

    inverteLista(&listaUm, &listaInvertida);

    imprimeLista(&listaInvertida);

    return 0;
}

void inverteLista(Lista *lista1, Lista *listaInvertida){
    No *ptr = lista1->inicio;

    while(ptr != NULL){
        No *novoNo = (No*)malloc(sizeof(No));

        novoNo->dado = ptr->dado;
        novoNo->proximo = listaInvertida->inicio;

        listaInvertida->inicio = novoNo;

        ptr = ptr->proximo;
    }
}

void lista1(Lista *lista, int dado){
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