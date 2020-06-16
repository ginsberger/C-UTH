#include <stdlib.h>
#include <stdio.h>
#include "encapsulation_defs.h"
const char* _Z5Shelf7messagev = "The total volume held on the shelf is";




void _ZN3Box1CEP3Boxd(Box* box, double dim)
{
    box->length = dim;
    box->height = dim;
    box->width = dim;
    _ZNKBox5printEP3Box(box);
}

void _ZN3Box1CEP3Boxddd(Box* box,double l, double w, double h)
{
    box->length = l;
    box->width = w;
    box->height = h;
    _ZNKBox5printEP3Box(box);
}

void _ZN3Box1initEP3BoxP3Box(Box* box,const Box*const other)
{
    box->length = other->length;
    box->width = other->width;
    box->height = other->height;
}

void _ZN3Box1CEP3BoxP3Box(Box* box,const Box*const other)
{
    _ZN3Box1initEP3BoxP3Box(box, other);
}

Box* _ZN3Box18AssignmentOperatorEP3BoxP3Box(Box* box,const Box*const other)
{
    _ZN3Box1initEP3BoxP3Box(box, other);
    return box;
}


void _ZN3Box1DEP3Box(Box* box)
{
    printf("Box destructor, %f x %f x %f\n", box->width, box->height, box->length);
}


Box* _ZNBox2mLEP3Boxd(Box* box, double mult)
{
    box->width *= mult;
    box->length *= mult;
    box->height *= mult;
    return box;
}

void _ZNKBox5printEP3Box(const Box*const box)
{
    printf("Box: %f x %f x %f\n", box->length, box->width, box->height);
}




void _ZN5Shelf1CEP5Shelf(Shelf* shelf)
{
    size_t i = 0;
    for(;i<3;i++)
    {
        _ZN3Box1CEP3Boxd(&shelf->boxes[i],1);
    }
}

void _ZN5Shelf1DEP5Shelf(Shelf* shelf)
{
    int i;
    for(i=2;i>=0;i--)
    {
        _ZN3Box1DEP3Box(&shelf->boxes[i]);
    }
}
void _ZN5Shelf6setBoxEP5ShelfiP3Box(Shelf* shelf, int index, const Box* dims)
{
    _ZN3Box18AssignmentOperatorEP3BoxP3Box(&shelf->boxes[index],dims);
}

void _ZN5Shelf4initEP5ShelfP5Shelf(Shelf* shelf,const Shelf*const other)
{
    size_t i = 0;
    for(;i<3;i++)
    {
        _ZN3Box1CEP3BoxP3Box(&shelf->boxes[i],&other->boxes[i]);
    }
}

void _ZN5Shelf1CEP5ShelfP5Shelf(Shelf* shelf,const Shelf*const other)
{
    _ZN5Shelf4initEP5ShelfP5Shelf(shelf, other);
}

Shelf* _ZN5Shelf18AssignmentOperatorEP3BoxP3Box(Shelf* shelf,const Shelf*const other)
{
    _ZN5Shelf4initEP5ShelfP5Shelf(shelf, other);
    return shelf;
}

double _ZNK5Shelf9getVolumeEP5Shelf(const Shelf*const shelf)
{
    double vol = 0;
    size_t i;
    for (i = 0; i < 3; ++i)
        vol += shelf->boxes[i].width * shelf->boxes[i].length * shelf->boxes[i].height;
    return vol;
}

void _ZNK5Shelf5printEP5Shelf(const Shelf*const shelf)
{
    printf("%s %f\n", _Z5Shelf7messagev, _ZNK5Shelf9getVolumeEP5Shelf(shelf));
}
