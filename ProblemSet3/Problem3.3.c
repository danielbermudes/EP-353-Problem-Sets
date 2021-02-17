/* This file displays:
B Bb A Ab G Gb F E Eb D Db C 

To compile and run this program type:
clang Problem3.3.c -o Problem3.3 && ./Problem3.3
*/

#include <stdio.h>

int main(){
    int i = 11;

    for (int i = 11; i >= 0; i--)
    
     switch (i){
        case 11:
            printf("B ");
            break;
        case 10:
            printf("Bb ");
            break;
        case 9:
            printf("A ");
            break;
        case 8:
            printf("Ab ");
            break;
        case 7:
            printf("G ");
            break;
        case 6:
            printf("Gb ");
            break;
        case 5:
            printf("F ");
            break;
        case 4:
            printf("E ");
            break;
        case 3:
            printf("Eb ");
            break;
        case 2:
            printf("D ");
            break;
        case 1:
            printf("Db ");
            break;
        case 0:
            printf("C \n");
            break;

     }


    return 0;
}



