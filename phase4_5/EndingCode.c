#include "EndingCode.h"


double* numConsts=NULL;
unsigned totalNumConsts=0;
char** stringConsts=NULL;
unsigned totalStringConsts=0;
char** namedLibfuncs=NULL;
unsigned totalNamedLibfuncs=0;
struct userfunc *userFuncs=NULL;
unsigned totalUserFuncs=0;

extern unsigned int currQuad;
extern unsigned programVarOffset;

struct instruction* instructions=(instruction*)0;
unsigned totalIns=0;
unsigned currIns=0;

struct incomplete_jump* ij_head = (incomplete_jump*)0;
unsigned ij_total = 0;

generator_func_t generators[]={
    generate_ASSIGN,
    generate_ADD,
    generate_SUB,
    generate_MUL,
    generate_DIV,
    generate_MOD,
    generate_UMINUS,
    generate_AND,
    generate_OR,
    generate_NOT,
    generate_IF_EQ,
    generate_IF_NOTEQ,
    generate_IF_LESSEQ,
    generate_IF_GREATEREQ,
    generate_IF_LESS,
    generate_IF_GREATER,
    generate_CALL,
    generate_PARAM,
    generate_RETURN,
    generate_GETRETVAL,
    generate_FUNCSTART,
    generate_FUNCEND,
    generate_NEWTABLE,
    generate_TABLEGETELEM,
    generate_TABLESETELEM,
    generate_JUMP
};


void emitIns(instruction ins){
    instruction *i;
    if(currIns==totalIns)expandIns();
    i=instructions + currIns++;
    i->opcode=ins.opcode;
    i->result=ins.result;
    i->arg1=ins.arg1;
    i->arg2=ins.arg2;
    i->srcLine=ins.srcLine;
}

void expandIns(){
    assert(totalIns==currIns);
    instruction* i=(instruction*)malloc(NEW_SIZE_I);
    if(instructions){
        memcpy(i,instructions,CURR_SIZE_I);
        free(instructions);
    }
    instructions=i;
    totalIns += EXPAND_SIZE_I;
}


unsigned consts_newstring(char* s){
    if(stringConsts==NULL){
        stringConsts=(char**)malloc(sizeof(char*));
    }else{
        stringConsts=(char**)realloc(stringConsts,sizeof(char*)*(totalStringConsts+1));
    }
    stringConsts[totalStringConsts]=strdup(s);
    return totalStringConsts++;
}

unsigned consts_newnumber(double n){
    if(numConsts==NULL){
        numConsts=(double*)malloc(sizeof(double));
    }else{
        numConsts=(double*)realloc(numConsts,sizeof(double)*(totalNumConsts+1));
    }
    numConsts[totalNumConsts]=n;
    return totalNumConsts++;
}

unsigned libfuncs_newused(const char* s){
    if(namedLibfuncs==NULL){
        namedLibfuncs=(char**)malloc(sizeof(char*));
    }else{
        namedLibfuncs=(char**)realloc(namedLibfuncs,sizeof(char*)*(totalNamedLibfuncs+1));
    }
    namedLibfuncs[totalNamedLibfuncs]=strdup(s);
    return totalNamedLibfuncs++;
}

unsigned userfuncs_newfunc(struct Entry* sym){
    if(userFuncs==NULL){
        
        userFuncs=(struct userfunc*)malloc(sizeof(struct userfunc));
    }else{
        userFuncs=(struct userfunc*)realloc(userFuncs,sizeof(struct userfunc)*(totalUserFuncs+1));
    }
    
    userFuncs[totalUserFuncs].address=sym->iaddress;
    userFuncs[totalUserFuncs].localSize=sym->totalLocals;
    userFuncs[totalUserFuncs].id=strdup(sym->value.funcVal->name);
    return totalUserFuncs++;
}

