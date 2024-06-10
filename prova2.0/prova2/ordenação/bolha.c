#include <stdio.h>
#include <stdlib.h>

#define TAM_MAX_COD_MUN 5
#define TAM_MAX_NOME 40

struct dados
{
    char uf[3];
    char cod_uf[5];
    char cod_mun[TAM_MAX_COD_MUN];
    char nome[TAM_MAX_NOME];
    int populacao;
};

void bubbleSort(struct dados *vet[], int tam)
{
    int i, j;
    struct dados *temp;
    for (i = tam - 1; i > 0; i--)
    {
        for (j = 0; j < i; j++) // Faz trocas até posição i
            if (vet[j]->populacao > vet[j + 1]->populacao)
            {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
    }
}

int main()
{
    struct dados dados[5571];
    struct dados *dados_ptrs[5571];
    FILE *fp = fopen("estimativa_dou_2021.csv", "r");
    if (fp == NULL)
    {
        puts("Arquivo não encontrado\n");
        system("pause");
        exit(0);
    }

    FILE *ff = fopen("arquivo_ordenado_bolha", "w");
    if (ff == NULL)
    {
        puts("Arquivo não criado\n");
        system("pause");
        exit(0);
    }

    if (fp != NULL)
    {

        char primeiralinha[100]; // Lê a primeira linha do arquivo e armazena em primeiralinha
        fscanf(fp, "%[^\n]\n", primeiralinha);
        int i = 0;

        while (!feof(fp))
        {
            fscanf(fp, "%[^;];%2[^;];%[^;];%[^;];%d",
                dados[i].uf,
                dados[i].cod_uf,
                dados[i].cod_mun,
                dados[i].nome,
                &dados[i].populacao);
            dados_ptrs[i] = &dados[i];
            i++;
        }
        bubbleSort(dados_ptrs, i);

        for (int j = 0; j < i; j++)
        {
            // tá assim por mexer com array
            fprintf(ff, "%s;%s;%s;%s;%d\n",
                    dados_ptrs[j]->uf,
                    dados_ptrs[j]->cod_uf,
                    dados_ptrs[j]->cod_mun,
                    dados_ptrs[j]->nome,
                    dados_ptrs[j]->populacao);
        }

        fclose(ff);
        fclose(fp);
        return 0;
    }
}
