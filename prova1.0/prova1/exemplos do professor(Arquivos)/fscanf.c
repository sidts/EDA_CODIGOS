#include "stdio.h"
struct emp
{
  char name[40] ;
  int age ;
  float bs ;
};
main( )
{
  FILE *fp ;
  struct emp e ;
  fp = fopen ( "EMPLOYEE.DAT", "r" ) ;
  if ( fp == NULL )
  {
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;
  }
  while ( fscanf ( fp, "%s %d %f", e.name, &e.age, &e.bs ) != EOF )
     printf ( "%s %d %0.2f\n", e.name, e.age, e.bs ) ;
  system("pause");
  fclose ( fp ) ;
}
