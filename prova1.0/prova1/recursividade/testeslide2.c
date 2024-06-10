#include <stdio.h>

int pot(int base, int exp)
{
    if (!exp){
        return 1;
    }
    else{
        return (base*pot(base, exp-1));
    }
}

int main(){
    int x, y;
    printf("Escreva um número para base: ");
    scanf("%d", &x);
    printf("Escreva um número para o expoente: ");
    scanf("%d", &y);

    int valor_final = pot(x,y);
    printf("%d", valor_final);

    return 0;
}