#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    
    int g_number = (rand() % 100) + 1;
    int attempts = 0;
    int u_number;
    int max_attempts = 15; 
    
    printf("Welcome to the Number Guessing Game!\n");
    printf("I'm thinking of a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n\n", max_attempts);
    
    while (attempts < max_attempts) {
        printf("Attempt %d/%d - Enter your guess: ", attempts + 1, max_attempts);
        
       
        if (scanf("%d", &u_number) != 1) {
            printf("Please enter a valid number!\n");
            
            while (getchar() != '\n');
            continue;
        }
        
        
        if (u_number < 1 || u_number > 100) {
            printf("Please enter a number between 1 and 100!\n");
            continue;
        }
        
        attempts++;
        
        if (u_number == g_number) {
            printf("\nCongratulations! You guessed the correct number in %d attempts!\n", attempts);
            printf("Thanks for playing. Bye bye!\n");
            return 0;
        } else {
            if (u_number > g_number) {
                printf("Hint: Try a smaller number\n\n");
            } else {
                printf("Hint: Try a larger number\n\n");
            }
        }
    }
    
    printf("\nSorry, you've used all %d attempts. The number was %d.\n", max_attempts, g_number);
    printf("Better luck next time!\n");
    
    return 0;
}