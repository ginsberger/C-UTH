/*
//#include <stdio.h>
//#include "encapsulation_defs.h"
//
//static Box _ZL8largeBox;
//
//int isFirstDeclerationBox99 = 0;
//int isFirstDeclerationBox88 = 0;
//
//void _Z8thisFuncv()
//{
//    static Box _ZGVZ8thisFuncvE5box99;
//    if(isFirstDeclerationBox99 == 2)
//    {
//        _ZN3Box1DEP3Box(&_ZGVZ8thisFuncvE5box99);
//        return;
//    }
//    printf("\n--- thisFunc() ---\n\n");
//    if(!isFirstDeclerationBox99)
//    {
//        _ZN3Box1CEP3Boxddd(&_ZGVZ8thisFuncvE5box99,99, 99, 99);
//        isFirstDeclerationBox99 = 1;
//    }
//    _ZNBox2mLEP3Boxd(&_ZGVZ8thisFuncvE5box99, 10);
//}
//
//
//void _Z8thatFuncv()
//{
//    static Box _ZGVZ8thatFuncvE5box88;
//    if(isFirstDeclerationBox88 == 2)
//    {
//        _ZN3Box1DEP3Box(&_ZGVZ8thatFuncvE5box88);
//        return;
//    }
//    printf("\n--- thisFunc() ---\n\n");
//    if(!isFirstDeclerationBox88)
//    {
//        _ZN3Box1CEP3Boxddd(&_ZGVZ8thatFuncvE5box88,88, 88, 88);
//        isFirstDeclerationBox88 = 1;
//    }
//    _ZNBox2mLEP3Boxd(&_ZGVZ8thatFuncvE5box88, 10);
//}
//
//
//void _Z7doBoxesv()
//{
//    Box b1;
//    Box b2;
//    Box b3;
//    Box ret;
//    Box b4;
//    printf("\n--- Start doBoxes() ---\n\n");
//
//    _ZN3Box1CEP3Boxd(&b1,3);
//    _ZN3Box1CEP3Boxddd(&b2,4, 5, 6);
//    printf("b1 volume: %f\n", b1.length * b1.height * b1.width);
//    printf("b2 volume: %f\n", b2.length * b2.height * b2.width);
//
//    _ZNBox2mLEP3Boxd(&b1,1.5);
//    _ZNBox2mLEP3Boxd(&b2,0.5);
//
//    printf("b1 volume: %f\n", b1.length * b1.height * b1.width);
//    printf("b2 volume: %f\n", b2.length * b2.height * b2.width);
//
//    _ZN3Box1CEP3BoxP3Box(&b3, &b2);
//
//    _ZN3Box1CEP3BoxP3Box(&ret, &b2);
//    _ZNBox2mLEP3Boxd(&ret,3);
//    _ZN3Box1CEP3BoxP3Box(&b4, &ret);
//    _ZN3Box1DEP3Box(&ret);
//
//    printf("b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");
//
//    _ZNBox2mLEP3Boxd(&b3,1.5);
//    _ZNBox2mLEP3Boxd(&b4,0.5);
//
//    printf("Now, b3 %s b4\n", b3.width == b4.width && b3.height == b4.height && b3.length == b4.length ? "equals" : "does not equal");
//
//
//    printf("\n--- End doBoxes() ---\n\n");
//    _ZN3Box1DEP3Box(&b4);
//    _ZN3Box1DEP3Box(&b3);
//    _ZN3Box1DEP3Box(&b2);
//    _ZN3Box1DEP3Box(&b1);
//}
//
//
//void _Z9doShelvesv()
//{
//    Box aBox;
//    Box temp1;
//    Box temp2;
//    printf("\n--- start doShelves() ---\n\n");
//
//    _ZN3Box1CEP3Boxd(&aBox,5);
//
//    Shelf aShelf;
//    _ZN5Shelf1CEP5Shelf(&aShelf);
//    _ZNK5Shelf5printEP5Shelf(&aShelf);
//    _ZN5Shelf6setBoxEP5ShelfiP3Box(&aShelf,1,&_ZL8largeBox);
//    _ZN5Shelf6setBoxEP5ShelfiP3Box(&aShelf,0,&aBox);
//
//    _ZNK5Shelf5printEP5Shelf(&aShelf);
//    _Z5Shelf7messagev = "This is the total volume on the shelf:";
//    _ZNK5Shelf5printEP5Shelf(&aShelf);
//    _Z5Shelf7messagev = "Shelf's volume:";
//    _ZNK5Shelf5printEP5Shelf(&aShelf);
//
//    _ZN3Box1CEP3Boxddd(&temp1,2,4,6);
//    _ZN5Shelf6setBoxEP5ShelfiP3Box(&aShelf,1,&temp1);
//    _ZN3Box1DEP3Box(&temp1);
//
//    _ZN3Box1CEP3Boxd(&temp2,2);
//    _ZN5Shelf6setBoxEP5ShelfiP3Box(&aShelf,2,&temp2);
//    _ZN3Box1DEP3Box(&temp2);
//
//    _ZNK5Shelf5printEP5Shelf(&aShelf);
//
//    printf("\n--- end doShelves() ---\n\n");
//    _ZN5Shelf1DEP5Shelf(&aShelf);
//    _ZN3Box1DEP3Box(&aBox);
//
//}
//
//
//int main()
//{
//    printf("\n--- Start main() ---\n\n");
//    _ZN3Box1CEP3Boxddd(&_ZL8largeBox,10,20,30);
//    _Z7doBoxesv();
//
//    _Z8thisFuncv();
//    _Z8thisFuncv();
//    _Z8thisFuncv();
//    _Z8thatFuncv();
//    _Z8thatFuncv();
//
//    _Z9doShelvesv();
//
//
//    printf("\n--- End main() ---\n\n");
//
//    if(isFirstDeclerationBox99)
//    {
//        isFirstDeclerationBox99 = 2;
//        _Z8thisFuncv();
//    }
//
//    if(isFirstDeclerationBox88)
//    {
//        isFirstDeclerationBox88 = 2;
//        _Z8thatFuncv();
//    }
//
//    _ZN3Box1DEP3Box(&_ZL8largeBox);
//
//    return 0;
//}
//
//
//
//
*/
