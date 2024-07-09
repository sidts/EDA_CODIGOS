#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista duplamente encadeada
struct TNo {
    struct TNo *Ant;  // Ponteiro para o nó anterior
    int Numero;       // Variável para armazenar o número
    struct TNo *Prox; // Ponteiro para o próximo nó
};

// Função para verificar se a lista está vazia
// Retorna 1 se a lista está vazia, caso contrário retorna 0
int Vazia(struct TNo *pLista) {
    return pLista == NULL;
}

// Função para incluir um elemento no início da lista (cabeça da lista)
// Complexidade O(1)
struct TNo *IncluiCabeca(struct TNo *pLista, int pValor) {
    struct TNo *pNovoNo = (struct TNo *)malloc(sizeof(struct TNo)); // Aloca memória para o novo nó
    pNovoNo->Numero = pValor;  // Atribui o valor ao novo nó
    pNovoNo->Ant = NULL;       // Define o ponteiro anterior do novo nó como NULL
    pNovoNo->Prox = pLista;    // O próximo nó do novo nó é o nó atual da cabeça da lista
    if (pLista != NULL) {
        pLista->Ant = pNovoNo; // Se a lista não estiver vazia, define o ponteiro anterior do nó atual da cabeça para o novo nó
    }
    return pNovoNo; // Retorna o novo nó, que agora é a cabeça da lista
}

// Função para incluir um elemento no final da lista (cauda da lista)
// Complexidade O(n)
struct TNo *IncluiCalda(struct TNo *pLista, int pValor) {
    struct TNo *pNovoNo = (struct TNo *)malloc(sizeof(struct TNo)); // Aloca memória para o novo nó
    pNovoNo->Numero = pValor;  // Atribui o valor ao novo nó
    pNovoNo->Prox = NULL;      // Define o próximo nó do novo nó como NULL
    if (pLista == NULL) {
        pNovoNo->Ant = NULL;   // Se a lista estiver vazia, define o ponteiro anterior do novo nó como NULL
        return pNovoNo;        // O novo nó é o único nó na lista e, portanto, é retornado como a nova lista
    }
    struct TNo *pAux = pLista;
    while (pAux->Prox != NULL) {
        pAux = pAux->Prox;     // Percorre a lista até encontrar o último nó
    }
    pAux->Prox = pNovoNo;      // O próximo nó do último nó agora aponta para o novo nó
    pNovoNo->Ant = pAux;       // O ponteiro anterior do novo nó aponta para o antigo último nó
    return pLista;             // Retorna a lista com o novo nó adicionado ao final
}

// Função para incluir um elemento depois de um nó específico na lista
// Complexidade O(n)
struct TNo *IncluiDepois(struct TNo *pLista, int pChave, int pValor) {
    struct TNo *pNovoNo = (struct TNo *)malloc(sizeof(struct TNo)); // Aloca memória para o novo nó
    pNovoNo->Numero = pValor;  // Atribui o valor ao novo nó
    struct TNo *pAux = pLista;
    while (pAux != NULL && pAux->Numero != pChave) {
        pAux = pAux->Prox;     // Percorre a lista até encontrar o nó com o valor da chave
    }
    if (pAux != NULL) {        // Se o nó com a chave for encontrado
        pNovoNo->Prox = pAux->Prox; // O próximo nó do novo nó aponta para o próximo nó do nó encontrado
        pNovoNo->Ant = pAux;   // O ponteiro anterior do novo nó aponta para o nó encontrado
        if (pAux->Prox != NULL) {
            pAux->Prox->Ant = pNovoNo; // Se o nó encontrado não for o último, ajusta o ponteiro anterior do próximo nó
        }
        pAux->Prox = pNovoNo;  // O próximo nó do nó encontrado agora aponta para o novo nó
    } else {
        free(pNovoNo);         // Se o nó com a chave não for encontrado, libera a memória alocada para o novo nó
    }
    return pLista;             // Retorna a lista com o novo nó adicionado
}

