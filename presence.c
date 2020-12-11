#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc,char *argv[])
{

    char tmpd[256]=" -D ";
    char tmpn[256]=" -N ";
    char max[256];
    char final[256]="";
    FILE *file;
    int room_presence=0,flag=0,i=0,j=0;;
    char *type_doc='\0',*type_nurse='\0',*type='\0';
    for(i=1;i<argc;i++)
          {
            if(strcmp(argv[i],"-A")==0)
            {
                type="arrival";
                for(j=i+1;j<argc;j++)
                {
                 if(strcmp(argv[j],"-D")==0)
                   {type_doc=argv[j+1];break;}
                  else if(strcmp(argv[j],"-N")==0)
                   {type_nurse=argv[j+1];break;}
                }

            }
            if(strcmp(argv[i],"-L")==0)
            {
                type="leave";
               for(j=i+1;j<argc;j++)
                {
                 if(strcmp(argv[j],"-D")==0)
                   {type_doc=argv[j+1];break;}
                  else if(strcmp(argv[j],"-N")==0)
                   {type_nurse=argv[j+1];break;}
                }
            }
            if(strcmp(argv[i],"-R")==0)
              room_presence=1;

          }
    file = fopen("logfile.txt","r");
    if(type_doc!='\0')
      {
           strcat(type_doc," ");
           strcat(tmpd,type_doc);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if(strstr(max,tmpd))
              strcpy(final,max);
          }
       printf("%s",final);
       }
     else
     {
          strcat(type_nurse," ");
           strcat(tmpn,type_nurse);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if(strstr(max,tmpn))
              strcpy(final,max);
          }
          printf("%s",final);
      }


    if(strcmp(final,"")!=0)
      {
        if((strstr(final," -A ")!=0) && (strstr(final," -R ")!=0))
        {
            if((strcmp(type,"leave")==0) && (room_presence==1))
                {flag=1;printf("-l -R");}
        }
        else if(strstr(final," -A ")!=0)
        {
          if((strcmp(type,"arrival")==0) && room_presence==1)
            {
              flag=1;printf("-A -R");
            }
          else if(strcmp(type,"leave")==0 && room_presence==0)
            {
              flag=1;printf("-L");
            }
        }
        else if((strstr(final," -L ")!=0) && (strstr(final," -R ")!=0))
        {
            if((strcmp(type,"arrival")==0) && (room_presence==1))
                {flag=1;printf("-A -R");}
        }
        else if(strstr(final," -L ")!=0)
        {
            if(strcmp(type,"arrival")==0 && room_presence==0)
              {flag=1;printf("-A");}
        }
        else
          {flag=0;printf("Invalid Input");}
      }
      else
        flag=1;

    return(flag);
}
