#include "polymorphism_defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*memcpy*/

typedef void_ptr_function (void *(*)(void *));
typedef  void(*print) (void*,long,char);
/* TextFormatter defs */

void *(*VtableTextFormatter[])(void*) = {(void *(*)(void *)) _ZN20DefaultTextFormatterD1EP13TextFormatter, NULL};

void _ZN20DefaultTextFormatterD1EP13TextFormatter(void * this)
{
    TextFormatter* textFormatter = (TextFormatter*)this;
}

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* this)
{
    this->pVtable = VtableTextFormatter;
}




/* DefaultTextFormatter defs*/

void *(*VtableDefaultTextFormatter[])(void*) = {(void *(*)(void *)) _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter,
                                                (void *(*)(void *)) _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc};

int m_next_id = 0;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* this)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)this);
    this->m_id = m_next_id++;
    ((TextFormatter*)this)->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);
}

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)this);
    this->m_id = m_next_id++;
    ((TextFormatter*)this)->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->m_id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* this, const DefaultTextFormatter*const other)
{
    memcpy((TextFormatter*)this + sizeof(TextFormatter), (TextFormatter*)other + sizeof(TextFormatter), sizeof(DefaultTextFormatter) - sizeof(TextFormatter));
    printf("--- DefaultTextFormatter operator=(), from m_id: %d to m_id: %d\n", other->m_id, this->m_id);
    return this;
}

void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(void * this)
{
    DefaultTextFormatter* defaultTextFormatter = (DefaultTextFormatter*)this;
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", defaultTextFormatter->m_id);
    ((TextFormatter*)defaultTextFormatter)->pVtable = VtableTextFormatter;
    _ZN20DefaultTextFormatterD1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
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

void *(*VtablePrePostFixer[])(void*) = {(void *(*)(void *)) _ZN12PrePostFixer1DEP12PrePostFixer,
                                        (void *(*)(void *)) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                        (void *(*)(void *)) _ZNK12PrePostFixer5printEPK12PrePostFixerlc,
                                        (void *(*)(void *)) _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer};

void _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc(PrePostFixer* this, const char* prefix, const char* postfix)
{
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter((DefaultTextFormatter*)this);
    this->m_pre = prefix;
    this->m_post = postfix;
    ((TextFormatter*)this)->pVtable = VtableTextFormatter;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
}

void _ZN12PrePostFixer1CEP12PrePostFixerPK12PrePostFixer(PrePostFixer* this, const PrePostFixer*const other)
{
    _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter((DefaultTextFormatter*)this, (DefaultTextFormatter*)other);
    memcpy(this + sizeof(DefaultTextFormatter), other + sizeof(DefaultTextFormatter), sizeof(PrePostFixer) - sizeof(DefaultTextFormatter));
}

void _ZN12PrePostFixer1DEP12PrePostFixer(void* this)
{
    PrePostFixer* postFixer = (PrePostFixer*)this;
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", postFixer->m_pre, postFixer->m_post);
    ((TextFormatter*)this)->pVtable = VtableDefaultTextFormatter;
    _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter((DefaultTextFormatter*)this);
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

void *(*VtablePrePostDollarFixer[])(void*) = {(void *(*)(void *)) _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer,
                                        (void *(*)(void *)) _ZNK12PrePostFixer5printEPK12PrePostFixerPKc,
                                        (void *(*)(void *)) _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerlc,
                                        (void *(*)(void *)) _ZNK18PrePostDollarFixer16getDefaultSymbolEPK18PrePostDollarFixer};


void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPKcPKc(PrePostDollarFixer* this, const char* prefix, const char* postfix)
{
    _ZN12PrePostFixer1CEP12PrePostFixerPKcPKc((PrePostFixer*)this, prefix, postfix);
    ((TextFormatter*)this)->pVtable = VtablePrePostDollarFixer;
    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixer1CEP18PrePostDollarFixerPK18PrePostDollarFixer(PrePostDollarFixer* this, const PrePostDollarFixer*const other)
{
    _ZN12PrePostFixer1CEP12PrePostFixerPK12PrePostFixer((PrePostFixer*)this, (PrePostFixer*)other);
    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
}

void _ZN18PrePostDollarFixer1DEP18PrePostDollarFixer(void * this)
{
    PrePostDollarFixer* prePostDollarFixer = (PrePostDollarFixer*)this;
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", ((PrePostFixer*)this)->m_pre, ((PrePostFixer*)this)->m_post);
    ((TextFormatter*)prePostDollarFixer)->pVtable = VtablePrePostFixer;
    _ZN12PrePostFixer1DEP12PrePostFixer((PrePostFixer*)this);
}

void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixeric(const PrePostDollarFixer*const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");
    ((print)(((TextFormatter*)this)->pVtable[2]))((void*)this,num,symbol);
}

void _ZNK18PrePostDollarFixer5printEPK18PrePostDollarFixerlc(const void *const this, long num, char symbol)
{
    PrePostDollarFixer* prePostDollarFixer = (PrePostDollarFixer*)this;
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");
    _ZNK12PrePostFixer5printEPK12PrePostFixerlc((PrePostFixer*)this, num, symbol);
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






