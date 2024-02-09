#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "header.h"
#include "temp.h"
#include "scope_offset.h"


//typedef struct Entry *SymTab_Entry;

extern struct Entry *scopes[100];
extern int Scope;

int checkIfLibFunction(const char* name);

struct Entry* checkedInsertionLocalVar(unsigned int scope,const char* name, unsigned int line, SymbolType type,int isFunction);

struct Entry* checkD_Scope(const char* name);

struct Entry* checkedInsertionFormal(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

struct Entry* checkedInsertionFunction(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

struct Entry* checkedInsertion(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction);

int checkIfVarORFunc(enum SymbolType type);

struct Entry* checkedInsertionVariable(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction);

void libfunctions();

struct Entry *lookUpScope(const char* name,int scope);

struct Entry *lookUp(const char* name);

struct Entry* InsertAtScope(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

void hideScope(int scope);

void printRes();

#endif