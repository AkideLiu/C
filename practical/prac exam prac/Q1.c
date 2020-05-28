// Author : Akide Liu 
// Date : 29/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int main(){
    const int count = 5;
    double *array;
    array = (double*) malloc(sizeof(double) * count);
    double number;
    double max = 0;

    for (int i = 0; i < count ; ++i) {
        printf("enter a number : ");
        scanf("%lf", &number);

        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
        array[i] = number;

    }

    for (int j = 0; j < count ; ++j) {
        (j == 0) ? max = array[j] : max;
        if (max < array[j]) {
            max = array[j];
        }
    }

    printf("The largest of your numbers is: %.1lf", max);

    free(array);
}