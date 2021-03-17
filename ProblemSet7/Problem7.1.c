/* clang Problem7.1.c -o Problem7.1 && ./Problem7.1

I wasn't able to understand how to print out the layout that the Problem asked for (with "---+" and "===+").
At first I thought it was just a matter of using printf() to print those out, but I think 
I may have just been overthinking it because I then thought it wasn't that. 

*/
#include <stdio.h>
#include <stdlib.h> //Included <stdlib.h> to use malloc() and free()
#include <time.h> //Included <time.h> to use rand() and srand()
    
int main(){

    int numBeats = 0;
    int numPercs = 0;
        printf("How many beats would you like in your drum pattern?: ");  //Asking the user for a number of beats
        scanf("%d", &numBeats);
        printf("How many percussions would you like in your drum kit?: "); //Asking the user for a number of percussions
        scanf("%d", &numPercs);
        
    char *sequence = malloc(sizeof(int) * numBeats * numPercs); //Alocating memory space for 'sequence', a char pointer-type variable.
    if(sequence == NULL){
        printf("malloc failed\n");
        return -1;
    }

    for (int perc = 0; perc < numPercs; perc++) {
    for (int beat = 0; beat < numBeats; beat++) {
      printf("beat: %d, perc: %d, state: %d, index: %d\n", 
      	beat, perc, sequence[perc * numBeats + beat], perc * numBeats + beat);
    }
  }

    int lower = 0, upper = 1, count = 1; //Implementing rand() and srand()
        srand(time(0));

    for (int i = 0; i < count; i++) {
        int num = (rand() % (upper - lower + 1)) + lower;
        printf("%d\n", num);
    }
    
    free(sequence); //Freeing the memory space
    return 0;
}

// clang Problem7.1.c -o Problem7.1 && ./Problem7.1
