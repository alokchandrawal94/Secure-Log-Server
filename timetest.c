#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main() {

    /*time_t rawtime;
  struct tm * timeinfo;

  time ( &rawtime );
  timeinfo = localtime ( &rawtime );
  printf ( "Current local time and date: %s", asctime (timeinfo) );

  SYSTEMTIME str_t;
	GetSystemTime(&str_t);

	printf("Year:%d\nMonth:%d\nDate:%d\nHour:%d\nMin:%d\nSecond:% d\n"
	,str_t.wYear,str_t.wMonth,str_t.wDay
	,str_t.wHour,str_t.wMinute,str_t.wSecond);
    return 0;*/
     time_t t;
     printf("%d",time(&t));
     time(&t);
    printf("\nThis program has been writeen at (date and time): %s", ctime(&t));

     const char *time_string = "Wed Feb 05 10:50:55 2019";
    struct tm tm;
    strptime(time_string, "%H:%M:%S", &tm);
    time_t k = mktime(&tm);

    //k = (time_t) atoll(time_string);
    printf("%d",time(&k));



}
