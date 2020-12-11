#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "FinalFunctions.h"

int main(int argc, char *argv[])
{
   int i=0,check_integrity=0,entered_time=0,i1=0,arr=0,batch=0,pos=0;
   char *key_entered = '\0',*log_position='\0',*password='\0';
      if(argc == 10 || argc ==12)
   {
       i1=Normal_Enter_Input(argc,argv);
       if(i1==0)
        {
          for(i=1;i<argc;i++)
          {
            if (strcmp(argv[i],"-K")==0)
              key_entered=argv[i+1];
            if(strcmp(argv[i],"-T")==0)
             entered_time= atoi(argv[i+1]);
             if (strcmp(argv[i],"-F")==0)
              log_position=argv[i+1];
             if(strcmp(argv[i],"-A")==0)
                arr++;
              if(strcmp(argv[i],"-R")==0)
                 arr--;
              if(strcmp(argv[i],"-K")==0)
                pos=i+1;
          }
           //printf("%s\n%s\n%d\n",key_entered,log_position,entered_time);
           check_integrity = check_HandleFile(argc,argv,key_entered,entered_time,log_position,arr,pos);

            if(check_integrity==1)
              {printf("Integrity Violation");exit(255);}
         }
       else
        {printf("INVALID INPUT");exit(255);}
   }

  else if(argc==3)
    {
        printf("batch file\n");
        batch=Batch_Enter_Input(argc,argv);
     }
   else
   {
     printf("INVALID INPUT");
     exit(255);

   }

}
/*int check_HandleFile(int argc,char *argv[],char *key_entered, int entered_time,char *log_position,int arr)
{
    FILE *file;
    char *c[12];
    int i=0,j=0,flag=0,recent_time_check=0,presence_check=0;

         if (file = fopen(log_position, "r"))
           {
             while(fscanf(file, "%s", c) != EOF)
              {
                if(strcmp(c,"-K")==0)
                {
                   break;
                }
              }
              fscanf(file, "%s", c);
              printf("\n%s\n", c);
              recent_time_check=most_recent_time_check(entered_time,log_position);
              presence_check=check_staff_presence(file,argc,argv);
              if(strcmp(key_entered,c)!=0 || recent_time_check!=0)
                   flag=1;
               else if(presence_check==1)
               {
                   file=fopen(log_position, "a");
                   for (i=1;i<argc;i++)
                     {  fprintf(file,"%s ",argv[i]);}
                 fprintf(file,"\n");
                }
                else
                {
                    printf("Invalid Input");
                    exit(255);
                }

              fclose(file);

           }
    else
        {
          if(arr==1)
            {file = fopen(log_position, "w");
            for (i=1;i<argc;i++)
            {
                fprintf(file,"%s ",argv[i] );
            }
            fprintf(file,"\n");
            }
            fclose(file);
         }
  return flag;
}
int Batch_Enter_Input(int argc,char *argv[])
{
    FILE *file;
    char c;
    if(strcmp(argv[1],"-B")==0)
       {
       if (file = fopen(argv[2], "r"))
         {
          fclose(file);
          printf("file exists");
         }
        else
         {
           printf("file doesn't exist");
         }
        }
        else
         printf("Invalid Input");
  return 0;
}
int Normal_Enter_Input(int argc,char *argv[])
{
    int i=0,check=0;
    char *location = "",*nullCheck='\0';
    int Acount=0,Lcount=0,Ncount=0,Dcount=0,Tcount=0,Fcount=0,Kcount=0;
    for(i=1;i<argc;i++)
    {
        if (strcmp(argv[i],"-K")==0)
        {
             Kcount++;
            if(nullCheck==argv[i+1])
               check=1;
        }
        if (strcmp(argv[i],"-A")==0)
           Acount++;
        if (strcmp(argv[i],"-L")==0)
           Lcount++;

        if(strcmp(argv[i],"-N")==0)
        {
         Ncount++;
          if(nullCheck!=argv[i+1])
            {
              if(Check_ifAlphabet(argv[i+1])==1)
                   check=1;
              }
            else
              check=1;
        }
        if(strcmp(argv[i],"-D")==0)
        {
           Dcount++;
           if(nullCheck!=argv[i+1])
            {
              if(Check_ifAlphabet(argv[i+1])==1)

                       check=1;
            }
            else
              check=1;
        }
        if (strcmp(argv[i],"-T")==0)
         {
            Tcount++;
            if(nullCheck!=argv[i+1])
            {
                if(Check_ifNumber(argv[i+1])==1)
                  check=1;
            }
            else
              check=1;
         }
        if (strcmp(argv[i],"-F")==0)
           {
               Fcount++;
               location= argv[i+1];
               if(location=='\0')
               {
                check=1;
                printf("Invalid location");
               }
           }
        }
        if((Lcount==Acount)|| (Lcount!=1 && Acount!=1))
            check=1;
        if((Ncount==Dcount)||(Ncount!=1 && Dcount!=1))
            check=1;
        if(Fcount!=1 || Tcount!=1 ||Kcount!=1)
            check=1;
     return(check);
}


int Check_ifAlphabet(char c[100])
 {
     int l=0,j=0;
     l=strlen(c);
     int flag=0;
     for(j=0;j<l;j++)
           {
            if((c[j] >= 'a' && c[j] <= 'z') || (c[j] >= 'A' && c[j] <= 'Z')){}
            else
            {
              flag=1;
              printf("%d",flag);
              break;
            }
        }
        return(flag);
}
int Check_ifNumber(char c[100])
{
   int l=0,j=0;
     l=strlen(c);
     int flag=0;
     for(j=0;j<l;j++)
           {
            if((c[j] >= '0' && c[j] <= '9'))
               {
               }
            else
            {
              flag=1;
              break;
            }
        }
        return(flag);
}
int most_recent_time_check(int c,char *log_position)
{
    int entered_time=0,flag=0,x=0,j=0,i=0;
    char tmp[1024];
    char sub[1000];
    FILE *fp;

          fp = fopen(log_position, "r");
            while(!feof(fp))
                fgets(tmp, 1024, fp);
              fclose(fp);


          for(i=0;i<strlen(tmp);i++)
          {
              if((tmp[i]=='-')  && (tmp[i+1]=='T'))
              {
                  while (j < strlen(tmp))
                    {
                       sub[j] = tmp[i+3+j];
                       j++;
                    }
                    sub[j] = '\0';
                    break;
              }
          }
          x = atoi(sub);
        if(x>=c)
        {
         printf("Invalid Input");
         exit(255);
        }

return flag;

}
int check_staff_presence(FILE *file,int argc,char *argv[])
{

    char tmpd[256]=" -D ";
    char tmpn[256]=" -N ";
    char max[256];
    char final[256]="";
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
            else if(strcmp(type,"leave")==0 && room_presence==0)
                 {flag=1;printf("-L");}
        }
        else if(strstr(final," -L ")!=0)
        {
            if(strcmp(type,"arrival")==0 && room_presence==0)
              {flag=1;printf("-A");}
        }
        else
          {flag=0;printf("Invalid Input");}
      }
     else if((strcmp(type,"arrival")==0) && (room_presence==0))
         flag=1;
     else
          flag=0;

    return(flag);
}*/