// Função para excluir o primeiro elemento da lista (cabeça da lista)
// Complexidade O(1)
struct TNo *ExcluiCabeca(struct TNo *pLista) {
    if (pLista == NULL) return NULL; // Se a lista estiver vazia, retorna NULL
    struct TNo *pAux = pLista;
    pLista = pLista->Prox;       // A cabeça da lista agora é o próximo nó
    if (pLista != NULL) {
        pLista->Ant = NULL;      // Se a nova cabeça não for NULL, define seu ponteiro anterior como NULL
    }
    free(pAux);                  // Libera a memória do antigo nó da cabeça
    return pLista;               // Retorna a lista com a nova cabeça
}

// Função para excluir o último elemento da lista (cauda da lista)
// Complexidade O(n)
struct TNo *ExcluiCalda(struct TNo *pLista) {
    if (pLista == NULL) return NULL; // Se a lista estiver vazia, retorna NULL
    struct TNo *pAux = pLista;
    while (pAux->Prox != NULL) {
        pAux = pAux->Prox;       // Percorre a lista até encontrar o último nó
    }
    if (pAux->Ant != NULL) {
        pAux->Ant->Prox = NULL;  // Se o último nó não for o primeiro, ajusta o ponteiro do próximo do penúltimo nó
    } else {
        pLista = NULL;           // Se o último nó era o único nó, a lista agora está vazia
    }
    free(pAux);                  // Libera a memória do último nó
    return pLista;               // Retorna a lista com o novo último nó
}

// Função para excluir um nó específico na lista
// Complexidade O(n)
struct TNo *ExcluiChave(struct TNo *pLista, int pChave) {
    struct TNo *pAux = pLista;
    while (pAux != NULL && pAux->Numero != pChave) {
        pAux = pAux->Prox;       // Percorre a lista até encontrar o nó com o valor da chave
    }
    if (pAux == NULL) return pLista; // Se o nó com a chave não for encontrado, retorna a lista inalterada
    if (pAux->Ant != NULL) {
        pAux->Ant->Prox = pAux->Prox; // Ajusta o ponteiro do próximo do nó anterior ao nó encontrado
    } else {
        pLista = pAux->Prox;     // Se o nó encontrado era a cabeça, ajusta a cabeça da lista
    }
    if (pAux->Prox != NULL) {
        pAux->Prox->Ant = pAux->Ant; // Ajusta o ponteiro anterior do nó seguinte ao nó encontrado
    }
    free(pAux);                  // Libera a memória do nó encontrado
    return pLista;               // Retorna a lista com o nó removido
}

int main() {
    struct TNo *lista = NULL;
int opcao, valor, chave;

    do {
        printf("Menu:\n");
        printf("1. Incluir na cabeca\n");
        printf("2. Incluir na cauda\n");
        printf("3. Incluir depois de um valor\n");
        printf("4. Excluir cabeca\n");
        printf("5. Excluir cauda\n");
        printf("6. Excluir um valor\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            printf("Digite o valor a ser incluído na cabeça: ");
            scanf("%d", &valor);
            lista = IncluiCabeca(lista, valor);
            printf("Valor %d incluído na cabeça.\n", valor);
            break;
        case 2:
            printf("Digite o valor a ser incluído na cauda: ");
            scanf("%d", &valor);
            lista = IncluiCalda(lista, valor);
            printf("Valor %d incluído na cauda.\n", valor);
            break;
        case 3:
            printf("Digite o valor da chave: ");
            scanf("%d", &chave);
            printf("Digite o valor a ser incluído após a chave: ");
            scanf("%d", &valor);
            lista = IncluiDepois(lista, chave, valor);
            printf("Valor %d incluído após a chave %d.\n", valor, chave);
            break;
        case 4:
            lista = ExcluiCabeca(lista);
            printf("Cabeça excluída.\n");
            break;
        case 5:
            lista = ExcluiCalda(lista);
            printf("Cauda excluída.\n");
            break;
        case 6:
            printf("Digite o valor a ser excluído: ");
            scanf("%d", &valor);
            lista = ExcluiChave(lista, valor);
            printf("Valor %d excluído.\n", valor);
            break;
        case 7:
            printf("Saindo...\n");
            break;
        default:
            printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}
