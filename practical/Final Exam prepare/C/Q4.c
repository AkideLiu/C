// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

int main(){
    char *array_row = (char *) malloc(sizeof(char) * 10);
    int count = 0;

    printf("How many sequences will you enter?: ");
    scanf("%d", &count);
    scanf("%*[^\n]"); scanf("%*c");

    char **array = (char **) malloc(sizeof(char *) * count);


    for (int i = 0; i < count; ++i) {
        printf("Enter the sequence: ");
        scanf("%s", array_row);
        scanf("%*[^\n]"); scanf("%*c");
        array[i] = array_row;
    }


    printf("\nSequences: \n");
    for (int i = 0; i < count; ++i) {
        printf("%s\n", array[i]);
    }


    free(array);
    free(array_row);

    return 0;
}