#ifndef QUADS_H
#define QUADS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "header.h"
#include "SymbolTable.h"

#define EXPAND_SIZE 1024
#define CURR_SIZE (total*sizeof(quad))
#define NEW_SIZE (EXPAND_SIZE*sizeof(quad) + CURR_SIZE)

extern quad* quads;
extern unsigned total;
extern unsigned int currQuad;

unsigned nextquad(void);

void emit(enum iopcode op,expr* arg1,expr* arg2,expr* result,unsigned label, unsigned line);

struct expr* emit_iftableitem(struct expr* e,int scope,int line);

void expand(void);

void patchlabel(unsigned quadNo, unsigned label);

void patchlist(int list,int label);

struct stmt_t* make_stmt();

struct forprefix* make_prefix();

int newlist(int i);

int mergelist(int l1,int l2);

struct expr* lvalue_expr(struct Entry* sym);

struct expr* newexpr(expr_t t);

struct expr* newexpr_conststring(char* s);

struct expr* exprNumConst(double i);

struct expr* newexpr_constbool(unsigned int b);

struct expr* member_item(struct expr* lv,char* name,int scope,int line);

struct expr* make_call (expr* lv, expr* reversed_elist,int scope,int line);
struct List* makelist(unsigned i);

void printReturnVal(int i,char* op);
void printParameter(int i,char *op);
void backpatch(List* list,unsigned i);
struct List* mergeTrueORFalseList(List *list1,List *list2);

void check_arith(expr* e);

void printAddConst(int i);

void printQuads();
	
#endif

