/* This file displays (Example):
The frequency of a MIDI note number 69 is 440.0000Hz.

To compile and run this program type:
clang Problem3.1.c -o Problem3.1 && ./Problem3.1
*/

#include <stdio.h>
#include <math.h>

int main(){

    char midiNote;
    float frequency;

    midiNote = 'E'; //Change this value into any single character.
    frequency = pow(2, (((int) midiNote - 69) / 12.0)) * 440.0;

    printf("The frequency of a MIDI note number %d is %.*fHz.\n", midiNote, 4, frequency); //%d is used instead of %c to change midiNote to numerical format in printout.

    return 0;
}
