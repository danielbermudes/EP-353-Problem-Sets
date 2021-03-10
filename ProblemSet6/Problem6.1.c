/* This C program displays (example):
 The string, "Without music, life would be a mistake", has 38 characters.

To compile and run this program type:
clang Problem6.1.c -o Problem6.1 && ./Problem6.1
*/
#include <stdio.h>
 
void countCharacter(int n,char *string)
{ 
    if(string[n] == '\0') 
    {
        printf("%d characters.\n", n); 
        return;
    }
     
    countCharacter(n+1,string);
    
}
 
int main()
{ 
    int n;
    char string[100];
    printf("Give a string : \n"); 
    scanf("%[^\n]",string);
    printf("The string, \"%s\", has ", string);
    countCharacter(0,string);
     
    return 0;
}