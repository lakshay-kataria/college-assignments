#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_choice(int choice) {
    if (choice == 0) {
        printf("Rock\n");
    } else if (choice == 1) {
        printf("Paper\n");
    } else {
        printf("Scissors\n");
    }
}

int main() {
    int user_choice, computer_choice;
    int random_num;

    // Seed the random number generator
    srand(time(0));

    // Display game instructions
    printf("Rock, Paper, Scissors Game\n");
    printf("Enter your choice:\n");
    printf("0. Rock\n1. Paper\n2. Scissors\n");
    printf("Enter a number (0, 1, or 2): ");
    scanf("%d", &user_choice);

    // Validate user input
    if (user_choice < 0 || user_choice > 2) {
        printf("Invalid choice! Please enter 0, 1, or 2.\n");
        return 1;
    }

    // Generate a random number for the computer's choice
    random_num = rand() % 100;

    // Determine the computer's choice based on the random number
    if (random_num < 34) {
        computer_choice = 0;  // Rock
    } else if (random_num < 67) {
        computer_choice = 1;  // Paper
    } else {
        computer_choice = 2;  // Scissors
    }

    // Display the choices
    printf("\nYour choice: ");
    display_choice(user_choice);
    printf("Computer's choice: ");
    display_choice(computer_choice);

    // Determine the winner
    if (user_choice == computer_choice) {
        printf("It's a draw!\n");
    } else if ((user_choice == 0 && computer_choice == 2) ||
               (user_choice == 1 && computer_choice == 0) ||
               (user_choice == 2 && computer_choice == 1)) {
        printf("You win!\n");
    } else {
        printf("Computer wins!\n");
    }

    return 0;
}
