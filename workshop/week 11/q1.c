// Author : Akide Liu 
// Date : 27/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include<stdio.h>
#include<stdlib.h>

// simple program to copy 1d array of numbers

void array_copy(int *src, int *dest, int len){
    // copies from src to dest array.
    for(int i=0; i<len; i++){
        dest[i]=src[i];
    }
}


// driver code for array copy
int main(void){

    // declare 1d array
    int length=6;
    int vals[]={1,2,3,4,5,6};
    int *val_copy;

    // dynamically allocate space for val_copy
    val_copy=malloc(sizeof(int)*length);
    if(val_copy==NULL){
        printf("allocation error\n");
        return 1;
    }

    // copy
    array_copy(vals,val_copy,length);

    // test
    for(int i=0;i<length;i++){
        printf("val_copy %d is %d\n",i,val_copy[i]);
    }

    return 0;

}