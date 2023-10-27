#include <stdio.h>

char board[3][3]; // Tic-Tac-Toe board

void initializeBoard() {
    // Initialize the Tic-Tac-Toe board with empty spaces
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void printBoard() {
    // Print the Tic-Tac-Toe board
    printf("-------------\n");
    for(int i = 0; i < 3; i++) {
        printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
        printf("-------------\n");
    }
}

int checkWin() {
    // Check rows, columns, and diagonals for a win
    for(int i = 0; i < 3; i++) {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return 1; // Row win
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return 1; // Column win
    }
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return 1; // Diagonal win
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return 1; // Diagonal win
    return 0; // No win
}

int main() {
    int row, col, player = 1, totalMoves = 0;
    char mark;

    initializeBoard();

    printf("Tic-Tac-Toe Game\n");
    printf("Player 1: X\nPlayer 2: O\n");

    while(1) {
        printf("Player %d, enter row (0, 1, or 2) and column (0, 1, or 2) separated by space: ", player);
        scanf("%d %d", &row, &col);

        // Validate user input
        if(row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            mark = (player == 1) ? 'X' : 'O';
            board[row][col] = mark;
            totalMoves++;

            printBoard();

            // Check if the current player wins
            if(checkWin()) {
                printf("Player %d wins! Congratulations!\n", player);
                break;
            }

            // Check for a draw
            if(totalMoves == 9) {
                printf("It's a draw! Well played!\n");
                break;
            }

            // Switch to the next player
            player = (player == 1) ? 2 : 1;
        } else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}

