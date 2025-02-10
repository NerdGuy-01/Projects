#include<stdio.h>
#include<string.h>

#define WORDS 100
int main(){
 char words[WORDS];
  printf("Enter Passoword");
 fflush(stdout);
  fgets(words,sizeof(words),stdin);
  return 0;
}
