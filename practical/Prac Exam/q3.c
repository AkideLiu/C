// Author : Akide Liu 
// Date : 3/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int main(){
    int count = 0;
    int input_num = 0;
    int second_array_index = 0;


    printf("How many grades to be entered: ");
    scanf("%d", &count);

    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    int *first_array = malloc(sizeof(int) * (count + 1));
    int *second_array = malloc(sizeof(int) * (count + 1));

    if (first_array == NULL || second_array == NULL ) {
        printf("allocation error\n");
        return 1;
    }

    first_array[0] = '\0';
    second_array[0] = '\0';

    for (int i = 0; i < count; ++i) {
        printf("Enter a grade: ");
        scanf("%d", &input_num);

        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");

        if (input_num >= 0 && input_num <= 100) {
            first_array[i] = input_num;
        } else {
            printf("Invalid grade ignored\n");
            i--;
        }
    }

    for (int i = 0; i < count; ++i) {
        if (first_array[i] >= 50) {
            second_array[second_array_index] = first_array[i];
            second_array_index++;
        }
    }

    printf("You entered the grades: ");
    for (int i = 0; i < count; ++i) {
        printf(" %d", first_array[i]);
        if (i < count - 1) {
            printf(",");
        }
    }

    printf("\nThe passing marks are: ");
    for (int i = 0; i < second_array_index; ++i) {
        printf(" %d", second_array[i]);
        if (i < second_array_index - 1) {
            printf(",");
        }
    }

    free(first_array);
    free(second_array);

    return 0;
}