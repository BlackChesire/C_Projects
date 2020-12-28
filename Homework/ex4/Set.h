#ifndef SET_H
#define SET_H
#include <stdbool.h>

typedef void* Element;
typedef struct set_rec* Set;

Set            SetCreate(Element (*cpy)(Element),
                         void (*fre)(Element),
                         bool (*cmp)(Element, Element));
void            SetDestroy(Set);
void            SetAdd(Set, Element);
void           SetRemove(Set, Element);
bool    SetIsIn(Set, Element);
bool    SetIsEmpty(Set);
const Element    SetNext(Set);
const Element    SetFirst(Set);
#endif
