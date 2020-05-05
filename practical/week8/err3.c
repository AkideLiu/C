//

// Author : Akide Liu 
// Date : 4/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE

//

#include <stdio.h>

int main() {
    int  x = 0;

    printf("enter a number and I'll double it: ");
    scanf("%d", &x);
    // error occurred by missing &
    printf("twice %d is %d\n", x, 2*x);
    return 0;
}