#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()
{
char tmp[1024];
FILE *fp;
int x=0;
char *c[10];

fp = fopen("logfile.log", "r");
while(!feof(fp))
    fgets(tmp, 1024, fp);

    char str3[10] = "99 - y 77!";
    x = atoi(tmp);
    printf("Converting : %d\n", x);


printf("%s", tmp);
}
