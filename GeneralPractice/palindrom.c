
#include <stdio.h>
int main(){
    int num,copynum=0,trash;
    printf("please enter a number :");
    scanf("%d",&num);
    trash = num;
    while (trash != 0)
    {
        copynum *= 10;
        copynum += trash % 10;
        trash /= 10;
    }
    if(copynum == num){
        printf("this is a palindorm");
    }
    else
    {
        printf("this is not a palindrom");
    }
    
    

    return 0;
}