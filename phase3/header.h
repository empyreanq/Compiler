#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

typedef enum symbol_t {
	var_s,
	programfunc_s,
	libraryfunc_s
}symbol_t;

typedef enum SymbolType{
	GLOBAL,
    LOCAL_TYPE,
    FORMAL,
    USERFUNC,
    LIBFUNC,
    TRUE_LOCAL_TYPE
}SymbolType;

typedef enum scopespace_t{
	programvar,
	functionlocal,
	formalarg
}scopespace_t;



struct Entry{
    bool isActive;
    union {
        Variable *varVal;
        Function *funcVal;
    }value;
    enum SymbolType type;
    symbol_t supersetType;
    scopespace_t space;
	unsigned	offset;
    struct Entry *next;
};

typedef enum expr_t{
	var_e,
	tableitem_e,
	programfunc_e,
	libraryfunc_e,
	arithexpr_e,
	boolexpr_e,
	assignexpr_e,
	newtable_e,
	constnum_e,
	constbool_e,
	conststring_e,
	nil_e	
}expr_t;

typedef struct expr{
	expr_t type;
	struct Entry* sym; //Entry field
	struct expr* index;
	double numConst;
	char* strConst;
	unsigned char boolConst;
	struct expr* next;
	struct List* truelist;
	struct List* falselist;
}expr;


/*entoles quads*/
typedef enum iopcode{
assign, add, sub,
mul, divide, mod,
uminus, and, or,
not, if_eq, if_noteq,
if_lesseq, if_greatereq, if_less, 
if_greater, call, param,
ret, getretval, funcstart,
funcend, tablecreate,
tablegetelem, tablesetelem,
jump
}iopcode;

typedef struct quad{
	iopcode op;
	expr* result;
	expr* arg1;
	expr* arg2;
	unsigned label;
	unsigned line;
}quad;


typedef struct stmt_t{	// struct gia diafania 26/26 dialeksi 11
	int breaklist;
	int contlist;
}stmt_t;

typedef struct List{
	unsigned label;
	struct List* next;
}List;


typedef struct calle{
	struct expr* elist;
	unsigned char method;
	char* name;
}calle;

typedef struct forprefix{
	int test;
	int enter;
}forprefix;

#endif