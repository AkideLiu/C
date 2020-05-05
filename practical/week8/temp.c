//

// Author : Akide Liu 
// Date : 4/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : Temperatures in degrees Celsius can be converted to Fahrenheit by multiplying by 9, dividing by 5, and adding 32.
//
#include <stdio.h>

int main(){
    int temp = 0;
    printf("please enter temperature in unit of degrees Celsius: ");

    //request input for temperature in DC
    scanf("%d", &temp);

    //calculate temperature in Fahrenheit
    int fTemp = (temp * 9) / 5 + 32 ;
    printf("%d degrees Celsius is %d Fahrenheit", temp, fTemp);

    return 0;

}
