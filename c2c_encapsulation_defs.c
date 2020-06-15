#include <stdlib.h>
#include <stdio.h>
#include "c2c_encapsulation_defs.h"
const char* _Z5Shelf7messagev = "The total volume held on the shelf is";



void _ZN3Box1CEP3Box(Box* box)
{
    box->length = 1;
    box->height = 1;
    box->width = 1;
    _ZNKBox5printEP3Box(box);
}

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

void _ZN3Box1DEP3Box(Box* box)
{
    free(box);
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




void _ZN5Shelf1CEP5Shelf(Shelf* shelf){}
void _ZN5Shelf1DEP5Shelf(Shelf* shelf){}
void _ZN5Shelf6setBoxEP5ShelfiP3Box(Shelf* shelf, int index, const Box* dims)
{
    shelf->boxes[index] = *dims;
}

double _ZNK5Shelf9getVolumeEP5Shelf(const Shelf*const shelf)
{
    double vol = 0;
    for (size_t i = 0; i < 3; ++i)
        vol += shelf->boxes[i].width * shelf->boxes[i].length * shelf->boxes[i].height;
    return vol;
}

void _ZNK5Shelf5printEP5Shelf(const Shelf*const shelf)
{
    printf("%s %f\n", _Z5Shelf7messagev, _ZNK5Shelf9getVolumeEP5Shelf(shelf));
}
