#include <stdio.h>


int somaDigitos(int n) {
    // Caso base: se o número for menor que 10, seu próprio valor é a soma dos dígitos
    if (n < 10) {
        return n;
    } else {
        // Caso recursivo: soma o último dígito (n % 10) com a soma dos dígitos do restante do número (n / 10)
        return (n % 10) + somaDigitos(n / 10);
    }
}

int produto(int a, int b) {
    // Caso base: Se b é 0, o produto é 0
    if (b == 0) {
        return 0;
    } else if (b > 0) {
        // Caso b seja positivo, soma 'a' a 'produto(a, b-1)'
        return a + produto(a, b - 1);
    } else {
        // Caso b seja negativo, subtrai 'a' de 'produto(a, -b)'
        return -a + produto(a, b + 1);
    }
}

int potencia(int x, int n){
    if(n == 0){
        return 1;
    }
    else{
        return x * potencia(x, n-1);
    }

}

int ehPalindromo(char *str, int inicio, int fim) {
    // Caso base: se a string tiver apenas um caractere ou nenhum caractere, é um palíndromo
    if (inicio >= fim) {
        return 1;
    }

    // Verifica se os caracteres no início e no fim da string são iguais
    if (str[inicio] != str[fim]) {
        return 0; // Se forem diferentes, não é um palíndromo
    }

    // Chama a função recursivamente para verificar o restante da string
    return ehPalindromo(str, inicio + 1, fim - 1);
}

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}


int maiorElemento(int vetor[], int tamanho) {
    if (tamanho == 1) {
        return vetor[0];
    } else {
        int maiorRestante = maiorElemento(vetor, tamanho - 1);
        return (vetor[tamanho - 1] > maiorRestante) ? vetor[tamanho - 1] : maiorRestante;
    }
}


int posicaoElemento(int vetor[], int tamanho, int elemento, int indice) {
    if (indice == tamanho) {
        return -1; // Elemento não encontrado
    } else if (vetor[indice] == elemento) {
        return indice; // Elemento encontrado
    } else {
        return posicaoElemento(vetor, tamanho, elemento, indice + 1); // Verifica o próximo elemento
    }
}

int posicaoElementoOrdenado(int vetor[], int inicio, int fim, int elemento) {
    if (inicio > fim) {
        return -1; // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == elemento) {
        return meio; // Elemento encontrado
    } else if (vetor[meio] < elemento) {
        return posicaoElementoOrdenado(vetor, meio + 1, fim, elemento); // Verifica a metade direita
    } else {
        return posicaoElementoOrdenado(vetor, inicio, meio - 1, elemento); // Verifica a metade esquerda
    }
}


#include <stdio.h>

int main() {
    // Testando a função somaDigitos
    int numero1 = 12345;
    printf("A soma dos digitos de %d e: %d\n", numero1, somaDigitos(numero1));

    // Testando a função produto
    int numA = 5, numB = 3;
    printf("O produto de %d e %d e: %d\n", numA, numB, produto(numA, numB));

    // Testando a função potencia
    int base = 2, expoente = 3;
    printf("%d elevado a %d e igual a: %d\n", base, expoente, potencia(base, expoente));

    // Testando a função ehPalindromo
    char palindromo[] = "arara";
    if (ehPalindromo(palindromo, 0, strlen(palindromo) - 1)) {
        printf("A string \"%s\" e um palindromo.\n", palindromo);
    } else {
        printf("A string \"%s\" nao e um palindromo.\n", palindromo);
    }

    // Testando a função mdc
    int a = 15, b = 18;
    printf("O MDC de %d e %d e: %d\n", a, b, mdc(a, b));

    // Testando a função maiorElemento
    int vetor[] = {4, 7, 2, 9, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    printf("O maior elemento do vetor e: %d\n", maiorElemento(vetor, tamanho));

    // Testando a função posicaoElemento
    int elemento = 9;
    int posicao = posicaoElemento(vetor, tamanho, elemento, 0);
    if (posicao != -1) {
        printf("O elemento %d esta na posicao %d no vetor.\n", elemento, posicao);
    } else {
        printf("O elemento %d nao foi encontrado no vetor.\n", elemento);
    }

    // Testando a função posicaoElementoOrdenado
    int vetorOrdenado[] = {2, 3, 5, 7, 9};
    int posicaoOrdenado = posicaoElementoOrdenado(vetorOrdenado, 0, tamanho - 1, elemento);
    if (posicaoOrdenado != -1) {
        printf("O elemento %d esta na posicao %d no vetor ordenado.\n", elemento, posicaoOrdenado);
    } else {
        printf("O elemento %d nao foi encontrado no vetor ordenado.\n", elemento);
    }

    return 0;
}
