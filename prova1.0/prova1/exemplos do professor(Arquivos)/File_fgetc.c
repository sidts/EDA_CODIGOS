#include<stdio.h>
int main( )
{
  FILE *fp;
  char ch;
  fp = fopen ("arquivo1.txt", "r" );
  while ( 1 )
  {
    // fgetc = função que captura um caracter de um arquivo
    ch = fgetc(fp);
    // EOF analisa se o caracter lido é o ultimo do arquivo
    if(ch==EOF)
      break;
    printf("%c",ch);
  }
  fclose ( fp );
  return 0;
}
