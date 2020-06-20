#ifndef UNDERTHEHOODCC_POLYMORPHISM_H
#define UNDERTHEHOODCC_POLYMORPHISM_H
#include <stdio.h>

extern next_id;

/* TextFormatter */

typedef struct TextFormatter
{
    void *(**pVtable)(void*);
}TextFormatter;

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* textFormatter);
void _ZN20DefaultTextFormatterD1EP13TextFormatter(TextFormatter* textFormatter);
void *(*VtableTextFormatter[])(void*) = {(void *(*)(void *)) _ZN20DefaultTextFormatterD1EP13TextFormatter, NULL};




/* DefaultTextFormatter */

typedef struct Ider
{
}Ider;

typedef struct DefaultTextFormatter
{
    TextFormatter* textFormatter;
    int id;
    void *(**pVtable)(void*);
}DefaultTextFormatter;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter);
void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other);
DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other);
void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter);
void _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc(const DefaultTextFormatter*const defaultTextFormatter, const char* text);
void *(*VtableDefaultTextFormatter[])(void*) = {_ZN20DefaultTextFormatter1DEP20DefaultTextFormatter, _ZNK20DefaultTextFormatter5printEPK20DefaultTextFormatterPKc};

DefaultTextFormatter* _Z22generateFormatterArrayv();






#endif //UNDERTHEHOODCC_POLYMORPHISM_H
