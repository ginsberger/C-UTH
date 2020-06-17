#include "inheritance_defs.h"
#include <stdio.h>

const char* const names[] = { "Plastic", "Metal", "Wood", "Paper", "Other" };

/* Materials Defs */
void _ZN9Materials1CEP9Materials(Materials* materials){}
void _ZN9Materials1CEP9MaterialsPK9Materials(Materials* materials, const Materials*const materials1){}
void _ZN9Materials18AssignmentOperatorEP9MaterialsPK9Materials(Materials* materials, const Materials*const materials1){}
void _ZN9Materials1DEP9Materials(Materials* materials){}

/* Material_t Defs */
void _ZN10Material_ts1CEP10Material_t(Material_t* material_t){}

void _ZN10Material_ts18AssignmentOperatorEP10Material_tPK10Material_t(Material_t* material_t, const Material_t*const material_t1)
{
    _ZN9Materials18AssignmentOperatorEP9MaterialsPK9Materials(&material_t->materials, &material_t1->materials);
}

void _ZN10Material_ts1DEP10Material_t(Material_t* material_t){
    _ZN9Materials1DEP9Materials(&material_t->materials);
}

/* PhysicalBox Defs */
void _ZN11PhysicalBox1CEP11PhysicalBoxddd(PhysicalBox* physicalBox, double l, double w, double h)
{
    _ZN3Box1CEP3Boxddd((Box*)physicalBox,l, w, h);

    Material_t mat2;
    _ZN9Materials1CEP9Materials(&mat2.materials);
    mat2.material = OTHER;
    printf("Material created, set to %s\n", names[mat2.material]);

    _ZNK11PhysicalBox6printpEPK11PhysicalBox(physicalBox);
}

void _ZN11PhysicalBox1CEP11PhysicalBoxdddN9Materials5TypesE(PhysicalBox* physicalBox, double l, double w, double h, Types t)
{
    _ZN3Box1CEP3Boxddd((Box*)physicalBox,l, w, h);

    Material_t mat2;
    _ZN9Materials1CEP9Materials(&mat2.materials);
    mat2.material = t;

    printf("Material created, set to %s\n", names[mat2.material]);

    _ZNK11PhysicalBox6printpEPK11PhysicalBox(physicalBox);/*throwing here*/
}

void _ZN11PhysicalBox1CEN9Materials5TypesE(PhysicalBox* physicalBox, Types t)
{
    _ZN3Box1CEP3Boxd((Box*)physicalBox, 1);

    Material_t mat2;
    Materials materials2;
    _ZN9Materials1CEP9Materials(&materials2);
    mat2.material = t;

    printf("Material created, set to %s\n", names[mat2.material]);

    _ZNK11PhysicalBox6printpEPK11PhysicalBox(physicalBox);
}

void _ZNK11PhysicalBox6printpEPK11PhysicalBox(const PhysicalBox*const physicalBox)
{
    printf("PhysicalBox, made of %s; ", names[physicalBox->material.material]);
    _ZNKBox5printEP3Box((Box*)physicalBox);
}

void _ZN11PhysicalBox1DEP11PhysicalBox(PhysicalBox* physicalBox)
{
    printf("PhysicalBox dtor, %f x %f x %f, %s; ", physicalBox->box.length, physicalBox->box.height, physicalBox->box.width, names[physicalBox->material.material]);
    _ZN10Material_ts1DEP10Material_t(&physicalBox->material);
    _ZN3Box1DEP3Box((Box*)physicalBox);
}

void _ZN11PhysicalBox1CEP11PhysicalBoxPK11PhysicalBox(PhysicalBox* physicalBox, const PhysicalBox*const physicalBox1)
{
    _ZN3Box1CEP3Boxd((Box*)physicalBox, 1);
    physicalBox->material = physicalBox1->material;
}

void _ZN11PhysicalBox18AssignmentOperatorEP11PhysicalBoxPK11PhysicalBox(PhysicalBox* physicalBox, const PhysicalBox*const physicalBox1)
{
    _ZN3Box18AssignmentOperatorEP3BoxP3Box((Box*)physicalBox, (Box*)physicalBox1);
    physicalBox->material = physicalBox1->material;
}







