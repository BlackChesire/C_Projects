//Asaf Ben Shabat 312391774 && Avichai Aziz 316373497
#include "Biggie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> //????

struct Biggie
{
    char *number;
    unsigned int size;
};

/******************************************************************************************************/
// You can (bbut don't have to) use the following internal functions

// Allocate memory, fill with 0's (like calloc), make sure everything is ok
void *AllocateMemory(unsigned int size, const char *file, int line_num);
// Realloc, make sure all is well
void *ReallocateMemory(void *mem, unsigned int size, const char *file, int line_num);
// Return the larger of two numbers
unsigned int max(unsigned int x, unsigned int y);

/******************************************************************************************************/
void *AllocateMemory(unsigned int size, const char *file, int line_num)
{
    void *ptr = calloc(size, sizeof(unsigned char));

    // If we failed the user will know exactly where the error happened
    if (ptr == NULL)
    {
        fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
        exit(-1);
    }

    return ptr;
}

/******************************************************************************************************/
void *ReallocateMemory(void *mem, unsigned int size, const char *file, int line_num)
{
    void *ptr = realloc(mem, size);

    // If we failed the user will know exactly where the error happened
    if (ptr == NULL)
    {
        fprintf(stderr, "Fatal error in %s (%d): failed to allocate memory of size %u\n\n", file, line_num, size);
        exit(-1);
    }

    return ptr;
}

/******************************************************************************************************/
unsigned int max(unsigned int x, unsigned int y)
{
    return (x > y) ? x : y;
}

// Creates a Biggie initialized to 0
Biggie BiggieCreate(int size)
{
    if (size < 0)
    {
        fprintf(stderr, "Error, size must be positive number, file: %s , line: %d", __FILE__, __LINE__);
    }
    Biggie biggie = AllocateMemory(sizeof(struct Biggie), __FILE__, __LINE__);
    biggie->size = size;
    biggie->number = (char *)AllocateMemory(size, __FILE__, __LINE__);
    biggie->number = 0;
    return biggie;
}

// Creates a Biggie from a string (e.g. "12345678999")
Biggie BiggieCreateFromString(const char *num)
{
    Biggie bn = BiggieCreate(atoi(num)); //should be working ! need to check
    return bn;
}
// Creates a new copy of bn
Biggie BiggieCreateFromBiggie(const Biggie bn)
{
    Biggie new_biggie = BiggieCreate(bn->size);
    BiggieCopy(new_biggie, bn);
    return new_biggie;
}

// Creates a Biggie from an integer
//Biggie BiggieCreateFromUInt(unsigned int n);

// Assign the value of bn2 to bn1. Change bn1's size if required
void BiggieCopy(Biggie bn1, const Biggie bn2)
{
    if (bn1->size == bn2->size)
    {
        int i;
        for (i = 0; i < bn1->size; i++)
        {
            bn1->number[i] = bn2->number[i];
        }
    }
    else if ((bn1->size) < (bn2->size))
    {
        BiggieResize(bn1, bn2->size);
        int j;
        for (j = 0; j < bn1->size; j++)
        {
            bn1->number[j] = bn2->number[j];
        }
    }
    else if ((bn1->size) > (bn2->size))
    {
        printf("hi\n");
    }
}

// Destructor for Biggies
void BiggieDestroy(Biggie bn)
{
    free(bn->number);
    free(bn);
}

// Return the number of bits in a Biggie
// Example: 000000001011 => numbits == 4
//unsigned int BiggieNumBits(const Biggie bn);

// Change Biggie's size - only if it does not hurt
void BiggieResize(Biggie bn, unsigned int new_size)
{
    if (new_size < 0)
    {
        fprintf(stderr, "Error, size must be positive number, file: %s , line: %d", __FILE__, __LINE__);
    }
    bn = ReallocateMemory(bn, new_size, __FILE__, __LINE__);
}

// // Left-shift by any number (<< 1)
// Biggie BiggieLeftShift1(const Biggie bn);

