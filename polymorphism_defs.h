#ifndef UNDERTHEHOODCC_POLYMORPHISM_H
#define UNDERTHEHOODCC_POLYMORPHISM_H
#include <stdio.h>

extern int m_next_id;

/* TextFormatter */

typedef struct TextFormatter
{
    void *(**pVtable)(void*);
}TextFormatter;

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* this);
void _ZN20DefaultTextFormatterD1EP13TextFormatter(void* this);



/* DefaultTextFormatter */

typedef struct DefaultTextFormatter
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

typedef struct PrePostFixer
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

typedef struct PrePostDollarFixer
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





#endif /*UNDERTHEHOODCC_POLYMORPHISM_H*/
