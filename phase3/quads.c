#include "quads.h"

unsigned nextquad(void){
    return currQuad;
}

void emit(enum iopcode op,expr* arg1,expr* arg2,expr* result,unsigned label, unsigned line) {
	quad * p;
	if(currQuad == total){
		expand();
	}
	p=quads + currQuad++;
	p->arg1=arg1;
	p->arg2=arg2;
	p->result=result;
	p->label=label;
	p->line=line;
	p->op=op;
}

struct expr* emit_iftableitem(struct expr* e,int scope,int line){ // vazume extra argument to scope gt to xreiazete h newtemp
	if(e->type != tableitem_e){
		return e;
	}else{
		struct expr* result = newexpr(var_e);
		result->sym = newtemp(scope);
		emit(tablegetelem,e,e->index,result,0,line);
		return result;
	}
}

struct expr* make_call (expr* lv, expr* reversed_elist,int scope,int line) {
	expr* func = emit_iftableitem(lv,scope,line);
	while (reversed_elist) {
		emit(param, reversed_elist, NULL, NULL,0,line);
		reversed_elist = reversed_elist->next;
	}
	emit(call, func,NULL, NULL,0,line);
	expr* result = newexpr(var_e);
	result->sym = newtemp(scope);
	emit(getretval, NULL, NULL, result,0,line);
	return result;
}

void expand(void){
	assert(total==currQuad);
	quad *p=(quad*)malloc(NEW_SIZE);
	if(quads){
		memcpy(p,quads,CURR_SIZE);
		free(quads);
	}
	quads=p;
	total += EXPAND_SIZE;
}

void patchlabel(unsigned quadNo, unsigned label){
    assert(quadNo<currQuad && !quads[quadNo].label);
    quads[quadNo].label = label;
	printf("duadno=%d   label=%d\n",quadNo,quads[quadNo].label);
}

//============26/26 dialeksi 11
void patchlist(int list,int label){
	printf("LIST::::::::::::%d label====%d\n",list,label);
	while(list){
		printf("LIST::::::::::::%d label====%d metatwhile\n",list,label);
		int next=quads[list].label;
		quads[list].label=label;
		list=next;
	}
}

//============26/26 dialeksi 11
struct stmt_t* make_stmt(){
	struct stmt_t* s=(struct stmt_t*)malloc(sizeof(struct stmt_t));
	s->breaklist=0;
	s->contlist=0;
	return s;
}

//============26/26 dialeksi 11
int newlist(int i){
	quads[i].label=0;
	return i;
}

struct List* makelist(unsigned i){
	struct List* l=(struct List*)malloc(sizeof(struct List));
	l->label=i;
	l->next=NULL;
	return l;
}

void backpatch(List* list,unsigned i){
	struct List* l=list;
	while(l){
		quads[l->label].label=i;
		l=l->next;
	}
}

//============26/26 dialeksi 11
int mergelist(int l1,int l2){
	if(!l1){
		return l2;
	}else if(!l2){
		return l1;
	}else{
		int i=l1;
		while(quads[i].label){
			i=quads[i].label;
		}
		quads[i].label=l2;
		return l1;
	}
}

struct List* mergeTrueORFalseList(List *list1,List *list2){
	assert(list1);
	struct List* l1=list1;
	while(list1->next){
		list1=list1->next;
	}
	list1->next=list2;
	return l1;
}

//	forprefix 17/26 11DIALEKSI
struct forprefix* make_prefix(){
	struct forprefix* s=(struct forprefix*)malloc(sizeof(struct forprefix));
	s->test=0;
	s->enter=0;
	return s;
}


struct expr* lvalue_expr(struct Entry* sym){
	assert(sym);
	struct expr* e=(struct expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));

	e->next=(expr*) 0;
	e->sym=sym;

	switch(sym->supersetType){
		case 0	: e->type= var_e; break;
		case 1 	: e->type= programfunc_e; break;
		case 2 	: e->type= libraryfunc_e; break;
		default: assert(0);	
	}
	return e;
}

struct expr* newexpr(expr_t t){
	expr* e= (expr*)malloc(sizeof(expr));
	memset(e,0,sizeof(expr));
	e->type=t;
	return e;
}

struct expr* newexpr_conststring(char* s){
	expr* e= newexpr(conststring_e);
	e->strConst=strdup(s);
	return e;
}

