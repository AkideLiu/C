// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <string.h>
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

char  * remove_nucleotide(const char * dna_sequence, char nucleotide, int sequence_length){

    char *new_array = (char *) malloc(sizeof(dna_sequence[0]) * sequence_length);

    int new_array_index = 0;

    for (int i = 0; i < sequence_length; ++i) {
        if (dna_sequence[i] != nucleotide){
            new_array[new_array_index] = dna_sequence[i];
            new_array_index++;
        }
    }

    return new_array;
}


int main(){
    char *array = (char *) malloc(sizeof(char) * 10);
    char remove_element;

    printf("Enter the sequence: ");
    scanf("%s", array);
    scanf("%*[^\n]"); scanf("%*c");

    printf("Which nucleotide do you want to remove?: ");
    scanf("%c", &remove_element);
    scanf("%*[^\n]"); scanf("%*c");

    array = remove_nucleotide(array, remove_element, (int)strlen(array));

    printf("\nSequences: \n%s \n", array);

    counter(array);

    free(array);

    return 0;
}