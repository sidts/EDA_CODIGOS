#include <stdio.h>


// complexidade O(n)
// Função de busca sequencial ordenada
int buscaSequencialOrdenada(int *V, int n, int chave) {
    int posic = -1;
    int p = 0;
    while (p < n && chave <= V[p]) {
        if (V[p] == chave) {
            posic = p;
            break; // Se a chave for encontrada, podemos interromper o loop
        }
        p++;
    }
    return posic;
}

int main() {
    int vetor[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Vetor ordenado
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Realiza algumas buscas
    int chave;
    while (1) {
        printf("Digite um número para buscar (-1 para sair): ");
        scanf("%d", &chave);
        if (chave == -1)
            break;
        int posicao = buscaSequencialOrdenada(vetor, tamanho, chave);
        if (posicao != -1) {
            printf("Número encontrado na posição %d.\n", posicao);
        } else {
            printf("Número não encontrado.\n");
        }
    }

    return 0;
}
