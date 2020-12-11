int check_HandleFile(int argc,char *argv[],char *key_entered, int entered_time)
{
    FILE *file;
    char *c[12];
    int i=0,j=0,flag=0,recent_time_check=0;

         if (file = fopen("logfile.txt", "r"))
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
              recent_time_check=most_recent_time_check(entered_time);
              if(strcmp(key_entered,c)!=0 || recent_time_check!=0)
                 flag=1;
               else
               {
                   file=fopen("logfile.txt", "a");
                   for (i=1;i<argc;i++)
                     {  fprintf(file,"%s ",argv[i] );}
                 fprintf(file,"\n");
                }

              fclose(file);

           }
    else
        {

            file = fopen("logfile.txt", "w");
            for (i=1;i<argc;i++)
            {
                fprintf(file,"%s ",argv[i] );
            }
            fprintf(file,"\n");
            fclose(file);
         }
  return flag;
}
void Batch_Enter_Input(int argc,char *argv[])
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

}
int Normal_Enter_Input(int argc,char *argv[])
{
    int i=0,check=0;
    char *location = "logfile.txt",*nullCheck='\0';
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
int most_recent_time_check(int c)
{
    int entered_time=0,flag=0,x=0,j=0,i=0;
    char tmp[1024];
    char sub[1000];
    FILE *fp;
          fp = fopen("logfile.txt", "r");
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
        if(x>c)
        {
         printf("Invalid Input");
         exit(255);
        }

return flag;

}
int Logread_Normal_Enter_Input(int argc,char *argv[])
{
    int i=0,check=0;
    char *location = "",*nullCheck='\0';
    int Rcount=0,Ncount=0,Dcount=0,Scount=0,Fcount=0,Kcount=0;
    for(i=1;i<argc;i++)
    {
        if (strcmp(argv[i],"-K")==0)
        {
             Kcount++;
            if(nullCheck==argv[i+1])
               check=1;
        }
        if (strcmp(argv[i],"-S")==0)
           Scount++;
        if (strcmp(argv[i],"-R")==0)
           Rcount++;

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
        if((Rcount==Scount)|| (Rcount!=1 && Scount!=1))
            check=1;
        if(Rcount==1)
        {
            if((Ncount==Dcount)||(Ncount!=1 && Dcount!=1))
            check=1;
        }
        if(Fcount!=1 || Kcount!=1)
            check=1;
     return(check);
}


int Logread_check_HandleFile(int argc,char *argv[],char *key_entered,char *log_position)
{
    FILE *file;
    char *c[12];
    int i=0,j=0,flag=0;

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
              printf("%s\n", c);
              //recent_time_check=most_recent_time_check(entered_time,log_position);
              //presence_check=check_staff_presence(file,argc,argv);
              if(strcmp(key_entered,c)!=0)
                   flag=1;
              fclose(file);

           }
  return flag;
}
int read_log(int argc,char *argv[],char *log_position)
{
    int i=0,j=0,k=0,getName=0;
    FILE *file;
    char max[256];
    char tmpd[256]=" -D ";
    char tmpn[256]=" -N ";
    char sub[256];
    char* strings[50];
    char *typeRead='\0',*type_nurse='\0',*type_doc='\0';
    for(i=1;i<argc;i++)
    {
        if (strcmp(argv[i],"-S")==0)
              typeRead="state";
        if (strcmp(argv[i],"-R")==0)
              typeRead="Info";
        if (strcmp(argv[i],"-N")==0)
              type_nurse=argv[i+1];
        if (strcmp(argv[i],"-D")==0)
              type_doc=argv[i+1];

    }
    file=fopen(log_position,"r");
    if(strcmp(typeRead,"state")==0)
    {
     getName=Get_Name(file);
    }
    else
    {
     if(type_doc!='\0')
      {
           strcat(type_doc," ");
           strcat(tmpd,type_doc);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if((strstr(max,tmpd)) && (strstr(max," -R ")) && (strstr(max," -A ")))
              {
                  for(j=0;j<strlen(max);j++)
                  {
                     if((max[j]=='-') && (max[j+1]=='R'))
                     {
                        while (k < strlen(max))
                        {
                            sub[k] = max[k+3+j];
                              k++;
                        }
                        sub[k] = '\0';
                        k=0;
                        break;
                     }
                    }
                 printf("%d, ",atoi(sub));

              }
            }
       }
       else
       {
           strcat(type_nurse," ");
           strcat(tmpn,type_nurse);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if(strstr(max,tmpn) && strstr(max," -R ") && strstr(max," -A "))
              {
                  for(j=0;j<strlen(max);j++)
                  {
                     if((max[j]=='-') && (max[j+1]=='R'))
                     {
                        while (k < strlen(max))
                        {
                            sub[k] = max[k+3+j];
                                k++;
                        }
                        sub[k] = '\0';
                        k=0;
                        break;
                     }
                    }
                 printf("%d, ",atoi(sub));
              }
            }
       }
     fclose(file);
    }
  return 0;
}

int Get_Name(FILE *file)
{
    int i=0,j=0,l=0,num=0,p=0;
    char *typeStaff='\0';
    FILE *file1;
    char sub[256];
    char max[256];
    while(fgets(max, sizeof(max), file) != NULL)
   {

      for(i=0;i<strlen(max);i++)
       {
         if((max[i]=='-') && (max[i+1]=='D'))
         {
            typeStaff="DOC";
            while(max[j+i+3]!=' ')
            {
               sub[j]=max[j+i+3];
                 j++;
            }
           sub[j]='\0';
           j=0;
           file1=file;
           num=last_presence(file1,sub,typeStaff);
           printf("%s",sub);
        }
        else if((max[i]=='-') && (max[i+1]=='N'))
          {
              typeStaff="NURSE";
               while(max[j+i+3]!=' ')
            {
               sub[j]=max[j+i+3];
                 j++;
            }
           sub[j]='\0';
           file1=file;
           num=last_presence(file1,sub,typeStaff);
           printf("%s",sub);
           j=0;
          }
       }
   }
   fclose(file);
        printf("%s",present_doctor);
        printf("%s",present_nurse);
        printf("%s",room_number);

}
int last_presence(FILE *file,char *dr,char *typeStaff)
{
    char tmpd[256]=" -D ";
    char tmpn[256]=" -N ";
    char final[256];
    char str[20];
    char max[256];
    int p=0;
    if(strstr(typeStaff,"DOC"))
    {
         strcat(dr," ");
         strcat(tmpd,dr);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if(strstr(max,tmpd))
              strcpy(final,max);
          }
          if((strstr(final," -A ")) && (strstr(final," -R ")))
             {
              strcat(present_doctor,dr);
              p=get_room_number(final);
              sprintf(str, "%d,", p);
              strcat(room_number,str);
              }
    }
    else
    {
         strcat(dr," ");
         strcat(tmpn,dr);
          while(fgets(max, sizeof(max), file) != NULL)
          {
           if(strstr(max,tmpn))
              strcpy(final,max);
          }
          if((strstr(final," -A ")) && (strstr(final," -R ")))
            {
                strcat(present_nurse,dr);
              p=get_room_number(final);
              sprintf(str, "%d,", p);
              strcat(room_number,str);
              }

    }
    return 0;
}

int get_room_number(char *tmp)
  {
      int i=0,x=0,j=0;
      char sub[50];
      for(i=0;i<strlen(tmp);i++)
          {
              if((tmp[i]=='-')  && (tmp[i+1]=='R'))
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

    return x;
}



