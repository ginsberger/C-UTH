#ifndef UNDERTHEHOODCC_POLYMORPHISM_H
#define UNDERTHEHOODCC_POLYMORPHISM_H
#include <stdio.h>

extern int m_next_id;

/* TextFormatter */

typedef struct TextFormatter
{
    void *(**pVtable)(void*);
}TextFormatter;

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* textFormatter);
void _ZN20DefaultTextFormatterD1EP13TextFormatter(TextFormatter* textFormatter);



/* DefaultTextFormatter */

typedef struct Ider
{
}Ider;

typedef struct DefaultTextFormatter
{
    TextFormatter* textFormatter;
    int m_id;
    void *(**pVtable)(void*);
}DefaultTextFormatter;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter);
void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other);
DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other);
void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter);
void _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(const DefaultTextFormatter*const defaultTextFormatter, const char* text);

DefaultTextFormatter* _Z22generateFormatterArrayv();




/* PrePostFixer */
typedef struct PrePostFixer
{
    DefaultTextFormatter* defaultTextFormatter;
    const char* m_pre;
    const char* m_post;
    void *(**pVtable)(void*);
}PrePostFixer;

void _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(PrePostFixer* this, const char* prefix, const char* postfix);
void _ZN12PrePostFixer1DEP12PrePostFixer(PrePostFixer* this);
void _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(const PrePostFixer*const this, const char* text);
void _ZNK12PrePostFixer5printEPK12PrePostFixerlc(const PrePostFixer*const this,long num, char symbol);
char _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer(const PrePostFixer*const this);





#endif /*UNDERTHEHOODCC_POLYMORPHISM_H*/
