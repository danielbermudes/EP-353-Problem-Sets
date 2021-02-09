/* This file displays
"This MIDI note consists of:
         Pitch:          68
         Velocity:       110
         Channel:        1

This MIDI note consists of:
         Pitch:          68
         Velocity:       0
         Channel:        1"

To compile and run this program type:
clang Problem2.2.c -o Problem2.2 && ./Problem2.2
*/

#include <stdio.h>

int main(){

    int Pitch = 68;
    int Velocity = 110;
    int Channel = 1;

printf("This MIDI note consists of:\n\t Pitch:\t\t %d\n\t Velocity:\t %d\n\t Channel:\t %d\n\n", Pitch, Velocity, Channel);

    Pitch = 68;
    Velocity = 0;
    Channel = 1;

printf("This MIDI note consists of:\n\t Pitch:\t\t %d\n\t Velocity:\t %d\n\t Channel:\t %d\n", Pitch, Velocity, Channel);

return 0;

}