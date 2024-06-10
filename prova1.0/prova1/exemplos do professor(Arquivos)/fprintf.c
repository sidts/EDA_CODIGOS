#include<stdio.h>
struct emp
  {
    char name[40] ;
    int age ;
    float bs ;
  };
main( )
{
  FILE *fp ;
  char another = 'Y' ;
  struct emp e ;
  fp = fopen ( "EMPLOYEE.DAT", "w" ) ;
  if ( fp == NULL )
  {
    puts ( "Cannot open file" ) ;
    system("pause");
    exit(0) ;
  }
  while ( another == 'Y' || another == 'y' )
  {
     printf ( "\nEnter name, age and basic salary: " ) ;
     scanf ( "%s %d %f", e.name, &e.age, &e.bs ) ;
     fprintf ( fp, "%s %d %0.2f\n", e.name, e.age, e.bs ) ;
     printf ( "Add another record (Y/N) " ) ;
     fflush ( stdin ) ;
     another = getche( ) ;
  }
  fclose ( fp ); 
}
