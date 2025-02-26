#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define MAX_WORDS 20 


int main(){
     char choice[MAX_WORDS]; 
  printf("Hello, welcome to this Hangman Game \n");
  printf("Would you like to know Rules ?");
  scanf("%s",choice);
  if(strcmp(choice,"Yes")==0 || strcmp(choice,"yes")==0) {
    printf("1. There is given a word with omitted characters and you need to guess the characters to win the game.");
    printf("if you win the Man survives or Man gets hanged.");
  }
}