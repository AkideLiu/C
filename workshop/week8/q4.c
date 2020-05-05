// Author : Akide Liu 
// Date : 5/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//
#include <stdio.h>
#include <math.h>

int main(){
    int a , b , c;
    printf("Enter the first value : ");
    scanf("%d", &a);

    printf("Enter the second value : ");
    scanf("%d", &b);

    c = a + b;
    c = pow(c, 2);
    printf("%d + %d = %d\n", a, b, c);

    return 0;
}