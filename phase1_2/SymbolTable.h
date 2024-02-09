#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef struct Variable{
	const char *name;
	unsigned int scope;
	unsigned int line;
}Variable;

typedef struct Function{
    const char *name;
    //list of arguments !!!!!!!!!!!!!!!!!!!!!!!
    unsigned int scope;
    unsigned int line;
}Function;

enum SymbolType{
	GLOBAL,
    LOCAL_TYPE,
    FORMAL,
    USERFUNC,
    LIBFUNC
};

struct Entry{
    bool isActive;
    union {
        Variable *varVal;
        Function *funcVal;
    }value;
    enum SymbolType type;
    struct Entry *next;
};

typedef struct Entry *SymTab_Entry;

extern struct Entry *scopes[100];
extern int Scope;

int checkIfLibFunction(const char* name);

int checkedInsertionLocalVar(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction);

int checkD_Scope(const char* name);

struct Entry* checkedInsertionFormal(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

struct Entry* checkedInsertionFunction(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

int checkedInsertion(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction);

int checkIfVarORFunc(enum SymbolType type);

int checkedInsertionVariable(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction);

void libfunctions();

SymTab_Entry lookUpScope(const char* name,int scope);

SymTab_Entry lookUp(const char* name);

int InsertAtScope(unsigned int scope,const char* name, unsigned int line,enum SymbolType type);

void hideScope(int scope);

void printRes();