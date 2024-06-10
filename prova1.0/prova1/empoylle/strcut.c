#include <stdio.h>
#include <stdlib.h>

struct dados {
    char nome[20];
    int idade;
    float salario;
};

int main() {
    struct dados info = {"Ph", 21, 1500.00};
    FILE *fp;
    // variavel para ler o digito e continuar cadastrando, quando digitado no teclado
    char continuar = 'S';

    fp = fopen("EMPLOYEE.DAT", "a");
    
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    while (continuar == 'S' || continuar == 's')
    {
        printf("Escreva o nome, idade e salario: \n");
        scanf("%s %d %f", info.nome,&info.idade, &info.salario);
        fprintf(fp, "%s %d %.2f\n", info.nome, info.idade, info.salario);
        printf("Deseja continuar (S/N) \n");
        // obtem o proximo digito no teclado
        continuar = getche();
    }
    
    fclose(fp);

    return 0;
}
