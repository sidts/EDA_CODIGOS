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

int smallerIndex(struct dados populacao[], int tam, int ini){
    int min = ini, j;
    for(j=ini+1; j<tam; j++){
        if(populacao[j].populacao > populacao[min].populacao)
        min = j;
    }
    return min;
}

void ordenaPopulacao(struct dados *populacao, int tam){
    int i, min, aux;
    for(i = 0 ; i < tam ; i++){
        min = smallerIndex(populacao, tam, i);
        aux = populacao[i].populacao;
        populacao[i] = populacao[min];
        populacao[min].populacao = aux;
    }
}


int main(){
    struct dados dados[5571];
    FILE *fp = fopen("estimativa_dou_2021.csv", "r");
    if(fp == NULL){
        puts("Arquivo não encontrado\n");
        system("pause");
        exit(0);
    }

    FILE *ff = fopen("arquivo_ordenado", "w");
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
                i++;
        }
        ordenaPopulacao(dados, i);

        for(int j = 0 ; j < i ; j++){
            fprintf(ff, "%s;%s;%s;%s;%d\n",
            dados[j].uf,
            dados[j].cod_uf,
            dados[j].cod_mun,
            dados[j].nome,
            dados[j].populacao);
        }

    
        fclose(ff);
        fclose(fp);
        return 0;


    }
}