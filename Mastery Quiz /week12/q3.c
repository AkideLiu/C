// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdlib.h>
#include <stdio.h>

int main(){
    int numbers1[5][4];

    int * numbers2 = malloc (5*4*sizeof(int));

    int ** numbers3 = malloc (5 * sizeof(int *));
    for (int r = 0; r < 5; r++) {
        numbers3[r] = malloc(4 * sizeof(int));
    }

    // numbers1[2][3] = 5;
    // numbers1[2*4+3] = 5;
    numbers2[2*4 + 3] = 5;
    // numbers2[2][3] = 5;
    // numbers3[2][3] = 5;
    // numbers3[2*4+3] = 5;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            // printf(" %d ", numbers1[i][j]);
        }
        printf("\n");
    }

    for (int k = 0; k < 2 * 4 + 3; ++k) {
        printf(" %d ", numbers2[k]);
    }

    free(numbers2);
    free(numbers3);
}