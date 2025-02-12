// The following code performs encryptions and decryption 
#include<stdio.h>
#include<string.h>

void main(){
    char string[100];
    char choice[50];
    printf("Enter the string:");
    scanf("%s",string);

    for(int i=0;string[i]!='\0';i++){
        if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122) ||  string[i]>=33 && string[i]<=42||string[i]==64){
         if(i<=5){
             string[i] += 5;
         }
         else {
             string[i] += 7;
         }
        }
    
    }

    printf("The encrypted string is:- %s",string);
  // For decryption
    printf("\nWant to decrypt?(yes or no )");
scanf("%s",choice);
if(strcmp(choice,"yes")==0 || strcmp(choice,"Yes")==0){
    for(int i=0;string[i]!='\0';i++){
        if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122) ||  string[i]>=33 && string[i]<=42||string[i]==64){
         if(i<=5){
             string[i] -= 5;
         }
         else{
             string[i] -= 7;
         }
        }
    
    }
    printf("Your original string  is : %s",string);
}
}


// #define WORDS 100
// void main(){
//  char words[WORDS];
//   printf("Enter Passoword");
//  fflush(stdout);
//   fgets(words,sizeof(words),stdin);
//   return 0;
// }
