// Author : Akide Liu 
// Date : 3/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int count_negatives(const int *pInt, int size){

    int negative_count = 0;

    for (int i = 0; i < size; ++i) {
        if (pInt[i] < 0) {
            negative_count += 1;
        }
    }

    return negative_count;
};

int main(void) {

    int values[8]={-1,2,4,5,-3,6,-2,-6};
    int size=8;

    printf("There are %d negative values\n", count_negatives(values, size));

    return 0;
}


