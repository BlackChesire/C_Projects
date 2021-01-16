#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Biggie.h"

/******************************************************************************************************
 * This program will test the Biggie module using random numbers. You can run the program multiple
 * times to try different numbers. If you want to repeat a test then replace this line:
 * time_t seed = time(NULL);
 * with
 * time_t seed = <your-seed>;
 * where <your-seed> is the seed you want to use. For example, to use 123456, do
 * time_t seed = 123456;
 * The seed is always reported in the first line of the output.
 ******************************************************************************************************/
int main()
{
    time_t seed = time(NULL);
    srand((unsigned int)seed);

    unsigned int x1 = rand();
    unsigned int x2 = rand();
    unsigned int x = 0;
    Biggie bn1 = BiggieCreateFromUInt(x1);
    Biggie bn2 = BiggieCreateFromUInt(x2);
    Biggie bn = NULL;

    // BiggieCreate(int size), BiggieConvert
    bn = BiggieCreate(4);
    printf("Seed:                \t%ld\n", seed);
    printf("BiggieCreate, Convert\t%s\t(Biggie=%u, Expected=0)\n", ((BiggieConvert(bn) == 0) ? "ok" : "fail"), BiggieConvert(bn));
    BiggieDestroy(bn);

    // BiggieCreateFromUInt
    printf("BiggieCreateFromUInt/1\t%s\t(Biggie=%u, Expected=%u)\n", ((x1 == BiggieConvert(bn1)) ? "ok" : "fail"), BiggieConvert(bn1), x1);
    printf("BiggieCreateFromUInt/2\t%s\t(Biggie=%u, Expected=%u)\n", ((x2 == BiggieConvert(bn2)) ? "ok" : "fail"), BiggieConvert(bn2), x2);

    // BiggieCreateFromBiggie
    bn = BiggieCreateFromBiggie(bn1);
    printf("BiggieCreateFromBiggie\t%s\t(Biggie=%u, Expected=%u)\n", ((BiggieConvert(bn) == BiggieConvert(bn1)) ? "ok" : "fail"), BiggieConvert(bn), BiggieConvert(bn1));
    BiggieDestroy(bn);

    // BiggieResize
    x = rand();
    bn = BiggieCreateFromUInt(x);
    BiggieResize(bn, 1);
    printf("BiggieResize        \t%s\t(Biggie=%u, expected=%u)\n", ((BiggieConvert(bn) == (unsigned char)x) ? "ok" : "fail"), BiggieConvert(bn), (unsigned char)x);
    BiggieDestroy(bn);

    // BiggieLeftShift
    bn = BiggieLeftShift(bn2, 5);
    printf("BiggieLeftShift     \t%s\t(Biggie=%u, Expected=%u)\n", (((x2 << 5) == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x2 << 5);
    BiggieDestroy(bn);

    // BiggieRightShift
    bn = BiggieRightShift(bn1, 7);
    x = BiggieConvert(bn1);
    printf("BiggieRightShift    \t%s\t(Biggie=%u, Expected=%u)\n", (((x1 >> 7) == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x1 >> 7);
    BiggieDestroy(bn);

    // // BiggieXor
    x = BiggieConvert(bn1) ^ BiggieConvert(bn2);
    bn = BiggieXor(bn1, bn2);
    printf("BiggieXor           \t%s\t(Biggie=%u, Expected=%u)\n", ((x == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x);
    BiggieDestroy(bn);

    // BiggieAnd
    x = BiggieConvert(bn1) & BiggieConvert(bn2);
    bn = BiggieAnd(bn1, bn2);
    printf("BiggieAnd           \t%s\t(Biggie=%u, Expected=%u)\n", ((x == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x);
    BiggieDestroy(bn);

    // BiggieOr
    x = BiggieConvert(bn1) | BiggieConvert(bn2);
    bn = BiggieOr(bn1, bn2);
    printf("BiggieOr            \t%s\t(Biggie=%u, Expected=%u)\n", ((x == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x);
    BiggieDestroy(bn);

    // BiggieNot
    x = ~BiggieConvert(bn1);
    bn = BiggieNot(bn1);
    printf("BiggieNot           \t%s\t(Biggie=%u, Expected=%u)\n", ((x == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), x);
    BiggieDestroy(bn);

    // BiggieCopy
    bn = BiggieCreate(3);
    BiggieCopy(bn, bn1);
    printf("BiggieCopy          \t%s\t(Biggie=%u, Expected=%u)\n", ((BiggieConvert(bn1) == BiggieConvert(bn)) ? "ok" : "fail"), BiggieConvert(bn), BiggieConvert(bn1));
    BiggieDestroy(bn);

    // BiggieNumBits
    for (x = 0; BiggieConvert(bn1) >> x; x++)
        ;
    printf("BiggieNumBits       \t%s\t(Biggie=%u, Expected=%u)\n", ((BiggieNumBits(bn1) == x) ? "ok" : "fail"), BiggieNumBits(bn1), x);

    // // BiggieGT
    printf("BiggieGT            \t%s\t(Biggie=%s, Expected=%s)\n", ((BiggieGT(bn1, bn2) == (x1 > x2)) ? "ok" : "fail"), (BiggieGT(bn1, bn2) ? "True" : "False"), ((x1 > x2) ? "True" : "False"));

    // // BiggieLT
    printf("BiggieLT            \t%s\t(Biggie=%s, Expected=%s)\n", ((BiggieLT(bn1, bn2) == (x1 < x2)) ? "ok" : "fail"), (BiggieLT(bn1, bn2) ? "True" : "False"), ((x1 < x2) ? "True" : "False"));

    // // BiggieEQ
    printf("BiggieEQ            \t%s\t(Biggie=%s, Expected=%s)\n", ((BiggieEQ(bn1, bn2) == (x1 == x2)) ? "ok" : "fail"), (BiggieEQ(bn1, bn2) ? "True" : "False"), ((x1 == x2) ? "True" : "False"));

    BiggieDestroy(bn1);
    BiggieDestroy(bn2);

    x1 = rand() % 10000;
    x2 = rand() % 10000;
    bn1 = BiggieCreateFromUInt(x1);
    bn2 = BiggieCreateFromUInt(x2);

    // BiggieAdd
    bn = BiggieAdd(bn1, bn2);
    printf("BiggieAdd           \t%s\t(Biggie=%u, Expected=%u)\n", ((BiggieConvert(bn) == (x1 + x2)) ? "ok" : "fail"), BiggieConvert(bn), (x1 + x2));
    BiggieDestroy(bn);

    // BiggieMultiply
    bn = BiggieMultiply(bn1, bn2);
    printf("BiggieMultiply      \t%s\t(Biggie=%u, Expected=%u)\n", ((BiggieConvert(bn) == x1 * x2) ? "ok" : "fail"), BiggieConvert(bn), x1 * x2);
    BiggieDestroy(bn);

    BiggieDestroy(bn1);
    BiggieDestroy(bn2);

    // // BiggieCreateFromString
    // char str[128];
    // sprintf(str, "%u", rand());
    // bn = BiggieCreateFromString(str);
    //  printf("BiggieCreateFromString\t%s\t(Biggie=%u, Expected=%s)\n", ((BiggieConvert(bn)==atoi(str))? "ok" : "fail"), BiggieConvert(bn), str);
    //  BiggieDestroy(bn);

    return 0;
}
