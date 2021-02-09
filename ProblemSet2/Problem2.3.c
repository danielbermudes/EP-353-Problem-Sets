/* This file displays 
"This sine tone has:
         Frequency of 415.304Hz
         Decibel level of -47.9dB"

To compile and run this program type:
clang Problem2.3.c -o Problem2.3 && ./Problem2.3
*/

#include <stdio.h>

int main(){

    float Frequency = 415.304f;
    float Decibel = -47.9f;

printf("This sine tone has:\n\t Frequency of %.*fHz\n\t Decibel level of %.*fdB\n", 3, Frequency, 1, Decibel);

return 0;

}