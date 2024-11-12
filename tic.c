#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function to print the board
void printBoard(char board[SIZE][SIZE]) {
    printf("\nTic Tac Toe Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j < SIZE - 1) printf("|");
        }
        printf("\n");
        if (i < SIZE - 1) printf("---|---|---\n");
    }
}

// Function to check if there's a winner
int checkWinner(char board[SIZE][SIZE], char player) {
    // Check rows and columns
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Row check
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))    // Column check
            return 1;
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||  // Diagonal check
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;

    return 0;
}

// Function to check if the board is full (i.e., draw condition)
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;  // Found an empty space
            }
        }
    }
    return 1;  // No empty spaces, board is full
}

// Function to make the player's move
void playerMove(char board[SIZE][SIZE]) {
    int row, col;
    printf("Enter row and column (0, 1, or 2) for your move (X): ");
    scanf("%d %d", &row, &col);
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
        board[row][col] = 'X';  // Player moves
    } else {
        printf("Invalid move! Try again.\n");
        playerMove(board);  // Recursive call for a valid move
    }
}

// Function to make the computer's move (random move)
void computerMove(char board[SIZE][SIZE]) {
    int row, col;
    srand(time(0));  // Seed the random number generator
    do {
        row = rand() % SIZE;
        col = rand() % SIZE;
    } while (board[row][col] != ' ');  // Find an empty space
    board[row][col] = 'O';  // Computer moves
    printf("Computer moves at: %d %d\n", row, col);
}

// Main game loop
int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int turn = 0;  // 0 for Player 1 (X), 1 for Player 2 (Computer - O)
    int winner = 0;

    printBoard(board);

    while (!isBoardFull(board)) {
        if (turn % 2 == 0) {
            // Player's move
            playerMove(board);
            printBoard(board);
            winner = checkWinner(board, 'X');
            if (winner) {
                printf("Player wins!\n");
                break;
            }
        } else {
            // Computer's move
            computerMove(board);
            printBoard(board);
            winner = checkWinner(board, 'O');
            if (winner) {
                printf("Computer wins!\n");
                break;
            }
        }

        turn++;
    }

    if (!winner && isBoardFull(board)) {
        printf("It's a draw!\n");
    }

    return 0;
}
