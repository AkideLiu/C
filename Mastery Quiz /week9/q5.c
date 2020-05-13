// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>

int main(){
/*    % returns the last element of array A that contains an even number
    % length contains the number of elements
    % in the array*/

    int A[5] = {1, 2, 4, 5, 7};

    int length = sizeof(A)/sizeof(int);

    for ( int i = length - 1; i > -1; i =  i-1) {
        if ( A[i] % 2 == 0) { // value mod 2 = 0 indicates even
            return i;
        }
    }
}