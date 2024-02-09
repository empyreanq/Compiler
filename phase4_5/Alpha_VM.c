#include "Alpha_VM.h"


double* numConsts=NULL;
unsigned totalNumConsts=0;
char** stringConsts=NULL;
unsigned totalStringConsts=0;
char** namedLibfuncs=NULL;
unsigned totalNamedLibfuncs=0;
struct userfunc *userFuncs=NULL;
unsigned totalUserFuncs=0;

unsigned programVarOffset;

unsigned currIns;

struct instruction* code=(instruction*)0;


struct avm_memcell ax, bx, cx;
struct avm_memcell retval;
unsigned top,topsp;

unsigned char executionFinished=0;
unsigned pc=0;
unsigned currLine=0;
unsigned codesize;

unsigned totalActuals=0;



execute_func_t executeFuncs[]={
	
	execute_assign,
	execute_add,
	execute_sub,
	execute_mul,
	execute_div,
	execute_mod,
	execute_uminus,
	execute_and,
	execute_or,
	execute_not,
	execute_jeq,
	execute_jne,
	execute_jle,
	execute_jge,
	execute_jlt,
	execute_jgt,
	execute_call,
	execute_pusharg,
	execute_funcenter,
	execute_funcexit,
	execute_newtable,
	execute_tablegetelem,
	execute_tablesetelem,
	execute_nop,
	execute_jump
	
};


memclear_func_t memclearFuncs[]={
	
	
	0,
	memclear_string,
	0,
	memclear_table,
	0,
	0,
	0,
	0
	
};


tostring_func_t tostringFuncs[]={
	number_tostring,
	string_tostring,
	bool_tostring,
	table_tostring,
	userfunc_tostring,
	libfunc_tostring,
	nil_tostring,
	undef_tostring
	
	
};



arithmetic_func_t arithmeticFuncs[]={
	add_impl,
	sub_impl,
	mul_impl,
	div_impl,
	mod_impl
};


tobool_func_t toboolFuncs[]={
	number_tobool,
	string_tobool,
	bool_tobool,
	table_tobool,
	userfunc_tobool,
	libfunc_tobool,
	nil_tobool,
	undef_tobool
	
};

char* typeStrings[]={
	"number",
	"string",
	"bool",
	"table",
	"userfunc",
	"libfunc",
	"nil",
	"undef"
	
};

library_func_t libFuncs[]={
    libfunc_print,
    libfunc_input,
    libfunc_objectmemberkeys,
    libfunc_objecttotalmembers,
    libfunc_objectcopy,
    libfunc_totalarguments,
    libfunc_argument,
    libfunc_typeof,
    libfunc_strtonum,
    libfunc_sqrt,
    libfunc_cos,
    libfunc_sin
};


