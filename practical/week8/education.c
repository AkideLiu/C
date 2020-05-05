// Author : Akide Liu 
// Date : 6/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
// Write a C program that reads in a positive integer representing the number of year's a person has spent in education so far and prints out the level of educational attainment associated with that number of year's education. Use the following guide:
//
// 0-7 years inclusive - Primary level education
// 8-12 years inclusive - Secondary level education
// 13+ years   - Tertiary level education.

//

#include <stdio.h>

int main(){
    //variables declaration
    int eduLevel = -1;

    //input validation
    while (eduLevel < 0) {
        //read input
        printf("Enter the number of year that you has spent in education\n");
        scanf("%d",&eduLevel);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
    }

    //conditional
    if (eduLevel >= 0 && eduLevel <= 7) {
        printf("You have spent %d years in education, you are currently in Primary level education", eduLevel);
    } else if (eduLevel >= 7 && eduLevel <= 12) {
        printf("You have spent %d years in education, you are currently in Secondary level education", eduLevel);
    } else if (eduLevel >= 13) {
        printf("You have spent %d years in education, you are currently in Tertiary level education", eduLevel);
    }

    return 0;
}