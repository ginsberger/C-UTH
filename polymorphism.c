#include "polymorphism_defs.h"
#include <string.h>
#include <stdlib.h>

void doPrePostFixer()
{
    printf("\n--- start doPrePostFixer() ---\n\n");

    PrePostFixer angleBrackets,*temp;
    DefaultTextFormatter *temp2;
    TextFormatter *temp3;
    _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(&angleBrackets, "<<< ", " >>>");
    _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(&angleBrackets, "Hello World!");
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, -777, '\0');
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, 350, '#');
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc(&angleBrackets, (long int)3.14, '\0');

    temp = &angleBrackets;
    temp2 = angleBrackets.defaultTextFormatter;
    temp3 = temp2->textFormatter;
    (temp3)->vPtr = VtablePrePostFixer;
    (angleBrackets.defaultTextFormatter)->textFormatter->vPtr = NULL;
    ((temp->defaultTextFormatter)->textFormatter)->vPtr = NULL;
    ((TextFormatter*)temp)->vPtr = VtablePrePostFixer;
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
    _ZN23PrePostFloatDollarFixer1DEP23PrePostFloatDollarFixer(&hashes2);
    _ZN23PrePostFloatDollarFixer1DEP23PrePostFloatDollarFixer(&hashes);
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

    ((printlc)((((TextFormatter*)pp)->vPtr)[E_printlc]))((void*)pp, 123, '\0');

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

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1;
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)&m1);
    m1.m_times = 3;
    ((TextFormatter*)&m1)->vPtr = VtableMultiplier;
    printf("--- Multiplier CTOR: times = %d\n", m1.m_times);

    Multiplier temp;
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)&temp);
    temp.m_times = 5;
    ((TextFormatter*)&m1)->vPtr = VtableMultiplier;
    printf("--- Multiplier CTOR: times = %d\n", temp.m_times);
    Multiplier m2;
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter((DefaultTextFormatter*)&m2, (DefaultTextFormatter*)&temp);
    ((TextFormatter*)&m2)->vPtr = VtableMultiplier;
    m2.m_times = temp.m_times;

    Multiplier m3;
    memcpy(&m3, &m1, sizeof(Multiplier));

    Multiplier m4;
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter((DefaultTextFormatter*)&m4, (DefaultTextFormatter*)&m2);
    ((TextFormatter*)&m4)->vPtr = VtableMultiplier;
    m4.m_times = m2.m_times;

    _ZNK10Multiplier5printEP10MultiplierPKc(&m1, "abc ");
    _ZNK10Multiplier5printEP10MultiplierPKc(&m2, "abc ");
    _ZNK10Multiplier5printEP10MultiplierPKc(&m3, "abc ");
    _ZNK10Multiplier5printEP10MultiplierPKc(&m4, "abc ");

    printf("\n--- start doMultiplier() ---\n\n");

    _ZN10MultiplierD1EP10Multiplier(&m4);
    _ZN10MultiplierD1EP10Multiplier(&m3);
    _ZN10MultiplierD1EP10Multiplier(&m2);
    _ZN10MultiplierD1EP10Multiplier(&m1);
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");
    DefaultTextFormatter formatters[3];
    PrePostDollarFixer temp1;
    Multiplier temp2;
    PrePostChecker temp3;
    int i;

    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc(&temp1, "!!! ", " !!!");
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(&formatters[0], (DefaultTextFormatter*)&temp1);
    _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer(&temp1);

    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)&temp2);
    temp2.m_times = 4;
    ((TextFormatter*)&temp2)->vPtr = VtableMultiplier;
    printf("--- Multiplier CTOR: times = %d\n", temp2.m_times);
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(&formatters[1], (DefaultTextFormatter*)&temp2);
    _ZN10MultiplierD1EP10Multiplier(&temp2);

    _ZN14PrePostChecker1CEP14PrePostChecker(&temp3);
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(&formatters[2], (DefaultTextFormatter*)&temp3);
    _ZN14PrePostChecker1DEP14PrePostChecker(&temp3);

    for (i = 0; i < 3; ++i)
    {
        _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(&formatters[i], "Hello World");
    }

    printf("\n--- end doFormatterArray() ---\n\n");

    _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(&formatters[2]);
    _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(&formatters[1]);
    _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(&formatters[0]);
}

void doFormatterPtrs()
{
    DefaultTextFormatter* pfmt[3];
    int i;
    printf("\n--- start doFormatterPtrs() ---\n\n");

    pfmt[0] = malloc(sizeof(PrePostDollarFixer));
    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc((PrePostDollarFixer *) pfmt[0], "!!! ", " !!!");

    pfmt[1] = malloc(sizeof(Multiplier));
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)&pfmt[1]);
    ((Multiplier*)pfmt[1])->m_times = 4;
    ((TextFormatter*)&pfmt[1])->vPtr = VtableMultiplier;
    printf("--- Multiplier CTOR: times = %d\n", ((Multiplier*)pfmt[1])->m_times);

    pfmt[2] = malloc(sizeof(Multiplier));
    _ZN14PrePostChecker1CEP14PrePostChecker((PrePostChecker *) pfmt[2]);

    for (i = 0; i < 3; ++i)
    {
        ((printPKc)((((TextFormatter*)pfmt[i])->vPtr)[E_printPKc]))((void*)pfmt[i], "Hello World!");
    }

    for (i = 2; i >= 0; --i)
    {
        ((Dtor)((((TextFormatter*)pfmt[i])->vPtr)[E_Dtor]))(pfmt[i]);
        free(pfmt[i]);
    }

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    DefaultTextFormatter* formatters;
    int i;
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    formatters = _Z22generateFormatterArrayv();

    for (i = 0; i < 3; ++i)
    {
        ((printPKc)((((TextFormatter*)(formatters+i))->vPtr)[E_printPKc]))((void*)(formatters+i), "Hello World!");
    }

    for (i = 2; i >=0; --i)
    {
        ((Dtor)((((TextFormatter*)(formatters+i))->vPtr)[E_Dtor]))(formatters+i);
    }
    free(formatters);
    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}


int main()
{
    printf("\n--- Start main() ---\n\n");

/*     doPrePostFixer();
      doPrePostDollarFixer();
       doPrePostFloatDollarFixer();*/
/*       doPrePostChecker();*/

       PrePostHashFixer hfix;
/*       _ZN16PrePostHashFixer1CEP16PrePostHashFixeri(&hfix, 4);*/
       runAsPrePostFixerRef((const PrePostFixer *) &hfix);
/*       runAsPrePostDollarFixerRef(hfix);
       runAsPrePostDollarFixerObj(hfix);
       runAsPrePostHashFixerRef(hfix);*/

/*       doMultiplier();

       doFormatterArray();
       doFormatterPtrs();
       doFormatterDynamicArray();
   */
    printf("\n--- End main() ---\n\n");

    return 0;
}


