#ifndef ENDINGCODE_H
#define ENDINGCODE_H


#include "header.h"
#include "quads.h"


#define EXPAND_SIZE_I 4
#define CURR_SIZE_I (totalIns*sizeof(instruction))
#define NEW_SIZE_I (EXPAND_SIZE_I*sizeof(instruction) + CURR_SIZE_I)


typedef enum vmopcode{
    assign_v,add_v,sub_v,
    mul_v,div_v,mod_v,
    uminus_v,and_v,or_v,
    not_v,jeq_v,jne_v,
    jle_v,jge_v,jlt_v,
    jgt_v,call_v,pusharg_v,
    funcenter_v,funcexit_v,newtable_v,
    tablegetelem_v,tablesetelem_v,nop_v,
    jump_v
}vmopcode;

typedef enum vmarg_t{
    label_a     =0,
    global_a    =1,
    formal_a    =2,
    local_a     =3,
    number_a    =4,
    string_a    =5,
    bool_a      =6,
    nil_a       =7,
    userfunc_a  =8,
    libfunc_a   =9,
    retval_a    =10
}vmarg_t;

typedef struct vmarg{
    vmarg_t type;
    unsigned val;
}vmarg;

typedef struct instruction{
    vmopcode opcode;
    vmarg result;
    vmarg arg1;
    vmarg arg2;
    unsigned srcLine;
}instruction;

typedef struct userfunc{
    unsigned address;
    unsigned localSize;
    char* id;
}userfunc;



/*double* numConsts=NULL;
unsigned totalNumConsts=0;
char** stringConsts=NULL;
unsigned totalStringConsts=0;
char** namedLibfuncs=NULL;
unsigned totalNamedLibfuncs=0;
struct userfunc *userFuncs=NULL;
unsigned totalUserFuncs=0;

extern unsigned int currQuad;

struct instruction* instructions=(instruction*)0;
unsigned totalIns=0;
unsigned currIns=0;*/
typedef void (*generator_func_t)(quad*);


void emitIns(instruction ins);

void expandIns();


unsigned consts_newstring(char* s);

unsigned consts_newnumber(double n);

unsigned libfuncs_newused(const char* s);

unsigned userfuncs_newfunc(struct Entry* sym);

void make_operand(expr* e,vmarg* arg);

typedef struct incomplete_jump{
    unsigned instrNo;
    unsigned iaddress;
    struct incomplete_jump* next;
}incomplete_jump;

/*struct incomplete_jump* ij_head = (incomplete_jump*)0;
unsigned ij_total = 0;*/

void add_incomplete_jump(unsigned instrNo, unsigned iaddress);

void patch_incomplete_jump();

void generate(vmopcode op,quad* quad);

void generate_ADD(quad* quad);
void generate_SUB(quad* quad);
void generate_MUL(quad* quad);
void generate_DIV(quad* quad);
void generate_MOD(quad* quad);


void generate_NEWTABLE(quad* quad);
void generate_TABLEGETELEM(quad* quad);
void generate_TABLESETELEM(quad* quad);
void generate_ASSIGN(quad* quad);
void generate_NOP();


void generate_relational(vmopcode op,quad* quad);

void generate_JUMP(quad* quad);
void generate_IF_EQ(quad* quad);
void generate_IF_NOTEQ(quad* quad);
void generate_IF_GREATER(quad* quad);
void generate_IF_GREATEREQ(quad* quad);
void generate_IF_LESS(quad* quad);
void generate_IF_LESSEQ(quad* quad);

void generate_PARAM(quad* quad);
void generate_CALL(quad* quad);
void generate_GETRETVAL(quad* quad);

void generate_FUNCSTART(quad* quad);

void generate_RETURN(quad* quad);

void generate_FUNCEND(quad* quad);

void generate_AND(quad* quad);
void generate_OR(quad* quad);
void generate_NOT(quad* quad);

void generate_UMINUS(quad* quad);




void generator(void);


void writeBinary();

#endif