/*Read a finished 3×3 board using scanf(" %c", &board[i][j]) (characters X, O, or -). Check
all rows, columns, and both diagonals, then print the winner or declare a draw.*/
#include <stdio.h>

int main() {
    char board[3][3];
    int i, j;
    char winner = '-';
    
    printf("Do Your Moves(X or O):\n");

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            scanf(" %c", &board[i][j]);
        }
    }
	for (i = 0; i < 3; i++) {
    	for (j = 0; j < 3; j++) {
            printf(" %c ",board[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            winner = board[i][0];
        }
    }

    for (j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            winner = board[0][j];
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        winner = board[0][0];
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        winner = board[0][2];
    }

    if (winner == 'x' || winner == 'o') {
        printf("%c wins\n", winner);
    } else {
        printf("Draw\n");
    }

    return 0;
}
