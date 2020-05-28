// Author : Akide Liu 
// Date : 29/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdlib.h>
#include <stdio.h>

int values_under_100(const int *array, int size){
    int count = 0;
    for (int i = 0; i < size; ++i) {
        (array[i] < 100) ? count += 1 : count ;
    }
    return count;
}

int main(void) {

    int values[6]={-1,200,400,5,-3,600};
    int size=6;

    // call the function
    int count = values_under_100(values, size);

    printf("There are %d values under 100\n", count);

    return 0;
}
