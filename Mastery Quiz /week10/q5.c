// Author : Akide Liu 
// Date : 21/5/20
// License and copyright notice: GNU General Public License v3.0 
// https://github.com/AkideLiu/C/blob/master/LICENSE
// Description : 

//

#include <stdio.h>
#include <string.h>
int main(void) {

    char firstname[5];
    char lastname[5];
    char fullname[20] = "";  // initialise with empty string

    int count = scanf("%s %s", firstname, lastname);

    strcat(fullname, firstname);
    strcat(fullname, lastname);

    printf("%s\n", fullname);

    return 0;
}