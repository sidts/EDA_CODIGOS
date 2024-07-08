#include <stdio.h>
#include <stdlib.h>

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
        *raiz = create_node(data);
    } else {
        if (data <= (*raiz)->data) {
            insert_node(&(*raiz)->left, data);
        } else {
            insert_node(&(*raiz)->right, data);
        }
    }
}

// Encontra o nó com o menor valor
node* find_min(node* raiz) {
    // enquanto existir um filho a esquerda ele continua
    while (raiz->left != NULL) raiz = raiz->left;
    // quando o letf é NULL significa que chegou mais a esquerda o nó, ou seja o menor
    return raiz;
}

// Remove um nó da árvore binária
node* delete_node(node *raiz, int data) {
    if (raiz == NULL) return raiz;

    if (data < raiz->data) {
        raiz->left = delete_node(raiz->left, data);
    } else if (data > raiz->data) {
        raiz->right = delete_node(raiz->right, data);
    } else {
        // Nó encontrado, agora vamos removê-lo
        if (raiz->left == NULL) {
            // senão tem filho na esquerda retorna o filho da direita
            node *temp = raiz->right;
            free(raiz);
            return temp;
        } else if (raiz->right == NULL) {
            // senão tem filho na direita retorna o filho da esquerda
            node *temp = raiz->left;
            free(raiz);
            return temp;
        }

        // Nó com dois filhos: obtenha o sucessor em ordem (menor na subárvore direita)
        node *temp = find_min(raiz->right);
        // procura o maior nó sucessivo baseando-se função anterior
        raiz->data = temp->data;
        // copia o valor do nó encontrado para o atual
        raiz->right = delete_node(raiz->right, temp->data);
        // Remove o sucessor na subárvore direita chamando recursivamente delete_node na subárvore direita com o valor do sucessor.

    }
    return raiz;
}

// Imprime a árvore binária em ordem crescente
void print_inorder(node *raiz) {
    if (raiz != NULL) {
        print_inorder(raiz->left);
        printf("%d ", raiz->data);
        print_inorder(raiz->right);
    }
}

// Função principal
int main() {
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

    // Remove um nó da árvore
    raiz = delete_node(raiz, 10);

    // Imprime a árvore em ordem crescente após a remoção
    printf("Árvore binária em ordem crescente após remoção: ");
    print_inorder(raiz);
    printf("\n");

    return 0;
}