void readBinary(){
    FILE *br;
    unsigned i=0;
    unsigned strlength=0;
    br=fopen("out.abc","rb");

    unsigned magicnumber;
    fread(&magicnumber,sizeof(magicnumber),1,br);
    printf("magicnumber=%u\n",magicnumber);

    fread(&programVarOffset,sizeof(programVarOffset),1,br);
    fread(&totalStringConsts,sizeof(totalStringConsts),1,br);
    fread(&totalNumConsts,sizeof(totalNumConsts),1,br);
    fread(&totalUserFuncs,sizeof(totalUserFuncs),1,br);
    fread(&totalNamedLibfuncs,sizeof(totalNamedLibfuncs),1,br);


    printf("programVarOffset=%u\ttotalStringConsts=%u\ttotalNumConsts=%u\ttotalUserFuncs=%u\ttotalNamedLibfuncs=%u\n",programVarOffset,totalStringConsts,totalNumConsts,totalUserFuncs,totalNamedLibfuncs);

    stringConsts=(char**)malloc(totalStringConsts*sizeof(char*));
    for(i=0;i<totalStringConsts;i++){

        fread(&strlength,sizeof(unsigned),1,br);
        stringConsts[i]=(char*)malloc(strlength*sizeof(char));
        fread(stringConsts[i],strlength,1,br);
        
        printf("stringConsts[%u]=%s\n",i,stringConsts[i]);
    }

    numConsts=(double*)malloc(totalNumConsts*sizeof(double));
    for(i=0;i<totalNumConsts;i++){

        fread(&numConsts[i],sizeof(double),1,br);

        printf("numConsts[%u]=%f\n",i,numConsts[i]);
    }

    userFuncs=(struct userfunc*)malloc(totalUserFuncs*sizeof(struct userfunc));
    for(i=0;i<totalUserFuncs;i++){
        fread(&userFuncs[i].address,sizeof(unsigned),1,br);
        fread(&userFuncs[i].localSize,sizeof(unsigned),1,br);
        fread(&strlength,sizeof(unsigned),1,br);
        userFuncs[i].id=(char*)malloc(strlength*sizeof(char));
        fread(userFuncs[i].id,strlength,1,br);

        printf("userFuncs[%u].address=%u \tuserFuncs[%u].localSize=%u\tuserFuncs[%u].id=%s\n",i,userFuncs[i].address,i,userFuncs[i].localSize,i,userFuncs[i].id);
    }


    namedLibfuncs=(char**)malloc(totalNamedLibfuncs*sizeof(char*));
    for(i=0;i<totalNamedLibfuncs;i++){
        fread(&strlength,sizeof(unsigned),1,br);
        namedLibfuncs[i]=(char*)malloc(strlength*sizeof(char));
        fread(namedLibfuncs[i],strlength,1,br);

        printf("namedLibfuncs[%u]=%s\n",i,namedLibfuncs[i]);

    }

    i=0;
    fread(&currIns,sizeof(unsigned),1,br);
    codesize=currIns;
    printf("total Instructions:%u\n\n",currIns);

    code=(struct instruction*)malloc(currIns*sizeof(struct instruction));
    while(i<currIns){

        fread(&code[i].opcode,sizeof(enum vmopcode),1,br);
        printf("code[%u].opcode=%d\n",i,code[i].opcode);
        
        fread(&code[i].arg1.type,sizeof(int),1,br);
        fread(&code[i].arg1.val,sizeof(int),1,br);

        printf("code[%u].arg1.type=%d\n",i,code[i].arg1.type);
        printf("code[%u].arg1.val=%d\n",i,code[i].arg1.val);

        fread(&code[i].arg2.type,sizeof(int),1,br);
        fread(&code[i].arg2.val,sizeof(int),1,br);
        
        
        printf("code[%u].arg2.type=%d\n",i,code[i].arg2.type);
        printf("code[%u].arg2.val=%d\n",i,code[i].arg2.val);

        fread(&code[i].result.type,sizeof(int),1,br);
        fread(&code[i].result.val,sizeof(int),1,br);

        printf("code[%u].result.type=%d\n",i,code[i].result.type);
        printf("code[%u].result.val=%d\n",i,code[i].result.val);
        
        i++;
    }
}


static void avm_initstack(void){
    top=AVM_STACKSIZE - programVarOffset -1;
    topsp=top;
    for(unsigned i=0;i<AVM_STACKSIZE;i++){
        AVM_WIPEOUT(stack[i]);stack[i].type=undef_m;
    }
}

void avm_tableincrefcounter(struct avm_table* t){
    ++t->refCounter;
}

void avm_tabledecrefcounter(struct avm_table* t){
    assert(t->refCounter>0);
    if(!--t->refCounter)avm_tabledestroy(t);
}

void avm_tablebucketsinit(struct avm_table_bucket** p){
    for(unsigned i=0;i<AVM_TABLE_HASHSIZE;++i){
        p[i]=(struct avm_table_bucket*)0;
    }
}

struct avm_table* avm_tablenew(void){
    struct avm_table* t=(struct avm_table*)malloc(sizeof(struct avm_table));
    AVM_WIPEOUT(*t);

    t->refCounter=t->total=0;
    avm_tablebucketsinit(t->numIndexed);
    avm_tablebucketsinit(t->strIndexed);
    return t;
}

void avm_tablebucketsdestroy(struct avm_table_bucket** p){
    for(unsigned i=0;i<AVM_TABLE_HASHSIZE;++i,++p){
        for(struct avm_table_bucket* b = *p; b;){
            struct avm_table_bucket* del=b;
            b=b->next;
            avm_memcellclear(&del->key);
            avm_memcellclear(&del->value);
            free(del);
        }
        p[i]=(avm_table_bucket*)0;
    }
}

void avm_tabledestroy(struct avm_table* t){
    avm_tablebucketsdestroy(t->strIndexed);
    avm_tablebucketsdestroy(t->numIndexed);
}



