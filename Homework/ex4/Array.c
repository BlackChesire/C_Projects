#include "Array.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Array{
	LinkedList ll;
};

Array ArrayCreate(int arraysize,Element (*cpy)(Element), void (*fre)(Element)){
    if(arraysize > MAX_ARRAY_SIZE)
    fprintf(stderr,"the size you requesting for the array is too big ! file %s, line:%d\n",__FILE__, __LINE__);
    Array array = (Array)malloc(sizeof(struct Array)); // freed by ArrayDestroy
    array->ll = LLCreate(cpy,fre); // allocate NULL as requsted.
    for(int i=0; i<arraysize;i++){
        LLAdd(array->ll, i, NULL);
    }
    return array;
}

void ArrayDestroy(Array array){
    LLDestroy(array->ll);
}

int ArraySize(Array array){
    return LLSize(array->ll);
}

void ArrayResize(Array array,int new_array_size) {
    if(new_array_size < ArraySize(array)) {
        unsigned int index = ArraySize(array);
        while(index != new_array_size) {
            LLRemove(array->ll, index);
            index--;
        }
    }

    else if(new_array_size > ArraySize(array)) {
        unsigned int index = ArraySize(array);
        while(index >= new_array_size) {
            LLAdd(array->ll, index, NULL);
            index++;
        }
    }

    else if(new_array_size > MAX_ARRAY_SIZE) {
        fprintf(stderr, "Error, the maximum size of the array is 1000000, %d entered, __FILE__, __LINE__", new_array_size);
    }
}

Element ArrayGet(Array array,int index) {
    return array->ll
}
