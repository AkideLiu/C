// Author : Akide Liu 
// Date : 4/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Your name is <name>, you are <age> years old and your employment fraction is <fraction>.
            //  Name (no more than 20 letters)
            //  Age in years
            //  Full-time employment fraction (between 0.0 and 1.0)

            // clear input buffer reference :
            // https://www.geeksforgeeks.org/taking-string-input-space-c-3-different-methods/
//
#include <stdio.h>

int main(){
    //initialize variables
    char name[20];
    int age = 0;
    double empFra = 0;

    //ask for name
    printf("what is your name ? \n");
    scanf("%s", name);

    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");


    //ask for age
    printf("How old are you ? \n");
    scanf("%d", &age);

    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");


    //ask for employment fraction
    //input validation
    while (empFra <= 0.0 || empFra > 1.0){
        printf("What your Full-time employment fraction ? [0.0 1.0] \n");
        scanf("%lf", &empFra);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
    }



    //output
    printf("Your name is %s, you are %d years old and your employment fraction is %.1lf", name, age, empFra);

    return 0;
}