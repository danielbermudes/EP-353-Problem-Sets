/* This file is supposed to display a pattern of 'Boots N Cats N' and 'Potato Cats!' based on what the user inputs as a number of bars with scanf().

To compile and run this program type:
clang Problem4.2.c -o Problem4.2 && ./Problem4.2
*/
#include <stdio.h>

void beatbox(int bar);
{
  for (int bar = 0; bar % 4 != 0; bar++ )
  }
    printf("Boots N Cats N\n");

    return;

//void beatbox(int bar){
  //if  
  //printf("Boots N Cats N\n");
  //printf("Potato Cats!\n\n");

int main(){
    
  int bar;

  printf("How many bars would you like to beatbox for?: ");
  scanf("%d", &bar);
  printf("You typed in: %d\n\n", bar);
    
  return 0;
}