#include <stdio.h>

// Função de busca sequencial desordenada
int buscaSequencialDesordenada(int *V, int n, int chave) {
    int posic = -1;
    for (int p = 0; p < n; p++) {
        if (chave == V[p]) {
            posic = p;
            break; // Se a chave for encontrada, podemos interromper o loop
        }
    }
    return posic;
}

int main() {
    int vetor[] = {7, 2, 5, 8, 1, 9, 3, 6, 4}; // Vetor desordenado
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
        int posicao = buscaSequencialDesordenada(vetor, tamanho, chave);
        if (posicao != -1) {
            printf("Número encontrado na posição %d.\n", posicao);
        } else {
            printf("Número não encontrado.\n");
        }
    }

    return 0;
}