struct avm_memcell* avm_translate_operand(vmarg* arg, avm_memcell* reg){
	switch(arg->type){
        case global_a: return &stack[AVM_STACKSIZE-1-(arg->val)];
        case local_a:  return &stack[topsp-(arg->val)];
        case formal_a: return &stack[topsp+AVM_STACKENV_SIZE+1+(arg->val)];
        case retval_a: return &retval;
        case number_a: {
            reg->type = number_m;
            reg->data.numVal = consts_getnumber(arg->val);
            return reg;
        }
        case string_a: {
            reg->type= string_m;
            reg->data.strVal = strdup(consts_getstring(arg->val));
            return reg;
        }
        case bool_a:{
            reg->type = bool_m;
            reg->data.boolVal = arg->val;
            return reg;
        }
        case nil_a:{
            reg->type = nil_m;
            return reg;
        }
        case userfunc_a:{
            reg->type = userfunc_m;
            reg->data.funcVal = arg->val;
            return reg;
        }
        case libfunc_a:{
            reg->type = libfunc_m;
            reg->data.libfuncVal = libfuncs_getused(arg->val);
            return reg;
        }
        default: assert(0);
    }
	
}



void execute_cycle(void){

	
	if(executionFinished){
	return;
	}else if(pc == AVM_ENDING_PC){
			executionFinished=1;

			return;
	}else{
		assert(pc <AVM_ENDING_PC);
		instruction* instr= code + pc;
		assert( (instr->opcode) >= 0 && (instr->opcode <= AVM_MAX_INSTRUCTIONS));
		if(instr->srcLine){
			currLine=instr->srcLine;
		}
        //printf("opcode=%d\n",instr->opcode);
		unsigned oldpc=pc;
		(*executeFuncs[instr->opcode])(instr);
		if(pc == oldpc){
			++pc;
		}
		
		
		return;
		
	}
	
	
}


void avm_memcellclear(struct avm_memcell* m){
	
	if(m->type != undef_m){
		memclear_func_t f= memclearFuncs[m->type];
		if(f){
			(*f)(m);
			
		}
		m->type=undef_m;
	}
	
}

void memclear_string(struct avm_memcell* m){
	
	assert(m->data.strVal);
	//free(m->data.strVal);
	
}


void memclear_table(struct avm_memcell* m){
	
	assert(m->data.tableVal);
	avm_tabledecrefcounter(m->data.tableVal);
	
}

void execute_assign(struct instruction* instr){
	avm_memcell* lv= avm_translate_operand(&instr->result,(avm_memcell*)0);
	avm_memcell* rv=avm_translate_operand(&instr->arg1,&ax);
	//assert( lv && (&stack[N-1] >= lv && lv > &stack[top] || lv== &retval));
	assert(rv);
	avm_assign(lv,rv);
	
	
}


void avm_assign(struct avm_memcell* lv,struct avm_memcell* rv){
	
	if(lv == rv){
		return;
	}
	
	if(lv->type == table_m && rv->type==table_m && lv->data.tableVal==rv->data.tableVal){
		return;
	}
	
	if(rv->type==undef_m){
		avm_warning("assigning from undef content!\n");
		
		
	}
	
	avm_memcellclear(lv);
	memcpy(lv,rv,sizeof(avm_memcell));
	if(lv->type==string_m){
		lv->data.strVal==strdup(rv->data.strVal);
		
	}else if(lv->type==table_m){
		avm_tabledecrefcounter(lv->data.tableVal);
	}
	
}

void execute_call(struct instruction* instr){
	avm_memcell* func=avm_translate_operand(&instr->arg1,&ax);
	assert(func);
	avm_callsaveenvironment();
	
	switch(func->type){
		case userfunc_m:
		pc=func->data.funcVal;
		assert(pc < AVM_ENDING_PC);
		assert(code[pc].opcode==funcenter_v);
		break;
		
		case string_m:
		avm_calllibfunc(func->data.strVal);
		break;
		case libfunc_m:
		avm_calllibfunc(func->data.libfuncVal);
		break;
		
		default:
		{char *s=avm_tostring(func);
		avm_error("call: cannot bind  to function!\n");
		free(s);
		executionFinished=1;}
		
	}
	
	
}

void avm_dec_top(void){
	if(!top){
		
		avm_error("stack overflow\n");
		executionFinished=1;
	}else{
		--top;
	}
	
	
	
}


