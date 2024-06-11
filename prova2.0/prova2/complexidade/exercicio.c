#include <stdio.h>
#include <math.h>

void questao5(float *v, int m, int j, int k) {
    int pmenor, pdir, pesq; // Declara variáveis para posições menores, à direita e à esquerda
    pesq = j - 1; // Inicializa a posição à esquerda do elemento central
    pdir = j + 1; // Inicializa a posição à direita do elemento central

    while (k > 0) { // Continua até que k elementos sejam encontrados
        if ((pesq >= 0) && (pdir < m)) { // Verifica se ambos os índices estão dentro dos limites do array
            if (fabs(v[pesq] - v[j]) < fabs(v[pdir] - v[j])) { // Compara a diferença absoluta dos elementos com o central
                pmenor = pesq; // Se a diferença do elemento à esquerda for menor, seleciona este
                pesq--; // Move para a próxima posição à esquerda
            } else {
                pmenor = pdir; // Se a diferença do elemento à direita for menor ou igual, seleciona este
                pdir++; // Move para a próxima posição à direita
            }
        } else if (pesq >= 0) { // Se só há elementos à esquerda
            pmenor = pesq; // Seleciona o elemento à esquerda
            pesq--; // Move para a próxima posição à esquerda
        } else if (pdir < m) { // Se só há elementos à direita
            pmenor = pdir; // Seleciona o elemento à direita
            pdir++; // Move para a próxima posição à direita
        } else {
            break; // Se não há mais elementos à esquerda ou à direita, sai do loop
        }

        printf("%f\n", v[pmenor]); // Imprime o elemento selecionado
        k--; // Decrementa o contador de elementos a serem encontrados
    }

    return; // Retorna da função
}
