#include <stdio.h>
#include "c2c_encapsulation_defs.h"

static Box _ZL8largeBox;
Box _ZZ8thisFuncvE5box99;
//_ZN3Box1CEP3Boxddd(_ZL8largeBox,10, 20, 30);

void _ZGVZ8thisFuncvE5box99()
{
    printf("\n--- thisFunc() ---\n\n");
    static Box box99(99, 99, 99);
    box99 *= 10;
}