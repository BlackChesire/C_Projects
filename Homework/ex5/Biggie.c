//Asaf Ben Shabat 312391774 && Avichai Aziz 316373497
#include "Biggie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Biggie {
    char* number;
    unsigned int size;
};

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

// Creates a Biggie initialized to 0
Biggie    BiggieCreate(int size) {
    if(size < 0) {
        fprintf(stderr, "Error, size must be positive number, file: %s , line: %d", __FILE__, __LINE__)
    }
    Biggie biggie = AllocateMemory(sizeof(struct Biggie), __FILE__ , __LINE__);
    biggie -> size = size;
    biggie -> number = (char*)AllocateMemory(size, __FILE__ , __LINE__);
    return biggie;
}

// Creates a Biggie from a string (e.g. "12345678999")
Biggie    BiggieCreateFromString(const char* num);




// Creates a new copy of bn
Biggie    BiggieCreateFromBiggie(const Biggie bn) {
    Biggie new_biggie = BiggieCreate(bn->size);
    BiggieCopy(new_biggie, bn);
    return new_biggie;
}

// Creates a Biggie from an integer
Biggie    BiggieCreateFromUInt(unsigned int n);

// Assign the value of bn2 to bn1. Change bn1's size if required
void    BiggieCopy(Biggie bn1, const Biggie bn2) {
    if(bn1->size == bn2->size) {
        bn1->number = bn2->number; ///???
    }
    else if((bn1->size) < (bn2->size)) {
        bn1 = BiggieResize(bn1 ,bn2->size);
        bn1->number = bn2->number; ///???
    }
    else if((bn1->size) < (bn2->size)) { //?????

    }

}

// Destructor for Biggies
void    BiggieDestroy(Biggie bn) {
    free(bn->number);
    free(bn->size);
    free(bn);
}

// Return the number of bits in a Biggie
// Example: 000000001011 => numbits == 4
unsigned int BiggieNumBits(Biggie bn);

// Change Biggie's size - only if it does not hurt
Biggie BiggieResize(Biggie bn, int new_size) {
    ReallocateMemory(void* mem, unsigned int size, const char* file, int line_num)
}

// Left-shift by any number (<< 1)
Biggie BiggieLeftShift1(Biggie bn);

// Left-shift by any number (<< n)
Biggie BiggieLeftShift(Biggie bn, int n);

// Right-shift by one bit
Biggie BiggieRightShift1(Biggie bn);

// Right-shift by any number
Biggie BiggieRightShift(Biggie bn, int n);

// Bitwise xor. Will change bn1's size if it is smaller than bn2's
Biggie BiggieXor(const Biggie bn1, const Biggie bn2);

// Bitwise and. Will change bn1's size if it is smaller than bn2's
Biggie BiggieAnd(const Biggie bn1, const Biggie bn2);

// Bitwise or. Will change bn1's size if it is smaller than bn2's
Biggie BiggieOr(const Biggie bn1, const Biggie bn2);

// Bitwise not
Biggie BiggieNot(const Biggie bn);

// Convert a Biggie to an unsigned int. Ignore bytes that are larger than sizeof(int).
unsigned int BiggieConvert(const Biggie bn);

// Compaerators:
// Greater than (>)
bool    BiggieGT(const Biggie bn1, const Biggie bn2);

// Less than (<)
bool    BiggieLT(const Biggie bn1, const Biggie bn2);

// Equals (==)
bool    BiggieEQ(const Biggie bn1, const Biggie bn2);

// Add bn1 and bn2, return the result
Biggie    BiggieAdd(Biggie bn1, const Biggie bn2);

// Multiply bn1 by bn2, return the result's address
Biggie    BiggieMultiply(Biggie bn1, const Biggie bn2);

#endif
