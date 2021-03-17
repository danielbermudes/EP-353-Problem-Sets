/* This C program displays (example):
Input a value for Pitch: <
Input a value for Velocity: ^?
Input a value for Channel: ^A
The MIDI Note has:
Pitch -> 60
Velocity -> 127
Channel -> 1

To compile and run this program type:
clang Problem7.2.c -o Problem7.2 && ./Problem7.2
*/

#include <stdio.h>
#include <stdlib.h> //Included <stdlib.h> to use malloc() and free()

    struct Note{
    unsigned char pitch;
    unsigned char velocity;
    unsigned char channel;
    };

void printNote(struct Note *note); //Declaring a function called `printNote`

int main(){
    
    struct Note *note = malloc(sizeof(*note)); //Alocating memory space for 'Note', a struct.

    if(note == NULL){
        printf("malloc failed\n");
        return 1;
    }

    note->pitch = 0; //Initilazing each member with `0`
    note->velocity = 0;
    note->channel = 0;

    printf("Input a value for Pitch: "); //Asking the user for a pitch value
    scanf("%s", &note->pitch); //Inputs into its correspnding member
    printf("Input a value for Velocity: "); //Asking the user for a velocity value
    scanf("%s", &note->velocity); //Inputs into its correspnding member
    printf("Input a value for Channel: "); //Asking the user for a channel value
    scanf("%s", &note->channel); //Inputs into its correspnding member

    printNote(note);

    free(note); //Freeing the memory space
    return 0;
}

void printNote(struct Note *note){ //Defining the `printNote` function. To output decimal values, one must use char variables.
    printf("The MIDI Note has:\n");
    printf("Pitch -> %d\n", note->pitch);
    printf("Velocity -> %d\n", note->velocity);
    printf("Channel -> %d\n", note->channel);
}
