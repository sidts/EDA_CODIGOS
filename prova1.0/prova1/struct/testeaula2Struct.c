#include <stdio.h>


typedef struct // Cria uma STRUCT para armazenar os dados de uma pessoa
{
    float Peso; // define o campo Peso
    int Idade; // define o campo Idade
    float Altura; // define o campo Altura
} Pessoa; // Define o nome do novo tipo criado


//faz uma função baseada em uma struct
Pessoa SetPessoa(int idade, float peso, float altura)
{
    Pessoa P;
    P.Idade = idade;
    P.Peso = peso;
    P.Altura = altura;
    return P; // retorna a struct contendo os dados passados por parâmetro
}

void ImprimePessoa(Pessoa P) // declara o parâmetro como uma struct
{
    printf("Idade: %d Peso: %.2f Altura: %.2f\n", P.Idade, P.Peso, P.Altura);
}


int main()
{
    Pessoa Joao;
// atribui o retorno da função a uma variável struct:
    Joao = SetPessoa(15,60.5,1.75);
    ImprimePessoa(Joao);
    return 0;
}