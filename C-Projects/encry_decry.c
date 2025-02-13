// The following code performs encryptions and decryption 
#include<stdio.h>
#include<string.h>

//Encryption2: Shifting the first 2 elements by 5(ASCII) steps and remaining by 5(ASCII) steps
void encrypt2(char *str){
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ||  str[i]>=33 && str[i]<=42||str[i]==64){
         if(i<=5)
             str[i] += 2;
         else
             str[i] += 5;
        }
    }
}

void decrypt2(char *str){
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ||  str[i]>=33 && str[i]<=42||str[i]==64){
         if(i<=5){
             str[i] -= 2;
         }
         else{
             str[i] -= 5;
         }
        }
    
}
}


void main(){
    char string[100];
    char choice[50];
    printf("Enter the string:");
    scanf("%s",string);
    encrypt2(string);
     printf("The encrypted string is:- %s",string);
  // For decryption
    printf("\nWant to decrypt?(yes or no )");
    scanf("%s",choice);
    if(strcmp(choice,"yes")==0 || strcmp(choice,"Yes")==0)
        decrypt2(string);

    
    printf("Your original string  is : %s",string);
}
