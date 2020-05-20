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
    char input2[257];

    // read in the arrays
    printf("Enter a string (max 256 char) ");
    scanf("%256s",input1);

    printf("Enter another string (max 256 char) ");
    scanf("%256s",input2);

    // find out their lengths
    int len1,len2;
    len1=strlen(input1);
    len2=strlen(input2);

    // allocate an array big enough for both
    char *combined;
    combined=malloc(sizeof(char)*(len1+len2+1));
    combined[0]='\0';  // set a null at beginning to
    // mark as empty.

    //concatenate
    strcat(combined,input1);
    strcat(combined,input2);

    // print
    printf("%s\n",combined);

    return 0;
}
