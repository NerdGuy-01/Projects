// This is a code for Tick tack Toe game 
#include<stdio.h>
int main(){
  char choice[10];
  printf("Hello users Welcome to this Tick tack Toe game\n ");
  printf("Would you like to know rule ? (yes or no)");
  scanf("%s",choice);
  if(strcmp(choice,"Yes")==0 || strcmp(choice,"yes")==0){
    printf("Here are the rules of Game : \n");
    printf("Here are the rules of This game\n");
    printf("1. The game is played on a 3x3 board\n"
      "2. Two players take  turns marking the grid with X or O"
      "3.The first player to get three marks in a row, either vertically, horizontally, or diagonally, wins"
      "4. If all nine squares are filled and no player has three marks in a row, the game is a tie");
  }
}
