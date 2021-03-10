/* This C program displays (example):
Enter five integers: 10 11 12 13 14
Input a number of steps to rotate: 3
User input:              10, 11, 12, 13, 14
After 3 rotations:       12, 13, 14, 10, 11

To compile and run this program type:
clang Problem6.3.c -o Problem6.3 && ./Problem6.3
*/

#include <stdio.h>

int numbers[5]; //Declares int array "numbers" with size of 5

void rotate(int *numbers, int size, int steps);
void rotate(int *numbers, int size, int steps){
    int i;
    int itr = 0;

    if(steps > 0){ //Rotation to the right
        while(itr < steps){ //Iterates rotation of the first index of the array to the right as user specifies.
            int last = *(numbers +(size - 1));

            for(i = size - 1; i >= 0; i--) {  // Decrements through the array
                *(numbers + i) = *(numbers + (i - 1)); // Changes value at current index to value at preceding index
            }
            *numbers = last; // Places last value in the array into first index

            itr++;
        }
    }
        

    else if(steps < 0){ //rotation to the left
        while(itr < (steps * -1)) { //Iterates rotation of the first index of the array to the left as user specifies.
            int first = *numbers;

            for(i = 0; i < size - 1; i++){ //Increments through the array.
                *(numbers + i) = *(numbers + (i + 1));
            }
            *(numbers + (size - 1)) = first;

            itr++;
        }
    }
}

int main(){

    printf("Enter five integers: ");
    scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]); // Takes integers and stores them in their respective element #.
    int userSteps; // Declares variable used to store user input for rotating steps
    printf("Input a number of steps to rotate: ");
    scanf("%d", &userSteps); // Takes user input and stores it in "steps"

    printf("User input:\t\t %d, %d, %d, %d, %d\n", numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]); // Prints integers from their element #.

    rotate(numbers, 5, userSteps);

    printf("After %d rotations:\t %d, %d, %d, %d, %d\n", userSteps, numbers[0], numbers[1], numbers[2], numbers[3], numbers[4]);
    
    return 0;
}