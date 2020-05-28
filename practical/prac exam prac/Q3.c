// Author : Akide Liu 
// Date : 29/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//
#include <stdlib.h>
#include <stdio.h>

int values_under_100(const int *array, int size , int **final_array){

    int count = 0;
    for (int i = 0; i < size; ++i) {
        (array[i] < 100) ? count += 1 : 0 ;
    }


    *final_array = (int *)malloc(sizeof(int) * (count + 1));

    int index = 0;

    for (int j = 0; j < size; ++j) {
        if (array[j] < 100) {
            (*final_array)[index] = array[j];
            index++;
        }
    }

    return count;
}

int main(void) {

    int number;
    int size;
    printf("How many values do you want to enter:");
    scanf("%d", &size);

    int *values;
    values = (int *) malloc(sizeof(int) * size);


    for (int i = 0; i < size; ++i) {
        printf("Enter a number:");
        scanf("%d", &number);

        values[i] = number;
    }

    // call the function
    int *under_100_array;

    int count = values_under_100(values, size ,&under_100_array);

    printf("There are %d values under 100\n", count);

    printf("The values less than 100 were: ");

    for (int i = 0; i < count; ++i) {
            printf(" %d ", under_100_array[i]);
    }

    free(values);
    free(under_100_array);

    return 0;
}