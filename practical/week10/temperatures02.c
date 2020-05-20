// Author : Akide Liu 
// Date : 20/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a program called temperatures01 that reads a (non-empty) sequence maximum daily temperatures.  Your program should first ask for the number of temperatures to read and dynamically allocate  an array just big enough to hold the number of temperatures you read.  You should then read in the elements of the array using a loop.  You then should print out the elements of the array in reverse order (from most recent to oldest).


//initally allocate an array to hold up to 5 temperatures.
// prompt the user to enter temperatures and type the value -100.0 when they are finished.
// if the user fills up the array your program should
// dynamically allocate a new array which is double the size.
// copy the old values across to the new array.
// deallocate the old array.
// continue reading into the new array.

//

#include <stdio.h>
#include <stdlib.h>

int main(){

    //-------------declaration and initialization part -------------


    double *temperArray;
    int count = 0;
    double temp;
    const int initialLen = 5;
    int runTimeLen = initialLen;


    //allocate dynamic array to store temperatures
    temperArray = (double *) malloc(sizeof(double) * (initialLen));
    // set a null at beginning to
    // mark as empty.
    temperArray[0] = '\0';

    //reverse store temperatures
    for (int i = 0; i < runTimeLen; ++i) {
        printf("please enter the temperatures: ");
        scanf("%lf", &temp);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");

        //the switch to stop the loop
        if (temp == -100){
            break;
        }

        //count how many number imputed
        count ++;

        //when the length of temperature array nearly run out
        // 1. temporarily create a temporary array to store the old data
        // 2. destroy temperArray
        // 3. extend the run time length of new temperArray (double the size of temperArray)
        // 4. create new temperArray using new run time length
        // 5. copy data from temporary array to new temperArray
        // 6. append data to new temperArray
        // 7. destroy temporary array

        if (i == runTimeLen - 1){

            double *tmpArray;
            tmpArray = (double *) malloc(sizeof(double) * runTimeLen);
            for (int j = 0; j <runTimeLen ; ++j) {
                tmpArray[j] = temperArray[j];
            }
            free(temperArray);

            runTimeLen = runTimeLen * 2;
            temperArray = (double *) malloc(sizeof(double) * (runTimeLen));
            for (int j = 0; j < runTimeLen / 2 ; ++j) {
                temperArray[j] = tmpArray[j];
            }
            temperArray[i] = temp;

            free(tmpArray);

        } else{
            temperArray[i] = temp;
        }
    }


    //output result
    printf("temperatures in reserved order : ");

    for (int j = count; j >= 0 ; --j) {
        if (temperArray[j] != 0.0 ){
            printf(" %.1lf ", temperArray[j]);
        }
    }

    //destroy dynamic array
    free(temperArray);
    return 0;
}