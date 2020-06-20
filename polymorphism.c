#include "polymorphism_defs.h"

void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets;
    _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(&angleBrackets, "<<< ", " >>>");
    _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(&angleBrackets, "Hello World!");
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, -777, '\0');
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, 350, '#');
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, (long int)3.14, '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");
}



int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
/*    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef(hfix);
    runAsPrePostDollarFixerRef(hfix);
    runAsPrePostDollarFixerObj(hfix);
    runAsPrePostHashFixerRef(hfix);

    doMultiplier();

    doFormatterArray();
    doFormatterPtrs();
    doFormatterDynamicArray();
*/
    printf("\n--- End main() ---\n\n");

    return 0;
}


