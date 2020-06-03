// Author : Akide Liu 
// Date : 2/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdlib.h>
#include <stdio.h>

int** make_zeros(int rows, int cols){
    int **result = malloc(sizeof(int*) * rows);
    for (int row = 0; row < rows; ++row) {
        result[row] = malloc(sizeof(int) * cols);
    }

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            result[row][col] = 0;
        }
    }
    return result;
}

int main(){
    int rows = 0;
    int cols = 0;
    printf("Enter rows : ");
    scanf("%d", &rows);
    printf("Enter cols : ");
    scanf("%d", &cols);

    int** result = make_zeros(rows, cols);

    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            printf(" %d ", result[row][col]);
        }
        printf("\n");
    }
}