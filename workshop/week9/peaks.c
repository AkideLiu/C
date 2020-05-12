// Author : Akide Liu 
// Date : 12/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : In this question, you have to write C code which initialises an array called vals of 10 integers (you can do this in the source-file for this exercise).  And calculates and stores, in another array called peaks, the numbers from vals which are peaks. A number is a peak if the two numbers on either side of it are less than it.  Your program should print the values in the peaks array.

//


#include <stdio.h>
int main() {
    int vals[10] = {1, 2, 2, 3, 2, 4, 1};
    // int vals[10] = {3, 2, 1, 4, 1, 3, 1};
    // int vals[10] = {1, 2, 3, 4, 4, 3, 2};
    int peaks[10];
    int peek_index = 0;

    for (int i = 0; vals[i] != '\0'; ++i) {
        if (vals[i] > vals[i - 1] && vals[i] > vals[i + 1]) {
            if (i != 0 && i != sizeof(peaks)/sizeof(peaks[0])){
                peaks[peek_index] = vals[i];
                peek_index ++ ;
            }
        }
    }

    peaks[peek_index] = '\0';

    for (int j = 0; peaks[j] != '\0' ; ++j) {
        printf("%d ",peaks[j]);
    }
}