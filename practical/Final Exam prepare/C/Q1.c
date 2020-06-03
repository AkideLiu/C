// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :
// Write a script (MATLAB)/main function (C) that asks the user for the DNA sequence and prints this sequence.  For this question, you may assume the sequence is no more than 10 characters.

//
#include <stdio.h>

int main(){
    char array[10];

    printf("Enter the sequence: ");
    scanf("%s", array);

    scanf("%*[^\n]"); scanf("%*c");

    printf("Sequences: \n%s", array);
}
