
#include <stdio.h>
#include "inheritance_defs.h"


void  _Z11doMaterialsv()
{
    printf("\n--- Start doMaterials() ---\n\n");

    Materials mat;
    _ZN9Materials1CEP9Materials(&mat);

    printf("Size of Materials: %lu\n", sizeof(Materials));
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    typedef struct MatTest { Materials mat; Material_t mat_t; }MatTest;
    printf("Size of Materials + Material_t: %lu\n", sizeof(MatTest));

    Material_t mat1;
    Materials materials1;
    _ZN9Materials1CEP9Materials(&materials1);
    mat1.material = OTHER;
    printf("Material created, set to %s\n", names[mat1.material]);

    Material_t mat2;
    Materials materials2;
    _ZN9Materials1CEP9Materials(&materials2);
    mat2.material = METAL;
    printf("Material created, set to %s\n", names[mat2.material]);

    printf("\n--- End doMaterials() ---\n\n");
    _ZN10Material_ts1DEP10Material_t(&mat2);
    _ZN10Material_ts1DEP10Material_t(&mat1);


}

void _Z13doPhysicalBoxv()
{
    printf("\n--- Start doPhysicalBox() ---\n\n");

    PhysicalBox pb1;
    _ZN11PhysicalBox1CEP11PhysicalBoxdddN9Materials5TypesE(&pb1, 8, 6, 4, PLASTIC);
    PhysicalBox pb2;
    _ZN11PhysicalBox1CEN9Materials5TypesE(&pb2, WOOD);

    PhysicalBox pb3;
    _ZN11PhysicalBox1CEP11PhysicalBoxddd(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    PhysicalBox pb4;
    _ZN11PhysicalBox1CEP11PhysicalBoxPK11PhysicalBox(&pb4, &pb1);

    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb4);
    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb1);
    printf("pb4 %s pb1\n", (const Box*)&pb4 == (const Box*)&pb1 && pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _ZN11PhysicalBox18AssignmentOperatorEP11PhysicalBoxPK11PhysicalBox(&pb4, &pb3);
    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb4);
    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb3);
    printf("pb4 %s pb3\n", (const Box*)&pb4 == (const Box*)&pb3 && pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb4);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb3);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb2);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb1);
}
/*
void doWeightBox()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1(8, 6, 4, 25);
    WeightBox pw2(1, 2, 3);
    WeightBox pw3(10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox pw4 = pw1;
    pw4.printw();
    pw1.printw();
    printf("pw4 %s pw1\n", pw4 == pw1 ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    pw4 = pw3;
    pw4.printw();
    pw3.printw();
    printf("pw4 %s pw3\n", pw4 == pw3 ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");
}
*/




int main()
{
    printf("\n--- Start main() ---\n\n");

    _Z11doMaterialsv();

    _Z13doPhysicalBoxv();

/*    doWeightBox(); */

    printf("\n--- End main() ---\n\n");

}




