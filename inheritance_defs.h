
#ifndef UNDERTHEHOODCC_INHERITANCE_DEFS_H
#define UNDERTHEHOODCC_INHERITANCE_DEFS_H

#include "encapsulation_defs.h"
/*//// Materials ////////////*/
extern const char* const names[];


typedef struct Materials
{
    enum Types
    {
        PLASTIC,
        METAL,
        WOOD,
        PAPER,
        OTHER
    };

}Materials;

typedef enum Types Types;
void _ZN9Materials1CEP9Materials(Materials* materials);
void _ZN9Materials1CEP9MaterialsPK9Materials(Materials* materials, const Materials*const materials1);
void _ZN9Materials18AssignmentOperatorEP9MaterialsPK9Materials(Materials* materials, const Materials*const materials1);
void _ZN9Materials1DEP9Materials(Materials* materials);




typedef struct Material_t
{
    Materials materials;
    Types material;
}Material_t;

void _ZN10Material_ts1CEP10Material_tPK10Material_t(Material_t* material_t, const Material_t*const material_t1);
void _ZN10Material_ts18AssignmentOperatorEP10Material_tPK10Material_t(Material_t* material_t, const Material_t*const material_t1);
void _ZN10Material_ts1DEP10Material_t(Material_t* material_t);




/*/// PhysicalBox ///////////*/
typedef struct PhysicalBox
{
    Box box;
    Material_t material;
}PhysicalBox;

void _ZN11PhysicalBox1CEP11PhysicalBoxddd(PhysicalBox* physicalBox, double l, double w, double h);
void _ZN11PhysicalBox1CEP11PhysicalBoxdddN9Materials5TypesE(PhysicalBox* physicalBox, double l, double w, double h, Types t);
void _ZN11PhysicalBox1CEN9Materials5TypesE(PhysicalBox* physicalBox, Types t);

void _ZN11PhysicalBox1CEP11PhysicalBoxPK11PhysicalBox(PhysicalBox* physicalBox, const PhysicalBox*const physicalBox1);
void _ZN11PhysicalBox18AssignmentOperatorEP11PhysicalBoxPK11PhysicalBox(PhysicalBox* physicalBox, const PhysicalBox*const physicalBox1);
void _ZN11PhysicalBox1DEP11PhysicalBox(PhysicalBox* physicalBox);

void _ZNK11PhysicalBox6printpEPK11PhysicalBox(const PhysicalBox*const physicalBox);





#endif /*UNDERTHEHOODCC_INHERITANCE_DEFS_H*/
