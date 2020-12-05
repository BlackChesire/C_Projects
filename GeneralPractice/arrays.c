#include <stdio.h>
#define NUM_OF_GRADES 5
float calc_avg(int grades[NUM_OF_GRADES]){
    int sum = 0;
    for (int i = 0; i < NUM_OF_GRADES; ++i){
        sum += grades[i];
    }
    return (float)sum / NUM_OF_GRADES;
}
int main(){
    int grades[NUM_OF_GRADES]; // definning array in the size of NUM_OF_GRADES (5)
    for(int i = 0; i < NUM_OF_GRADES; ++i){
        printf("Enter grade number %d:\n",i + 1);
        scanf("%d",&grades[i]);
    }
    printf("the average of the grades is:%f \n", calc_avg(grades));


    return 0;
}
