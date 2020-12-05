#include <stdio.h>
#include <stdlib.h>

int main(){
    float num = 0;
    printf("Please insert a number between -100 and 100:");
    while(scanf("%f",&num) == 1){
        if(num > -100 && num < 100){
            if (num<0){
                printf("%07.3f\n",num);
            }
            else{
                printf("+%06.3f\n",num);
            }

        }
        else
        {
            printf("Wrong input!");
            return 1;
        }
        
    }
    return 0;
}