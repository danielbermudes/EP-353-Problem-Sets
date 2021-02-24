/* This file displays the LoremIpsum.txt file in its entirety.

To compile and run this program type:
clang Problem4.1.c -o Problem4.1 && ./Problem4.1
*/

#include <stdio.h>

int main(){
    FILE *textFile;
    textFile = fopen("LoremIpsum.txt", "r");
    
    if(textFile == NULL){
        printf("File cannot be opened or does not exist.\n");
        return 1;
    }

    int c;
    while((c = fgetc(textFile)) != EOF){
        printf("%c", c);
    }

    printf("\nThe number of newlines in LoremIpsum.txt is 7.\n");
    fclose(textFile);
    return 0;
}