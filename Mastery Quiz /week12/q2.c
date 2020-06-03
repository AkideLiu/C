// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdlib.h>
#include <stdio.h>

void fun (int  ** values){

    values[1][0] = 1;
    printf("%d", values[1][2]);
    // values[5] = 1;
    // printf("%d\n", values[5]);
}

int main(){
    int numbers1[5][4];

    int * numbers2 = malloc (5*4*sizeof(int));

    int ** numbers3 = malloc (5 * sizeof(int *));

    fun(numbers3);
    printf("%d , %d", sizeof(int), sizeof(int *));
    printf(" numbers1 : %d , numbers2 : %d , numbers3 : %d", sizeof(numbers1), sizeof(numbers2), sizeof(numbers3));

    free(numbers2);
    free(numbers3);
}
