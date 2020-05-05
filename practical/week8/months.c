// Author : Akide Liu 
// Date : 6/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
// Write a C program that reads an integer (between 1 and 12) and prints out a three-letter abbreviation for a month corresponding to that number.

//

#include <stdio.h>
#include <errno.h>

int main(){
    //variables declaration
    int month = 0;
    //input validation
    while (month < 1 || month > 12) {
        printf("Please enter a number instead of months.txt [1 - 12]\n");
         scanf("%d", &month);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
    }

    //conditional
    switch (month) {
        case 1 : printf("Jan\n");
            break;

        case 2 : printf("Feb\n");
            break;

        case 3 : printf("Mar\n");
            break;

        case 4 : printf("Apr\n");
            break;

        case 5 : printf("May\n");
            break;

        case 6 : printf("Jun\n");
            break;

        case 7 : printf("Jul\n");
            break;

        case 8 : printf("Aug\n");
            break;

        case 9 : printf("Sep\n");
            break;

        case 10 : printf("Oct\n");
            break;

        case 11 : printf("Nov\n");
            break;

        case 12 : printf("Dec\n");
            break;

        default: printf("Month error, error input is %d",month);
    }

    return 0;
}