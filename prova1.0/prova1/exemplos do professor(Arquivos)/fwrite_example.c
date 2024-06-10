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
   struct emp e[2] = {"Jamil khan", 35, 65000.95 ,
                      "Tariq mahmood", 45, 70000};
   fp = fopen("emp.dat", "wb");
   if(fp == NULL)
   {
      printf("Unable to create a file \n");
      system("pause");
      exit(0);      
   }
   fwrite(&e, sizeof(e), 2, fp);
   fclose(fp);
   system("pause");
}
