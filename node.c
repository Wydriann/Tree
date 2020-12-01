#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node *inserir(Node *raiz, int novoValor){
    if(raiz == NULL)
        return criar(novoValor);

    if (novoValor < raiz->valor )
        raiz->esq = inserir(raiz->esq, novoValor);

    if (novoValor > raiz->valor )
        raiz->dir = inserir(raiz->dir, novoValor);

    return raiz;
}

Node *criar(int novoValor){
    Node *temp = (Node*)malloc(sizeof(Node));
    temp->valor = novoValor;
    temp->esq = temp->dir = NULL;
    return temp;
}

void inOrder(Node *raiz){
    if (raiz != NULL) {

        inOrder(raiz->esq);

        printf("%d\n", raiz->valor );
        inOrder(raiz->dir);
    }
}

void preOrder(Node *raiz){
    if (raiz != NULL) {
        printf("%d\n", raiz->valor);

        preOrder(raiz->esq);
        preOrder(raiz->dir);
    }
}

void posOrder(Node *raiz){
    if (raiz != NULL) {

        posOrder(raiz->esq);
        posOrder(raiz->dir);

        printf("%d\n", raiz->valor);


    }
}

Node* removerMaior(Node **raiz){
    if ((*raiz)->dir != NULL) {
       return removerMaior(&(*raiz)->dir);
    }
    else {
       Node *aux = *raiz;
       if ((*raiz)->esq != NULL) {
          *raiz = (*raiz)->esq;
       }
       else {
          *raiz = NULL;
       }

       return aux;
    }
}

Node* removerMenor(Node **raiz) {
    if ((*raiz)->esq != NULL) {
        return removerMenor(&(*raiz)->esq);
    }
    else {
       Node *aux = *raiz; 
       if ((*raiz)->dir != NULL) {
           *raiz = (*raiz)->dir;
        }
       else {
           *raiz = NULL;
        }

       return aux;
       }
}