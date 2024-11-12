#include <stdio.h>
#include <string.h>

#define MAX_TRIES 3

void display_word(char word[], char guessed_word[]) {
    for (int i = 0; i < strlen(word); i++) {
        if (guessed_word[i] == '_') {
            printf("_ ");
        } else {
            printf("%c ", guessed_word[i]);
        }
    }
    printf("\n");
}

int main() {
    char word[] = "programming";  // The word to guess
    int word_length = strlen(word);
    char guessed_word[word_length];  // To store the guessed word with '_' for unknown letters
    int tries_left = MAX_TRIES;
    int correct_guesses = 0;
    char guess;
    int guessed_correctly;

    // Initialize guessed_word with underscores
    for (int i = 0; i < word_length; i++) {
        guessed_word[i] = '_';
    }

    printf("Welcome to Hangman!\n");
    printf("You have %d chances to guess the word.\n", MAX_TRIES);

    while (tries_left > 0 && correct_guesses < word_length) {
        printf("\nCurrent word: ");
        display_word(word, guessed_word);

        printf("Enter your guess (a letter): ");
        scanf(" %c", &guess);  // Using space before %c to discard any newline character from buffer

        guessed_correctly = 0;

        // Check if the guess is correct
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess && guessed_word[i] == '_') {
                guessed_word[i] = guess;
                correct_guesses++;
                guessed_correctly = 1;
            }
        }

        if (guessed_correctly) {
            printf("Good guess! You found a letter.\n");
        } else {
            tries_left--;
            printf("Incorrect guess. You have %d tries left.\n", tries_left);
        }

        if (correct_guesses == word_length) {
            printf("\nCongratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    if (tries_left == 0) {
        printf("\nSorry, you've run out of tries. The word was: %s\n", word);
    }

    return 0;
}
