#include <stdio.h>
#include <string.h>
void main(int argc,char *argv[])
{
    FILE *file;
    char c;
    int i=0;
    char buf[10];
    if(strcmp(argv[1],"-B")==0)
       {
       if (file = fopen(argv[2], "r"))
         {
           while( fscanf(file, "%s", buf) != EOF )
           {
            printf("%s\n", buf);
           }
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
