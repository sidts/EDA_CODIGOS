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

void intercala(int p, int q, int r, struct dados *v[])
{
    // está assim por conta da alocação dinamica
    struct dados **w;
    w = malloc((r - p) * sizeof(int));
    int i = p, j = q;
    int k = 0;

    while (i < q && j < r)
    {
        if (v[i]->populacao <= v[j]->populacao)
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i < q)
        w[k++] = v[i++];
    while (j < r)
        w[k++] = v[j++];
    for (i = p; i < r; ++i)
        v[i] = w[i - p];
    free(w);
}

void mergesort(int p, int r, struct dados *v[])
{
    if (p < r - 1)
    {
        int q = (p + r) / 2;
        mergesort(p, q, v);
        mergesort(q, r, v);
        intercala(p, q, r, v);
    }
}

int main()
{
    struct dados dados[5571];
    // para poder mexer com array escrever assim
    struct dados *dados_ptrs[5571];
    FILE *fp = fopen("estimativa_dou_2021.csv", "r");
    if (fp == NULL)
    {
        puts("Arquivo não encontrado\n");
        system("pause");
        exit(0);
    }

    FILE *ff = fopen("arquivo_ordenado_intercala", "w");
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
        mergesort(0 , i, dados_ptrs);

        for (int j = 0; j < i; j++)
        {
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