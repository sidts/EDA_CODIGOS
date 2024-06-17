#include <stdio.h>
#include <stdlib.h>

struct dados_voo
{
    int Lenght; // Tempo do voo (Length)
    int Delay;    // Indicação de atraso (Delay)
};

// Função de particionamento do Quick Sort
int separa(struct dados_voo v[], int baixo, int alto)
{
    int pivo = v[alto].Lenght;
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++)
    {
        if (v[j].Lenght < pivo)
        {
            i++;
            // Troca sem usar função swap
            struct dados_voo temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    // Troca sem usar função swap
    struct dados_voo temp = v[i + 1];
    v[i + 1] = v[alto];
    v[alto] = temp;
    return (i + 1);
}

// Implementação do Quick Sort
void quicksort(struct dados_voo v[], int baixo, int alto)
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
    struct dados_voo dados[539384];
    FILE *fp = fopen("Airlines.csv", "r");
    if (fp == NULL)
    {
        puts("Arquivo não encontrado\n");
        exit(0);
    }

    FILE *ff = fopen("arquivo_ordenado.txt", "w");
    if (ff == NULL)
    {
        puts("Arquivo não criado\n");
        exit(0);
    }

    char primeira_linha[256];
    if (fgets(primeira_linha, sizeof(primeira_linha), fp) == NULL)
    {
        puts("Erro ao ler a primeira linha\n");
        exit(0);
    }

    int i = 0;
    char linha[256];
    while (fgets(linha, sizeof(linha), fp))
    {
        if (sscanf(linha, "%*d;%*99[^;];%*d;%*3[^;];%*3[^;];%*d;%*d;%d;%d",
                   &dados[i].Lenght,
                   &dados[i].Delay) == 2)
        {
            i++;
        }
        else
        {
            printf("Erro ao ler linha: %s\n", linha);
        }
    }

    printf("Total de registros lidos: %d\n", i);

    quicksort(dados, 0, i - 1);

    for (int j = 0; j < i; j++)
    {
        fprintf(ff, "%d;%d\n",
                dados[j].Lenght,
                dados[j].Delay);
    }

    printf("Arquivo de saída criado com sucesso.\n");

    fclose(ff);
    fclose(fp);
    return 0;
}
