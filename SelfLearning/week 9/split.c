// Author : Akide Liu 
// Date : 12/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
// split a string into letters less than m and greater or equal to m

int main(void) {
    // Prompts the user for a string consisting only lower-case letters (less than 20 characters long).
    char myString[21];
    //Reads that string into a character array. 
    printf("Please enter a string of up to 20 characters: ");
    scanf("%20s%*[^\n]%*c",myString);

    //Iterates through the string and places letters that are less than 'm' into an array called first and the letters that are 'm' or greater are placed into an array called last. 
    char first[21];
    int current_first_index = 0;
    char last[21];
    int current_last_index = 0;

    for (int i=0; myString[i]!='\0';i++) {
        if (myString[i] < 'm') {
            first[current_first_index] = myString[i];
            current_first_index++;
        }
        else {
            last[current_last_index] = myString[i];
            current_last_index++;
        }
    }
    //After finishing you should place a null character on the end of each array of letters so that they can be easily printed.
    first[current_first_index] = '\0';
    last[current_last_index] = '\0';

    //Your program should then print out the contents of first and second.
    printf("first is: %s\nlast is: %s\n", first, last);

    return 0;
}
