#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "EndingCode.h"


#define AVM_STACKSIZE 4096
#define AVM_WIPEOUT(m) memset(&(m),0,sizeof(m))

#define AVM_TABLE_HASHSIZE 211

#define AVM_STACKENV_SIZE 4

#define AVM_ENDING_PC codesize

#define AVM_NUMACTUALS_OFFSET +4
#define AVM_SAVEDPC_OFFSET +3
#define AVM_SAVEDTOP_OFFSET +2
#define AVM_SAVEDTOPSP_OFFSET +1 

#define execute_add execute_arithmetic
#define execute_sub execute_arithmetic
#define execute_mul execute_arithmetic
#define execute_div execute_arithmetic
#define execute_mod execute_arithmetic



enum avm_memcell_t{
    number_m    =0,
    string_m    =1,
    bool_m      =2,
    table_m     =3,
    userfunc_m  =4,
    libfunc_m   =5,
    nil_m       =6,
    undef_m     =7
};

typedef struct avm_memcell{
    enum avm_memcell_t type;
    union{
        double                  numVal;
        char*                   strVal;
        unsigned char           boolVal;
        struct avm_table*       tableVal;
        unsigned                funcVal;
        char*                   libfuncVal;
    }data;
}avm_memcell;

struct avm_memcell stack[AVM_STACKSIZE];



typedef struct avm_table_bucket{
    struct avm_memcell key;
    struct avm_memcell value;
    struct avm_table_bucket* next;
}avm_table_bucket;

typedef struct avm_table{
    unsigned refCounter;
    struct avm_table_bucket* strIndexed[AVM_TABLE_HASHSIZE];
    struct avm_table_bucket* numIndexed[AVM_TABLE_HASHSIZE];
    unsigned total;
}avm_table;


static void avm_initstack(void);

struct avm_table* avm_tablenew(void);
void avm_tabledestroy(struct avm_table* t);
//struct avm_memcell* avm_tablegetelem(struct avm_memcell* key,avm_memcell* index);
//void avm_tablesetelem(struct avm_memcell* key,struct avm_memcell* value, avm_memcell* content);
struct avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index);
void avm_tablesetelem(avm_table* table,avm_memcell* index, avm_memcell* content);

void avm_tableincrefcounter(struct avm_table* t);
void avm_tabledecrefcounter(struct avm_table* t);
void avm_tablebucketsinit(struct avm_table_bucket** p);

void avm_memcellclear(avm_memcell* m);

void avm_tablebucketsdestroy(struct avm_table_bucket** p);
void avm_tabledestroy(struct avm_table* t);



double consts_getnumber(unsigned index);
char* consts_getstring(unsigned index);
char* libfuncs_getused(unsigned index);


struct avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg);


typedef void (*execute_func_t) (struct instruction*);

#define AVM_MAX_INSTRUCTIONS (unsigned) jump_v


void execute_assign (struct instruction* i);

void execute_add 	(struct instruction* i);
void execute_sub	(struct instruction* i);
void execute_mul	(struct instruction* i);
void execute_div	(struct instruction* i);
void execute_mod	(struct instruction* i);
void execute_uminus	(struct instruction* i);

void execute_and 	(struct instruction* i);
void execute_or 	(struct instruction* i);
void execute_not 	(struct instruction* i);

void execute_jeq	(struct instruction* i);
void execute_jne	(struct instruction* i);
void execute_jle	(struct instruction* i);
void execute_jge	(struct instruction* i);
void execute_jlt	(struct instruction* i);
void execute_jgt	(struct instruction* i);

void execute_call		(struct instruction* i);
void execute_pusharg	(struct instruction* i);
void execute_funcenter	(struct instruction* i);
void execute_funcexit	(struct instruction* i);

void execute_newtable		(struct instruction* i);
void execute_tablegetelem	(struct instruction* i);
void execute_tablesetelem	(struct instruction* i);

void execute_nop	(struct instruction* i);
void execute_jump	(struct instruction* i);



void execute_cycle(void);



typedef void (*memclear_func_t)(avm_memcell*);
void memclear_string(struct avm_memcell* m);
void memclear_table(struct avm_memcell* m);


void avm_warning(char* format);
void avm_assign(struct avm_memcell* lv,struct avm_memcell* rv);

void execute_assign(struct instruction* instr);


void avm_error(char* format);
char* avm_tostring(struct avm_memcell*);
void avm_calllibfunc(char* funcName);
void avm_callsaveenvironment(void);

void execute_call(struct instruction* instr);

void avm_dec_top(void);
void avm_push_envvalue(unsigned val);

struct userfunc* avm_getfuncinfo(unsigned address);

void execute_funcenter(struct instruction* instr);

unsigned avm_get_envvalue(unsigned i);
void execute_funcexit(struct instruction* unused);


typedef void (*library_func_t)(void);
library_func_t avm_getlibraryfunc(char* id);

unsigned avm_totalactuals(void);
struct avm_memcell* avm_getactual(unsigned i);

void libfunc_print();
void libfunc_input();
void libfunc_objectmemberkeys();
void libfunc_objecttotalmembers();
void libfunc_objectcopy();
void libfunc_totalarguments();
void libfunc_argument();
void libfunc_typeof();
void libfunc_strtonum();
void libfunc_sqrt();
void libfunc_cos();
void libfunc_sin();

void avm_registerlibfunc(char *id,library_func_t addr);

typedef char* (*tostring_func_t)(avm_memcell*);

char* number_tostring (struct avm_memcell* m);
char* string_tostring (struct avm_memcell* m);
char* bool_tostring (struct avm_memcell* m);
char* table_tostring (struct avm_memcell* m);
char* userfunc_tostring (struct avm_memcell* m);
char* libfunc_tostring (struct avm_memcell* m);
char* nil_tostring (struct avm_memcell* m);
char* undef_tostring (struct avm_memcell* m);

typedef double (*arithmetic_func_t)(double x, double y);


double add_impl(double x, double y);
double sub_impl(double x, double y);
double mul_impl(double x, double y);
double div_impl(double x, double y);
double mod_impl(double x, double y);

void execute_arithmetic(instruction* instr);

typedef unsigned char (*tobool_func_t)(avm_memcell*);

unsigned char number_tobool(avm_memcell* m);
unsigned char string_tobool(avm_memcell* m);
unsigned char bool_tobool(avm_memcell* m);
unsigned char table_tobool(avm_memcell* m);
unsigned char userfunc_tobool(avm_memcell* m);
unsigned char libfunc_tobool(avm_memcell* m);
unsigned char nil_tobool(avm_memcell* m);
unsigned char undef_tobool(avm_memcell* m);


unsigned char avm_tobool(struct avm_memcell* m);

void libfunc_typeof();

void avm_initialize();

void libfunc_totalarguments();

void readBinary();

int main();