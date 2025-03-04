#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

struct variables{
  char choice[3];
  int random_words;
}

int main(){
  printf("Hello Welcome to this Hangman game");
  printf("(would you like to know rules ?)");
  scanf("%s",choice);
  if(strcmp(choice,"Yes")==0 || strcmp(choice,"yes")){
    printf(" 1. There is given a word with omitted characters and you need to guess the characters to win the game.");
    printf(" 2. If you guessed all characters right the  man lives otherwise he Dies");
  }
  

}