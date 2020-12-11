#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "FinalFunctions.h"

int main(int argc, char *argv[])
{
  int i=0,check_integrity=0,i1=0,ack=0;
   char *key_entered = '\0',*log_position='\0';
  if(argc ==6 || argc==8)
   {
    i1=Logread_Normal_Enter_Input(argc,argv);
       if(i1==0)
        {
          for(i=1;i<argc;i++)
          {
            if (strcmp(argv[i],"-K")==0)
              key_entered=argv[i+1];
             if (strcmp(argv[i],"-F")==0)
              log_position=argv[i+1];
          }
           check_integrity = Logread_check_HandleFile(argc,argv,key_entered,log_position);

            if(check_integrity==1)
              printf("Integrity Violation");
            else
            ack=read_log(argc,argv,log_position);
         }
       else
        printf("INVALID INPUT");
   }
   else
   {
       printf("%d",argc);
     printf("INVALID INPUT");

   }
}
