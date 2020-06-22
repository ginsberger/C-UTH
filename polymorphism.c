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
    _ZN12PrePostFixer1DEP12PrePostFixer(&angleBrackets);
}

void doPrePostDollarFixer()
{
    printf("\n--- start doPrePostDollarFixer() ---\n\n");
    PrePostDollarFixer asterisks;
    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc(&asterisks, "***** ", " *****");

    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(&asterisks, -777, '$');
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(&asterisks, 350, '#');
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerdc(&asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");
    _ZN12PrePostFixer1DEP12PrePostFixer(&asterisks);
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes;
    _ZN23PrePostFloatDollarFixer1CEP23PrePostFloatDollarFixerPKcPKc(&hashes, "### ", " ###");
    _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerf(&hashes, -777);
    _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerfc(&hashes, 350, '#');
    _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerf(&hashes, 3.14f);

    PrePostDollarFixer hashes2;
    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPK18PrePostDollarFixer(&hashes2, (PrePostDollarFixer*)&hashes);
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerdc(&hashes2, 7.5, '$');
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(&hashes2, 100, '$');

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}

void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    _ZN14PrePostChecker1CEP14PrePostChecker(&check);
    _ZNK14PrePostChecker24printThisSymbolUsingFuncEPK14PrePostChecker(&check);
    _ZNK14PrePostChecker23printThisSymbolDirectlyEPK14PrePostChecker(&check);
    _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEPK14PrePostChecker(&check);
    _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEPK14PrePostChecker(&check);
    _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEPK14PrePostChecker(&check);
    _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEPK14PrePostChecker(&check);

    printf("\n--- end doPrePostChecker() ---\n\n");
    _ZN14PrePostChecker1DEP14PrePostChecker(&check);
}


void runAsPrePostFixerRef(const PrePostFixer* pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ((print)(((TextFormatter*)pp)->pVtable[E_printlc]))((void*)pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerRef(const PrePostDollarFixer* pp)
{
    printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(pp, 123, '$');
    printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");
    _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(&pp, 123, '$');
    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer* pp)
{
    printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");
_ZNK16PrePostHashFixer5printEPK16PrePostHashFixeric(pp, 123, '#');
    printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

int main()
{
    printf("\n--- Start main() ---\n\n");

    doPrePostFixer();
/*    doPrePostDollarFixer();
    doPrePostFloatDollarFixer();
    doPrePostChecker();

    PrePostHashFixer hfix;
    runAsPrePostFixerRef((const PrePostFixer *) &hfix);*/
/*    runAsPrePostDollarFixerRef(hfix);
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


