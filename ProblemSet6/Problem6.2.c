/* This C program displays (example):
Enter a number to initialize with:
15
The 'numbers' array is now initialized to 15:
        15, 15, 15, 15, 15, 15, 15, 15

To compile and run this program type:
clang Problem6.2.c -o Problem6.2 && ./Problem6.2
*/

#include <stdio.h>

int numbers[8];
void setArray(int *numbers, int value, int size);

void setArray(int *numbers, int value, int size){
    for(int i = 0; i < size; i++){
        numbers[i] = value;
    }
}

int main(){

    int value;
    printf("Enter a number to initialize with:\n");
    scanf("%d", &value);
    setArray(numbers, value, 8);
    printf("The 'numbers' array is now initialized to %d:\n\t", value);
    
    for(int i = 0; i < 8; i++){ //This section is more for laying out the printout like how the problem requested it, with ','.
        if(i < 7){
            printf("%d, ", numbers[i]);
        }
        else{
            printf("%d\n", numbers[i]);
        }
    }
    return 0;
}