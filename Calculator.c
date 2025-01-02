// This is my first project A calculator and also learned time library 
#include<stdio.h>
#include<time.h>
int main(){
  char user_name[50];
  int input,dig,total=0,product=1;
  printf("Enter your name :");
  scanf("%s",user_name);
  time_t t;
  struct tm *ptr;
  t = time(NULL); // Get current time 
  ptr = gmtime(&t); // Get local time 
  // For comparsion get int hour from struct tm
  ptr->tm_hour += 5; // Handles time in indian standard 
  ptr->tm_min += 30;
  // Handles overflow of min and hour
  if(ptr->tm_min>=60){
    ptr->tm_min -=60;
    ptr->tm_hour ++;
  }
  if(ptr->tm_hour >=24){
    ptr->tm_hour -=24;
  }
  int hour = ptr->tm_hour;
  // Checking time
  if(hour >=5 && hour < 12){
    printf("Good morning %s\n",user_name);
  }
  else if(hour >=12 && hour<=17){
    printf("Good afternoon %s\n",user_name);
  
  }
  else{
    printf("Good evening %s\n",user_name);
    
  }
  
   // printf("%s",asctime(ptr)); This program will show the time 
  printf("\n%s You can perform these tasks with this program \U0001F447\n",user_name);

    printf("\n Addition\n");
    printf(" Check whether number is prime or not \n ");
    printf("Multiplication\n ");
    printf("Factorial\n");
  // Choosing user input
  printf("Your choice(Enter from number 1 to 4) :");
  scanf("%d",&input);
  //Checking which input and then Performing actions according to it 
  if(input==1 || input==3){
 // Now asking for user digits and those digit input
  printf("\nHow many digits does your calculations require ?");
  scanf("%d",&dig);
  int arr[dig];
  printf("Enter %d digits : ",dig);
  for(int i=0;i<dig;i++){
    scanf("%d",&arr[i]);
  }
    if(input==1){
      for(int i=0;i<dig;i++){
        total+=arr[i];
      }
        printf("The Addition of %d numbers is : %d",dig,total);
    }
    if(input==3){
      for(int i=0;i<dig;i++){
        product*=arr[i];
      }
      printf("The product of %d numbers is : %d",dig,product);
    }
  }
 else{
   if(input==2){
     printf("Sorry for the inconvience this product is still under development, you can wait for few hours  \U0001F613\n");
   }
   if(input==4){
     int f=1,n;
     printf("Enter number :");
     scanf("%d",&n);
     
     for(int i=1;i<=n;i++){
       f = f*i;
     }
     printf("Factorial of given number is : %d",f);
   }
 }
  
}
