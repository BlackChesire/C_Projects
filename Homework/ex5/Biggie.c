#include "Biggie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/******************************************************************************************************/
// You can (bbut don't have to) use the following internal functions

// Allocate memory, fill with 0's (like calloc), make sure everything is ok
void* AllocateMemory(unsigned int size, const char* file, int line_num);
// Realloc, make sure all is well
void* ReallocateMemory(void* mem, unsigned int size, const char* file, int line_num);
// Return the larger of two numbers
unsigned int max(unsigned int x, unsigned int y);

/******************************************************************************************************/
void* AllocateMemory(unsigned int size, const char* file, int line_num)
{
    void*   ptr = calloc(size, sizeof(unsigned char));
    
    // If we failed the user will know exactly where the error happened
    if(ptr == NULL) {
        fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
        exit(-1);
    }
    
    return ptr;
}

/******************************************************************************************************/
void* ReallocateMemory(void* mem, unsigned int size, const char* file, int line_num)
{
    void*   ptr = realloc(mem, size);
    
    // If we failed the user will know exactly where the error happened
    if(ptr == NULL) {
        fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
        exit(-1);
    }
    
    return ptr;
}

/******************************************************************************************************/
unsigned int max(unsigned int x, unsigned int y)
{
    return (x > y)? x : y;
}
