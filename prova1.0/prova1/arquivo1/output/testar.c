#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *foriginal, *fcopia;
    char ch;
    foriginal = fopen("arquivo1.txt", "r");
    if(foriginal == NULL){
        puts("Arquivo não existe\n");
        exit(0);
    }

    fcopia = fopen("Copia_arquivo.txt", "w");
    if(fcopia == NULL){
        puts("Arquivo não gerado\n");
        exit(0);
    }
    while(1){
        ch = fgetc(foriginal);
        if(ch == EOF)
        break;
        fputc(ch , fcopia);
    }
    fclose(foriginal);
    fclose(fcopia);
    

    return 0;
}