#include <stdio.h>
#include <stdlib.h>

// Esta fun��o rearranja o vetor v[0..n-1] em ordem crescente.
//Ref.: https://www.ime.usp.br/~pf/algoritmos/aulas/ordena.html

long int insercao(int n, int v[])
{
   long int pesforco = 0;
   for (int j = 1; j < n; ++j) {
      int x = v[j];
      int i;
      for (i = j-1; i >= 0 && v[i] > x; --i){
         v[i+1] = v[i];// COMANDO A SER CONTABILIZADO
         pesforco++;
      }
      v[i+1] = x;
   }
   return pesforco;
}


// Bubble sort algorithm.
// Ref.: https://github.com/kayelserafim/bubble-sort-mpi/blob/main/src/parallel_master.c

long int bs(int n, int *vetor) {
	int c = 0, d, troca, trocou = 1;
    long int pesforco = 0;
	while ((c < (n - 1)) & trocou) {
		trocou = 0;
		for (d = 0; d < n - c - 1; d++){
            pesforco++;
			if (vetor[d] > vetor[d + 1]) { // COMANDO A SER CONTABILIZADO
				troca = vetor[d];
				vetor[d] = vetor[d + 1];
				vetor[d + 1] = troca;
				trocou = 1;
			}
		}
		c++;
	}
    return pesforco;
}

int *gera_vet_aleatorio(int pn){
    int *pvet = (int *)malloc(sizeof(int)*pn);
    int pind;
    for(pind=0;pind<pn;pind++)
        pvet[pind] = rand();

    return pvet;
}


void funcaoT() {
    FILE *pArqTeste, *pArqComp;
    int n, *V, *Vcopia;
    long int eB = 0;
    long int el = 0;
    
    pArqComp = fopen("esforcocomputacional2.txt", "w");
    if (!pArqComp) {
        printf("Erro ao abrir arquivo de saída\n");
        return;
    }

    pArqTeste = fopen("testes2.txt", "r");
    if (!pArqTeste) {
        printf("Arquivo de Teste não encontrado\n");
        fclose(pArqComp);
        return;
    }
    
    // Processa o arquivo de teste
    while (fscanf(pArqTeste, "%d", &n) == 1) {
        V = gera_vet_aleatorio(n); // Gera o vetor aleatório original
        // Faz isso para que as comparações sejam feitas igualmente, pois pode ocorrer o risco
        // do vetor ser parcialmente ordenado e a outra função não precisar ordenar mais
        Vcopia = (int *)malloc(sizeof(int) * n); // Aloca memória para a cópia do vetor
        
        // Copia o vetor original para garantir que cada algoritmo receba o mesmo input
        for (int i = 0; i < n; i++) {
            Vcopia[i] = V[i];
        }
        
        eB = bs(n, V);
        el = insercao(n, Vcopia);

        fprintf(pArqComp, "[%d, %ld, %ld]\n", n, eB / n, el / n);
        
        free(V);
        free(Vcopia);
    }

    fclose(pArqTeste);
    fclose(pArqComp);
}


void funcaoR() {
    FILE *pArqComp = fopen("esforcocomputacional2.txt", "r");
    if (!pArqComp) {
        printf("Arquivo não encontrado\n");
        return;
    };
    int n, count = 0;
    long int eB, el;
    long int soma_eB = 0, soma_el = 0;
    long int menor_eB, maior_eB;
    long int menor_el, maior_el;


    if (fscanf(pArqComp, "[%d, %ld, %ld]\n", &n, &eB, &el) != 3) {
        printf("Erro ao ler o primeiro registro do arquivo.\n");
        fclose(pArqComp);
        return;
    }

    soma_eB = eB;
    soma_el = el;
    // inicializa para ser usada no while ali em baixo
    menor_eB = maior_eB = eB;
    menor_el = maior_el = el;
    count = 1;

    while (fscanf(pArqComp, "[%d, %ld, %ld]\n", &n, &eB, &el) == 3) {
        soma_eB += eB;
        soma_el += el;
        // substitui os valores caso ache alguma dessas verificações
        if (eB < menor_eB) menor_eB = eB;
        if (eB > maior_eB) maior_eB = eB;

        if (el < menor_el) menor_el = el;
        if (el > maior_el) maior_el = el;

        count++;
    }

    fclose(pArqComp);

    double media_eB = soma_eB/count;
    double media_el = soma_el/count;

    printf("Média Eb: %.2f\n", media_eB);
    printf("Melhor Caso Eb: %ld\n", menor_eB);
    printf("Pior Caso Eb: %ld\n", maior_eB);

    printf("Média El: %.2f\n", media_el);
    printf("Melhor Caso El: %ld\n", menor_el);
    printf("Pior Caso El: %ld\n", maior_el);
}


void funcaoS(int *V, int*Vcopia){
    if(V != NULL){
        free(V);
    }
    if(Vcopia != NULL){
        free(Vcopia);
    }

    exit(0);

}



int main(){

    int option;

    do{
        printf("Escolha a opcao desejada: \n");
        printf("1) T\n");
        printf("2) R \n");
        printf("3) S \n");
        scanf("%d", &option);
        if(option >= 4){
            printf("Opcao invalida\n");
        }

        switch(option){
            case 1:
            funcaoT();
            break;
        
            case 2:
            funcaoR();
            break;
        
            case 3:
            funcaoS(NULL, NULL);
            break;

        }
    } while (option != 3);
    
}