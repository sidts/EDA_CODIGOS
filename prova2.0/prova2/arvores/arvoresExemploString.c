#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da árvore binária para strings
typedef struct node {
    char data[50]; // Assume que cada string terá no máximo 49 caracteres + 1 para o terminador nulo
    struct node *left;
    struct node *right;
} node;

// Cria um novo nó
node* create_node(char *data) {
    node *novo_no = (node*)malloc(sizeof(node));
    strcpy(novo_no->data, data);
    novo_no->left = NULL;
    novo_no->right = NULL;
    return novo_no;
}

// Insere um novo nó na árvore binária
void insert_node(node **raiz, char *data) {
    if (*raiz == NULL) {
        *raiz = create_node(data);
    } else {
        if (strcmp(data, (*raiz)->data) <= 0) {
            insert_node(&(*raiz)->left, data);
        } else {
            insert_node(&(*raiz)->right, data);
        }
    }
}

// Encontra o nó com o menor valor
node* find_min(node* raiz) {
    while (raiz->left != NULL) raiz = raiz->left;
    return raiz;
}

// Remove um nó da árvore binária
node* delete_node(node *raiz, char *data) {
    if (raiz == NULL) return raiz;

    if (strcmp(data, raiz->data) < 0) {
        raiz->left = delete_node(raiz->left, data);
    } else if (strcmp(data, raiz->data) > 0) {
        raiz->right = delete_node(raiz->right, data);
    } else {
        // Nó encontrado, agora vamos removê-lo
        if (raiz->left == NULL) {
            node *temp = raiz->right;
            free(raiz);
            return temp;
        } else if (raiz->right == NULL) {
            node *temp = raiz->left;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos: obtenha o sucessor em ordem (menor na subárvore direita)
        node *temp = find_min(raiz->right);
        strcpy(raiz->data, temp->data);
        raiz->right = delete_node(raiz->right, temp->data);
    }
    return raiz;
}

// Imprime a árvore binária em ordem crescente
void print_inorder(node *raiz) {
    if (raiz != NULL) {
        print_inorder(raiz->left);
        printf("%s ", raiz->data);
        print_inorder(raiz->right);
    }
}

// Função principal
int main() {
    node *raiz = NULL;

    // Insere alguns nós na árvore
    insert_node(&raiz, "z");
    insert_node(&raiz, "o");
    insert_node(&raiz, "r");
    insert_node(&raiz, "a");
    insert_node(&raiz, "t");
    insert_node(&raiz, "t");
    insert_node(&raiz, "o");

    //com essa implementação o segundo t fica na esquerda do t primeiro
    // no caso desse código

    // Imprime a árvore em ordem crescente
    printf("Árvore binária em ordem crescente: ");
    print_inorder(raiz);
    printf("\n");

    // Remove um nó da árvore
    raiz = delete_node(raiz, "t");

    // Imprime a árvore em ordem crescente após a remoção
    printf("Árvore binária em ordem crescente após remoção: ");
    print_inorder(raiz);
    printf("\n");

    return 0;
}
