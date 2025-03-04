#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

int main(){
  char choice[3];
  char options[][7] = {"Luffy","Saitama","Zorro"};

  printf("Hello Welcome to this Hangman game");
  printf("(would you like to know rules ?)");
  scanf("%s",choice);

  if(strcmp(choice,"Yes")==0 || strcmp(choice,"yes")){
    printf(" 1. There is given a word with omitted characters and you need to guess the characters to win the game.");
    printf(" 2. If you guessed all characters right the  man lives otherwise he Dies");
  }
  
 int size = sizeof(options)/sizeof(options[0]); // To get number of elements
 
  int random_index = rand() % size;

}