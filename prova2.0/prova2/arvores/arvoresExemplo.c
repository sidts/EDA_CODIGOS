#include <stdio.h>
#include <stdlib.h>

// mesma estrutura de listas 
// Estrutura da árvore binária
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Cria um novo nó
node* create_node(int data) {
    node *novo_no = (node*)malloc(sizeof(node));
    novo_no->data = data;
    novo_no->left = NULL;
    novo_no->right = NULL;
    return novo_no;
}

// Insere um novo nó na árvore binária
void insert_node(node **raiz, int data) {
    if (*raiz == NULL) {
        // se não adiciona no inicio
        *raiz = create_node(data);
    } else {
        // verifica se o valor que entra é maior ou menor que o no raiz
        if (data <= (*raiz)->data) {
            insert_node(&(*raiz)->left, data);
        } else {
            insert_node(&(*raiz)->right, data);
        }
    }
}

// Imprime a árvore binária em ordem crescente
void print_inorder(node *raiz) {
    if (raiz != NULL) {
        // chamada recursiva
        print_inorder(raiz->left);
        printf("%d ", raiz->data);
        print_inorder(raiz->right);
    }
}

// Função principal
int main() {
    // Cria a árvore binária
    node *raiz = NULL;

    // Insere alguns nós na árvore
    insert_node(&raiz, 10);
    insert_node(&raiz, 5);
    insert_node(&raiz, 15);
    insert_node(&raiz, 2);
    insert_node(&raiz, 7);
    insert_node(&raiz, 12);
    insert_node(&raiz, 20);

    // Imprime a árvore em ordem crescente
    printf("Árvore binária em ordem crescente: ");
    print_inorder(raiz);
    printf("\n");

    return 0;
}
