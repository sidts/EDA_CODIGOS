#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINHA 200
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
int buscaBinaria(struct Municipio municipios[], int inicio, int fim, int chave);

int main() {
    struct Municipio municipios[5570];
    const char *filename = "arquivo_ordenado_insercao.txt";

    carregarMunicipio(municipios, filename);

    int opcao;
    while (1) {
        printf("Menu:\n1. Buscar por número da linha\n2. Sair\nEscolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int linha;
            printf("Digite o número da linha: ");
            scanf("%d", &linha);

            if (linha >= 1 && linha <= 5570) {
                struct Dados dados;
                int indice = buscaBinaria(municipios, 0, 5569, linha);
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

    char linha[MAX_LINHA];
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

    char fileLine[MAX_LINHA];
    int currentLine = 0;
    while (fgets(fileLine, sizeof(fileLine), file)) {
        currentLine++;
        if (currentLine == linha) {
            sscanf(fileLine, "%2s;%4s;%5s;%[^;];%d", dados->uf, dados->cod_uf, dados->cod_mun, dados->nome, &dados->populacao);
            fclose(file);
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

int buscaBinaria(struct Municipio municipios[], int inicio, int fim, int chave) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (municipios[meio].linha == chave) {
        return meio;
    } else if (municipios[meio].linha < chave) {
        return buscaBinaria(municipios, meio + 1, fim, chave);
    } else {
        return buscaBinaria(municipios, inicio, meio - 1, chave);
    }
}
