// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Write a program called odds_evens that declares an array of ints called nums containing the numbers: 11, 3, 9, 7, 6, 10, 13, 17, 2, 8, 3 and declares two more integer arrays called evens and odds with length 12.  Then write code to copy all of the even numbers in nums (in order) to evens and all the odd numbers of nums to the odds array.

//

#include <stdio.h>

int main(){

    //declaration of integer arrays
    // int odds_evens[12] = {11, 3, 9, 7, 6, 10, 13, 17, 2, 8, 3 };
    // int odds_evens[12] = {11, 13, 19, 17, 16, 10, 13, 17, 12, 18, 13 };
    int odds_evens[12] = {21, 23, 29, 27, 26, 20, 23, 27, 22, 28, 23 };

    int evens[12] = {};

    int odds[12] = {};

    //declaration of index of evens and odds array

    int even_index = 0; int odd_index = 0;

    //use iteration to classify even and odd, then put every elements into corresponding array

    for (int i = 0; odds_evens[i] != '\0' ; ++i) {

        //if elements can be divide by to 2 with remainder 0 -- > even
        //otherwise  --> odd

        if (odds_evens[i] % 2 == 0 ){

            //in order to append elements
            evens[even_index] = odds_evens[i];

            //increasing index after elements has been appended
            even_index ++ ;

        } else{

            //in order to append elements
            odds[odd_index] = odds_evens[i];

            //increasing index after elements has been appended
            odd_index ++ ;

        }
    }

    //display output
    printf("original array contains : ");

    for (int j = 0; odds_evens[j] != '\0' ; ++j) {
        printf("%d ", odds_evens[j]);
    }

    //display output
    printf("\nEvens array contains : ");

    for (int j = 0; evens[j] != '\0' ; ++j) {
        printf("%d ", evens[j]);
    }

    //display output
    printf("\nOdds array contains : ");

    for (int j = 0; odds[j] != '\0' ; ++j) {
        printf("%d ", odds[j]);
    }


    return 0;
}