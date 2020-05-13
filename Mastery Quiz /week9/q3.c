// Author : Akide Liu 
// Date : 14/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>

int main(){
    // char data = 'A';
    char data = 'G';
    //both valid for A and G
    switch (data) {
        case 'G':
        case 'A':
            printf("Valid\n");
            // break;
    }

    if (data == 'A' || data == 'G'){
        printf("Valid\n");
    }
}