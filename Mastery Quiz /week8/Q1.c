// Author : Akide Liu 
// Date : 6/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description :What will be the result stored in x for the following line of code:
//
//
//
// float x = -5.6 + 1 / 2;
//
// show 6 units after the decimal point:  for example, if the answer were 1.123 enter the result 1.123000

//
#include <stdio.h>

int main(){
    float x = -5.6 + 1 / 2;
    printf("%.6f", x);
}

