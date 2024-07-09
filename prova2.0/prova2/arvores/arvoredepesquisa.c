#include <stdio.h>
#include <stdlib.h>

// Estrutura da árvore binária de busca
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;

// Função para criar um novo nó
node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Função para inserir um novo nó na árvore binária de busca
node* insert_node(node* raiz, int data) {
    // Se a árvore está vazia, retorna um novo nó
    if (raiz == NULL) {
        return create_node(data);
    }

    // Caso contrário, percorre a árvore de acordo com as regras da BST
    if (data < raiz->data) {
        raiz->left = insert_node(raiz->left, data);
    } else if (data > raiz->data) {
        raiz->right = insert_node(raiz->right, data);
    }

    // Retorna a raiz (não modificada) da árvore
    return raiz;
}

// Função para realizar a busca em uma árvore binária de busca
node* search(node* raiz, int valor) {
    // Caso base: se a raiz é nula ou encontramos o valor
    if (raiz == NULL || raiz->data == valor) {
        return raiz;
    }
    
    // Se o valor é menor que o valor do nó atual, busca na subárvore esquerda
    if (valor < raiz->data) {
        return search(raiz->left, valor);
    }
    
    // Se o valor é maior que o valor do nó atual, busca na subárvore direita
    return search(raiz->right, valor);
}

// Função para imprimir a árvore em ordem crescente
void print_inorder(node* raiz) {
    if (raiz != NULL) {
        print_inorder(raiz->left);
        printf("%d ", raiz->data);
        print_inorder(raiz->right);
    }
}

// Função principal
int main() {
    node* raiz = NULL;

    // Insere alguns nós na árvore
    raiz = insert_node(raiz, 10);
    insert_node(raiz, 5);
    insert_node(raiz, 15);
    insert_node(raiz, 2);
    insert_node(raiz, 7);
    insert_node(raiz, 12);
    insert_node(raiz, 20);

    // Imprime a árvore em ordem crescente
    printf("Árvore binária de busca em ordem crescente: ");
    print_inorder(raiz);
    printf("\n");

    // Realiza algumas buscas na árvore
    int valorProcurado = 0;
    node* resultadoBusca = search(raiz, valorProcurado);

    if (resultadoBusca != NULL) {
        printf("Valor %d encontrado na árvore.\n", valorProcurado);
    } else {
        printf("Valor %d não encontrado na árvore.\n", valorProcurado);
    }

    // Libera a memória alocada para a árvore (pode ser feito recursivamente)
    // Libera a árvore depois de terminar todas as operações
    return 0;
}
