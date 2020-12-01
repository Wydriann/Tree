
#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

typedef struct node {
    struct node *esq;
    int valor;
    struct node *dir;
} Node;

Node *criar(int valor);

Node *inserir(Node *raiz, int novoValor);

void inOrder(Node *raiz);

void preOrder(Node *raiz);

void posOrder(Node *raiz);

Node* removerMaior(Node **raiz);

Node* removerMenor(Node **raiz);

#endif // NODE_H_INCLUDED
