#include <stdlib.h>
#include <stdio.h>
#include "c2c_encapsulation_defs.h"
#define BoxGetWidth(box) box->width
#define BoxGetLength(box) box->length
#define BoxGetHeight(box) box->heigth
#define BoxGetVolume(box) box->height * box->length * box->width


struct Box{
double length;
double width;
double height;
};

void BoxDefaultConstractor(struct Box* box)
{
    box->length = 1;
    box->height = 1;
    box->width = 1;
//    print();
}

void BoxConstractorDouble(struct Box* box, double dim)
{
    box->length = dim;
    box->height = dim;
    box->width = dim;
//    print();
}

void BoxConstractorDoubleDoubleDouble(struct Box* box,double l, double w, double h)
{
    box->length = l;
    box->width = w;
    box->height = h;
//    print();
}

void BoxDestractor(struct Box* box)
{
    free(box);
}

//
//double BoxGetWidth(const struct Box* box)
//{
//    return box->width;
//}
//double BoxGetLength(const struct Box* box)
//{
//    return box->length;
//}
//double BoxGetHeight(const struct Box* box)
//{
//    return box->height;
//}
//double BoxGetVolume(const struct Box* box)
//{
//    return box->height * box->length * box->width;
//}

Box* BoxOperatorMultipleAssignment(struct Box* box, double mult)
{
    box->width *= mult;
    box->length *= mult;
    box->height *= mult;
    return box;
}

static void print(const struct Box* box)
{
    printf("Box: %f x %f x %f\n", box->length, box->width, box->height);
}


