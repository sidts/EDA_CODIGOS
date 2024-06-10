#include <stdio.h>


typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso; // define o campo Peso
    int Idade; // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado


void SetPessoa(Pessoa *P, int idade, float peso, float altura)
{ // Nesta função o parâmetro P é um ponteiro para uma struct
    (*P).Idade = idade; // o campo pode ser acessado desta forma
    P->Peso = peso; // ou desta
    P->Altura = altura;
}

void ImprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
    printf("Idade: %d Peso: %.2f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}


int main()
{
    Pessoa Joao;
    SetPessoa(&Joao, 15, 70.5, 1.75);
    ImprimePessoa(Joao);
    return 0;
}