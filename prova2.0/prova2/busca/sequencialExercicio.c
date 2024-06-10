#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 5570
#define MAX_NOME 50

struct Municipio {
    int linha;
};

struct Dados {
    char uf[3];
    char cod_uf[5];
    char cod_mun[6];
    char nome[MAX_NOME];
    int populacao;
};


void carregarMunicipio(struct Municipio municipios[], const char *filename);
void obterDadosLinha(int linha, const char *filename, struct Dados *dados);
void imprimirDados(const struct Dados *dados);
int buscaSequencialDesordenada(struct Municipio *V, int n, int chave);

int main() {
    struct Municipio municipios[MAX_LINHA];
    const char *filename = "estimativa_dou_2021.csv";

    carregarMunicipio(municipios, filename);

    int opcao;
    while (1) {
        printf("1. Buscar por número da linha\n2. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int linha;
            printf("Digite o número da linha: ");
            scanf("%d", &linha);

            if (linha >= 1 && linha <= MAX_LINHA) {
                struct Dados dados;
                int indice = buscaSequencialDesordenada(municipios, MAX_LINHA, linha);
                if (indice != -1) {
                    obterDadosLinha(municipios[indice].linha, filename, &dados);
                    imprimirDados(&dados);
                } else {
                    printf("Número de linha não encontrado.\n");
                }
            } else {
                printf("Número de linha inválido.\n");
            }
        } else if (opcao == 2) {
            break;
        } else {
            printf("Opção inválida. Por favor, tente novamente.\n");
        }
    }

    return 0;
}

void carregarMunicipio(struct Municipio municipios[], const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char linha[MAX_NOME + 20]; // Aumentando o tamanho para garantir que a linha completa seja lida
    int i = 0;
    while (fgets(linha, sizeof(linha), file)) {
        municipios[i].linha = i + 1;
        i++;
    }

    fclose(file);
}

void obterDadosLinha(int linha, const char *filename, struct Dados *dados) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    char fileLine[MAX_NOME + 20];
    int currentLine = 0;
    while (fgets(fileLine, sizeof(fileLine), file)) {
        currentLine++;
        if (currentLine == linha) {
            fclose(file); // Fecha o arquivo antes de retornar, evitando vazamento de recursos

            // Remove o caractere de nova linha, se presente
            char *newline = strchr(fileLine, '\n');
            if (newline) *newline = '\0';

            
            if (sscanf(fileLine, "%[^;];%2[^;];%[^;];%[^;];%d", dados->uf, dados->cod_uf, dados->cod_mun, dados->nome, &dados->populacao) != 5) {
                fprintf(stderr, "Erro ao ler os dados da linha.\n");
                exit(EXIT_FAILURE);
            }

            return;
        }
    }

    fclose(file);
    fprintf(stderr, "Erro: Linha não encontrada.\n");
    exit(EXIT_FAILURE);
}


void imprimirDados(const struct Dados *dados) {
    printf("UF: %s\n", dados->uf);
    printf("Código UF: %s\n", dados->cod_uf);
    printf("Código Município: %s\n", dados->cod_mun);
    printf("Nome do Município: %s\n", dados->nome);
    printf("População: %d\n", dados->populacao);
}

int buscaSequencialDesordenada(struct Municipio *V, int n, int chave) {
    int posic = -1;
    for (int p = 0; p < n; p++) {
        if (chave == V[p].linha) {
            posic = p;
            break;
        }
    }
    return posic;
}
