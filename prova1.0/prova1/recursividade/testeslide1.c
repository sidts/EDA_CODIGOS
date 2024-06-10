#include <stdio.h>
#include <stdlib.h>


int Fatorial(int x)
{
    if (x == 1 || x == 0)
    {
        // condição de parada( caso x==1 e x==0, pois é sempre 1)
        return 1;
    }
    else
    {
        // chama a propria função no return, sendo assim recursividade
        return x * Fatorial(x-1);
    }
}

int main(){
    int x;
    scanf("%d", &x);
    int valor_final = Fatorial(x);
    printf("%d", valor_final);
    
    return 0;
}