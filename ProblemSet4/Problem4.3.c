/* This file is supposed to display a pattern where the local variable values remain at 9, while the global variable values decrement from 9 to 0.

To compile and run this program type:
clang Problem4.3.c -o Problem4.3 && ./Problem4.3
*/
#include <stdio.h>
int global = 9;
                
void decrement();
void decrement(){
    //int global = 9;
    while(global > 0){
        global--;
    }
                                       
    int local = 9;
    while(local > 0){
        local--;
    }
    
   // printf("  %d   |   %d\n", local, global);
    
}

int main (){
{    
    printf("local | global\n--------------\n");
}
    decrement();
    for(int global = 9; global > 0; --global)
    printf("  %d   |   %d\n", global);

    return 0;
}