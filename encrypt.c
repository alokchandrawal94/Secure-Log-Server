#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include "FinalFunctions.h"
int main()
{
   char *encrpyt='\0',*decrypt='\0';

   encrpyt=encrypt("secret","0gejwo");
   printf("%s",encrpyt);
   //decrpyt=decrypt("secret","0gejwo");
   // printf("%s",decrpyt);


    return 0;

}
