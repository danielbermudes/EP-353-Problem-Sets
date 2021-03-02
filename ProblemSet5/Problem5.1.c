/* This C program displays:
The value of arr at index 0 is 3
The value of arr at index 1 is 8
The value of arr at index 2 is 4
The value of arr at index 3 is 2
The value of arr at index 4 is 1
The value of arr at index 5 is 9
The value of arr at index 6 is 5

To compile and run this program type:
clang Problem5.1.c -o Problem5.1 && ./Problem5.1
*/

#include <stdio.h>

int main(){

    int numbers[] = {5, 9, 1, 2, 4, 8, 3};
    int i; //represents each individual element in the array.
    int j; //represents the actual index # in the array.

    for (int j = 0, i = 6; i >= 0; j++, i--){ //'j' will increment from 0 to 6, while 'i' will decrement from 3 to 5.
        printf("The value of arr at index %d is %d\n", j, numbers[i]);
    }
    return 0;
}