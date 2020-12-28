#include "Array.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Array{
	LinkedList ls;
};

Array ArrayCreate(int arraysize,Element (*cpy)(Element), void (*fre)(Element)){
    if(arraysize > MAX_ARRAY_SIZE)
    fprintf(stderr,"the size you requesting for the array is too big ! file %s, line:%d\n",__FILE__, __LINE__);
    Array array = (Array)malloc(sizeof(struct Array)); // freed by ArrayDestroy
    array->ls = LLCreate(cpy,fre); // allocate NULL as requsted.
    for(int i=0; i<arraysize;i++){
        LLAdd(array->ls, i, NULL);
    }
    return array;
}

void ArrayDestroy(Array array){
    LLDestroy(array->ls);
}

int ArraySize(Array array){
    return LLSize(array->ls);
}