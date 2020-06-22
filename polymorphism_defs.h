#ifndef UNDERTHEHOODCC_POLYMORPHISM_H
#define UNDERTHEHOODCC_POLYMORPHISM_H
#include <stdio.h>



typedef  void *(*genericFunctionPointer)(void*);
typedef void_ptr_function (void *(*)(void *));
typedef void(*print) (void*,long,char);
typedef char(*getDefaultSymbol)(void*);
typedef enum E_VIRTUAL_FUNCTION
{
    E_Dtor,
    E_printPKc,
    E_printlc,
    E_getDefaultSymbol
}E_VIRTUAL_FUNCTION;


extern int m_next_id;
extern genericFunctionPointer VtableTextFormatter[];
extern genericFunctionPointer VtableDefaultTextFormatter[];
extern genericFunctionPointer VtablePrePostFixer[];
extern genericFunctionPointer VtablePrePostDollarFixer[];
extern genericFunctionPointer VtablePrePostHashFixer[];
extern genericFunctionPointer VtablePrePostFloatDollarFixer[];
extern genericFunctionPointer VtablePrePostChecker[];
extern genericFunctionPointer VtableMultiplier[];


/* TextFormatter */

typedef struct
{
    genericFunctionPointer *vPtr;
}TextFormatter;

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* this);
void _ZN13TextFormatter1DEP13TextFormatter(void* this);



/* DefaultTextFormatter */

typedef struct
{
    TextFormatter* textFormatter;
    int m_id;
}DefaultTextFormatter;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* this);
void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other);
DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other);
void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(void * this);
void _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(const void *const this, const char* text);

DefaultTextFormatter* _Z22generateFormatterArrayv();




/* PrePostFixer */

typedef struct
{
    DefaultTextFormatter* defaultTextFormatter;
    const char* m_pre;
    const char* m_post;
}PrePostFixer;

void _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(PrePostFixer* this, const char* prefix, const char* postfix);
void _ZN12PrePostFixer1CEP12PrePostFixerPK12PrePostFixer(PrePostFixer* this, const PrePostFixer*const other);
void _ZN12PrePostFixer1DEP12PrePostFixer(void* this);
void _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(const void *const this, const char* text);
void _ZNK12PrePostFixer5printEPK12PrePostFixerlc(const void *const this,long num, char symbol);
char _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer(const void *const this);




/* PrePostDollarFixer */

typedef struct
{
    PrePostFixer* postFixer;
}PrePostDollarFixer;

void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc(PrePostDollarFixer* this, const char* prefix, const char* postfix);
void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPK18PrePostDollarFixer(PrePostDollarFixer* this, const PrePostDollarFixer*const other);
void _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer(void * this);
void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(const PrePostDollarFixer*const this, int num, char symbol);
void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerlc(const void *const this, long num, char symbol);
void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerdc(const PrePostDollarFixer*const this, double num, char symbol);
char _ZNK18PrePostDollarFixer16getDefaultSymbolEPK18PrePostDollarFixer(const void *const this);




/* PrePostHashFixer */

typedef struct
{
    PrePostDollarFixer* prePostDollarFixer;
    int precision;
}PrePostHashFixer;

void _ZN16PrePostHashFixer1CEP16PrePostHashFixeri(PrePostHashFixer* prePostHashFixer, int prc);/*prc=4*/
void _ZN16PrePostHashFixer1DEP16PrePostHashFixer(void * this);
void _ZNK16PrePostHashFixer5printEPK16PrePostHashFixeric(const PrePostHashFixer*const this, int num, char symbol);
void _ZNK16PrePostHashFixer5printEPK16PrePostHashFixerlc(const void *const this, long num, char symbol);
char _ZNK16PrePostHashFixer16getDefaultSymbolEPK16PrePostHashFixer(const void *const this);





/* PrePostFloatDollarFixer */

typedef struct
{
    PrePostDollarFixer* prePostDollarFixer;
}PrePostFloatDollarFixer;

void _ZN23PrePostFloatDollarFixer1CEP23PrePostFloatDollarFixerPKcPKc(PrePostFloatDollarFixer* this, const char* prefix, const char* postfix);
void _ZN23PrePostFloatDollarFixer1DEP23PrePostFloatDollarFixer(void* this);
void _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerf(const PrePostFloatDollarFixer*const this, float num);
void _ZNK23PrePostFloatDollarFixer5printEPK23PrePostFloatDollarFixerfc(const PrePostFloatDollarFixer*const this, float num, char symbol);
char _ZNK23PrePostFloatDollarFixer16getDefaultSymbolEPK23PrePostFloatDollarFixer(const void *const this);





/* PrePostChecker */
typedef struct
{
    PrePostFloatDollarFixer* prePostFloatDollarFixer;
}PrePostChecker;

void _ZN14PrePostChecker1CEP14PrePostChecker(PrePostChecker* this);
void _ZN14PrePostChecker1DEP14PrePostChecker(void* this);
void _ZNK14PrePostChecker24printThisSymbolUsingFuncEPK14PrePostChecker(const PrePostChecker*const this);
void _ZNK14PrePostChecker23printThisSymbolDirectlyEPK14PrePostChecker(const PrePostChecker*const this);
void _ZNK14PrePostChecker32printDollarSymbolByCastUsingFuncEPK14PrePostChecker(const PrePostChecker*const this);
void _ZNK14PrePostChecker33printDollarSymbolByScopeUsingFuncEPK14PrePostChecker(const PrePostChecker*const this);
void _ZNK14PrePostChecker31printDollarSymbolByCastDirectlyEPK14PrePostChecker(const PrePostChecker*const this);
void _ZNK14PrePostChecker32printDollarSymbolByScopeDirectlyEPK14PrePostChecker(const PrePostChecker*const this);



/* Multiplier */
typedef struct
{
    DefaultTextFormatter* defaultTextFormatter;
    int times;
}Multiplier;

void _ZN10MultiplierD1EP10Multiplier(void* this);
void _ZNK10Multiplier5printEP10MultiplierPKc(void* this, const char* text);





#endif /*UNDERTHEHOODCC_POLYMORPHISM_H*/
