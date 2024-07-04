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

void mostrarOpções()
{
    printf("1 - Carregar Arquivo de Dados\n");
    printf("2 - Emitir Relatorios\n");
    printf("3 - Sair\n");
}


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


void carregarArquivo()
{
    char *nomeArq[50];

    printf("Digite o nome do arquivo: \n");
    scanf("%s", nomeArq);

    FILE *ARQBASE = fopen("Breast_Cancer.csv", "r");

    if (nomeArq != ARQBASE)
    {
        printf("Arquivo Inexistente... \n");
    }
}

void emitirRelatorio()
{
}

int main()
{
    int opcao;
    do
    {
        mostrarOpções();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Carregar Arquivo de Dados\n");
            break;
        case 2:
            printf("Emitir Relatorios\n");
            break;
        case 3:
            printf("Sair\n");
            break;
        default:
            printf("Opção Inválida\n");
        }
    } while (opcao != 3);
    return 0;
}