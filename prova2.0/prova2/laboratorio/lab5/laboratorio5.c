#include <stdio.h>
#include <stdlib.h>

struct dados_voo
{
    int Lenght; // Tempo do voo (Length)
    int Delay;  // Indicação de Delay (Delay)
};

// Função de particionamento do Quick Sort
int separa(struct dados_voo *v[], int baixo, int alto)
{
    int pivo = v[alto]->Lenght;
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (v[j]->Lenght < pivo)
        {
            i++;
            struct dados_voo *temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    struct dados_voo *temp = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = temp;
    return (i + 1);
}

// Implementação do Quick Sort
void quicksort(struct dados_voo *v[], int baixo, int alto)
{
    if (baixo < alto)
    {
        int pi = separa(v, baixo, alto);
        quicksort(v, baixo, pi - 1);
        quicksort(v, pi + 1, alto);
    }
}

int main()
{
    struct dados_voo dados[200]; // Ajustado para o tamanho do caso de teste
    struct dados_voo *dados_ptrs[200];

    // Abrindo o arquivo CSV de entrada
    FILE *fp = fopen("C:\\Users\\enric\\OneDrive\\Documentos\\Programas\\EDA_CODIGOS\\prova2.0\\prova2\\laboratorio\\metade.csv", "r");
    if (fp == NULL)
    {
        perror("Erro ao abrir o arquivo de entrada");
        exit(EXIT_FAILURE);
    }

    // Criando o arquivo de saída
    FILE *ff = fopen("arquivo_ordenado.txt", "w");
    if (ff == NULL)
    {
        perror("Erro ao criar o arquivo de saída");
        fclose(fp);
        exit(EXIT_FAILURE);
    }

    char primeira_linha[256];
    if (!fgets(primeira_linha, sizeof(primeira_linha), fp))
    {
        perror("Erro ao ler a primeira linha do arquivo");
        fclose(fp);
        fclose(ff);
        exit(EXIT_FAILURE);
    }

    int i = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), fp))
    {
        if (i >= 200)
        { // Ajuste para o tamanho do caso de teste
            fprintf(stderr, "Número de linhas excede o tamanho do array.\n");
            break;
        }
        if (sscanf(linha, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%*[^,],%d,%d",
                &dados[i].Lenght,
                &dados[i].Delay) == 2)
        {
            dados_ptrs[i] = &dados[i];
            i++;
        }
        else
        {
            fprintf(stderr, "Erro ao ler linha %d: %s", i + 1, linha);
        }
    }

    if (i > 0)
    {
        quicksort(dados_ptrs, 0, i - 1);

        for (int j = 0; j < i; j++)
        {
            if (fprintf(ff, "%d;%d\n", dados_ptrs[j]->Lenght, dados_ptrs[j]->Delay) < 0)
            {
                perror("Erro ao escrever no arquivo de saída");
                fclose(ff);
                fclose(fp);
                exit(EXIT_FAILURE);
            }
        }
    }

    fclose(ff);
    fclose(fp);
    printf("Arquivo ordenado criado com sucesso.\n");
    return 0;
}