// Author : Akide Liu 
// Date : 12/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include<stdio.h>

// main function
int main(void){
    // declare strings
    char letters[20], first[20], last[20];

    // read in a lower-case string
    printf("enter letters: ");
    scanf("%19s",letters);  //the number %19s limits the string to being
    //19 characters long (plus the null character)

    // setup indexes to track current index of  arrays.
    int letters_index, first_index, last_index;
    letters_index=0;
    first_index=0;
    last_index=0;

    // loop and split
    while(letters[letters_index] != 0) { // not null
        char curr_letter = letters[letters_index];
        // less than 'm'?
        if(curr_letter < 'm'){
            // add to first
            first[first_index]=curr_letter;
            first_index++;
        } else {
            // otherwise, add to last
            last[last_index]=curr_letter;
            last_index++;
        }
        letters_index++;
    }

    // now add nulls
    first[first_index]='\0';
    last[last_index]='\0';

    // print arrays
    printf("first: %s\n",first);
    printf("last: %s\n",last);
}