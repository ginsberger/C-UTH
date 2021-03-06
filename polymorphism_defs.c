#include "polymorphism_defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*memcpy*/

int m_next_id = 0;

genericFunctionPointer VtableTextFormatter[] = {(genericFunctionPointer) _ZN13TextFormatter1DEP13TextFormatter, NULL};
genericFunctionPointer VtableDefaultTextFormatter[] = {(genericFunctionPointer) _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter,
                                                       (genericFunctionPointer) _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc};
genericFunctionPointer VtablePrePostFixer[] = {(genericFunctionPointer) _ZN12PrePostFixer1DEP12PrePostFixer,
                                               (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                               (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerlc,
                                               (genericFunctionPointer) _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer};
genericFunctionPointer VtablePrePostDollarFixer[] = {(genericFunctionPointer) _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer,
                                                     (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                                     (genericFunctionPointer) _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerlc,
                                                     (genericFunctionPointer) _ZNK18PrePostDollarFixer16getDefaultSymbolEPK18PrePostDollarFixer};
genericFunctionPointer VtablePrePostHashFixer[] = {(genericFunctionPointer) _ZN16PrePostHashFixer1DEP16PrePostHashFixer,
                                                   (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                                   (genericFunctionPointer) _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc,
                                                   (genericFunctionPointer) _ZNK16PrePostHashFixer16getDefaultSymbolEPK16PrePostHashFixer};
genericFunctionPointer VtablePrePostFloatDollarFixer[] = {(genericFunctionPointer) _ZN16PrePostHashFixer1DEP16PrePostHashFixer,
                                                          (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                                          (genericFunctionPointer) _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc,
                                                          (genericFunctionPointer) _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEPK23PrePostFloatDollarFixer};
genericFunctionPointer VtablePrePostChecker[] = {(genericFunctionPointer) _ZN14PrePostChecker1DEP14PrePostChecker,
                                                 (genericFunctionPointer) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                                 (genericFunctionPointer) _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc,
                                                 (genericFunctionPointer) _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEPK23PrePostFloatDollarFixer};
genericFunctionPointer VtableMultiplier[] = {(genericFunctionPointer) _ZN10MultiplierD1EP10Multiplier,
                                             (genericFunctionPointer) _ZNK10Multiplier5printEP10MultiplierPKc,
                                             (genericFunctionPointer) _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc,
                                             (genericFunctionPointer) _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEPK23PrePostFloatDollarFixer};





/* TextFormatter defs */

void _ZN13TextFormatter1DEP13TextFormatter(void * this)
{
    TextFormatter* textFormatter = (TextFormatter*)this;
}

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* this)
{
    this->vPtr = VtableTextFormatter;
}




/* DefaultTextFormatter defs*/

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* this)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)this);/*inline*/
    this->m_id = m_next_id++;
    ((TextFormatter*)this)->vPtr = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);
}

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)this);
    ((TextFormatter*)this)->vPtr = VtableDefaultTextFormatter;
    this->m_id = m_next_id++;
    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->m_id, this->m_id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other)
{
    printf("--- DefaultTextFormatter operator=(), from m_id: %d to m_id: %d\n", other->m_id, this->m_id);
    return this;
}

void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(void * this)
{
    DefaultTextFormatter* defaultTextFormatter = (DefaultTextFormatter*)this;
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", defaultTextFormatter->m_id);
    ((TextFormatter*)defaultTextFormatter)->vPtr = VtableTextFormatter;
    (((TextFormatter*)this)->vPtr[E_Dtor])((void*)this);
}

void _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(const void *const this, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* _Z22generateFormatterArrayv()
{
    DefaultTextFormatter *arr = malloc(sizeof(DefaultTextFormatter)*3);

    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(&arr[0]);
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(&arr[1]);
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(&arr[2]);

    return arr;
}





/* PrePostFixer Defs */

void _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(PrePostFixer* this, const char* prefix, const char* postfix)
{
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)this);
    this->m_pre = prefix;
    this->m_post = postfix;
    ((TextFormatter*)this)->vPtr = VtableTextFormatter;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
}

