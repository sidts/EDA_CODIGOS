#include <stdio.h>
#include <stdlib.h>

struct dados {  
    char nome[20];
    int idade;
    float salario;
};

int main() {
    struct dados e;
    FILE *fp;
    fp = fopen("EMPLOYEE.DAT", "r");
    
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while ( fscanf ( fp, "%s %d %f", e.nome, &e.idade, &e.salario ) != EOF )
    printf ( "%s %d %0.2f\n", e.nome, e.idade, e.salario ) ;
    system("pause");
    
    
    fclose(fp);

    return 0;
}
