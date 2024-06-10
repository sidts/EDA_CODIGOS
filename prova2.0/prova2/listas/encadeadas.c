#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura do nó da lista
struct TNo {
    int Numero;      // Variável para armazenar o número
    struct TNo *Prox;  // Ponteiro para o próximo nó da lista
};

// Função para verificar se a lista está vazia
int Vazia(struct TNo *pLista) {
    if (pLista == NULL) {
        return 1; // Lista está vazia
    } else {
        return 0; // Lista não está vazia
    }
}

// Função para incluir um elemento no início da lista (cabeça da lista)
// Complexidade O(1)
struct TNo *IncluiCabeca(struct TNo *pLista, int pValor) {
    // Aloca memória para um novo nó
    struct TNo *pNovoNo;
    pNovoNo = (struct TNo *)malloc(sizeof(struct TNo));
    
    // Atribui o valor à variável 'Numero' do novo nó
    pNovoNo->Numero = pValor;
    
    // Faz o ponteiro 'Prox' do novo nó apontar para o antigo primeiro nó da lista
    pNovoNo->Prox = pLista;
    
    // Atualiza a cabeça da lista para ser o novo nó
    pLista = pNovoNo;
    
    // Retorna a nova cabeça da lista
    return pLista;
}

// Função para incluir um elemento no final da lista (cauda da lista)
// Complexidade O(n)
struct TNo *IncluiCalda(struct TNo *pLista, int pValor) {
    // Aloca memória para um novo nó
    struct TNo *pNovoNo, *pAux;
    pNovoNo = (struct TNo *)malloc(sizeof(struct TNo));
    
    // Atribui o valor à variável 'Numero' do novo nó
    pNovoNo->Numero = pValor;
    
    // Como será o último nó, o próximo dele é NULL
    pNovoNo->Prox = NULL;
    
    // Se a lista estiver vazia, o novo nó será o primeiro nó
    if (pLista == NULL) {
        return pNovoNo;
    }
    
    // Percorre a lista até o último nó
    pAux = pLista;
    while (pAux->Prox != NULL) {
        pAux = pAux->Prox;
    }
    
    // Faz o último nó atual apontar para o novo nó
    pAux->Prox = pNovoNo;
    
    // Retorna a lista com o novo nó adicionado
    return pLista;
}

// Função para incluir um elemento antes de um nó específico na lista
// Complexidade O(n)
struct TNo *IncluiAntes(struct TNo *pLista, int pChave, int pValor) {
    // Aloca memória para um novo nó
    struct TNo *pNovoNo, *pAux;
    pNovoNo = (struct TNo *)malloc(sizeof(struct TNo));
    
    // Atribui o valor à variável 'Numero' do novo nó
    pNovoNo->Numero = pValor;
    
    // Se a lista estiver vazia ou o nó desejado for o primeiro nó, utiliza IncluiCabeca
    if (pLista == NULL || pLista->Numero == pChave) {
        pNovoNo->Prox = pLista;
        return pNovoNo;
    }
    
    // Percorre a lista até encontrar o nó anterior ao nó com a chave
    pAux = pLista;
    while (pAux->Prox != NULL && pAux->Prox->Numero != pChave) {
        pAux = pAux->Prox;
    }
    
    // Faz o novo nó apontar para o nó atual que tem a chave
    pNovoNo->Prox = pAux->Prox;
    
    // Faz o nó anterior apontar para o novo nó
    pAux->Prox = pNovoNo;
    
    // Retorna a lista com o novo nó adicionado
    return pLista;
}

// Função para excluir o primeiro elemento da lista (cabeça da lista)
// Complexidade O(1)
struct TNo *ExcluiCabeca(struct TNo *pLista) {
    if (pLista == NULL) return NULL;
    struct TNo *pAux = pLista;
    pLista = pLista->Prox;
    free(pAux);
    return pLista;
}

// Função para excluir o último elemento da lista (cauda da lista)
// Complexidade O(n)
struct TNo *ExcluiCalda(struct TNo *pLista) {
    if (pLista == NULL) return NULL;
    if (pLista->Prox == NULL) {
        free(pLista);
        return NULL;
    }
    struct TNo *pAux = pLista;
    while (pAux->Prox->Prox != NULL) {
        pAux = pAux->Prox;
    }
    free(pAux->Prox);
    pAux->Prox = NULL;
    return pLista;
}

// Função para excluir um nó específico na lista, identificado por sua chave
// Complexidade O(n)
struct TNo *ExcluiChave(struct TNo *pLista, int pChave) {
    if (pLista == NULL) return NULL;
    if (pLista->Numero == pChave) {
        struct TNo *pAux = pLista;
        pLista = pLista->Prox;
        free(pAux);
        return pLista;
    }
    struct TNo *pAnt = pLista;
    while (pAnt->Prox != NULL && pAnt->Prox->Numero != pChave) {
        pAnt = pAnt->Prox;
    }
    if (pAnt->Prox != NULL) {
        struct TNo *pAux = pAnt->Prox;
        pAnt->Prox = pAux->Prox;
        free(pAux);
    }
    return pLista;
}

// Função principal para demonstrar as operações na lista
int main() {
    // Inicializa a lista como vazia
    struct TNo *lista = NULL;

    // Verifica se a lista está vazia
    if (Vazia(lista)) {
        printf("A lista está vazia.\n");
    }

    // Inclui elementos na cabeça da lista
    lista = IncluiCabeca(lista, 10);
    lista = IncluiCabeca(lista, 20);
    lista = IncluiCabeca(lista, 30);
    printf("Incluiu 30, 20, 10 na cabeça da lista.\n");

    // Inclui um elemento no final da lista (cauda)
    lista = IncluiCalda(lista, 40);
    printf("Incluiu 40 na cauda da lista.\n");

    // Inclui um elemento antes de um nó específico
    lista = IncluiAntes(lista, 20, 25);
    printf("Incluiu 25 antes do 20 na lista.\n");

    // Exclui a cabeça da lista
    lista = ExcluiCabeca(lista);
    printf("Excluiu a cabeça da lista (30).\n");

    // Exclui a cauda da lista
    lista = ExcluiCalda(lista);
    printf("Excluiu a cauda da lista (40).\n");

    // Exclui um nó específico da lista
    lista = ExcluiChave(lista, 25);
    printf("Excluiu o nó com chave 25 da lista.\n");

    // Libera a memória alocada para os nós restantes
    while (lista != NULL) {
        struct TNo *temp = lista;
        lista = lista->Prox;
        free(temp);
    }

    printf("Memória liberada e lista excluída.\n");

    return 0;
}