void _ZN12PrePostFixer1CEP12PrePostFixerPK12PrePostFixer(PrePostFixer* this, const PrePostFixer*const other)
{
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter((DefaultTextFormatter*)this, (DefaultTextFormatter*)other);
    this->m_post = other->m_post;
    this->m_pre = other->m_pre;
    ((TextFormatter*)this)->vPtr = VtableTextFormatter;
}

void _ZN12PrePostFixer1DEP12PrePostFixer(void* this)
{
    TextFormatter *temp;
    genericFunctionPointer *temp2 = VtableDefaultTextFormatter;
    PrePostFixer* postFixer = (PrePostFixer*)this;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", postFixer->m_pre, postFixer->m_post);

    temp = (TextFormatter*)postFixer;
    ((TextFormatter*)postFixer)->vPtr = VtableDefaultTextFormatter;
    printf("\n------------- sizeof postFixer vPtr=%ld, sizeof VtableDefaultTextFormatter=%ld\n", sizeof( ((TextFormatter*)postFixer)->vPtr), sizeof(VtableDefaultTextFormatter));
    printf("sizeof vtable[0] = %ld\n", sizeof(VtableDefaultTextFormatter[0]));
    (((TextFormatter*)postFixer)->vPtr[E_Dtor])(postFixer);
}

void _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(const void *const this, const char* text)
{
    PrePostFixer* postFixer = (PrePostFixer*)this;
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", postFixer->m_pre, text, postFixer->m_post);
}

void _ZNK12PrePostFixer5printEPK12PrePostFixerlc(const void *const this,long num, char symbol)
{
    PrePostFixer* postFixer = (PrePostFixer*)this;
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", postFixer->m_pre, symbol, num, postFixer->m_post);
    }

    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", postFixer->m_pre, num, postFixer->m_post);
    }
}

char _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer(const void *const this)
{
    return '\0';
}





/* PrePostDollarFixer Defs */

void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc(PrePostDollarFixer* this, const char* prefix, const char* postfix)
{
    _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc((PrePostFixer*)this, prefix, postfix);
    ((TextFormatter*)this)->vPtr = VtablePrePostDollarFixer;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPK18PrePostDollarFixer(PrePostDollarFixer* this, const PrePostDollarFixer*const other)
{
    _ZN12PrePostFixer1CEP12PrePostFixerPK12PrePostFixer((PrePostFixer*)this, (PrePostFixer*)other);
    ((TextFormatter*)this)->vPtr = VtablePrePostDollarFixer;
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer(void * this)
{
    PrePostDollarFixer* prePostDollarFixer = (PrePostDollarFixer*)this;
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)prePostDollarFixer)->vPtr = VtablePrePostFixer;
    (((TextFormatter*)this)->vPtr[E_Dtor])(this);
}

void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(const PrePostDollarFixer*const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    ((printlc)(((TextFormatter*)this)->vPtr[E_printlc]))((void*)this, num, symbol);
}

void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerlc(const void *const this, long num, char symbol)
{
    PrePostDollarFixer* prePostDollarFixer = (PrePostDollarFixer*)this;
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    PrePostFixer* postFixer = (PrePostFixer*)this;
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", postFixer->m_pre, symbol, num, postFixer->m_post);
    }

    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", postFixer->m_pre, num, postFixer->m_post);
    }
}

void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerdc(const PrePostDollarFixer*const this, double num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", ((PrePostFixer*)this)->m_pre, symbol, num, ((PrePostFixer*)this)->m_post);
}

char _ZNK18PrePostDollarFixer16getDefaultSymbolEPK18PrePostDollarFixer(const void *const this)
{
    return '$';
}





/* PrePostHashFixer Defs */

void _ZN16PrePostHashFixer1CEP16PrePostHashFixeri(PrePostHashFixer* this, int prc)
{
    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc((PrePostDollarFixer*)this, "===> ", " <===");
    this->m_precision = prc;
    ((TextFormatter*)this)->vPtr = VtablePrePostHashFixer;
    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post, this->m_precision);

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, '$', this->m_precision, 9999.9999, ((PrePostFixer*)this)->m_post);
}

void _ZN16PrePostHashFixer1DEP16PrePostHashFixer(void * this)
{
    PrePostHashFixer* prePostHashFixer = (PrePostHashFixer*)this;
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n",  ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)prePostHashFixer)->vPtr = VtablePrePostDollarFixer;
    (((TextFormatter*)this)->vPtr[E_Dtor])((void*)this);
}

