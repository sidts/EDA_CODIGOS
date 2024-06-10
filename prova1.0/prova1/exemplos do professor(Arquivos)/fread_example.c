#include<stdio.h>
struct emp
  {
    char name[40] ;
    int age ;
    float bs ;
  };

main()
{
   FILE *fp;
   struct emp e[2];
   fp = fopen("emp.dat", "rb");
   if(fp == NULL)
   {
      printf("Unable to create a file \n");
      system("pause");
      exit(0);      
   }
   fread(&e, sizeof(e), 2, fp);
   printf("%s : %d : %0.2f \n", e[0].name, e[0].age, e[0].bs);
   printf("%s : %d : %0.2f \n", e[1].name, e[1].age, e[1].bs);
   fclose(fp);
   system("pause");
}
