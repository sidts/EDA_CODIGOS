#include <stdio.h>

long int somavet(int *a, int qtde){
    if(qtde == 0){
        return 0;
    }
    else{
       //  a[0] é o primeiro vetor, a+1 representa que o ponteiro estará apontando para o próximo vetor(a[1]), qtde-1 ele encurta o tamanho do vetor
        return a[0] + somavet(a+1, qtde-1);
    }

}


int sao_iguais(char *s1, char *s2) {
    // Se ambas as strings estiverem vazias, elas são iguais
    if (*s1 == '\0' && *s2 == '\0') {
        return 1;
    }
    //Se um dos caracteres for diferente ou uma das strings chegar ao fim enquanto a outra não,
    //elas não são iguais
    if (*s1 != *s2 || (*s1 == '\0' && *s2 != '\0') || (*s1 != '\0' && *s2 == '\0')) {
        return 0;
    }
    // Chamada recursiva com os próximos caracteres
    return sao_iguais(s1 + 1, s2 + 1);
}

int fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return fibonacci(n-1) + fibonacci(n-2);
    }
}



int main(){
    int a[] ={0,1,2,3,4,5,6,7};
    // sizeof é a quantidade de bytes da variavel
    int tamanho = sizeof(a)/sizeof(a[0]);
    int soma = somavet(a, tamanho);
    printf("%d\n", soma);


    char str1[] = "Filipe";
    char str2[] = "Fijipe";

    if(sao_iguais(str1, str2)){
        printf("Sao iguais\n");
    }
    else{
        printf("Sao diferentes\n");
    }


    return 0;
}