#include<stdio.h>
#include<string.h>

void main(){
    char string[100];
    printf("Enter the string:");
    scanf("%s",string);

    for(int i=0;string[i]!='\0';i++){
        if((string[i]>=65 && string[i]<=90) || (string[i]>=97 && string[i]<=122))
            string[i]+=2;
    
    }

    printf("The encrypted string is:- %s",string);
  // For decryption
    printf("\nWant to decrypt?(yes or no )");
scanf("%s",choice);
if(strcmp(choice,"yes")==0 || strcmp(choice,"Yes")==0){
    for(int i=0;string[i]!='\0';i++){
        string[i] -= 2;
    }
    printf("Your original passoword is : %s",string);
}
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
