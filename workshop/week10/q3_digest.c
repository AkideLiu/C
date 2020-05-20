// Author : Akide Liu 
// Date : 20/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
//reads in a string containing digits (you can assume the user types only digits).
// allocates an array of ints just big enough to hold the number of  digits.
// one-at-a-time converts the character digits from the string into integer digits in the int array.
// sums the digits in the integer array
// displays the resulting sum.

//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    char input[256] = {};

    printf("Please enter a string contains digits\n");
    scanf("%s",input);

    int digitalLen = 0;
    for (int i = 0; i < strlen(input) ; ++i) {
        if (input[i] >= 48 && input[i] <= 57){
            digitalLen ++;
        }
    }

    int *digitalArray;
    digitalArray = (int*)malloc(digitalLen*sizeof(int) + 1);
    digitalArray[0] = '\0';

    int digitalArrayIndex = 0;
    for (int j = 0; j < strlen(input) ; ++j) {
        if (input[j] >= 48 && input[j] <= 57){
            digitalArray[digitalArrayIndex] = input[j] - 48;
            digitalArrayIndex ++;
        }
    }

    int sum = 0;
    for (int k = 0; k < digitalArrayIndex  ; ++k) {
        sum += digitalArray[k];
    }

    printf("sum is %d",sum);

    free(digitalArray);
    return 0;
}