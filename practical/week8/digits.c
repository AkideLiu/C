// Author : Akide Liu 
// Date : 5/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Read in a positive, three digit integer and calculate the number of ones (units), tens and hundreds in the number and print these on separate lines.

//
#include <stdio.h>

int main(){
    int inputInt = 0;
    int hundred, tens, ones;

    while (inputInt < 100 || inputInt > 1000) {
        printf("Enter enter three digit integer : \n");
        scanf("%d", &inputInt);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
    }



    //calculate units
    //(int) convert inputInt to
    hundred = (int)inputInt / 100 % 10;
    tens = (int)inputInt / 10 % 10;
    ones = (int)inputInt % 10;

    //output
    printf("%d \n%d \n%d \n", hundred, tens, ones);

    return 0;

}