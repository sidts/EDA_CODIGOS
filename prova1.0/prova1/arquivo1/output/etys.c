#include <stdio.h>

int main() {
    char ch;
    int contc = 0, contt = 0, conte = 0, contl = 0;
    FILE *fp;
    
    fp = fopen("arquivo1.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        contc++;
        if (ch == ' ') {
            conte++;
        }
        else if (ch == '\n') {
            contl++;
        }
        else if (ch == '\t') {
            contt++;
        }
    }

    fclose(fp);

    printf("Contador de caracteres: %d\n", contc);
    printf("Contador de espaços: %d\n", conte);
    printf("Contador de linhas: %d\n", contl);
    printf("Contador de tabs: %d\n", contt);

    return 0;
}
