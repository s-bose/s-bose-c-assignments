#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


int not_conflicting(int* position, int curr) {
    for (int i = 0; i < curr; i++) {
        if (position[i] == position[curr]) return 0; //horizontal conflict

        if (abs(curr - i) == abs(position[curr] - position[i])) return 0; //diagonal conflict

        //no vertical conflict since each queen is on separate column
    }
    return 1; 
}

void printSolution(int* position, int size) {
    int mat[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mat[i][j] = 0;
        }
    }

    fill_board(position, size, mat);
    display_board(size, mat);

}

int n_queens(int* position, int curr, int n) {
    if (curr == n) return 1;
    else {
        for (int i = 0; i < n; i++) {
            position[curr] = i;
            if (not_conflicting(position, curr)) {
                int ret = n_queens(position, curr+1, n);
                if (ret) {
                    printSolution(position, n);
                }
            }    
        }
        return 0;
    }
}



int* solve_n_queens(int n) {
    int* position = (int*)malloc(sizeof(int) * n);  //holds the current position (row no) of each queen in each column
    for (int i = 0; i < n; i++) {
        position[i] = -1;
    }

    if (n_queens(position, 0, n)) {
        return position;
    } 
    else return NULL;
}




int main() {
    int size;
    printf("Enter the board size: ");
    scanf("%d", &size);
    
    solve_n_queens(size);
     
    return 0;
}


