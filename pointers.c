#include <stdio.h>
int main(){
    int num = 5; 
    int* num_pointer = &num; // new pointer 
    // unsigned char* = num_adderss = (unsigned char*) &num; > we will use this to move 1 byte forward  
    int** pointer_to_pointer_to_num = &num_pointer;
    printf("the number is = %d, the pointer to num is = %p\n", num,num_pointer);
    return 0;
}