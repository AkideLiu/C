// Author : Akide Liu
// Date : 27/5/20
// License and copyright notice: GNU General Public License v3.0
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :

//

#include<stdio.h>
#include<stdlib.h>

int* make_zeros(int rows){
    int *result;
    result = (int *) malloc(sizeof(int) * rows);

    for (int i = 0; i < rows; ++i) {
        result[i] = 0;
    }

    return result;
}

void print_array(int *array ,int length){
    for(int i=0;i<length;i++){
        printf(" %d ",array[i]);
    }
}

// driver code for array copy
int main(void){

    // declare 1d array
    printf("Enter almost of zeros :");
    int length;
    scanf("%d", &length);

    int *array = make_zeros(length);

    print_array(array, length);


    return 0;


}