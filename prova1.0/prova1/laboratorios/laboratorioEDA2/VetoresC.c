#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int* CriaVetInt (int tamanhoVetor){
    int *vetor = (int*)malloc(sizeof(int)*tamanhoVetor);
    return vetor;
}

float *CriaVetFloat (int tamanhoVetor){
    float *vetor = (float*)malloc(sizeof(float)*tamanhoVetor);
    return vetor;
}

void AddChar(char *pvetcar , int ptammax , int * pqtde){
    char *vetor = (char*)malloc(sizeof(char)*ptammax);
    printf("Digite o caracter:");
    char chPedido;
    scanf("%c",&chPedido);

    // colocando o a caracter na primeira posicao disponivel do vetor
    if(*pqtde < ptammax){

    pvetcar[*pqtde] = chPedido;
    pqtde = pqtde + 1;
    }
    else{
        printf("Vetor cheio");
    }
}

 void ExcluiChar(char *pvetcar , int ptammax , int *pqtde){
     char *vetor = (char*)malloc(sizeof(char)*ptammax);

    char chPedido;
    scanf("%c ",&chPedido);
    for(int i =0 ;i<*pqtde;i++){
        if(pvetcar[i]==chPedido){
            pvetcar[i]=pvetcar[*pqtde -1 ];
            
        }
    }
        

}

bool AddVetOrdenado(float *pvalores, float pv, int pcapacidade, int *ptamanho) {
    // Verifica se há espaço disponível no vetor
    if (*ptamanho >= pcapacidade) {
        return false; // Falso, não há espaço para inclusão
    }

    // Encontra a posição adequada para inserir o valor
    int posicao = 0;
    while (posicao < *ptamanho && pvalores[posicao] <= pv) {
        posicao++;
    }

    printf("%d\n", posicao);

    // Atualiza o tamanho do vetor
    ptamanho++;
    pvalores[*ptamanho +1 ] = pvalores[*ptamanho];

    // Move os elementos para abrir espaço para o novo valor
    for (int i = *ptamanho - 1; i > posicao; i--) {
        pvalores[i] = pvalores[i - 1];
    }

    // Insere o novo valor na posição adequada
    pvalores[posicao] = pv;

    return true; // Verdadeiro, inclusão bem-sucedida
}

void ExcluiVetOrdenado(float *pvalores,int *ptamanho,float pv){
    int posicao = 0;
   while(posicao< *ptamanho && pvalores[posicao] < pv){
        posicao++;
    }
    printf("%d\n",posicao);
    for(int i = posicao;i<*ptamanho;i++){
        pvalores[i]=pvalores[i+1];
    }
    ptamanho--;
}

bool EIgual(int *pveta,int *pvetb, int ptama,int ptamb){
    if(ptama!=ptamb){
        return false;
    }
    for(int i = 0;i<ptama;i++){
        if(pveta[i]!=pvetb[i]){
            return false;
        }
    }
    return true;
}
float ArmazenaValor(int n, float *arranjo){
    for(int i = 0;i<n;i++){
        printf("Digite o valor:");
        scanf("%f",&arranjo[i]);
    
    }

    for(int j =0;j<n;j++){
        arranjo[j]=((j+1)/arranjo[n-1]);
    }
    
    float soma =0;
    for(int k =0 ;k<n;k++){
        soma = soma + arranjo[k];
    }
    printf("%f\n",soma);
    
    return soma;
}
int main() {
    float vetor[5];
    int resultado = ArmazenaValor(5, vetor);
    printf("%d", resultado);
    return 0;
    
}