// Author : Akide Liu 
// Date : 20/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a program called temperatures01 that reads a (non-empty) sequence maximum daily temperatures.  Your program should first ask for the number of temperatures to read and dynamically allocate  an array just big enough to hold the number of temperatures you read.  You should then read in the elements of the array using a loop.  You then should print out the elements of the array in reverse order (from most recent to oldest).

//

#include <stdio.h>
#include <stdlib.h>

int main(){

    //-------------declaration and initialization part -------------


    double *temperArray;
    int count;

    //Ask for how many number user want to enter.
    printf("please enter how many number of temperatures you want to entry \n");
    scanf("%d", &count);
    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    //allocate dynamic array to store temperatures
    temperArray = (double *) malloc(sizeof(double) * (count + 1));
    // set a null at beginning to
    // mark as empty.
    temperArray[0] = '\0';

    //reverse store temperatures
    for (int i = count - 1; i >= 0 ; --i) {
        printf("please enter the temperatures: ");
        scanf("%lf", &temperArray[i]);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
    }

    //output result
    printf("temperatures in reserved order : ");

    for (int j = 0; j < count ; ++j) {
        printf(" %.1lf ", temperArray[j]);
    }

    //destroy dynamic array
    free(temperArray);
    return 0;
}