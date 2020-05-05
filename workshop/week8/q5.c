// Author : Akide Liu 
// Date : 5/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//
#include <stdio.h>
#include <math.h>

int main(){
    double radius = 0;
    double pi = 3.1415926;
    printf("please enter a radius: ");
    scanf("%lf", &radius);

    double result = pow(radius, 2) * pi;
    printf("The area of the circle of radius %.2lf is %.2lf", radius, result);

}
