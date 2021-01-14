//Asaf Ben Shabat 312391774 && Avichai Aziz 316373497
#include "Biggie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Biggie
{
    unsigned char *number;
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
    Biggie biggie = (Biggie)AllocateMemory(sizeof(struct Biggie), __FILE__, __LINE__);
    biggie->number = (unsigned char *)AllocateMemory(size, __FILE__, __LINE__);
    biggie->size = size;
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

//Creates a Biggie from an integer
Biggie BiggieCreateFromUInt(unsigned int n)
{
    Biggie biggie = BiggieCreate(4);
    int i;
    for (i = 0; i < biggie->size; i++)
    {
        biggie->number[i] = (n >> (i * 8));
    }
    biggie->number[i] = (n >> (i * 8));
    return biggie;
}

// Assign the value of bn2 to bn1. Change bn1's size if required
void BiggieCopy(Biggie bn1, const Biggie bn2)
{
    if ((bn1->size) != (bn2->size))
    {
        BiggieResize(bn1, bn2->size);
    }

    int i;
    for (i = 0; i < bn1->size; i++)
    {
        bn1->number[i] = bn2->number[i];
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
unsigned int BiggieNumBits(const Biggie bn)
{
    int counter = 0;
    bool is_one = false;
    unsigned int returnN = 0;
    for (int i = (bn->size - 1); i > 0; i--)
    {
        for (int j = 7; j >= 0; j--)
        {
            if (((bn->number[i] << (7 - j)) >> 7) == 1)
            {
                is_one = true;
                if (j == 0 && (!is_one))
                    counter += 8;
            }
            if (is_one == true)
            {
                returnN = ((bn->size) * 8) - (7 - j);
                return returnN - counter;
            }
        }
    }
}

// Change Biggie's size
void BiggieResize(Biggie bn, unsigned int new_size)
{
    bn->number = ReallocateMemory(bn->number, new_size, __FILE__, __LINE__);
    bn->size = new_size;
}

// // Left-shift by any number (<< 1)
Biggie BiggieLeftShift1(const Biggie bn)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn);
    unsigned char carry = 0;
    int i;
    for (i = 0; i < new_bn->size; i++)
    {
        unsigned char new_carry = (new_bn->number[i] >> 7);
        new_bn->number[i] <<= 1;
        new_bn->number[i] |= carry;
        carry = new_carry;
    }
    return new_bn;
}

// Left-shift by any number (<< n)
Biggie BiggieLeftShift(const Biggie bn, int n)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn);
    int i;
    for (i = 0; i < n; i++)
    {
        Biggie temp = BiggieLeftShift1(new_bn);
        BiggieDestroy(new_bn);
        new_bn = temp;
    }
    return new_bn;
}

// // Right-shift by one bit
Biggie BiggieRightShift1(const Biggie bn)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn);
    unsigned char carry = 0;
    int i;
    for (i = (new_bn->size - 1); i >= 0; i--)
    {
        unsigned char new_carry = ((new_bn->number[i] << 7) >> 7);
        new_bn->number[i] >>= 1;
        new_bn->number[i] |= carry;
        carry = (new_carry << 7);
    }
    return new_bn;
}

// Right-shift by any number
Biggie BiggieRightShift(const Biggie bn, int n)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn);
    int i;
    for (i = 0; i < n; i++)
    {
        Biggie temp = BiggieRightShift1(new_bn);
        BiggieDestroy(new_bn);
        new_bn = temp;
    }
    return new_bn;
}

// // Bitwise xor. Will change bn1's size if it is smaller than bn2's
Biggie BiggieXor(const Biggie bn1, const Biggie bn2)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn1);
    if (new_bn->size < bn2->size)
    {
        BiggieResize(new_bn, bn2->size);
    }
    int i = 0;
    for (i = 0; i < new_bn->size; i++)
    {
        new_bn->number[i] ^= bn2->number[i];
    }
    return new_bn;
}

// // Bitwise and. Will change bn1's size if it is smaller than bn2's
Biggie BiggieAnd(const Biggie bn1, const Biggie bn2)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn1);
    if (new_bn->size < bn2->size)
    {
        BiggieResize(new_bn, bn2->size);
    }
    int i = 0;
    for (i = 0; i < new_bn->size; i++)
    {
        new_bn->number[i] &= bn2->number[i];
    }
    return new_bn;
}

// Bitwise or. Will change bn1's size if it is smaller than bn2's
Biggie BiggieOr(const Biggie bn1, const Biggie bn2)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn1);
    if (new_bn->size < bn2->size)
    {
        BiggieResize(new_bn, bn2->size);
    }
    int i = 0;
    for (i = 0; i < new_bn->size; i++)
    {
        new_bn->number[i] |= bn2->number[i];
    }
    return new_bn;
}

// Bitwise not
Biggie BiggieNot(const Biggie bn)
{
    Biggie new_bn = BiggieCreateFromBiggie(bn);
    int i;
    for (i = 0; i < bn->size; i++)
    {
        new_bn->number[i] = ~(new_bn->number[i]);
    }
    return new_bn;
}

// Convert a Biggie to an unsigned int. Ignore bytes that are larger than sizeof(int).
unsigned int BiggieConvert(const Biggie bn)
{
    unsigned int number = 0;
    number += bn->number[0];
    if (bn->size < 2)
    {
        return number;
    }
    number += bn->number[1] << 8;
    if (bn->size < 3)
    {
        return number;
    }
    number += bn->number[2] << 16;
    if (bn->size < 4)
    {
        return number;
    }
    number += bn->number[3] << 24;
    return number;
}

// Compaerators:
// Greater than (>)
bool BiggieGT(const Biggie bn1, const Biggie bn2)
{
    if (BiggieNumBits(bn1) > BiggieNumBits(bn2))
    {
        return true;
    }
    else if (BiggieNumBits(bn1) < BiggieNumBits(bn2))
    {
        return false;
    }
    int j;
    for (j = bn1->size - 1; j >= 0; j--)
    {
        if (bn1->number[j] > bn2->number[j])
        {
            return true;
        }
        else if (bn1->number[j] < bn2->number[j])
        {
            return false;
        }
    }

    return false;
}

// Less than (<)
bool BiggieLT(const Biggie bn1, const Biggie bn2)
{
    if (BiggieNumBits(bn1) == BiggieNumBits(bn2))
    {
        int j;
        for (j = bn1->size - 1; j >= 0; j--)
        {
            if (bn1->number[j] > bn2->number[j])
            {
                return false;
            }
            else if (bn1->number[j] < bn2->number[j])
            {
                return true;
            }
        }
    }
    return (!(BiggieGT(bn1, bn2)));
}

// // Equals (==)
bool BiggieEQ(const Biggie bn1, const Biggie bn2)
{
    if (BiggieLT(bn1, bn2) || BiggieGT(bn1, bn2))
    {
        return false;
    }
    return true;
}

//Add bn1 and bn2, return the result
Biggie BiggieAdd(const Biggie bn1, const Biggie bn2)
{
}

// Multiply bn1 by bn2, return the result's address
//Biggie BiggieMultiply(const Biggie bn1, const Biggie bn2)
