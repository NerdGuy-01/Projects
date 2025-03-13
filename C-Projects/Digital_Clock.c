#include<stdio.h>
#include<time.h>
#include<unistd.h> // for sleep 
#include<stdlib.h>
void fill_time(char * buffer,int choice)
{
    struct tm *time_info; // you can also use *current_time
    time_t current_time;
    current_time = time(NULL);
    time_info = localtime(&current_time);
    if(choice ==1)
    {
     strftime(buffer,50,"%H : %M : %S ",time_info); // strftime requires a pointer of struct tm as its last argument
    }
    else
    {
       strftime(buffer,50,"%I : %M : %S %p",time_info); 
    }
     
}

void fill_date(char* buffer)
{ 
    struct tm *time_info;
    time_t current_time;
    current_time = time(NULL);
    time_info = localtime(&current_time);
  strftime(buffer,50,"%A %B %d %Y",time_info);

}

void clear_screen(){
#ifdef _WIN32
 system("cls");
 #else
 system("clear");
 #endif
}

int main()
{
 int choice;
  char time[50],date[50];
  printf("Choose a format :\n");
  printf("1. 24 Hour format\n");
  printf("2. 12 Hour format(default)\n");
  scanf("%d",&choice);
  while(1){
  fill_time(time,choice);
  fill_date(date);
  clear_screen();
  printf("\nCurrent Time : %s\n",time);
  printf("\nDate : %s",date);
  sleep(1);
  }
 return 0 ;
}