void make_operand(expr* e,vmarg* arg){
    switch(e->type){
        case var_e:
        case tableitem_e:
        case arithexpr_e:
        case boolexpr_e:
        case assignexpr_e:
        case newtable_e:{
            assert(e->sym);
            arg->val = e->sym->offset;
            switch(e->sym->space){
                case programvar: arg->type = global_a; break;
                case functionlocal: arg->type = local_a; break;
                case formalarg: arg->type = formal_a; break;
            }
            break;
        }
        case constbool_e:{
            arg->val = e->boolConst;
            arg->type = bool_a; break;
        }
        case conststring_e:{
            arg->val = consts_newstring(e->strConst);
            arg->type = string_a;  break;
        }
        case constnum_e:{
            arg->val = consts_newnumber(e->numConst);
            arg->type = number_a; break;
        }
        case nil_e: arg->type=nil_a; break;

        case programfunc_e:{
            arg->type = userfunc_a;
            arg->val = userfuncs_newfunc(e->sym); break;
        }
        case libraryfunc_e:{
            arg->type = libfunc_a;
            arg->val = libfuncs_newused(e->sym->value.funcVal->name); break;
        }
        default: assert(0);
    }
}


void add_incomplete_jump(unsigned instrNo, unsigned iaddress){
    struct incomplete_jump* t=(struct incomplete_jump*)malloc(sizeof(incomplete_jump));
    t->instrNo=instrNo;
    t->iaddress=iaddress;
    if(ij_head==NULL){
        t->next=NULL;
        ij_head=t;
    }else{
        t->next=ij_head;
        ij_head=t;
    }
    ij_total++;
}

void patch_incomplete_jump(){
    struct incomplete_jump* t=ij_head;
    while(t){
        if(t->iaddress==currQuad){
            instructions[t->instrNo].result.val=currIns;
        }else{
            instructions[t->instrNo].result.val=quads[t->iaddress].taddress;
        }
        t=t->next;
    }
}

void generate(vmopcode op,quad* quad){
    struct instruction t;
    t.opcode = op;
    if(quad->arg1!=NULL)make_operand(quad->arg1, &t.arg1);
    else {t.arg1.type=-1;t.arg1.val=(unsigned)(-1);}
    if(quad->arg2!=NULL)make_operand(quad->arg2, &t.arg2);
    else {t.arg2.type=-1;t.arg2.val=(unsigned)(-1);}
    if(quad->result!=NULL)make_operand(quad->result, &t.result);
    else {t.result.type=-1;t.result.val=(unsigned)(-1);}
    quad->taddress = currIns;
    emitIns(t); 
}

void generate_ADD(quad* quad){generate(add_v,quad);}
void generate_SUB(quad* quad){generate(sub_v,quad);}
void generate_MUL(quad* quad){generate(mul_v,quad);}
void generate_DIV(quad* quad){generate(div_v,quad);}
void generate_MOD(quad* quad){generate(mod_v,quad);}


void generate_NEWTABLE(quad* quad){generate(newtable_v,quad);}
void generate_TABLEGETELEM(quad* quad){generate(tablegetelem_v,quad);}
void generate_TABLESETELEM(quad* quad){generate(tablesetelem_v,quad);}
void generate_ASSIGN(quad* quad){generate(assign_v,quad);}
void generate_NOP(){struct instruction t;t.opcode=nop_v;emitIns(t);}


void generate_relational(vmopcode op,quad* quad){
    struct instruction t;
    t.opcode=op;
    make_operand(quad->arg1,&t.arg1);
    make_operand(quad->arg2,&t.arg2);
    t.result.type=label_a;
    if(quad->label<currIns){
        t.result.val=quads[quad->label].taddress;
    }else{
        add_incomplete_jump(currIns,quad->label);
    }
    quad->taddress=currIns;
    emitIns(t);
}

void generate_JUMP(quad* quad){generate_relational(jump_v,quad);}
void generate_IF_EQ(quad* quad){generate_relational(jeq_v,quad);}
void generate_IF_NOTEQ(quad* quad){generate_relational(jne_v,quad);}
void generate_IF_GREATER(quad* quad){generate_relational(jgt_v,quad);}
void generate_IF_GREATEREQ(quad* quad){generate_relational(jge_v,quad);}
void generate_IF_LESS(quad* quad){generate_relational(jlt_v,quad);}
void generate_IF_LESSEQ(quad* quad){generate_relational(jle_v,quad);}

