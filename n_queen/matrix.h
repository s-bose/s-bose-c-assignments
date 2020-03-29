#include <stdio.h>
#include <stdlib.h>

void display_board(int n, int mat[n][n]) {
    //displays nxn chessboard

    for (int row = 0; row < n; row++) {
        for (int col=0; col < n; col++) {
            printf("%d ", mat[row][col]);
        }
        printf("\n");
    }
    printf("\n\n\n\n");
}

void clear_board(int n , int mat[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                mat[i][j] = 0;
            }
        }
    }
}

void fill_board(int* position, int n, int mat[n][n]) {
    for (int k = 0; k < n; k++) {
            int row_no = position[k];
            mat[row_no][k] = 1;
        }
}