void avm_push_envvalue(unsigned val){
	
	stack[top].type=number_m;
	stack[top].data.numVal=val;
	avm_dec_top();
	
}


void avm_callsaveenvironment(void){
	
	avm_push_envvalue(totalActuals);
	avm_push_envvalue(pc+1);
	avm_push_envvalue(top + totalActuals + 2);
	avm_push_envvalue(topsp);
	
}

void execute_funcenter(struct instruction* instr){
	
	avm_memcell* func=avm_translate_operand(&instr->result,&ax);
	assert(func);
	assert(pc==func->data.funcVal);
	
	totalActuals=0;
	userfunc* funcinfo=avm_getfuncinfo(pc);
	topsp=top;
	top=top - funcinfo->localSize;
	
}

unsigned avm_get_envvalue(unsigned i){
	assert(stack[i].type==number_m);
	unsigned val=(unsigned)stack[i].data.numVal;
	assert(stack[i].data.numVal== ((double)val));
	return val;
	
	
}


void execute_funcexit(struct instruction* unused){
	unsigned oldtop=top;
	//printf("top=%u pc=%u topsp=%u\n",top,pc,topsp);
	top=avm_get_envvalue(topsp + AVM_SAVEDTOP_OFFSET);
	pc= avm_get_envvalue(topsp + AVM_SAVEDPC_OFFSET);
	topsp= avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
    //printf("top=%u pc=%u topsp=%u\n",top,pc,topsp);

	
	while(++oldtop <= top){
        //printf("two here\n");
		avm_memcellclear(&stack[oldtop]);
	}
}


void avm_calllibfunc(char *id){
	library_func_t f=avm_getlibraryfunc(id);
    
	if(!f){
		//avm_error("unsupported lib func '%s' called!\n",id);
        avm_error("unsupported lib func  called!\n");
		executionFinished=1;
		
	}else{
		topsp=top;
		totalActuals=0;
		(*f)();
		if(!executionFinished){
			execute_funcexit((instruction*)0);
		}
		
	}
	
	
}

unsigned avm_totalactuals(void){
	return avm_get_envvalue(topsp + AVM_NUMACTUALS_OFFSET);
}


struct avm_memcell* avm_getactual(unsigned i){
	
	assert(i < avm_totalactuals());
	return &stack[topsp + AVM_STACKENV_SIZE + 1 + i];
	
}

void libfunc_print(){
	unsigned n=avm_totalactuals();
	for(unsigned i=0; i<n; i++){
        //printf("top=%u pc=%u stack[topsp+AVM_STACKENV_SIZE+1+i]=%u  stack->type=%d\n",top,pc,topsp+AVM_STACKENV_SIZE+1+i,stack[topsp+AVM_STACKENV_SIZE+1+i]);
		char* s=avm_tostring(avm_getactual(i));
        //char* s=strdup(avm_tostring(avm_getactual(i)));
		//puts(s);
		//free(s);
        
        printf("%s",s);
        
	}
	
}

void libfunc_input(){
    return;
}

void libfunc_objectmemberkeys(){return;}
void libfunc_objecttotalmembers(){return;}
void libfunc_objectcopy(){return;}
void libfunc_argument(){return;}
void libfunc_strtonum(){return;}
void libfunc_sqrt(){return;}
void libfunc_cos(){return;}
void libfunc_sin(){return;}




void execute_pusharg(instruction* instr){
	avm_memcell* arg=avm_translate_operand(&instr->arg1,&ax);
	assert(arg);
	
	avm_assign(&stack[top],arg);
	++totalActuals;
	avm_dec_top();
	
}

char* avm_tostring(struct avm_memcell* m){
	assert(m->type >= 0 && m->type<=undef_m);
    //printf("m->type=%d\n",m->type);
	return(*tostringFuncs[m->type])(m);
	
}




double add_impl(double x, double y){return x+y;}
double sub_impl(double x, double y){return x-y;}
double mul_impl(double x, double y){return x*y;}
double div_impl(double x, double y){if(y==(double)0){printf("Division by 0 is prohibited\n");executionFinished=1;return (double)0;}return x/y;}
double mod_impl(double x, double y){if(y==(double)0){printf("Division by 0 is prohibited\n");executionFinished=1;return (double)0;}return ((unsigned)x) % ((unsigned)y);}



