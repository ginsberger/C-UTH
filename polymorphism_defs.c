#include "polymorphism_defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*memcpy*/


/* TextFormatter defs */

void *(*VtableTextFormatter[])(void*) = {(void *(*)(void *)) _ZN20DefaultTextFormatterD1EP13TextFormatter, NULL};

void _ZN20DefaultTextFormatterD1EP13TextFormatter(TextFormatter* textFormatter){}

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* textFormatter)
{
    textFormatter->pVtable = VtableTextFormatter;
}




/* DefaultTextFormatter defs*/

void *(*VtableDefaultTextFormatter[])(void*) = {(void *(*)(void *)) _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter,
                                                (void *(*)(void *)) _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc};

int m_next_id = 0;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
    defaultTextFormatter->m_id = m_next_id++;
    defaultTextFormatter->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", defaultTextFormatter->m_id);
}

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
    defaultTextFormatter->m_id = m_next_id++;
    defaultTextFormatter->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", defaultTextFormatter->m_id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other)
{
    memcpy((TextFormatter*)defaultTextFormatter + sizeof(TextFormatter), (TextFormatter*)other + sizeof(TextFormatter), sizeof(DefaultTextFormatter) - sizeof(TextFormatter));
    printf("--- DefaultTextFormatter operator=(), from m_id: %d to m_id: %d\n", other->m_id, defaultTextFormatter->m_id);
    return defaultTextFormatter;
}

void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", defaultTextFormatter->m_id);
    defaultTextFormatter->pVtable = defaultTextFormatter->textFormatter->pVtable;
    _ZN20DefaultTextFormatterD1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
}

void _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(const DefaultTextFormatter*const defaultTextFormatter, const char* text)
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
    this->pVtable = VtablePrePostFixer;
    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
}

void _ZN12PrePostFixer1DEP12PrePostFixer(PrePostFixer* this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n", this->m_pre, this->m_post);
    this->pVtable = this->defaultTextFormatter->pVtable;
    _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter((DefaultTextFormatter*)this);
}

void _ZNK12PrePostFixer5printEPK12PrePostFixerPKc(const PrePostFixer*const this, const char* text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->m_pre, text, this->m_post);
}

void _ZNK12PrePostFixer5printEPK12PrePostFixerlc(const PrePostFixer*const this,long num, char symbol)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
        printf("%s%c%ld%s\n", this->m_pre, symbol, num, this->m_post);
    }

    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->m_pre, num, this->m_post);
    }
}

char _ZNK12PrePostFixer16getDefaultSymbolEPK12PrePostFixer(const PrePostFixer*const this)
{
    return '\0';
}

