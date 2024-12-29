// This is my first project A calculator and also learned time library 
#include<stdio.h>
#include<time.h>
int main(){
  char user_name[50];
  printf("Enter your name :");
  scanf("%s",user_name);
  time_t t;
  struct tm *ptr;
  t = time(NULL); // Get current time 
  ptr = localtime(&t); // Get local time 
  // For comparsion get int hour from struct tm
  int hour = ptr->tm_hour;
  // Checking time
  if(hour >=5 && hour < 12){
    printf("Good morning %s",user_name);
  }
  else if(hour >=12 && hour<=18){
    printf("Good afternoon %s",user_name);
  }
  else{
    printf("Good evening %s",user_name);
  }
}