void execute_arithmetic(instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*)0);
	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2=avm_translate_operand(&instr->arg2,&bx);
	
	//assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));
    assert(rv1&&rv2);
	if(rv1->type != number_m || rv2->type != number_m){
		avm_error("not a number in arithmetic!\n");
		executionFinished=1;
		
	}else{
		arithmetic_func_t op=arithmeticFuncs[instr->opcode - add_v];
		avm_memcellclear(lv);
		lv->type=number_m;
		lv->data.numVal=(*op)(rv1->data.numVal,rv2->data.numVal);
		
	}
	
	
}

unsigned char number_tobool(struct avm_memcell* m){return m->data.numVal != 0;}
unsigned char string_tobool(struct avm_memcell* m){return m->data.strVal[0] != 0;}
unsigned char bool_tobool(struct avm_memcell* m){return m->data.boolVal != 0;}
unsigned char table_tobool(struct avm_memcell* m){return 1;}
unsigned char userfunc_tobool(struct avm_memcell* m){return 1;}
unsigned char libfunc_tobool(struct avm_memcell* m){return 1;}
unsigned char nil_tobool(struct avm_memcell* m){return 0;}
unsigned char undef_tobool(struct avm_memcell* m){assert(0); return 0;}


unsigned char avm_tobool(struct avm_memcell* m){
	assert(m->type >= 0 && m->type < undef_m);
	return (*toboolFuncs[m->type])(m);
	
}


void execute_jeq(struct instruction* instr){
	
	assert(instr->result.type == label_a);
	avm_memcell* rv1=avm_translate_operand(&instr->arg1,&ax);
	avm_memcell* rv2= avm_translate_operand(&instr->arg2,&bx);
	
	unsigned char result=0;
	
	if(rv1->type ==undef_m || rv2->type == undef_m){
		avm_error("undef involved in equality!\n");
		
	}else if(rv1->type == nil_m || rv2->type==nil_m){
			result=rv1->type == nil_m && rv2->type== nil_m;
	}else if(rv1->type==bool_m || rv2->type== bool_m){
		result = (avm_tobool(rv1) == avm_tobool(rv2));
	
	}else if(rv1->type != rv2->type){
		//avm_error("%s == %s is illegal!\n",typeStrings[rv1->type],typeStrings[rv2->type]);
        avm_error("ERROR");
	}else{
		/*equality check with dispatching*/
	}
	if(!executionFinished && result){
		pc=instr->result.val;
	}
	
	
}


void libfunc_typeof(){
	unsigned n=avm_totalactuals();
	
	if(n!= 1){
		//avm_error("one argument (not %d) expected in 'typeof'!\n",n);
        avm_error("one argument (not ) expected in 'typeof'!\n");
	}else{
		avm_memcellclear(&retval);
		retval.type=string_m;
		retval.data.strVal=strdup(typeStrings[avm_getactual(0)->type]);
	}
	
}

void execute_newtable(struct instruction* instr){
	
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*)0);
	//assert(lv && (&stack[N-1] >= lv && lv > &stack[top] || lv==&retval));
	
	avm_memcellclear(lv);
	
	lv->type=table_m;
	lv->data.tableVal=avm_tablenew();
	avm_tabledecrefcounter(lv->data.tableVal);
}

void execute_tablegetelem(struct instruction* instr){
	avm_memcell* lv=avm_translate_operand(&instr->result,(avm_memcell*)0);
	avm_memcell* t=avm_translate_operand(&instr->arg1,(avm_memcell*)0);
	avm_memcell* i=avm_translate_operand(&instr->arg2,&ax);
	
	//assert(lv && (&stack[N-1] >= lv && lv> &stack[top] || lv == &retval));
	//assert(t && (&stack[N-1] >= t && t>&stack[top]));
	assert(i);
	
	avm_memcellclear(lv);
	lv->type=nil_m;
	
	if(t->type != table_m){
		//avm_error("illegal use of type %s as table!\n",typeStrings[t->type]);
        avm_error("illegal use of type as table!\n");
	}else{
		avm_memcell* content=avm_tablegetelem(t->data.tableVal,i);
		if(content){
			avm_assign(lv,content);
		}else{
			char *ts = avm_tostring(t);
			char *is= avm_tostring(i);
			//avm_warning("%s[%s] not found!\n",ts,is);
            avm_warning("warning not found!\n");
			free(ts);
			free(is);
		}
		
		
	}
	
}

