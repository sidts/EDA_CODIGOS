#include <stdio.h>
// manipulação de string
#include <string.h>
// alocação de memória
#include <stdlib.h>

// Função para encontrar a posição do ponto no nome do arquivo
int namefilepointposition(char *fullname) {
    int i;
    // vê o tamanho da string o strlen
    for (i = 0; i < strlen(fullname); i++) {
        // retorna a posição do ponteiro
        if (fullname[i] == '.')
            break;
    } 
    if (i >= strlen(fullname))
    // return -1 quer dizer que ele não acha ou quebra
        return -1;
    else
        // retorna a posição do nome
        return i;
}

// Função para converter o texto em um arquivo para o formato de vetor de palavras
int word2vec(char *pNomeTxtEntrada) {
    FILE *arqent, *arqsaida;
    char nomarq[40];
    int pointidx = namefilepointposition(pNomeTxtEntrada);
    int pp;
    // Gerando o nome do arquivo de saída    
    if (pointidx >= 0) {
        for (pp = 0; pp < pointidx; pp++)
            nomarq[pp] = pNomeTxtEntrada[pp];
        nomarq[pp] = '\0'; // Fim da string
    } else
    // copia o conteúdo de uma string para outra
    strcpy(nomarq, pNomeTxtEntrada);

    //adciona uma string a outra, nome do arquivo a vocabulo e txt
    strcat(nomarq, "_Vocabulo");
    strcat(nomarq, ".txt");

    // Gerando a saída:
    arqent = fopen(pNomeTxtEntrada, "r");
    arqsaida = fopen(nomarq, "w");
    char ch;
    if (arqent == NULL) {
        printf("Não existe arquivo\n");
        return 0;
    }
    while ((ch = fgetc(arqent)) != EOF) {
        if (ch != ' ') {
            fputc(ch, arqsaida);
        } else {
            fputc(',', arqsaida);
            fputc('\n', arqsaida);
        }
    }
    fclose(arqent);
    fclose(arqsaida);

    return 1;
}

// Função para verificar se uma palavra existe em um arquivo
int verificador(char *nomeArquivo, char *palavra) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        return 0;
    }
    char palavraAtual[100];
    while (fscanf(arquivo, "%s", palavraAtual) != EOF) {
        if (strcmp(palavraAtual, palavra) == 0) {
            fclose(arquivo);
            return 1;
        }
    }
    fclose(arquivo);
    return 0;
}

// Função para adicionar uma palavra a um arquivo
void adicionarPalavra(char *nomeArquivo, char *palavra) {
    FILE *arquivo = fopen(nomeArquivo, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }
    fprintf(arquivo, "%s\n", palavra);
    fclose(arquivo);
}

// Função para remover palavras duplicadas de um arquivo
int semDuplicacao(char *nomeArquivo) {
    FILE *arquent, *arqusaida;
    char palavra[100];
    arquent = fopen(nomeArquivo, "r");
    arqusaida = fopen("arquivocriado3.txt", "w");

    if (arquent == NULL || arqusaida == NULL) {
        printf("Erro ao abrir os arquivos\n");
        return 0;
    }

    while (fscanf(arquent, "%s", palavra) != EOF) {
        if (!verificador("arquivocriado3.txt", palavra)) {
            fprintf(arqusaida, "%s\n", palavra);
            adicionarPalavra("arquivocriado3.txt", palavra);
        }
    }

    printf("\nArquivo limpo com sucesso\n");

    fclose(arquent);
    fclose(arqusaida);

    return 1;
}

int main() {
    char nomearq[30];
    printf("Entre com nome do arquivo:");
    scanf("%s",nomearq);
    if (!word2vec(nomearq))
        printf("\nErro na geração do vocabulário!");
    else
        printf("\nVocabulário gerado com sucesso!");

    if(!semDuplicacao(nomearq)){
        printf("Erro na geração\n");
    }
    else
        printf("\nTokenização finalizada");
    

    return 0;
}
