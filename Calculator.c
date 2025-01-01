// This is my first project A calculator and also learned time library 
#include<stdio.h>
#include<time.h>
int main(){
  char user_name[50],choice[25];
  int input,dig,total=0,product=1;
  printf("Enter your name :");
  scanf("%s",user_name);
  time_t t;
  struct tm *ptr;
  t = time(NULL); // Get current time 
  ptr = gmtime(&t); // Get UTC standard time 
  // Correct time in Indian standard time
  ptr->tm_hour += 5;
  ptr->tm_min += 30;
  // Handles Time overflow
   if(ptr->tm_min >=60){
   ptr->tm_min -=60;
    ptr->tm_hour++;
    } 
   if(ptr->tm_hour >=24){
  ptr->tm_hour -=24;
   } 
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

  printf("\n %s You can perform the following tasks from this program \U0001F447\n");
  printf("\n Addition");
  printf("Substraction");
  printf("Multiplication");
  Printf("Division");
  // Choosing user input 
   printf("Your choice ?");
   scanf("%d",&input);
  // Now asking for user digits and input of those digits
  printf("How many digits does your calculation require");
  scanf("%d",&dig);
  int arr[dig];
  printf("Enter  %d digits :",dig);
  for(int i=1;i<dig+1;i++){
   scanf("%d",&arr[i]); 
   }
  // Using switch case 
  switch(input){
    case 1:
      for(int i=1;i<=dig;i++){
        total+=arr[i];
}
printf("The addtion of %d numbers is : %d",dig,total);
       break;
     
case 2:
     
       break;
   
case 3:
      for(int i=1;i<=dig;i++){
       product*=arr[i];
}
printf("The Product of %d numbers is : %d",dig,product);
       break;

 case 4:
      
       break;
   }
  
}