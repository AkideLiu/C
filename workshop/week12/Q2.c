// Author : Akide Liu 
// Date : 2/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int **array_copy2d(int **src, int rows, int cols){
    int **result = malloc(sizeof(int *) * rows);

    if (result == NULL) {
        printf("allocation error\n");
        return NULL;
    }

    for (int row = 0; row < rows; ++row) {
        result[row] = malloc(sizeof(int) * cols);

        if (result[row] == NULL) {
            printf("allocation error\n");
            return NULL;
        }

        for (int col = 0; col < cols; ++col) {
            result[row][col] = src[row][col];
        }
    }
    return result;

}

// driver code for array copy
int main(void){

    // declare and build 2d array
    int rows=3;
    int cols=2;
    int row0[]={1,2};
    int row1[]={3,4};
    int row2[]={5,6};
    int *vals[3];

    // build vals
    vals[0]=row0;
    vals[1]=row1;
    vals[2]=row2;

    // destination array
    int **val_copy;


    // copy
    val_copy=array_copy2d(vals,rows,cols);
    // check if malloc worked
    if(val_copy==NULL){
        printf("allocation error\n");
        return 1;
    }

    // test
    for(int row=0; row<rows; row++){
        for(int col=0; col<cols; col++){
            printf("%d ",val_copy[row][col]);
        }
        printf("\n");
    }

    return 0;

}