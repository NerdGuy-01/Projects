// The following code performs encryptions and decryption 
#include<stdio.h>
#include<string.h>

//Encryption1: Shifting the alphabetical characters by 2 steps
void encryption1(char *str){
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
            str[i]+=2; //str[i]=str[i]+2;

    }

}

//Encryption2: Shifting the first 5 elements by 5(ASCII) steps and remaining by 7(ASCII) steps
void encrypt2(char *str){
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ||  str[i]>=33 && str[i]<=42||str[i]==64){
         if(i<=5)
             str[i] += 5;
         else
             str[i] += 7;
        }
    }
}

void decryption1(char *estr){
    for(int i=0;estr[i]!='\0';i++){
        if((estr[i]>=65 && estr[i]<=90) || (estr[i]>=97 && estr[i]<=122))
            estr[i]-=2;   //estr[i]=estr[i]-2;

    }
}

void decrypt2(char *str){
    for(int i=0;str[i]!='\0';i++){
        if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122) ||  str[i]>=33 && str[i]<=42||str[i]==64){
         if(i<=5){
             str[i] -= 5;
         }
         else{
             str[i] -= 7;
         }
        }
    
}
}


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
