// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a C program called reverse_in_place which reads in a string (20 characters or less)  from the user into an array. Your program should then reverse that string and print out the reversed version.

//

#include <stdio.h>

int main(){

    //-------------declaration and initialization part -------------

    char array[20] = {};
    char reversArray1[20] = {},
         reversArray2[20] = {};
    int length = 0,
    reversArrayIndex = 0;

    //-------------input part -------------

    printf("Enter some words : \n");

    scanf("%s", array);
    //clear input buffer
    scanf("%*[^\n]"); scanf("%*c");

    //-------------progress part -------------

    //first way :
    //Get the how many elements inside of array
    for (int i = 0; array[i] != '\0' ; ++i) {
        length = i;
    }

    //inverse index to new array
    for (int j = length; j >= 0 ; --j) {
        reversArray1[reversArrayIndex] = array[j];
        reversArrayIndex ++;
    }


    //second way :
    {
        //additional work , no comments
        //tmp_from_s --> template element from start

        char tmp_from_s,
             tem_from_e;
        int tmp_from_s_index = 0,
            tmp_from_e_index = length;

        while (tmp_from_e_index != 0){
            tmp_from_s = array[tmp_from_s_index];
            tem_from_e = array[tmp_from_e_index];

            reversArray2[tmp_from_s_index] = tem_from_e;
            reversArray2[tmp_from_e_index] = tmp_from_s;

            if (length % 2 == 0){
                if (tmp_from_s == length / 2){
                    break;
                }
            } else{
                if (tmp_from_s == length / 2 - 1){
                    break;
                }
            }
            tmp_from_s_index ++;
            tmp_from_e_index --;
        }

    }


    //-------------output part -------------

    //format and display output

    printf("ReversArray1: %s\n", reversArray1);
    printf("ReversArray2: %s", reversArray2);

    return 0;
}



