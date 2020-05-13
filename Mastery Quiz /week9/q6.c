// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>

int main(){

    int numbers[5] = {1,2,3,4,5};

    for (int i = 0; i < 5; i++) {
        numbers[i] = numbers[i] + 1;
        printf("%d",numbers[i]);
    }

    // numbers[] = {2,3,4,5,6};
    // numbers = numbers + 1;

}