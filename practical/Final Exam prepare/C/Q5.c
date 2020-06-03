// Author : Akide Liu 
// Date : 4/6/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char ** remove_nucleotides(char ** sequences, char * nucleotides, int number_of_sequences, int DNA_length){

    char **new_array = (char **) malloc(sizeof(char *) * number_of_sequences);
    for (int i = 0; i < number_of_sequences; ++i) {
        new_array[i] = (char *) malloc(sizeof(char) * DNA_length);
    }

    int new_array_row_index = 0;
    int new_array_col_index = 0;
    int dismiss_count = 0;
    int correct_count = 0;
    for (int i = 0; nucleotides[i] != '\0' && nucleotides[i + 1] != '\0'; ++i) {
        correct_count++;
    }


    for (int i = 0; i < number_of_sequences; ++i) {
        for (int j = 0; j < DNA_length; ++j) {
            dismiss_count = 0;
            for (int k = 0; k < strlen(nucleotides); ++k) {
                if (sequences[i][j] == nucleotides[k] && nucleotides[k] != '\0') {
                    dismiss_count ++;
                }
            }
            if (dismiss_count == 0) {
                new_array[new_array_row_index][new_array_col_index] = sequences[i][j];
                new_array_col_index++;
            }
        }
        new_array_row_index++;
        new_array_col_index = 0;
    }
    return new_array;
}

int main(){

    char *array_row = (char *) malloc(sizeof(char) * 10);

    int count = 0;
    char *remove_elements = (char *) malloc(sizeof(char) * 10);


    printf("How many sequences will you enter?: ");
    scanf("%d", &count);
    scanf("%*[^\n]"); scanf("%*c");

    char **array = (char **) malloc(sizeof(char *) * count);


    for (int i = 0; i < count; ++i) {
        array[i] = malloc(sizeof(char) * 10);
        printf("Enter the sequence: ");
        scanf("%s", array_row);
        scanf("%*[^\n]"); scanf("%*c");
        for (int j = 0; j < strlen(array_row); ++j) {
            array[i][j] = array_row[j];
        }
    }

    printf("Which nucleotide do you want to remove?: ");
    //https://stackoverflow.com/questions/4358383/c-scanf-with-spaces-problem
    scanf("%[^\n]", remove_elements);
    scanf("%*[^\n]"); scanf("%*c");

    array = remove_nucleotides(array, remove_elements, count, (int)strlen(array[0]));



    printf("\nSequences: \n");
    for (int i = 0; i < count; ++i) {
        printf("%s\n", array[i]);
    }


    free(array);
    free(remove_elements);
    free(array_row);

    return 0;
}