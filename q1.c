#include <stdio.h>
#include <stdlib.h>
int main(){
    int num = 0,highestnum=0,lowestnum;
    scanf("%d",&lowestnum);
    scanf("%d",&highestnum);
    while(scanf("%d",&num) == 1){
        if (num > highestnum){
            highestnum = num;
        }
        if (num < lowestnum){
            lowestnum = num;
        }
    }
        printf("lowest num:%d\n",lowestnum);
        printf("highest num:%d\n",highestnum);
      return 0;  
    }


    
    