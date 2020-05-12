// Author : Akide Liu 
// Date : 12/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
    // int positions[10] = {1,2,3};
    int positions[10] = {7,8,2,3};

    int sumdiffs[10] = {};
    int sumdiffs_index = 0 ;
    int running_sum = 0;

    for (int i = 0; positions[i] != '\0' ; ++i) {
        for (int j = 0; positions[j] != '\0' ; ++j) {
            if (i != j){
                running_sum += abs(positions[j] - positions[i]);
            }
        }
        sumdiffs[sumdiffs_index] = running_sum;
        sumdiffs_index ++;
        running_sum = 0;
    }

    sumdiffs[sumdiffs_index] = '\0';

    for (int k = 0; sumdiffs[k] != '\0' ; ++k) {
        printf("%d ",sumdiffs[k]);
    }


}