#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Increased the size of the choice array to allow for a longer input ("Yes" requires 4 chars including '\0')
    char choice[10];  
    char input;
    // Increased each word's length to accommodate longer names and the null terminator
    char options[][10] = {"Luffy", "Saitama", "Zorro", "Naruto", "Ace"};

    printf("Hello, welcome to this Hangman game.\n");
    printf("Would you like to know the rules? (Yes/No): ");
    scanf("%9s", choice);  // Limiting input length to avoid overflow

    // Fixed the condition: both comparisons need to check for equality with 0
    if (strcmp(choice, "Yes") == 0 || strcmp(choice, "yes") == 0) {
        printf("Rules:\n");
        printf("1. A word is chosen randomly and some characters are omitted.\n");
        printf("2. Guess the characters to win the game. If you guess all correctly, the man lives; otherwise, he dies.\n");
    }
    
    int size = sizeof(options) / sizeof(options[0]);  // Get the number of elements
    srand(time(0));
    int random_index = rand() % size;
    
    // For a Hangman game, you normally hide the word. Here, we use a separate array to show guessed letters.
    int word_length = strlen(options[random_index]);
    char guessed[word_length + 1];
    for (int i = 0; i < word_length; i++) {
        guessed[i] = '_';
    }
    guessed[word_length] = '\0';
    
    int attempts = 0;
    // For simplicity, we allow as many attempts as there are letters in the word.
    while (attempts < word_length) {
        printf("\nCurrent word: %s\n", guessed);
        printf("Enter a letter: ");
        // Using " %c" with a space to skip any leftover whitespace (like newline)
        scanf(" %c", &input);
        
        int found = 0;
        // Check each letter in the random word
        for (int i = 0; i < word_length; i++) {
            if (options[random_index][i] == input) {
                guessed[i] = input;  // Reveal the correctly guessed letter
                found = 1;
            }
        }
        
        if (found) {
            printf("You guessed right!\n");
        } else {
            printf("Oops! You guessed wrong.\n");
        }
        
        attempts++;
    }
    
    printf("\nThe random word was: %s\n", options[random_index]);
    return 0;
}