// // Left-shift by any number (<< n)
// Biggie BiggieLeftShift(const Biggie bn, int n);

// // Right-shift by one bit
// Biggie BiggieRightShift1(const Biggie bn);

// // Right-shift by any number
// Biggie BiggieRightShift(const Biggie bn, int n);

// // Bitwise xor. Will change bn1's size if it is smaller than bn2's
// Biggie BiggieXor(const Biggie bn1, const Biggie bn2);

// // Bitwise and. Will change bn1's size if it is smaller than bn2's
// Biggie BiggieAnd(const Biggie bn1, const Biggie bn2);

// Bitwise or. Will change bn1's size if it is smaller than bn2's
// Biggie BiggieOr(const Biggie bn1, const Biggie bn2)
// {
//     Biggie new_bn = BiggieCopy(new_bn, bn);
//     int i = 0;
//     for (i = 0; i < new_bn->size; i++)
//     {
//         *(new_bn->number + i) |= (*(bn->number + i));
//     }
//     return new_bn;
// }
// Bitwise not
Biggie BiggieNot(const Biggie bn)
{
    Biggie new_bn;
    BiggieCopy(new_bn, bn);
    int i = 0;
    for (i = 0; i < new_bn->size; i++)
    {
        new_bn->number[i] = ~(bn->number[i]);
    }
    return new_bn;
}

// Convert a Biggie to an unsigned int. Ignore bytes that are larger than sizeof(int).
unsigned int BiggieConvert(const Biggie bn)
{
    unsigned int sum = 0;
    int j = 0;
    for (j = 0; j < (bn->size * 8); j++)
    {
        if (j < (8 * sizeof(int)))
        {
            sum += (bn->number[j] * pow(2, j));
        }
    }
    return sum;
}

// Compaerators:
// Greater than (>)
bool BiggieGT(const Biggie bn1, const Biggie bn2) //????
{
    // unsigned int biggie1 = BiggieConvert(bn1);
    // unsigned int biggie2 = BiggieConvert(bn2);
    // return (biggie1 > biggie2);

    int i = bn1->size;
    for (i; i >= 0; i--)
    {
        if (bn1->number[i] > bn2->number[i])
        {
            return true;
        }
    }
    return false;
    // return (max(bn1->number, bn2->number) == (bn1->number));
}

// Less than (<)
bool BiggieLT(const Biggie bn1, const Biggie bn2) //??????
{
    unsigned int biggie1 = BiggieConvert(bn1);
    unsigned int biggie2 = BiggieConvert(bn2);
    return (biggie1 < biggie2);

    // int i = bn1->size;
    // for (i; i >= 0; i--)
    // {
    //     if (bn1->number[i] > bn2->number[i])
    //     {
    //         return true;
    //     }
    // }
    // return false;

    // if (BiggieEQ(bn1, bn2))
    // {
    //     return false;
    // }
    // return (!(BiggieGT(bn1, bn2)));

    // int i = bn1->size;
    // for(i; i>=0; i--) {
    //     if(bn1->number[i] > bn2->number[i]) {
    //         return (!(BiggieGT(bn1,bn2)));
    //     }
    // }
    // return (!(BiggieGT(bn1,bn2)));
}

// Equals (==)
bool BiggieEQ(const Biggie bn1, const Biggie bn2)
{
    if (BiggieLT(bn1, bn2) || BiggieGT(bn1, bn2))
    {
        return false;
    }
    return true;

    // int i = bn1->size;
    // for(i ; i>=0; i--) {
    //     if(bn1->number[i] < bn2->number[i] || bn1->number[i] > bn2->number[i]) {
    //         return fasle;
    //     }
    // }
    // return true;
}

// Add bn1 and bn2, return the result
//Biggie BiggieAdd(const Biggie bn1, const Biggie bn2)

// Multiply bn1 by bn2, return the result's address
//Biggie BiggieMultiply(const Biggie bn1, const Biggie bn2);
