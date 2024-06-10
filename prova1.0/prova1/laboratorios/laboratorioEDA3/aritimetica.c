#include <stdio.h>
#include <ctype.h>

// Função auxiliar para processar números
int processNumber(const char **str) {
    int num = 0;
    while (isdigit(**str)) {
        // conversão a partir da tabela ascii
        num = num * 10 + (**str - '0');
        (*str)++;
    }
    return num;
}

// Função recursiva para avaliar expressões
int eval(const char **str) {
    int result = 0;
    char op = '+';

    while (**str) {
        if (**str == ' ') {
            (*str)++;
            continue;
        }
        if (**str == '(') {
            (*str)++; // pular o '('
            int subresult = eval(str);
            if (op == '+') result += subresult;
            if (op == '-') result -= subresult;
        } else if (isdigit(**str)) {
            int num = processNumber(str);
            if (op == '+') result += num;
            if (op == '-') result -= num;
        } else if (**str == ')') {
            (*str)++; // pular o ')'
            return result;
        } else {
            op = **str; // o operador
            (*str)++;
        }
    }
    return result;
}

// Função principal
int main() {
    const char *expression = "1 + (2 - (4 + 5) + (1 - 6))";
    printf("Resultado da expressao %s ", expression);
    printf("e %d", eval(&expression));
    return 0;
}