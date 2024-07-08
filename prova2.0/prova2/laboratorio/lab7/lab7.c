#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DadosCancer {
    int age;
    char race;
    char maritalStatus;
    char tStage;
    char nStage;
    char sixthStage;
    char differentiate;
    int grade;
    char aStage;
    int tumorSize;
    char estrogenStatus;
    char progesteroneStatus;
    int regionalNodeExamined;
    int reginolNodePositive;
    int survivalMonths;
    char status;
    int linha; // Para armazenar a linha no arquivo
    struct DadosCancer *direita;
    struct DadosCancer *esquerda;
} DadosCancer;


// Função para criar um novo nó
DadosCancer* novoNo(int age, char race, char maritalStatus, char tStage, char nStage, char sixthStage, char differentiate, int grade, char aStage, int tumorSize, char estrogenStatus, char progesteroneStatus, int regionalNodeExamined, int reginolNodePositive, int survivalMonths, char status, int linha) {
    DadosCancer *novo = (DadosCancer*)malloc(sizeof(DadosCancer));
    novo->age = age;
    novo->race = race;
    novo->maritalStatus = maritalStatus;
    novo->tStage = tStage;
    novo->nStage = nStage;
    novo->sixthStage = sixthStage;
    novo->differentiate = differentiate;
    novo->grade = grade;
    novo->aStage = aStage;
    novo->tumorSize = tumorSize;
    novo->estrogenStatus = estrogenStatus;
    novo->progesteroneStatus = progesteroneStatus;
    novo->regionalNodeExamined = regionalNodeExamined;
    novo->reginolNodePositive = reginolNodePositive;
    novo->survivalMonths = survivalMonths;
    novo->status = status;
    novo->linha = linha;
    novo->direita = NULL;
    novo->esquerda = NULL;
    return novo;
}

// Função para inserir um novo nó na árvore
DadosCancer* inserirNo(DadosCancer* raiz, DadosCancer* novo) {
    if (raiz == NULL) {
        return novo;
    }
    // Exemplo: Ordenar por 'age'
    if (novo->age < raiz->age) {
        raiz->esquerda = inserirNo(raiz->esquerda, novo);
    } else {
        raiz->direita = inserirNo(raiz->direita, novo);
    }
    return raiz;
}


// Função para carregar o arquivo de dados
DadosCancer* carregarArquivo(char* nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return NULL;
    }

    DadosCancer *raiz = NULL;
    int age, grade, tumorSize, regionalNodeExamined, reginolNodePositive, survivalMonths, linha = 0;
    char race, maritalStatus, tStage, nStage, sixthStage, differentiate, aStage, estrogenStatus, progesteroneStatus, status;

    while (fscanf(arquivo, "%d %c %c %c %c %c %c %d %c %d %c %c %d %d %d %c",
                  &age, &race, &maritalStatus, &tStage, &nStage, &sixthStage,
                  &differentiate, &grade, &aStage, &tumorSize, &estrogenStatus,
                  &progesteroneStatus, &regionalNodeExamined, &reginolNodePositive,
                  &survivalMonths, &status) != EOF) {
        DadosCancer *novo = novoNo(age, race, maritalStatus, tStage, nStage, sixthStage, differentiate, grade, aStage, tumorSize, estrogenStatus, progesteroneStatus, regionalNodeExamined, reginolNodePositive, survivalMonths, status, linha);
        raiz = inserirNo(raiz, novo);
        linha++;
    }
    fclose(arquivo);
    return raiz;
}


// Função para percorrer a árvore em ordem e imprimir o relatório
void imprimirRelatorio(DadosCancer* raiz, char* nomeArquivo) {
    if (raiz == NULL) {
        printf("Arquivo Vazio!!!\n");
        return;
    }
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    if (raiz->esquerda != NULL) {
        imprimirRelatorio(raiz->esquerda, nomeArquivo);
    }

    char linha[256];
    fseek(arquivo, 0, SEEK_SET); // Reset file pointer
    for (int i = 0; i <= raiz->linha; i++) {
        fgets(linha, sizeof(linha), arquivo);
    }
    printf("%s", linha);

    if (raiz->direita != NULL) {
        imprimirRelatorio(raiz->direita, nomeArquivo);
    }

    fclose(arquivo);
}

// Função para desalocar a árvore
void desalocarArvore(DadosCancer* raiz) {
    if (raiz != NULL) {
        desalocarArvore(raiz->esquerda);
        desalocarArvore(raiz->direita);
        free(raiz);
    }
}


int main() {
    DadosCancer* raiz = NULL;
    int opcao;
    char nomeArquivo[256];

    do {
        printf("1. Carregar Arquivo de Dados\n");
        printf("2. Emitir Relatório\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do arquivo: ");
                scanf("%s", nomeArquivo);
                raiz = carregarArquivo(nomeArquivo);
                break;
            case 2:
                imprimirRelatorio(raiz, nomeArquivo);
                break;
            case 3:
                desalocarArvore(raiz);
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 3);

    return 0;
}
