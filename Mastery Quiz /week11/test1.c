// Author : Akide Liu 
// Date : 1/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>

int function(int * b, int c) {
    b++;
    c = 4;

    return c;
}

int main(void) {

    int a = 1;
    int b = 2;
    int c = 3;

    a = function(&b, c);
    printf("%d %d %d", a, b, c);
}

