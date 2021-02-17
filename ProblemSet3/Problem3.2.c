/* This file displays (Example):
A note 'B' translates to 11 in pitch class.

To compile and run this program type:
clang Problem3.2.c -o Problem3.2 && ./Problem3.2
*/

#include <stdio.h>

int main(){
    char note = 'b'; //Change this value into any single character between 'C' and 'B' (exclude notes with ♯ and ♭).
    int pitchClass;

    switch(note){
        case 'C':
        case 'c':
        pitchClass = 0;
            printf("A note 'C' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'D':
        case 'd':
        pitchClass = 2;
            printf("A note 'D' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'E':
        case 'e':
        pitchClass = 4;
            printf("A note 'E' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'F':
        case 'f':
        pitchClass = 5;
            printf("A note 'F' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'G':
        case 'g':
        pitchClass = 7;
            printf("A note 'G' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'A':
        case 'a':
        pitchClass = 9;
            printf("A note 'A' translates to %d in pitch class.\n", pitchClass);
            break;
        case 'B':
        case 'b':
        pitchClass = 11;
            printf("A note 'B' translates to %d in pitch class.\n", pitchClass);
            break;
        default:
            printf("The note entered is invalid.\n");

    }

    return 0;
}