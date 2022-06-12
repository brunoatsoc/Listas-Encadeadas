#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int dado;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
}Lista;

void lista1(Lista *lista, int dado);
void lista2(Lista *lista, int dado);
void inicializaLista(Lista *lista);
void imprimeLista(Lista *lista);
void concatenaLista(Lista *lista1, Lista *lista2, Lista *listaConcatenada);

int main(void){
    Lista listaUm, listaDois, listaC;

    inicializaLista(&listaUm);
    inicializaLista(&listaDois);
    inicializaLista(&listaC);

    lista1(&listaUm, 1);
    lista1(&listaUm, 2);
    lista1(&listaUm, 3);
    lista1(&listaUm, 12);
    lista1(&listaUm, 90);

    lista2(&listaDois, 4);
    lista2(&listaDois, 5);
    lista2(&listaDois, 6);

    concatenaLista(&listaUm, &listaDois, &listaC);

    imprimeLista(&listaC);

    return 0;
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

void lista2(Lista *lista, int dado){
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

void concatenaLista(Lista *lista1, Lista *lista2, Lista *listaConcatenada){
    No *ptr = lista1->inicio;

    while(ptr != NULL){
        No *ptr2, *novoNo = (No*)malloc(sizeof(No));

        novoNo->dado = ptr->dado;
        novoNo->proximo = NULL;

        if(listaConcatenada->inicio == NULL){
            listaConcatenada->inicio = novoNo;
        }else{
            ptr2 = listaConcatenada->inicio;

            while(ptr2->proximo != NULL){
                ptr2 = ptr2->proximo;
            }

            ptr2->proximo = novoNo;
        }
        ptr = ptr->proximo;
    }

    ptr = lista2->inicio;

    while(ptr != NULL){
        No *ptr3, *novoNo = (No*)malloc(sizeof(No));

        novoNo->dado = ptr->dado;
        novoNo->proximo = NULL;

        if(listaConcatenada->inicio == NULL){
            listaConcatenada->inicio = novoNo;
        }else{
            ptr3 = listaConcatenada->inicio;

            while(ptr3->proximo != NULL){
                ptr3 = ptr3->proximo;
            }

            ptr3->proximo = novoNo;
        }
        ptr = ptr->proximo;
    }
}