struct expr* exprNumConst(double i){
	struct expr* exp= (struct expr *)malloc(sizeof(expr));
	exp->numConst=i;
	exp->type=constnum_e;
	return exp;
}

struct expr* newexpr_constbool(unsigned int b){
	expr* e= newexpr(constbool_e);
	e->boolConst = !!b;
	return e;
}

struct expr* member_item(struct expr* lv,char* name,int scope,int line){
	lv = emit_iftableitem(lv,scope,line);
	struct expr* ti = newexpr(tableitem_e);
	ti->sym = lv->sym;
	ti->index = newexpr_conststring(name);
	return ti;
}

void check_arith(expr* e){
	expr_t x=e->type;
	if( x==constbool_e||
		x==conststring_e||
		x==nil_e||
		x==programfunc_e||
		x==libraryfunc_e||
		x==boolexpr_e||
		x==newtable_e){
			printf("ERROR::::::: Illegal expr used!");
		}
}





void printArithmetics(int i,char* op){
	if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e){
		printf("%d:\t%s\t\t%s\t\t%f\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->numConst);
	}else if(quads[i].arg1->type==constnum_e){
		printf("%d:\t%s\t\t%s\t\t%f\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->sym->value.varVal->name);
	}else if(quads[i].arg2->type==constnum_e){
		printf("%d:\t%s\t\t%s\t\t%s\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst);
	}else{
		printf("%d:\t%s\t\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name);
	}
}

void printAssign(int i){
	if(quads[i].arg1->type==conststring_e){
		printf("%d:\tassign\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->strConst);
	}else if(quads[i].arg1->type==constbool_e){
		printf("%d:\tassign\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->boolConst!=0 ?"true":"false");
	}else if(quads[i].arg1->type==constnum_e){
		printf("%d:\tassign\t\t%s\t\t%f\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst);
	}else if(quads[i].arg1->type==programfunc_e){
		printf("%d:\tassign\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.funcVal->name);
	}else{
		printf("%d:\tassign\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name);
	}
}

void printUminus(int i){
	if(quads[i].arg1->type==constnum_e){
		printf("%d:\tuminus\t\t%s\t\t%f\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst);
	}else{
		printf("%d:\tuminus\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name);
	}
}

void printNot(int i){
	if(quads[i].arg1->type==constnum_e){
		printf("%d:\tnot\t\t%s\t\t%f\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst);
	}else{
		printf("%d:\tnot\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name);
	}//	DIF to check na dume pws dulevei to not !
}

void printIf_greatereq(int i){
	if(quads[i].arg1->type==constnum_e){
		printf("%d:\tif_greatereq\t\t%s\t\t%f\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst);
	}else{
		printf("%d:\tif_greatereq\t\t%s\t\t%s\n",i+1,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name);
	}
}

void printRelop(int i,char* op){
	if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e){
		if(op=="if_less")
		printf("%d:\t%s\t\t\t\t%f\t%f\t%d\n",i+1,op,quads[i].arg1->numConst,quads[i].arg2->numConst);
		else
		printf("%d:\t%s\t\t\t%f\t%f\t%d\n",i+1,op,quads[i].arg1->numConst,quads[i].arg2->numConst);		
	}else if(quads[i].arg1->type==constnum_e){
		if(op=="if_less")
		printf("%d:\t%s\t\t\t\t%f\t%s\t\t%d\n",i+1,op,quads[i].arg1->numConst,quads[i].arg2->sym->value.varVal->name,quads[i].label);
		else
		printf("%d:\t%s\t\t\t%f\t%s\t\t%d\n",i+1,op,quads[i].arg1->numConst,quads[i].arg2->sym->value.varVal->name,quads[i].label);
	}else if(quads[i].arg2->type==constnum_e){
		if(op=="if_less")
			printf("%d:\t%s\t\t\t\t%s\t\t%f\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst,quads[i].label);
		else
			printf("%d:\t%s\t\t\t%s\t\t%f\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst,quads[i].label);
	}else{
		if(op=="if_less")
		printf("%d:\t%s\t\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name,quads[i].label);
		else 
		printf("%d:\t%s\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name,quads[i].label);
	}
}

void printBoolop(int i,char* op){
	if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
		printf("%d:\t%s\t\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->boolConst?"true":"false",quads[i].arg2->boolConst?"true":"false");
	}else if(quads[i].arg1->type==constbool_e){
		printf("%d:\t%s\t\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->boolConst?"true":"false",quads[i].arg2->sym->value.varVal->name);
	}else if(quads[i].arg2->type==constbool_e){
		printf("%d:\t%s\t\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->boolConst?"true":"false");
	}else{
		printf("%d:\t%s\t\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name);
	}
}

void printIf(int i,char* op){
	if(quads[i].arg1->type==constbool_e && quads[i].arg2->type==constbool_e){
		printf("%d:\t%s\t\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->boolConst?"true":"false",quads[i].arg2->boolConst?"true":"false",quads[i].label);
	}else if(quads[i].arg1->type==constbool_e){
		printf("%d:\t%s\t\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->boolConst?"true":"false",quads[i].arg2->sym->value.varVal->name,quads[i].label);
	}else if(quads[i].arg2->type==constbool_e){
		printf("%d:\t%s\t\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->boolConst?"true":"false",quads[i].label);
	}else{
		printf("%d:\t%s\t\t\t\t%s\t\t%s\t\t%d\n",i+1,op,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name,quads[i].label);
	}
}



void printReturnVal(int i,char* op){
	if(op=="return"){
		if(quads[i].result->type==constnum_e){
			printf("%d:\t%s\t\t%f\n",i+1,op,quads[i].result->numConst);
		}else if(quads[i].result->type==conststring_e){
			printf("%d:\t%s\t\t\"%s\"\n",i+1,op,quads[i].result->strConst);
		}else if(quads[i].result->type==constbool_e){
			printf("%d:\t%s\t\t%s\n",i+1,op,quads[i].result->boolConst?"true":"false");
		}else if(quads[i].result->type==nil_e){
			printf("%d:\t%s\t\t%s\n",i+1,op,quads[i].result->strConst);
		}else{
			printf("%d:\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name);
		}
	}else{
		if(quads[i].result->type==constnum_e){
			printf("%d:\t%s\t%f\n",i+1,op,quads[i].result->numConst);
		}else if(quads[i].result->type==conststring_e){
			printf("%d:\t%s\t\"%s\"\n",i+1,op,quads[i].result->strConst);
		}else if(quads[i].result->type==constbool_e){
			printf("%d:\t%s\t%s\n",i+1,op,quads[i].result->boolConst?"true":"false");
		}else if(quads[i].result->type==nil_e){
			printf("%d:\t%s\t%s\n",i+1,op,quads[i].result->strConst);
		}else{
			printf("%d:\t%s\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name);
		}
	}
}

void printParameter(int i,char *op){
	if(quads[i].arg1->type==constnum_e){
		printf("%d:\t%s\t\t%f\n",i+1,op,quads[i].arg1->numConst);
	}else if(quads[i].arg1->type==conststring_e){
		printf("%d:\t%s\t\t\"%s\"\n",i+1,op,quads[i].arg1->strConst);
	}else if(quads[i].arg1->type==constbool_e){
		printf("%d:\t%s\t\t%s\n",i+1,op,quads[i].arg1->boolConst?"true":"false");
	}else{
				printf("%d:\t%s\t\t%s\n",i+1,op,quads[i].arg1->sym->value.varVal->name);

	}
}

void printJump(int i){
	printf("%d:\tjump\t\t\t\t\t\t\t\t%d\n",i+1,quads[i].label);
}

void printTableGetElem(int i,char* op){
	if(quads[i].arg1->type==constnum_e && quads[i].arg2->type==constnum_e){
		printf("%d:\t%s\t%s\t\t%f\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->numConst);
	}else if(quads[i].arg1->type==constnum_e){
		printf("%d:\t%s\t%s\t\t%f\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->sym->value.varVal->name);
	}else if(quads[i].arg2->type==constnum_e){
		printf("%d:\t%s\t%s\t\t%s\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst);
	}else{
		printf("%d:\t%s\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name);
	}
}

void printArg(struct expr* arg){
	//printf("TYPE:::%d\n",arg->type);
	if(!arg){printf("\t\t");return;}
	if(arg->type==constnum_e){
		printf("%f",arg->numConst);
	}else if(arg->type==conststring_e){
		printf("\"%s\"",arg->strConst);
	}else if(arg->type==constbool_e){
		printf("%s",arg->boolConst?"true":"false");
	}else if(arg->type==nil_e){
		printf("NULL");
	}else{	
		printf("%s",arg->sym->value.varVal->name);
	}
}

void printSet(int i,char* op){
	printf("%d:\t%s\t",i+1,op);
	if(op=="assign")printf("\t");
	printArg(quads[i].result);
	printf("\t\t");
	printArg(quads[i].arg1);
	printf("\t\t");
	if(quads[i].arg1->index!=NULL){
		printArg(quads[i].arg1->index);
	}
	else{
		printArg(quads[i].arg2);
	}
	printf("\n");
}



void printTableSetElem(int i,char* op){
	printf("ARG1 %d  ,  ARG2 %d   , ARG3  %d  ....\n",quads[i].arg1->type,quads[i].arg2->type,quads[i].result->type);
	if(quads[i].arg2->type==constnum_e){
		printf("1\n");
		printf("%d:\t%s\t%s\t\t%f\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->numConst);
		//printf("%d:\t%s\t%s\t\t%s\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst);
	}else if(quads[i].arg2->type==conststring_e){
		printf("2\n");
		printf("%d:\t%s\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->strConst);
		printf("ARG1 %d  ,  ARG2 %d   , ARG3  %d  ....\n",quads[i].arg1->type,quads[i].arg2->type,quads[i].result->type);
	}else{
		printf("3\n");
		printf("%d:\t%s\t%s\t\t%f\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->numConst,quads[i].arg2->sym->value.varVal->name);
	}
}

void printHelpTableGetElem(int i,char* op){
	if(quads[i].arg2->type==constnum_e){
		printf("%d:\t%s\t%s\t\t%s\t\t%f\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->numConst);
	}else if(quads[i].arg2->type==conststring_e){
		printf("%d:\t%s\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->strConst);
	}else{
		printf("%d:\t%s\t%s\t\t%s\t\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name,quads[i].arg1->sym->value.varVal->name,quads[i].arg2->sym->value.varVal->name);
	}
}

void printTableMake(int i,char* op){
		printf("%d:\t%s\t%s\n",i+1,op,quads[i].result->sym->value.varVal->name);
}

void printQuads(){
    int i=0;

	printf("\n-----------------------------------------------------------------------------\n\t\t\tPrinting intermidiate code\n-----------------------------------------------------------------------------\n");
	printf("quad#\topcode\t\tresult\t\targ1\t\targ2\t\tlabel\n-----------------------------------------------------------------------------\n");
    while(i<currQuad){
		if(quads[i].op==assign){printAssign(i);}
		else if(quads[i].op==add){printArithmetics(i,"add");}
		else if(quads[i].op==sub){printArithmetics(i,"sub");}
		else if(quads[i].op==mul){printArithmetics(i,"mul");}
		else if(quads[i].op==divide){printArithmetics(i,"div");}
		else if(quads[i].op==mod){printArithmetics(i,"mod");}
		else if(quads[i].op==uminus){printUminus(i);}
		else if(quads[i].op==and){printBoolop(i,"and");}
		else if(quads[i].op==or){printBoolop(i,"or");}
		else if(quads[i].op==not){printNot(i);}
		else if(quads[i].op==if_eq){printIf(i,"if_eq");}
		else if(quads[i].op==if_noteq){printRelop(i,"if_noteq");}
		else if(quads[i].op==if_lesseq){printRelop(i,"if_lesseq");}
		else if(quads[i].op==if_greatereq){printRelop(i,"if_greatereq");}//idia me to na ftiaxname mia printIFEQ
		else if(quads[i].op==if_less){printRelop(i,"if_less");}
		else if(quads[i].op==if_greater){printRelop(i,"if_greater");}
		else if(quads[i].op==call)printf("%d:\tcall\t\t%s\n",i+1,quads[i].arg1->sym->value.varVal->name);
		else if(quads[i].op==param){printParameter(i,"param");}
		else if(quads[i].op==ret){printReturnVal(i,"return");}
		else if(quads[i].op==getretval){printReturnVal(i,"getretval");}
		else if(quads[i].op==funcstart)printf("%d:\tfuncstart\t%s\n",i+1,quads[i].arg1->sym->value.funcVal->name);
		else if(quads[i].op==funcend)printf("%d:\tfuncend\t\t%s\n",i+1,quads[i].arg1->sym->value.funcVal->name);
		else if(quads[i].op==tablecreate){printTableMake(i,"tablecreate");}
		else if(quads[i].op==tablegetelem){printSet(i,"tablegetelem");}
		else if(quads[i].op==tablesetelem){printSet(i,"tablesetelem");}
		else if(quads[i].op==jump){printJump(i);}
		i++;
	}
	return;
}

