/* This C program displays (example):
Enter the first line of your most favorite lyric: Now I done grew up 'round some people livin' their life in bottles
nOW i DONE GREW UP 'ROUND SOME PEOPLE LIVIN' THEIR LIFE IN BOTTLES

To compile and run this program type:
clang Problem5.3.c -o Problem5.3 && ./Problem5.3
*/

#include <stdio.h>
#include <string.h> //Using this header allows for the usage of strlen to determine the string length that is typed by the user.

int main(){

   int i;
   char lyric[128];
   printf("Enter the first line of your most favorite lyric: ");
   fgets(lyric, 128, stdin); //Using scanf didn't take into account whitespaces when a user types in a string. It would only print out one word, and ignore the rest.

   for (i = 0; i <= strlen(lyric); i++){ 
      if (lyric[i] >= 97 && lyric[i] <= 122) //'97' ~ '122' represents 'a' ~ 'z' on the ASCII table. 
         lyric[i] = lyric[i] - 32; //By subtracting 32 from 'lyric[i]', we bring down any uppercase letter to its equivalent lowercase letter.
      else if(lyric[i] >= 65 && lyric[i] <= 90) //'65' ~ '90' represents 'A' ~ 'Z' on the ASCII table. 
         lyric[i] = lyric[i] + 32; //By adding 32 to 'lyric[i]', we bring up any lowercase letter to its equivalent uppercase letter.
      else;
   }
   printf("%s\n", lyric);

   return 0;
}