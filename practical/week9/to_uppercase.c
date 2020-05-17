// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a C program called to_uppercase that reads from the user, a string of no more than 20 characters. The string represents a person's name and you can assume the string consists only of lower case letters and commas (the commas are to  separate names).
//
// After reading the string the program should convert the string to all uppercase letters and print it. Comma characters should be left unchanged.

//

#include <stdio.h>
#include <stdlib.h>

//function used to convert lower case letter to uppercase
//parameter : char string[20]
//return : void
void toUpper(char string[20]) {
    for (int i = 0; string[i] != '\0' ; ++i) {
        if (string[i] >= 'a' && string[i]<='z'){
            // convert to uppercase by minus 32 to their ASCII value.
            // ref : http://www.asciitable.com/
            string[i] = string[i] - 32;
        }
    }
}

//function for input validation
//parameter1 : const char string1[20]
//parameter2 :const char string2[20]
//return : void
//or : exit with code 1
void inputValidation(const char string1[20], const char string2[20]){

    //if string2 empty
    if (string2[0] == '\0'){

        //calculate how many elements inside array
        int array_len = 0;

        for (int i = 0; string1[i] != '\0' ; ++i) {
            array_len = i;
        }

        //+1 due to index starts at 0
        if (array_len + 1 >= 20 ){
            printf("input over size , which have length over : %d",array_len + 1);
            exit(1);
        }


        //if string2 not empty
    } else{
        int array_len1 = 0;
        int array_len2 = 0;

        //calculate how many elements inside array
        for (int i = 0; string1[i] != '\0' ; ++i) {
            array_len1 = i;
        }

        for (int i = 0; string2[i] != '\0' ; ++i) {
            array_len2 = i;
        }

        //+1 due to index starts at 0
        if (array_len1 + array_len2 +1 >= 20){

            printf("input over size , which have length over : %d",array_len1 + array_len2 + 1);
            exit(1);
        }
    }
}


int main(){

    //-------------declaration and initialization part -------------

    //variable declaration
    char string1[20] = {};
    char string2[20] = {};
    char errorString[20] = {};

    //-------------input part -------------

    printf("Enter a name no more than 20 characters : \n");

    //ref : https://en.cppreference.com/w/c/io/fscanf
    scanf("%20[a-z],%20[a-z]", string1, string2);
    scanf("%20[A-Z]",errorString);
    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    //-------------progress part -------------

    for (int i = 0; errorString[i] !='\0' ; ++i) {
        if (errorString[i] != '\0'){
            printf("Error, your input contains UPPER case latter --> %s",errorString);
            exit(2);
        }
    }
    //call inputValidation
    inputValidation(string1,string2);

    //call toUpper
    toUpper(string1);
    toUpper(string2);

    //-------------output part -------------

    //upon different case
    //case 1 : string2 empty --- > display string1
    //case 2 : string2 not empty ---> connect two array with comma
    if (string2[0] == '\0'){

        printf("Convert to uppercase : %s", string1);

    } else{

        printf("Convert to uppercase : %s,%s", string1, string2);

    }

    return 0;
}



