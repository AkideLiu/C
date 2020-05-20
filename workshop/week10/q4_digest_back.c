// Author : Akide Liu 
// Date : 20/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
// In this question you have to write C code for a program called digest_back that extends digest by putting the characters in the sum of digits back into a character array as a string and displaying that string. You can use the original character array to store this string (no need to allocate a new one for this purpose).

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

    char *newChar;
    newChar = (char*)malloc(sizeof(char) * (strlen(input) + 1));
    //ref :  int to char[] conversion
    // https://stackoverflow.com/questions/5050067/simple-int-to-char-conversion/5050086
    sprintf(newChar,"%s %d",input,sum);

    printf("sum is %d , digest back is : %s",sum,newChar);

    free(digitalArray);
    free(newChar);
    return 0;
}