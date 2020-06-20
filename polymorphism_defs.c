#include "polymorphism_defs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> /*memcpy*/


/* TextFormatter defs */

void _ZN20DefaultTextFormatterD1EP13TextFormatter(TextFormatter* textFormatter){}

void _ZN13TextFormatterC1EP13TextFormatter(TextFormatter* textFormatter)
{
    textFormatter->pVtable = VtableTextFormatter;
}




/* DefaultTextFormatter defs*/

int next_id = 0;

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
    defaultTextFormatter->id = next_id++;
    defaultTextFormatter->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", defaultTextFormatter->id);
}

void _ZN20DefaultTextFormatter1CEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other)
{
    _ZN13TextFormatterC1EP13TextFormatter((TextFormatter*)defaultTextFormatter);
    defaultTextFormatter->id = next_id++;
    defaultTextFormatter->pVtable = VtableDefaultTextFormatter;
    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", defaultTextFormatter->id);
}

DefaultTextFormatter* _ZN20DefaultTextFormatter18AssignmentOperatorEP20DefaultTextFormatterPK20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter, const DefaultTextFormatter*const other)
{
    memcpy((TextFormatter*)defaultTextFormatter + sizeof(TextFormatter), (TextFormatter*)other + sizeof(TextFormatter), sizeof(DefaultTextFormatter) - sizeof(TextFormatter));
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, defaultTextFormatter->id);
    return defaultTextFormatter;
}

void _ZN20DefaultTextFormatter1DEP20DefaultTextFormatter(DefaultTextFormatter* defaultTextFormatter)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", defaultTextFormatter->id);
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







