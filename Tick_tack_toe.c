// This is a code for Tick tack Toe game 
#include<stdio.h>
#include<string.h>
// Making Computer player function
int board_display(){
  int board[3][3];
  int i,j;
  // Displaying the grid
  for( i=0;i<3;i++){
    for( j=0;j<3;j++){
      printf(" "); // Spaces for Grids 
      if(j<2){
        printf("|"); // Vertical separator, and the reason I have use GRID_SIZE-1, is because I need to put Line between grids but only 2 not the last one 
      }
    }
    printf("\n");
  
  }
  if( i<3){
    for(j=0;j<3;j++){
      printf("-");

      if(j<2){
        printf("+");
      }
    }
    printf("\n");
  }
}
  
}
int main(){
  char choice[10];
  int player_choice;
  // Greeting user and taking input
  printf("Hello users Welcome to this Tick tack Toe game\n ");
  printf("Would you like to know rule ? (yes or no)");
  scanf("%s",choice);
  // Checking whether input is yes or no 
  if(strcmp(choice,"Yes")==0 || strcmp(choice,"yes")==0){
    printf("Here are the rules of Game : \n");
    printf("Here are the rules of This game\n");
    printf("1. The game is played on a 3x3 board\n"
      "2. Two players take  turns marking the grid with X or O\n"
      "3.The first player to get three marks in a row, either vertically, horizontally, or diagonally, wins\n"
      "4. If all nine squares are filled and no player has three marks in a row, the game is a tie\n");
    // 
    printf("Choose one of the following options\n");
    printf("A.Play with friends");
    printf("B. Play with computer");
  }
  else if(strcmp(choice,"No")==0 || strcmp(choice,"no")==0){
    printf("Choose one of the following options\n");
    printf("A.Play with friends");
    printf("B. Play with computer");
  }
  else{
    printf(" Eroor !!!! Please enter only in Yes/No");
}
