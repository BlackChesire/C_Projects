#include "Array.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct Array{
	LinkedList ls;
};

Array ArrayCreate(int arraysize,Element (*cpy)(Element), void (*fre)(Element)){
    Array array = (Array)malloc(sizeof(struct Array));
    array->ls = LLCreate(cpy,fre);
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