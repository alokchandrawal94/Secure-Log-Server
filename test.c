#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   int i=0,j=0;
   for(i=1;i<argc;i++)
    {
        for(j=0;j<strlen(argv[i]);j++)
        {
            if((argv[i][j] > 'a' && argv[i][j] <'z') || (argv[i][j] > 'A' && argv[i][j] <'Z'))
                printf("%c\n",argv[i][j]);
            else
              break;

        }

    }
}
