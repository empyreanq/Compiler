#ifndef TEMP_H
#define TEMP_H
#include "header.h"
#include "SymbolTable.h"
#include "quads.h"

extern int tempcounter;

char *newtempname();

void resettemp();

struct Entry* newtemp(int scope);

#endif