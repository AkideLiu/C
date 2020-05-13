// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a program called process_ages  that reads in an array of up to 10 integers representing peoples ages in years and calculates and prints the maximum age and the minimum age and the average age.  Your program should stop reading when either the 10th number is entered or the user enters -1. If the user enters any other negative number or a value above 150, they should be warned and prompted again for a valid age.

//

#include <stdio.h>

int main(){

    //-------------declaration and initialization part -------------

    //declaration of integer arrays
    int collection[10] = {};

    //variable declaration
    int collection_index = 0,
    age,
    //due to accepted minimum for age is 0, so max starts at 0 and will increasing in run time
    max = 0,
    //due to accepted maximum for age is 150,so min starts at 150 and will decreasing in run time
    min = 150,
    sum = 0;

    double avg;


    //-------------input part -------------

    //control the max input times (from 0 - 9) -- 10 elements
    //loop will automatically stop when collection_index not under 10
    while (collection_index < 10){

        //Display the different info for user
        if (collection_index == 0){
            printf("Enter a integer as age (positive and under 151) : ");
        } else{
            printf("Enter next integer : ");
        }

        //general catch user's input
        scanf("%d", &age);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");

        //catch the input error in cases of negative input and oversize input.
        //then repeat
        while (age < -1 || age > 150){

            //give error warning when user's input wrong
            printf("Error input , Enter a integer as age (positive and under 151): ");

            //re-try catch user's input
            scanf("%d", &age);
            //clear input buffer
            scanf("%*[^\n]"); scanf("%*c");
        }

        //condition for exit loop
        if (age == -1){
            //Display info show that user request to exit input
            printf("According to your signal, "
                   "input request determined, "
                   "result shows below: \n");
            break;
        }

        //add current elements input collection array and increase the collection_index
        collection[collection_index] = age;
        collection_index ++;
    }

    //Display info show that user input 10 times
    if (collection_index == 10){
        printf("You have already input 10 ages ... "
               "reach the limitation ... "
               "result shows below: \n");
    }



    //-------------progress part -------------

    //looping the collection array, figure out the maximum , minimum and average
    for (int i = 0; i < collection_index ; ++i) {

        if (collection[i] > max){
            max = collection[i];
        }
        if (collection[i] < min ){
            min = collection[i];
        }

        sum += collection[i];
    }

    //calculate average
    //note : due to collection_index increasing due the input operations, so it can be refer the amount of elements in  collection array
    avg = (double)sum / collection_index;


    //-------------output part -------------

    //format and display output
    printf("Based on your input, maximum is %d, minimum is %d, average is %.1lf",max,min,avg);

    return 0;

}


