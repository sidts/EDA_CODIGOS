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

int separa(struct dados *a[], int p, int r)
{

    int c = a[r]->populacao; // pivô
    int j = p;
    for (int k = p; k < r; ++k)
        if (a[k]->populacao <= c)
        {
            struct dados *t = a[j];
            a[j] = a[k];
            a[k] = t;
            ++j;
        }
    struct dados *t = a[j];
    a[j] = a[r];
    a[r] = t;
    return j;
}

void quicksort(struct dados *a[], int p, int r)
{
    if (p < r)
    {
        int j = separa(a, p, r);
        quicksort(a, p, j - 1);
        quicksort(a, j + 1, r);
    }
}


int main(){
    struct dados dados[5571];
    // para poder mexer com array escrever assim
    struct dados *dados_ptrs[5571];
    FILE *fp = fopen("estimativa_dou_2021.csv", "r");
    if(fp == NULL){
        puts("Arquivo não encontrado\n");
        system("pause");
        exit(0);
    }

    FILE *ff = fopen("arquivo_ordenado_quicksort", "w");
    if(ff == NULL){
        puts("Arquivo não criado\n");
        system("pause");
        exit(0);
    }


    if(fp != NULL){
        
        char primeiralinha[100]; // Lê a primeira linha do arquivo e armazena em primeiralinha
        fscanf(fp, "%[^\n]\n", primeiralinha);
        int i = 0;

        while(!feof(fp)){
                fscanf(fp, "%[^;];%2[^;];%[^;];%[^;];%d",
                dados[i].uf,
                dados[i].cod_uf,
                dados[i].cod_mun,
                dados[i].nome,
                &dados[i].populacao);
                dados_ptrs[i] = &dados[i];
                i++;
        }
        quicksort(dados_ptrs, 0, i - 1);
        // tá assim por mexer com array
        for(int j = 0 ; j < i ; j++){
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
