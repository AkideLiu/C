// Author : Akide Liu 
// Date : 3/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int main(){
    const int count = 5;
    int input = 0;
    int *array = malloc(sizeof(int) * count);

    if (array == NULL) {
        printf("allocation error\n");
        return 1;
    }

    array[0] = '\0';

    int sum = 0;

    for (int i = 0; i < count; ++i) {
        printf("Enter a number: ");
        scanf("%d", &input);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");

        array[i] = input;
    }

    for (int i = 0; i < count; ++i) {
        sum += array[i];
    }

    printf("The sum of your numbers is: %d", sum);

    free(array);

    return 0;
}