void _ZNK16PrePostHashFixer5printEPK16PrePostHashFixeric(const PrePostHashFixer*const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)this)->m_pre, symbol, this->m_precision, (double )num, ((PrePostFixer*)this)->m_post);
}

void _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc(const void *const this, long num, char symbol)
{
    PrePostHashFixer* prePostHashFixer = (PrePostHashFixer*)this;
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");

    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");
    printf("%s[%c%.*f]%s\n", ((PrePostFixer*)prePostHashFixer)->m_pre, symbol, prePostHashFixer->m_precision, (double )num, ((PrePostFixer*)prePostHashFixer)->m_post);
}

char _ZNK16PrePostHashFixer16getDefaultSymbolEPK16PrePostHashFixer(const void *const this)
{
    return '#';
}





/* PrePostFloatDollarFixer Defs */

void _ZN23PrePostFloatDollarFixer1CEP23PrePostFloatDollarFixerPKcPKc(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix)
{
    _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc((PrePostDollarFixer*)this, prefix, postfix);
    ((TextFormatter*)this)->vPtr = VtablePrePostFloatDollarFixer;
    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN23PrePostFloatDollarFixer1DEP23PrePostFloatDollarFixer(void * this)
{
    PrePostFloatDollarFixer* prePostFloatDollarFixer = (PrePostFloatDollarFixer*)this;
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n",  ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)prePostFloatDollarFixer)->vPtr = VtablePrePostDollarFixer;
    (((TextFormatter*)this)->vPtr[E_Dtor])((void*)this);
}

void _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerf(const PrePostFloatDollarFixer*const this, float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");
    _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerfc(this, num, '@');
}

void _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerfc(const PrePostFloatDollarFixer*const this, float num, char symbol)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");
    printf("%s%c%.2f%s\n", ((PrePostFixer*)this)->m_pre, symbol, num, ((PrePostFixer*)this)->m_post);
}

char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEPK23PrePostFloatDollarFixer(const void *const this)
{
    return '@';
}





/* PrePostChecker Defs */

void _ZN14PrePostChecker1CEP14PrePostChecker(PrePostChecker* this)
{
    _ZN23PrePostFloatDollarFixer1CEP23PrePostFloatDollarFixerPKcPKc((PrePostFloatDollarFixer*)this, "[[[[ ", " ]]]]");
    ((TextFormatter*)this)->vPtr = VtablePrePostChecker;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN14PrePostChecker1DEP14PrePostChecker(void* this)
{
    PrePostChecker* prePostChecker = (PrePostChecker*)this;
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)prePostChecker)->vPtr = VtablePrePostDollarFixer;
    (((TextFormatter*)this)->vPtr[E_Dtor])(this);
}

void _ZNK14PrePostChecker24printThisSymbolUsingFuncEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");
    printf("Default symbol is %c\n", ((getDefaultSymbol)((TextFormatter*)this)->vPtr[3])((void *)this));
}

void _ZNK14PrePostChecker23printThisSymbolDirectlyEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");
    printf("Default symbol is %c\n", '@');
}

void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");
    printf("Default symbol is %c\n", ((getDefaultSymbol)((TextFormatter*)this)->vPtr[3])((void *)this));
}

void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");
    printf("Default symbol is %c\n", '$');
}

void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");
    printf("Default symbol is %c\n", '$');
}

void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEPK14PrePostChecker(const PrePostChecker*const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");
    printf("Default symbol is %c\n", '$');
}




/* Multiplier Defs */

void _ZN10MultiplierD1EP10Multiplier(void * this)
{
    Multiplier* multiplier = (Multiplier*)this;
    printf("--- Multiplier DTOR: m_times = %d\n", multiplier->m_times);
    ((TextFormatter*)multiplier)->vPtr = VtablePrePostDollarFixer;
    (((TextFormatter*)this)->vPtr[E_Dtor])(this);
}

void _ZNK10Multiplier5printEP10MultiplierPKc(void* this, const char* text)
{
    Multiplier* multiplier = (Multiplier*)this;

    printf("%-60s | ", "[Multiplier::print(const char*)]");
    int i ;
    for (i = 0; i < multiplier->m_times; ++i)
        printf("%s", text);
    printf("\n");
}








