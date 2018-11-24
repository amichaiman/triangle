#include <stdio.h>

#define DOLLAR 0
#define SPACE 1

void printPiramide(int height, int dollars, int spaces);
void printChar(char c, int n);

int main(){
    int height, dollars, spaces;
    printf("enter height:");
    scanf("%d", &height);
    printf("enter number of dollars:");
    scanf("%d", &dollars);
    printf("enter number of spaces:");
    scanf("%d", &spaces);
    printPiramide(height, dollars, spaces);
}


void printPiramide(int height, int dollars, int spaces){
    int i, j;
    int curDollars=0, curSpaces=0;
    int currentCharacter = DOLLAR;

    for (i=0; i<height-1; i++){
        printChar(' ', height-1-i);
        printf("*");
        /*          fill inside of piramide             */

        for (j=0; j<(i*2-1); j++){
            printf("%c", currentCharacter == DOLLAR ? '$': ' ');
            if (currentCharacter == DOLLAR) {
                curDollars++;
                if (curDollars == dollars) {
                    currentCharacter = SPACE;
                    curDollars = 0;
                }
            } else {
                curSpaces++;
                if (curSpaces == spaces) {
                    currentCharacter = DOLLAR;
                    curSpaces = 0;
                }
            }
        }

        /************************************************/
        if (i == 0){
            printf("\n");
        } else {
            printf("*\n");
        }
    }
    printChar('*', (height-1)*2+1);
}

void printChar(char c, int n){
    int i;
    for (int i=0; i<n; i++){
        putchar(c);
    }
}
