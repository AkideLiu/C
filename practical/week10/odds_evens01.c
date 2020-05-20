// Author : Akide Liu 
// Date : 21/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a program called odds_evens01 that reads a (non-empty) sequence of integers.  As for question 1 above, your program should first ask for the number of integers to read and dynamically allocate  an array just big enough to hold the number of values you read.

//

#include <stdlib.h>
#include <stdio.h>

int main() {
    int *oddsArray;
    int *evensArray;
    int *inputArray;
    int count;
    int oddsArrayLen = 0;
    int evensArrayLen = 0;

    //Ask for how many number user want to enter.
    printf("please enter how many number of temperatures you want to entry \n");
    scanf("%d", &count);
    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    //allocate dynamic array to store temperatures
    inputArray = (int *) malloc(sizeof(int) * (count + 1));
    // set a null at beginning to
    // mark as empty.
    inputArray[0] = '\0';


    //read user's input and store that into input array
    for (int i = 0; i < count ; ++i) {
        printf("please enter an integer: ");
        scanf("%1d", &inputArray[i]);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");

        //determine whatever odd or even number , then calculate the length of odd array or even array
        inputArray[i] % 2 != 0 ? oddsArrayLen ++ : evensArrayLen ++;

    }

    //allocate dynamic array
    oddsArray = (int *) malloc(sizeof(int) * (oddsArrayLen + 1));
    oddsArray[0] = '\0';
    evensArray = (int *) malloc(sizeof(int) * (evensArrayLen + 1));
    evensArray[0] = '\0';

    //initialize index of odd array and even array
    int oddsArrayIndex = 0;
    int evensArrayIndex = 0;

    //determine whatever odd or even number , then put them into related array
    for (int i = 0; i < count ; ++i) {
        if (inputArray[i] % 2 != 0){
            oddsArray[oddsArrayIndex] = inputArray[i];
            oddsArrayIndex ++;
        } else{
            evensArray[evensArrayIndex] = inputArray[i];
            evensArrayIndex ++;
        }

    }

    //output oddsArray and evensArray

    printf("Odds:");
    for (int i = 0; i < oddsArrayLen; ++i) {
        printf(" %d", oddsArray[i]);
    }

    printf("\nEvens:");
    for (int i = 0; i < evensArrayLen; ++i) {
        printf(" %d", evensArray[i]);
    }

    //destroy oddsArray and evensArray
    free(oddsArray);
    free(evensArray);

    return 0;
}