void generate_PARAM(quad* quad){
    quad->taddress=currIns;
    instruction t;
    t.opcode=pusharg_v;
    make_operand(quad->arg1,&t.arg1);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.result.type=-1;
    t.result.val=-1;
    emitIns(t);
}

void generate_CALL(quad* quad){
    quad->taddress=currIns;
    instruction t;
    t.opcode=call_v;
    make_operand(quad->arg1,&t.arg1);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.result.type=-1;
    t.result.val=-1;
    emitIns(t);
}

void generate_GETRETVAL(quad* quad){
    quad->taddress=currIns;
    instruction t;
    t.opcode=assign_v;
    make_operand(quad->result,&t.result);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.arg1.type=retval_a;
    t.arg1.val=-1;
    emitIns(t);
}

void generate_FUNCSTART(quad* quad){
    quad->taddress=currIns;
    instruction t;
    t.opcode=funcenter_v;
    make_operand(quad->arg1,&t.result);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.arg1.type=-1;
    t.arg1.val=-1;
    emitIns(t);
}

void generate_RETURN(quad* quad){
    quad->taddress=currIns;
    instruction t;
    t.opcode=assign_v;
    make_operand(quad->result,&t.arg1);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.result.type=-1;
    t.result.val=-1;
    emitIns(t);

    t.opcode= jump;
    //reset_operand(&t.arg1);
    //reset_operand(&t.arg2);
    t.result.type=label_a;
    emitIns(t);
}

void generate_FUNCEND(quad* quad){
    quad->taddress;
    instruction t;
    t.opcode=funcexit_v;
    make_operand(quad->arg1,&t.result);
    t.arg2.type=-1;
    t.arg2.val=-1;
    t.arg1.type=-1;
    t.arg1.val=-1;
    emitIns(t);
}

void generate_AND(quad* quad){return;}
void generate_OR(quad* quad){return;}
void generate_NOT(quad* quad){return;}

void generate_UMINUS(quad* quad){
    quad->arg2=exprNumConst(-1);
    generate(mul_v,quad);

}


//typedef void (*generator_func_t)(quad*);

void generator(void){
    for(unsigned i=0;i<currQuad;i++){
        (*generators[quads[i].op])(quads+i);
        //printf("quad=%u\n",i+1);
    }
}



