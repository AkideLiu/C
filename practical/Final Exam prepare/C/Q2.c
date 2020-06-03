// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <stdlib.h>

void counter(const char *array){
    int count_g = 0;
    int count_a = 0;
    int count_c = 0;
    int count_t = 0;

    for (int i = 0; array[i] != '\0'; ++i) {
        switch (array[i]) {
            case 'G':
                count_g++;
                break;
            case 'A':
                count_a++;
                break;
            case 'C':
                count_c++;
                break;
            case 'T':
                count_t++;
                break;
            default:
                printf("%c , error", array[i]);
        }
    }

    printf("\nThe sequence contains:\n"
           "%d guanine\n"
           "%d adenine\n"
           "%d cytosine\n"
           "%d thymine\n",
           count_g, count_a, count_c, count_t);

}

int main(){
    char *array = (char *) malloc(sizeof(char) * 10);

    printf("Enter the sequence: ");
    scanf("%s", array);

    scanf("%*[^\n]"); scanf("%*c");

    printf("\nSequences: \n%s \n", array);

    counter(array);

    free(array);

    return 0;
}