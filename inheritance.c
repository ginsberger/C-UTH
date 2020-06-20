
#include <stdio.h>
#include "inheritance_defs.h"


void  _Z11doMaterialsv()
{
    printf("\n--- Start doMaterials() ---\n\n");

    Materials mat;
    _ZN9Materials1CEP9Materials(&mat);

    printf("Size of Materials: %lu\n", sizeof(Materials)+1);
    printf("Size of mat: %lu\n", sizeof(mat));
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    typedef struct MatTest { Materials mat; Material_t mat_t; char placeHolder;}MatTest;/*do it global with 4 default functions*/
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
    printf("pb4 %s pb1\n", pb4.box.width == pb1.box.width && pb4.box.height == pb1.box.height && pb4.box.length == pb1.box.length && pb4.material.material == pb1.material.material ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    _ZN11PhysicalBox18AssignmentOperatorEP11PhysicalBoxPK11PhysicalBox(&pb4, &pb3);
    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb4);
    _ZNK11PhysicalBox6printpEPK11PhysicalBox(&pb3);
    printf("pb4 %s pb3\n", pb4.box.width == pb3.box.width && pb4.box.height == pb3.box.height && pb4.box.length == pb3.box.length && pb4.material.material == pb3.material.material ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb4);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb3);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb2);
    _ZN11PhysicalBox1DEP11PhysicalBox(&pb1);
}

void _Z11doWeightBoxv()
{
    printf("\n--- Start doWeightBox() ---\n\n");

    WeightBox pw1;
    _ZN9WeightBox1CEP9WeightBoxdddd(&pw1, 8, 6, 4, 25);

    WeightBox pw2;
    _ZN9WeightBox1CEP9WeightBoxdddd(&pw2, 1, 2, 3,0.0);

    WeightBox pw3;
    _ZN9WeightBox1CEP9WeightBoxdddd(&pw3, 10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    WeightBox pw4;
    _ZN9WeightBox1CEP9WeightBoxPK9WeightBox(&pw4, &pw1);
    _ZNK9WeightBox6printwEP9WeightBox(&pw4);
    _ZNK9WeightBox6printwEP9WeightBox(&pw1);

    printf("pw4 %s pw1\n", (const Box*)&pw4 == (const Box*)&pw1 && pw4.weight == pw1.weight ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    _ZN9WeightBox18AssignmentOperatorEP9WeightBoxPK9WeightBox(&pw4, &pw3);
    _ZNK9WeightBox6printwEP9WeightBox(&pw4);
    _ZNK9WeightBox6printwEP9WeightBox(&pw3);
    printf("pw4 %s pw3\n", (const Box*)&pw4 == (const Box*)&pw1 && pw4.weight == pw1.weight ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    _ZN9WeightBox1DEP9WeightBox(&pw4);
    _ZN9WeightBox1DEP9WeightBox(&pw3);
    _ZN9WeightBox1DEP9WeightBox(&pw2);
    _ZN9WeightBox1DEP9WeightBox(&pw1);
}




int main()
{
    printf("\n--- Start main() ---\n\n");

    _Z11doMaterialsv();

    _Z13doPhysicalBoxv();

    _Z11doWeightBoxv();

    printf("\n--- End main() ---\n\n");

}




