// Simple Loging C Program
// Made by Lamsten Corporation
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
  FILE *fptr;
  char filename[100], sentence[100], fnbuf[100], timecheck[100];
  char am[] = "AM", pm[] = "PM";
  
  time_t rawtime;
  time(&rawtime);
  struct tm *currentdate = localtime(&rawtime);
  int sec = currentdate->tm_sec;
  int min = currentdate->tm_min;
  int hour = currentdate->tm_hour;
  int day = currentdate->tm_mday;
  int mon = (currentdate->tm_mon) + 1;
  char *mont[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int year = (currentdate->tm_year) + 1900;
  
  printf("The time now is the %dth of %s, %d.\n"
  		 "Log anything you need to. Type \"===\" to quit.\n", day, mont[mon - 1], year);
  
  snprintf(fnbuf, sizeof(fnbuf), "log%d%d%d.txt", day, mon, year - 2000);
  fptr = fopen(fnbuf, "a+");
  snprintf(timecheck, sizeof(timecheck), "%d:%d:%02d %s\n", hour % 12, min, sec, (hour >= 12) ? "PM" : "AM"); 
  printf(timecheck);
  while (strcmp(gets(sentence), "===") != 0) 
  {	
  	fputs(timecheck, fptr);
    fputs(sentence, fptr);
    fputs("\n\n", fptr);
  }
  fclose(fptr);
  printf("\n======================\n");
  printf("File closed and saved.\n");
  printf("======================\n");
  sleep(2);
  
  return 0;
}