void writeBinary(){
    FILE* bw;
    FILE* tw;
    printf("Starting to write the binary File!!!!!!\n");
    unsigned i=0;
    unsigned strlength=0;
    bw=fopen("out.abc","wb");
    tw=fopen("out2.txt","w");
    unsigned magicnumber=13363212;
    fwrite(&magicnumber,sizeof(magicnumber),1,bw);
    fprintf(tw,"magicnumber=%u\n",magicnumber);

    //print global and arrays length

    fwrite(&programVarOffset,sizeof(programVarOffset),1,bw);
    fwrite(&totalStringConsts,sizeof(totalStringConsts),1,bw);
    fwrite(&totalNumConsts,sizeof(totalNumConsts),1,bw);
    fwrite(&totalUserFuncs,sizeof(totalUserFuncs),1,bw);
    fwrite(&totalNamedLibfuncs,sizeof(totalNamedLibfuncs),1,bw);

    fprintf(tw,"programVarOffset=%u\ttotalStringConsts=%u\ttotalNumConsts=%u\ttotalUserFuncs=%u\ttotalNamedLibfuncs=%u\n",programVarOffset,totalStringConsts,totalNumConsts,totalUserFuncs,totalNamedLibfuncs);

    for(i=0;i<totalStringConsts;i++){

        strlength=strlen(stringConsts[i]);
        fwrite(&strlength,sizeof(strlength),1,bw);
        fwrite(stringConsts[i],strlength,1,bw);

        fprintf(tw,"stringConsts[%u]=%s\n",i,stringConsts[i]);

    }

    for(i=0;i<totalNumConsts;i++){

        fwrite(&numConsts[i],sizeof(numConsts[i]),1,bw);

        fprintf(tw,"numConsts[%u]=%f\n",i,numConsts[i]);
    }

    for(i=0;i<totalUserFuncs;i++){
        
        strlength=strlen(userFuncs[i].id);
        fwrite(&userFuncs[i].address,sizeof(userFuncs[i].address),1,bw);
        fwrite(&userFuncs[i].localSize,sizeof(userFuncs[i].localSize),1,bw);
        fwrite(&strlength,sizeof(strlength),1,bw);
        fwrite(userFuncs[i].id,strlength,1,bw);

        fprintf(tw,"userFuncs[%u].address=%u \tuserFuncs[%u].localSize=%u\tuserFuncs[%u].id=%s\n",i,userFuncs[i].address,i,userFuncs[i].localSize,i,userFuncs[i].id);


    }

    for(i=0;i<totalNamedLibfuncs;i++){

        strlength=strlen(namedLibfuncs[i]);
        fwrite(&strlength,sizeof(strlength),1,bw);
        fwrite(namedLibfuncs[i],strlength,1,bw);

        fprintf(tw,"namedLibfuncs[%u]=%s\n",i,namedLibfuncs[i]);
    }


    i=0;
    fwrite(&currIns,sizeof(currIns),1,bw);
    fprintf(tw,"total Instructions:%u\n\n",currIns);
    while(i<currIns){
        
        fwrite(&instructions[i].opcode,sizeof(instructions[i].opcode),1,bw);
        fprintf(tw,"instructions[%u].opcode=%d\n",i,instructions[i].opcode);

        if(!(instructions[i].arg1.type<0||instructions[i].arg1.type>10)){
            fwrite(&instructions[i].arg1.type,sizeof(int),1,bw);
            fwrite(&instructions[i].arg1.val,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].arg1.type=%d\n",i,instructions[i].arg1.type);
            fprintf(tw,"instructions[%u].arg1.val=%u\n",i,instructions[i].arg1.val);
        }else{
            fwrite(&instructions[i].arg1.type,sizeof(int),1,bw);
            fwrite(&instructions[i].arg1.type,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].arg1.type=%d\n",i,instructions[i].arg1.type);
            fprintf(tw,"instructions[%u].arg1.val=%d\n",i,instructions[i].arg1.type);
        }

        if(!(instructions[i].arg2.type<0||instructions[i].arg2.type>10)){
            fwrite(&instructions[i].arg2.type,sizeof(int),1,bw);
            fwrite(&instructions[i].arg2.val,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].arg2.type=%d\n",i,instructions[i].arg2.type);
            fprintf(tw,"instructions[%u].arg2.val=%u\n",i,instructions[i].arg2.val);
        }else{
            fwrite(&instructions[i].arg2.type,sizeof(int),1,bw);
            fwrite(&instructions[i].arg2.type,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].arg2.type=%d\n",i,instructions[i].arg2.type);
            fprintf(tw,"instructions[%u].arg2.val=%d\n",i,instructions[i].arg2.type);
        }

        if(!(instructions[i].result.type<0||instructions[i].result.type>10)){
            fwrite(&instructions[i].result.type,sizeof(int),1,bw);
            fwrite(&instructions[i].result.val,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].result.type=%d\n",i,instructions[i].result.type);
            fprintf(tw,"instructions[%u].result.val=%u\n",i,instructions[i].result.val);
        }else{
            fwrite(&instructions[i].result.type,sizeof(int),1,bw);
            fwrite(&instructions[i].result.type,sizeof(int),1,bw);
            fprintf(tw,"instructions[%u].result.type=%d\n",i,instructions[i].result.type);
            fprintf(tw,"instructions[%u].result.val=%d\n",i,instructions[i].result.type);
        }



        i++;
    }

    fclose(bw);
    fclose(tw);
}
