// Author : Akide Liu 
// Date : 18/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
// Prompts the user for one string of no more than 256 characters.
// Reads that string into character array.
// Prompts the user for another string of no more than 256 characters.
// Reads this second string into a character array.
// Finds the length of both strings.
// Dynamically allocates memory to hold both strings.
// Concatenates both strings into the dynamically allocated array.
// Prints the concatenated string.

//
#include<stdio.h>
#include<stdlib.h> // for malloc
#include<string.h> // for string funs

int main(void){
    // two input arrays
    char input1[257];
    int len1;
    int combinedLen = 0;
    char *combined;
    char *tmpCombined;



    // read in the arrays
    printf("Enter a string (max 256 char) ");
    scanf("%256s",input1);
    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    int i = 0;
    while (input1[0] != '#'){
        len1=strlen(input1);

        combined=malloc(sizeof(char)*(combinedLen+len1+1));
        combined[0]='\0';

        if (i != 0){
            strcat(combined,tmpCombined);
        }
        strcat(combined,input1);
        combinedLen = strlen(combined);

        tmpCombined = malloc(sizeof(char)*(combinedLen+1));
        tmpCombined[0] = '\0';
        strcat(tmpCombined,combined);

        free(combined);

        printf("Enter a string (max 256 char) ");
        scanf("%256s",input1);
        //clear input buffer
        scanf("%*[^\n]"); scanf("%*c");
        i ++;

    }


    // print
    printf("%s\n",tmpCombined);

    free(tmpCombined);

    return 0;

}
