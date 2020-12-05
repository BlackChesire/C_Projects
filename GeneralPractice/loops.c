#include <stdio.h>
int main(){
    int number = 0, totalnumbers = 0;
    do{
    printf("enter a number any number but zero:\n");
    scanf("%d", &number);
    }
    while(number !=0);
    printf("you lied goodbye ! \n");
    return 0;
}