// Author : Akide Liu 
// Date : 2/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include<stdio.h>
#include<stdlib.h>

// simple program to copy 2d array of numbers
void array_copy2d(int **src, int **dest, int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            dest[r][c] = src[r][c];
        }
    }
}

int main(){
    int rows = 3;
    int cols = 2;
    int row0[] = {1, 2};
    int row1[] = {3, 4};
    int row2[] = {5, 6};
    int *vals[3];

    vals[0] = row0;
    vals[1] = row1;
    vals[2] = row2;

    int **val_copy;

    val_copy = malloc(sizeof(int*) * rows);
    if (val_copy == NULL) {
        printf("allocation error\n");
        return 1;
    }

    for (int row = 0; row < rows; ++row) {
        val_copy[row] = malloc(sizeof(int) * cols);
    }

    array_copy2d(vals, val_copy, rows, cols);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            printf(" %d ", val_copy[row][col]);
        }
        printf("\n");
    }

    return 0;
}