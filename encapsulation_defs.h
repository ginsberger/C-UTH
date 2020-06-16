
#ifndef UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H
#define UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H
extern const char* _Z5Shelf7messagev;

typedef struct Box {
        double length;
        double width;
        double height;
}Box;



void _ZN3Box1CEP3Boxd(Box* box, double dim);
void _ZN3Box1CEP3Boxddd(Box* box,double l, double w, double h);
void _ZN3Box1CEP3BoxP3Box(Box* box,const Box*const other);/*copy constractor*/
Box* _ZN3Box18AssignmentOperatorEP3BoxP3Box(Box* box,const Box*const other);
void _ZN3Box1DEP3Box(Box* box);
Box* _ZNBox2mLEP3Boxd(Box* box, double mult);
void _ZNKBox5printEP3Box(const Box*const box);



typedef struct Shelf{
    Box boxes[3];
}Shelf;


void _ZN5Shelf1CEP5Shelf(Shelf* shelf);
void _ZN5Shelf1DEP5Shelf(Shelf* shelf);
void _ZN5Shelf6setBoxEP5ShelfiP3Box(Shelf* shelf, int index, const Box* dims);
void _ZN5Shelf1CEP5ShelfP5Shelf(Shelf* shelf,const Shelf*const other);
Shelf* _ZN5Shelf18AssignmentOperatorEP3BoxP3Box(Shelf* shelf,const Shelf*const other);
double _ZNK5Shelf9getVolumeEP5Shelf(const Shelf*const shelf);
void _ZNK5Shelf5printEP5Shelf(const Shelf*const shelf);


#endif /*UNDERTHEHOODCC_CPP2C_ENCAPSULATION_DEFS_H*/