void execute_tablesetelem(struct instruction* instr){
	struct avm_memcell* t=avm_translate_operand(&instr->result,(avm_memcell*)0);
	struct avm_memcell* i=avm_translate_operand(&instr->arg1,&ax);
	struct avm_memcell* c=avm_translate_operand(&instr->arg2,&bx);
	
	//assert(t && (&stack[N-1] >= t && t > stack[top]));
	assert(i && c);
	
	if(t->type != table_m){
		//avm_error("illegal use of type %s as table!\n",typeStrings[t->type]);
        avm_error("illegal use of type as table!\n");
	}else{
		avm_tablesetelem(t->data.tableVal,i,c);
	}
	
}

void avm_initialize(){
	avm_initstack();
	avm_registerlibfunc("print",libfunc_print);
	avm_registerlibfunc("typeof",libfunc_print);
	avm_registerlibfunc("input",libfunc_print);
	avm_registerlibfunc("objectmemberkeys",libfunc_print);
	avm_registerlibfunc("objecttotalmembers",libfunc_print);
	avm_registerlibfunc("objectcopy",libfunc_print);
	avm_registerlibfunc("totalarguments",libfunc_print);
	avm_registerlibfunc("argument",libfunc_print);
	avm_registerlibfunc("strtonum",libfunc_print);
	avm_registerlibfunc("sqrt",libfunc_print);
	avm_registerlibfunc("cos",libfunc_print);
	avm_registerlibfunc("sin",libfunc_print);	
	
}

void avm_registerlibfunc(char *id,library_func_t addr){
    return;
}


void libfunc_totalarguments(){
	unsigned p_topsp= avm_get_envvalue(topsp + AVM_SAVEDTOPSP_OFFSET);
	avm_memcellclear(&retval);
	
	if(!p_topsp){
		avm_error("total arguments called outside a function!\n");
		retval.type=nil_m;
		
	}else{
		retval.type=number_m;
		retval.data.numVal=avm_get_envvalue(p_topsp + AVM_NUMACTUALS_OFFSET);
		
	}
	
}

double	consts_getnumber(unsigned index){return numConsts[index];}
char*	consts_getstring(unsigned index){return stringConsts[index];}
char*	libfuncs_getused(unsigned index){return namedLibfuncs[index];}

library_func_t avm_getlibraryfunc(char* id){
    if(strcmp("print",id)==0)return libFuncs[0];
}

void avm_warning(char* format){
    printf("%s",format);
}

void avm_error(char* format){
    printf("%s",format);
}



void execute_uminus	(struct instruction* i){return;}

void execute_and 	(struct instruction* i){return;}
void execute_or 	(struct instruction* i){return;}
void execute_not 	(struct instruction* i){return;}

void execute_jne	(struct instruction* i){return;}
void execute_jle	(struct instruction* i){return;}
void execute_jge	(struct instruction* i){return;}
void execute_jlt	(struct instruction* i){return;}
void execute_jgt	(struct instruction* i){return;}
void execute_nop	(struct instruction* i){return;}
void execute_jump	(struct instruction* i){return;}


char* number_tostring (struct avm_memcell* m){
    char* string=malloc(sizeof(char)*32);
    sprintf(string,"%.3f",m->data.numVal);
    return string;
}
char* string_tostring (struct avm_memcell* m){
    //char* string=malloc(sizeof(char)*strlen(m->data.strVal)+1);
    //string=strdup(m->data.strVal);
    return strdup(m->data.strVal);
}
char* bool_tostring (struct avm_memcell* m){return "";}
char* table_tostring (struct avm_memcell* m){return "";}
char* userfunc_tostring (struct avm_memcell* m){return "";}
char* libfunc_tostring (struct avm_memcell* m){return "";}
char* nil_tostring (struct avm_memcell* m){return "";}
char* undef_tostring (struct avm_memcell* m){return "";}


struct avm_memcell* avm_tablegetelem(avm_table* table, avm_memcell* index){return (avm_memcell*)0;}
void avm_tablesetelem(avm_table* table,avm_memcell* index, avm_memcell* content){return ;}

struct userfunc* avm_getfuncinfo(unsigned address){return (struct userfunc*)0;}


int main(){
    readBinary();
    avm_initialize();

    while(executionFinished==0){
        execute_cycle();
        //printf("top=%u pc=%u topsp=%u\n",top,pc,topsp);
    }
    return 0;
}