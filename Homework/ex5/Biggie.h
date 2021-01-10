#ifndef BIGGIE_H
#define BIGGIE_H

#include <stdbool.h>

typedef struct Biggie *Biggie;

// Creates a Biggie initialized to 0
Biggie BiggieCreate(int size);

// Creates a Biggie from a string (e.g. "12345678999")
Biggie BiggieCreateFromString(const char *num);

// Creates a new copy of bn
Biggie BiggieCreateFromBiggie(const Biggie bn);

// Creates a Biggie from an integer
Biggie BiggieCreateFromUInt(unsigned int n);

// Assign the value of bn2 to bn1. Change bn1's size if required
void BiggieCopy(Biggie bn1, const Biggie bn2);

// Destructor for Biggies
void BiggieDestroy(Biggie bn);

// Return the number of bits in a Biggie
// Example: 000000001011 => numbits == 4
unsigned int BiggieNumBits(const Biggie bn);

// Change Biggie's size
void BiggieResize(Biggie bn, unsigned int new_size);

// Left-shift by any number (<< 1)
Biggie BiggieLeftShift1(const Biggie bn);

// Left-shift by any number (<< n)
Biggie BiggieLeftShift(const Biggie bn, int n);

// Right-shift by one bit
Biggie BiggieRightShift1(const Biggie bn);

// Right-shift by any number
Biggie BiggieRightShift(const Biggie bn, int n);

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
bool BiggieGT(const Biggie bn1, const Biggie bn2);

// Less than (<)
bool BiggieLT(const Biggie bn1, const Biggie bn2);

// Equals (==)
bool BiggieEQ(const Biggie bn1, const Biggie bn2);

// Add bn1 and bn2, return the result
Biggie BiggieAdd(const Biggie bn1, const Biggie bn2);

// Multiply bn1 by bn2, return the result's address
Biggie BiggieMultiply(const Biggie bn1, const Biggie bn2);

#endif
