#include <stdio.h>

// n é o tamanho do vetor, V* é o ponteiro que aponta para o vetor
// O(log2n)
int buscaBinaria(int *V, int n, int chave)
{
    int inicio, final, meio;
    inicio = 0;
    final = n - 1;
    while (inicio <= final)
    {
        meio = (inicio + final) / 2;
        if (chave == V[meio])
            return meio;
        if (chave < V[meio])
            final = meio - 1 ;
        else
            inicio = meio + 1;
    }
    return -1;
}

int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");


    int chave;
    while (1) {
        printf("Digite um número para buscar (-1 para sair): ");
        scanf("%d", &chave);
        if (chave == -1)
            break;
        int indice = buscaBinaria(vetor, tamanho, chave);
        if (indice != -1) {
            printf("Número encontrado na posição %d.\n", indice);
        } else {
            printf("Número não encontrado.\n");
        }
    }

    return 0;
}