#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
 FILE *file;
    char tmp[50]="Alicelee";
    char c[50]=" ";
    char max[256];
    char final[256]="";
    char holder='\0';
    int i=1,j=0,flag=0,recent_time_check=0;

         file = fopen("logfile.txt", "r");
         strcat(tmp," ");
         strcat(c,tmp);
         printf("|%s|",c);
    while(fgets(max, sizeof(max), file) != NULL)
    {
        if(strstr(max,c))
            strcpy(final,max);
    }
    if(strcmp(final,"")!=0)
        printf("\n%sdshf",final);

}
