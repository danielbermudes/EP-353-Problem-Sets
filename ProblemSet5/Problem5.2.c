/* This C program displays:
MIDI Pitch Value: 28
MIDI Pitch Value: 35
MIDI Pitch Value: 51
MIDI Pitch Value: 54
MIDI Pitch Value: 68
MIDI Pitch Value: 74
MIDI Pitch Value: 89

To compile and run this program type:
clang Problem5.2.c -o Problem5.2 && ./Problem5.2
*/

#include <stdio.h>

int main(){
    int data[7];
    char pitches[] = {74, 68, 54, 28, 89, 51, 35};
    int temp; //This is a 'temporary' integer variable (like a ghost clip in Ableton!) that will help swap values between two elements in the array.

    //"Bubble Sort"
    for (int i = 0; i < 7; i++){ //This loop will run through the array, while the one below will be comparing itself with this one.
        for (int j = i+1; j < 7; j++){
            if(pitches[i] > pitches[j]){ //This indicates program to sort in ascending (>) order. 
                temp = pitches[i]; //Here, whatever was stored in temp will swap with pitches[i].
                pitches[i] = pitches[j]; //Whatever was stored in pitches[i] will swap with pitches[j].
                pitches[j] = temp; //Whatever was stored in pitches[j] will swap with temp, it's a whole cycle this code does, seeing which values are bigger or smaller.
            }
        }
    }

    for (int i = 0; i < 7; i++){
        data[i] = i;
        printf("MIDI Pitch Value: %d\n", pitches[i]); //'printf()' prints out array, now having been sorted.
    }

    return 0;
}