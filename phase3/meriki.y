/*introduction*/

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "header.h"
#include "quads.h"
#include "temp.h"
#include "scope_offset.h"

unsigned programVarOffset=0;
unsigned functionLocalOffset=0;
unsigned formalArgOffset=0;
unsigned scopeSpaceCounter=1;

quad* quads = (quad*) 0;
unsigned total=0;
unsigned int currQuad=0;


int yylex(void);
int yyerror(char* yaccProvidedMessage); /*kaleitai apo yacc gia na apokalipsei error*/


extern int yylineno;
extern char* yytext;
extern FILE* yyin;
int scope=0;
int funcounter=0;
char *aa;
int return_in_func=0;
int break_in_loop=0;
int con_in_loop=0;
int functionvar=0;
int libflag=0;
char *libflagname;
//if 
int ifprefixflag[100];
int ifprefixcounter=0;
int elseprefixflag[100];
int elseprefixcounter=0;
int returnflag[100];
int returncounter=0;
int scopeforreturn[100];

//loop
int loopcounter=0;
int merikicounter=0;
struct expr* assignexp=NULL;

%}

//%define parse.error verbose
//%error-verbose

/*yac definitions*/


%start program
%expect 1
/*dhlwsh termatikwn*/

%token	IF
%token	ELSE
%token	WHILE
%token	FOR
%token	FUNCTION
%token	RETURN 
%token<strVal>	BREAK
%token<strVal>	CONTINUE
%token	AND
%token	OR
%token	NOT
%token	LOCAL
%token	TRUE
%token	FALSE
%token	NIL
%token	PLUSPLUS
%token	MINMIN
%token	EQUAL
%token	NOTEQUAL
%token	ASSIGN
%token	PLUS
%token	MINUS
%token	MULTIPLY
%token	DIVIDE
%token	MODULO
%token	GREATEREQ
%token	LESSEQ
%token	GREATER
%token	LESS 

%token	LEFT_PAR 
%token	RIGHT_PAR 
%token	LEFT_BR 
%token	RIGHT_BR 
%token	LEFT_SQ 
%token 	RIGHT_SQ 

%token	DOUBLE_DOT
%token	DOT 
%token	D_SCOPE 
%token	SCOPE
%token	SEMICOLON
%token	COMMA


%union { 
	int intVal; 
	unsigned unsign;
	char* strVal; 
	float fltVal;
	struct Entry* exprNode;
	struct expr* expr;
	struct stmt_t* stmt_tt;
	struct forprefix* forprefixx;
	struct{
		struct expr* elist;
		unsigned char method;
		char* name;
	}callee;
	}

%token<intVal>	INTEGER_C
%token<fltVal>	REAL_C
%token<strVal>	ID

%token<strVal>  STRING

%type<expr>  	expr term returnstmt assignexpr lvalue primary const member call funcprefix funcdef elist expression indexed indexed_list indexedelem objectdef
%type<unsign>	whilestart whilecond M N funcbody
%type<stmt_tt>	stmt stmt_list whilestmt loopstmt block program
%type<forprefixx> forprefix
%type<strVal> funcname
%type<callee> callsuffix normcall methodcall

/*seira proteraiothtas kai proseteristikothta*/


%right		ASSIGN
%left		OR
%left		AND 
%nonassoc	EQUAL NOTEQUAL
%nonassoc	GREATER	GREATEREQ LESS	LESSEQ
%left		PLUS MINUS
%left		MULTIPLY DIVIDE MODULO
%right		NOT PLUSPLUS MINMIN UMINUS
%left		DOT	DOUBLE_DOT
%left		LEFT_SQ RIGHT_SQ
%left		LEFT_PAR RIGHT_PAR
%nonassoc 	IF ELSE







%%
/*grammar rules*/

program:	stmt_list{printf("\"Grammar\": program | program stmt\n");}
			|{$$=NULL;}
			;

stmt_list:	stmt_list stmt{
				//printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
				$$->breaklist=mergelist($1->breaklist,$2->breaklist);
				$$->contlist=mergelist($1->contlist,$2->contlist);
				//printf("\"Grammar\": stmt_list | stmt stmt_list\n");
				printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
			}
			|stmt{
				$$=$1;
			}
			//|{$$=NULL;}
			;

/*stmt_list:	stmt stmt_list{
				printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
				$2=make_stmt();
				$$->breaklist=mergelist($2->breaklist,$1->breaklist);
				$$->contlist=mergelist($2->contlist,$1->contlist);
				printf("\"Grammar\": stmt_list | stmt stmt_list\n");
				printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
			}
			|{
			}
			;*/

stmt:		expr SEMICOLON {
				
				if(merikicounter==1){
					struct expr* helper=lvalue_expr(newtemp(scope));;
					emit(assign,newexpr_constbool(1),NULL,helper,0,yylineno);
					backpatch($1->truelist,currQuad);
					emit(jump,NULL,NULL,NULL,currQuad+3,yylineno);
					emit(assign,newexpr_constbool(0),NULL,helper,0,yylineno);
					backpatch($1->falselist,currQuad);
					if(assignexp){
						emit(assign,helper,NULL,assignexp,0,yylineno);
						helper=lvalue_expr(newtemp(scope));
						emit(assign,assignexp,NULL,helper,0,yylineno);
					}
				}
				resettemp();
				$$=make_stmt();
				merikicounter=0;
				assignexp=NULL;
				if(libflag==-2)printf("ERROR :::::: Variable with name : %s is a libfunc!!!!!\nfailed at line : %d\n",libflagname,yylineno);libflag=0;printf("\"Grammar\": stmt | expr SEMICOLON\n");}
			|ifstmt {resettemp();$$=make_stmt();printf("\"Grammar\": stmt | ifstmt\n");}
			|whilestmt{resettemp();$$=make_stmt();printf("\"Grammar\": stmt | whilestmt\n");}
			|forstmt {resettemp();$$=make_stmt();printf("\"Grammar\": stmt | forstmt\n");}
			|returnstmt {resettemp();$$=make_stmt(); if(return_in_func == 0){printf("Error, return is not inside function at line %d!\n",yylineno); } printf("\"Grammar\": stmt | returnstmt\n"); }
			|BREAK SEMICOLON {resettemp();if(break_in_loop == 0){printf("Error, break is used but not in loop at line %d!\n",yylineno);}
				$$=make_stmt();
				$$->breaklist=newlist(currQuad);
				printf("%d\n",currQuad);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				printf("%d\n",currQuad);
				printf("breakLIST::::%d:::::::contlist:::::%d\n",$$->breaklist,$$->contlist);
				printf("\"Grammar\": stmt | BREAK SEMICOLON\n");
			}
			|CONTINUE SEMICOLON {resettemp();if(con_in_loop == 0){printf("Error, continue is used but not in loop at line %d!\n",yylineno);}
				$$=make_stmt();
				$$->contlist=newlist(currQuad);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				printf("\"Grammar\": stmt | CONTINUE SEMICOLON\n");
			}
			|block {resettemp();$$=$1;printf("\"Grammar\": stmt | block\n");}
			|funcdef {resettemp();$$=make_stmt();printf("\"Grammar\": stmt | funcdef\n");}
			|SEMICOLON {resettemp();$$=make_stmt();printf("\"Grammar\": stmt | SEMICOLON\n");}
			;

			
expr:	 	assignexpr {$$=$1;printf("\"Grammar\": expr | assignexpr\n");}
			| expr PLUS expr {$$=newexpr(arithexpr_e);$$->sym=newtemp(scope);emit(add,$1,$3,$$,0,yylineno);printf("\"Grammar\": expr | expr PLUS expr\n");}
			| expr MINUS expr {$$=newexpr(arithexpr_e);$$->sym=newtemp(scope);emit(sub,$1,$3,$$,0,yylineno);printf("\"Grammar\": expr | expr MINUS expr\n");}
			| expr MULTIPLY expr {$$=newexpr(arithexpr_e);$$->sym=newtemp(scope);emit(mul,$1,$3,$$,0,yylineno);printf("\"Grammar\": expr | expr MULTIPLY expr\n");}	//DIF to do slide5/26 diafanies 11
			| expr DIVIDE expr {$$=newexpr(arithexpr_e);$$->sym=newtemp(scope);emit(divide,$1,$3,$$,0,yylineno);printf("\"Grammar\": expr | expr DIVIDE expr\n");}
			| expr MODULO expr {$$=newexpr(arithexpr_e);$$->sym=newtemp(scope);emit(mod,$1,$3,$$,0,yylineno);printf("\"Grammar\": expr | expr MODULO expr\n");}
			| expr GREATER expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_greater,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);	
				printf("\"Grammar\": expr | expr GREATER expr\n");
			}
			| expr GREATEREQ expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_greatereq,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);
				printf("\"Grammar\": expr | expr GREATEREQ expr\n");
			}
			| expr LESS expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_less,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);
				printf("\"Grammar\": expr | expr LESS expr\n");
			}//	DIF ola ta reloop eine copy paste, kalitero error checking
			| expr LESSEQ expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_lesseq,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);
				printf("\"Grammar\": expr | expr LESSEQ expr\n");
			}
			| expr EQUAL expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_eq,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);
				printf("\"Grammar\": expr | expr EQUAL expr\n");
			}
			| expr NOTEQUAL expr {
				merikicounter=1;
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_noteq,$1,$3,$$,0,yylineno);
				//emit(assign,newexpr_constbool(0),NULL,$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);
				//emit(assign,newexpr_constbool(1),NULL,$$,0,yylineno);
				printf("\"Grammar\": expr | expr NOTEQUAL expr\n");
			}
			| expr AND M expr {
				merikicounter=1;
				if($1->truelist==NULL){
					if($4->truelist==NULL){
					$1->truelist=makelist(currQuad);
					$1->falselist=makelist(currQuad+1);
					emit(if_eq,$1,newexpr_constbool(1),$$,0,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);}
					else{
						
					}
				}
				if($4->truelist==NULL){
					$4->truelist=makelist(currQuad);
					$4->falselist=makelist(currQuad+1);
					emit(if_eq,$4,newexpr_constbool(1),$$,0,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);					
				}
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				backpatch($1->truelist,$3);
				$$->truelist=$4->truelist;
				$$->falselist=mergeTrueORFalseList($1->falselist,$4->falselist);
				//emit(and,$1,$4,$$,0,yylineno);
				printf("\"Grammar\": expr | expr AND expr\n");
			}
			| expr OR M expr {
				merikicounter=1;
				if($1->truelist==NULL){
					printf("$1mpika\n");
					$1->truelist=makelist(currQuad);
					$1->falselist=makelist(currQuad+1);
					emit(if_eq,$1,newexpr_constbool(1),$$,0,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					$3=$3+2;
				}
				if($4->truelist==NULL){
					printf("$2mpika\n");
					$4->truelist=makelist(currQuad);
					$4->falselist=makelist(currQuad+1);
					emit(if_eq,$4,newexpr_constbool(1),$$,0,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);					
				}
				$$=newexpr(boolexpr_e);
				//$$->sym=newtemp(scope);
				backpatch($1->falselist,$3);
				$$->truelist=mergeTrueORFalseList($1->truelist,$4->truelist);
				$$->falselist=$4->falselist;
				//emit(or,$1,$4,$$,0,yylineno);
				printf("\"Grammar\": expr | expr OR expr\n");
			}
			| term {
				/*merikicounter=1;
				
				$$=newexpr(boolexpr_e);
				$$->truelist=makelist(currQuad);
				$$->falselist=makelist(currQuad+1);
				emit(if_eq,$1,newexpr_constbool(1),$$,0,yylineno);
				emit(jump,NULL,NULL,NULL,0,yylineno);*/
				$$=$1;
				printf("\"Grammar\": expr | term\n");
			}
			;

term: 	 	LEFT_PAR expr RIGHT_PAR {$$=$2;printf("\"Grammar\": term | LEFT_PAR expr RIGHT_PAR\n");}
			|MINUS expr %prec UMINUS {
				printf("\"Grammar\": term | MINUS expr %prec UMINUS\n");
					check_arith($2);
					$$=newexpr(arithexpr_e);
					$$->sym=newtemp(scope);
					emit(uminus,$2,NULL,$$,0,yylineno);
			} /*The %prec modifier declares the precedence of a particular rule */
										/*by specifying a terminal symbol whose precedence should be used for that rule. */
										/*It’s not necessary for that symbol to appear otherwise in the rule.*/
			|NOT expr {
				$$=newexpr(boolexpr_e);
				$$->sym=newtemp(scope);
				$$->truelist=$2->falselist;
				$$->falselist=$2->truelist;
				emit(not,$2,NULL,$$,0,yylineno);
				printf("\"Grammar\": term | NOT expr\n");
			}
			|PLUSPLUS lvalue {
				check_arith($2);
				if($2->type==tableitem_e){}
				else{
					emit(add,$2,exprNumConst(1),$2,0,yylineno);
					$$=newexpr(arithexpr_e);
					$$->sym=newtemp(scope);
					emit(assign,$2,NULL,$$,0,yylineno);
				}
				printf("\"Grammar\": term | PLUSPLUS lvalue\n");
			}
			|lvalue PLUSPLUS {
				check_arith($1);
				$$=newexpr(var_e);
				$$->sym=newtemp(scope);
				if($$->type==tableitem_e){}
				else{
					emit(assign,$1,NULL,$$,0,yylineno);
					emit(add,$1,exprNumConst(1),$1,0,yylineno);
				}
				printf("\"Grammar\": term | lvalue PLUSPLUS\n");
			}
			|MINMIN lvalue {
				check_arith($2);
				if($2->type==tableitem_e){}
				else{
					emit(sub,$2,exprNumConst(1),$2,0,yylineno);
					$$=newexpr(arithexpr_e);
					$$->sym=newtemp(scope);
					emit(assign,$2,NULL,$$,0,yylineno);
				}
				printf("\"Grammar\": term | MINMIN lvalue\n");
			}
			|lvalue MINMIN {
				check_arith($1);
				$$=newexpr(var_e);
				$$->sym=newtemp(scope);
				if($$->type==tableitem_e){}
				else{
					emit(assign,$1,NULL,$$,0,yylineno);
					emit(sub,$1,exprNumConst(1),$1,0,yylineno);
				}
				printf("\"Grammar\": term | lvalue MINMIN\n");
			}
			|primary {$$=$1;printf("\"Grammar\": term | primary \n");}			
			;
			
assignexpr: lvalue ASSIGN expr {
				//isws elenxos gia an eine sunartiseis 		DIFFF
				if($1->type == tableitem_e){
					emit(tablesetelem,$1->index,$3,$1,0,yylineno);
					$$=emit_iftableitem($1,scope,yylineno);
					$$->type=assignexpr_e;
				}else{
					if(merikicounter==1){
						assignexp=$1;
						$$=$3;
					}else{
						emit(assign,$3,NULL,$1,0,yylineno);
						$$=lvalue_expr(newtemp(scope));
						$$->type=assignexpr_e; // $$=lvalue_expr(newtemp(scope)); h auto den kserw DIFFF
						//$$->sym=newtemp(scope);
						emit(assign,$1,NULL,$$,0,yylineno);
					}
				}
				/*emit(assign,$3,NULL,$1,0,yylineno);
				$$=lvalue_expr(newtemp(scope));				AUTO EIXAME PRIN PROS8ESW TA TABLE DIFFFF!!!!
				$$->type=assignexpr_e;
				emit(assign,$1,NULL,$$,0,yylineno);*/
				printf("\"Grammar\": assignexpr | lvalue ASSIGN expr\n");}
			;

primary:	lvalue {
				$$=emit_iftableitem($1,scope,yylineno);
				printf("\"Grammar\": primary | lvalue\n");
			}
			|call {printf("\"Grammar\": primary | call\n");}
			|objectdef {printf("\"Grammar\": primary | objectdef\n");}
			|LEFT_PAR funcdef RIGHT_PAR {$$=newexpr(programfunc_e);$$=$2;printf("\"Grammar\": primary | LEFT_PAR funcdef RIGHT_PAR\n");}
			|const {printf("\"Grammar\": primary | const \n");}
			;


lvalue:	 	ID {
				printf("$1=%s\n",$1);
				printf("\"Grammar\": lvalue | ID\n");
				struct Entry* x=lookUp($<strVal>1);
				if(x==NULL){
					$$=lvalue_expr(checkedInsertion(scope,$<strVal>1,yylineno,(scope==0)?0:1,functionvar));
					inccurroffset();
				}
				else {
					$$=lvalue_expr(x);
					inccurroffset();
				}
				/*
				}// prepei na bei periptwsh gia na uparxei to symbol wste na epistrefume ekeino. h na to dinume sthn lvalue_expre
				if(scope==0){
					libflag=checkedInsertion(scope,$<strVal>1,yylineno,0,functionvar);
				}
				else {
					libflag=checkedInsertion(scope,$<strVal>1,yylineno,1,functionvar);
				}
				if(libflag==-1){
						printf("failed at line : %d\n",yylineno);}
					else if(libflag==-2)
						libflagname=$<strVal>1;*/
			}

			|LOCAL ID {
				printf("\"Grammar\": lvalue | LOCAL ID\n");
				struct Entry* x=lookUp($<strVal>2);
				if(x==NULL){
					$$=lvalue_expr(checkedInsertion(scope,$<strVal>2,yylineno,(scope==0)?0:5,functionvar));
					inccurroffset();
				}
				else {
					$$=lvalue_expr(x);
					inccurroffset();
				}
				/*printf("\"Grammar\": lvalue | LOCAL ID\n");
				if(lookUpScope($<strVal>1,scope)==NULL){
					checkedInsertion(scope,$<strVal>1,yylineno,0,functionvar);
					inccurroffset();
				}
				if(scope==0){
					if(checkedInsertion(scope,$<strVal>2,yylineno,0,functionvar)==-1){
						printf("failed at line : %d\n",yylineno);
					}
				}else{
					libflag=checkedInsertion(scope,$<strVal>2,yylineno,5,functionvar);
					if(libflag==-1){
						printf("failed at line : %d\n",yylineno);
					}else if(libflag==-2)
						libflagname=$<strVal>2;
				}
			*/}
			
			|D_SCOPE ID {
				printf("\"Grammar\": lvalue | D_SCOPE\n");
				$$=lvalue_expr(checkD_Scope($<strVal>2)); // isws xreiastei inccurroffset++!!!
			}

			|member {$$=$1;
				printf("\"Grammar\": lvalue | MEMBER\n");}
			;

member:	 	lvalue DOT ID {
				$$=member_item($1,$3,scope,yylineno);	
				$$->type=tableitem_e;
				printf("\"Grammar\": member | lvalue DOT ID\n");
			}
			|lvalue LEFT_SQ expr RIGHT_SQ {
				$1=emit_iftableitem($1,scope,yylineno);
				$$=newexpr(tableitem_e);
				$$->sym=$1->sym;
				$$->index=$3;
				printf("\"Grammar\": member | lvalue LEFT_SQ\n");
			}
			|call DOT ID {
				printf("\"Grammar\": member | call DOT ID\n");
			}
			|call LEFT_SQ expr RIGHT_SQ {
				printf("\"Grammar\": member | call LEFT_SQ expr RIGHT_SQ\n");
			}
			;

call:	 	call LEFT_PAR elist RIGHT_PAR {
				printf("\"Grammar\": call | call LEFT_PAR elist RIGHT_PAR\n");
				$$=make_call($1,$3,scope,yylineno);	
				
			}
			|lvalue callsuffix {
				printf("\"Grammar\": call | lvalue callsuffix\n");
				$1=emit_iftableitem($1,scope,yylineno);
				if($2.method){
					expr *t=$1;
					$1=emit_iftableitem(member_item(t,$2.name,scope,yylineno),scope,yylineno);
					$2.elist->next=t;
				}	
				$$=make_call($1,$2.elist,scope,yylineno);
				
			}
			|LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR {
				printf("\"Grammar\": call | LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR\n");
				expr *func = newexpr(programfunc_e);
				func->sym=$2->sym;
				$$=make_call(func,$5,scope,yylineno);	
				
			}
			;

callsuffix:	normcall {$$=$1;printf("\"Grammar\": callsuffix | normcall\n");}
			|methodcall {$$=$1;printf("\"Grammar\": callsuffix | methodcall\n");}
			;

normcall:	LEFT_PAR elist RIGHT_PAR {
				printf("\"Grammar\": normcall | LEFT_PAR elist RIGHT_PAR\n");
				$$.elist=$2;
				$$.method=0;
				$$.name=NULL;

			}
			;

methodcall:	DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR {
				printf("\"Grammar\": methodcall | DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR\n");
				$$.elist=$4;
				$$.method=1;
				$$.name=$2;
			}
			;

expression:	expression COMMA expr{
				assert($1!=NULL && $3!=NULL);	
				struct expr* t = $1;
				while(t->next){
					t=t->next;
				}
				t->next=$3;
				$$=$1;
				//$3->next=$1;$$=$3;
				printf("\"Grammar\": expression | expression COMMA expr\n");}
			|expr{				
				if($1){$$=$1;}
				printf("\"Grammar\": expression | expr\n");}
			;



elist:	 	expression {printf("\"Grammar\": elist | expr\n");}
			| /* empty */{$$=NULL;printf("\"Grammar\": elist | empty\n");}
			;


objectdef:	LEFT_SQ elist RIGHT_SQ {
				struct expr* t=newexpr(newtable_e);
				t->sym=newtemp(scope);
				emit(tablecreate,NULL,NULL,t,0,yylineno); // isws adi gia 0 thelei currQuad DIFF
				for(int x=0;$2;$2=$2->next){emit(tablesetelem,exprNumConst(x++),$2,t,0,yylineno);}// isws adi gia 0 thelei currQuad DIFF
				$$=t;
				printf("\"Grammar\": objectdef | LEFT_SQ elist RIGHT_SQ\n");
			}
			|LEFT_SQ indexed RIGHT_SQ {
				struct expr* t=newexpr(newtable_e);
				t->sym=newtemp(scope);
				emit(tablecreate,NULL,NULL,t,0,yylineno);
				for(int x=0;$2;$2=$2->next){emit(tablesetelem,$2,t->index,t,0,yylineno);}// isws adi gia 0 thelei currQuad DIFF
				$$=t;
				printf("\"Grammar\": objectdef | LEFT_SQ indexed RIGHT_SQ\n");
			}
			;



indexed_list:	indexed_list COMMA indexedelem{
					assert($1!=NULL && $3!=NULL);
					struct expr* t = $1;
					while(t->next){
						t=t->next;
					}
					t->next=$3;
					$$=$1;
				}
				|indexedelem{$$=$1;}
				;

indexed:		indexed_list{printf("\"Grammar\": indexed | indexedelem\n");}
				;

indexedelem:	LEFT_BR expr SCOPE expr RIGHT_BR {
					$$=$2;
					$$->index=$4;
					printf("\"Grammar\": indexedelem | LEFT_BR expr SCOPE expr RIGHT_BR\n");}
				;





block:	 LEFT_BR {scope++;} stmt_list RIGHT_BR {
				$$=$3;
				hideScope(scope);scope--; 
				printf("\"Grammar\": block | LEFT_BR program RIGHT_BR\n");}
				;

funcname:	ID{$$=$1;printf("\"Grammar\": funcame | ID\n");}
			|{printf("\"Grammar\": funcame | empty\n");aa=malloc(sizeof(int)+4);
				snprintf(aa,sizeof(int)+4,"_f%d",funcounter++);
				$$=aa;
			}
			;

funcprefix:	FUNCTION funcname{
				printf("\"Grammar\": funcprefix | FUNCTION funcname\n");
				functionvar=1;
				struct Entry* x=checkedInsertion(scope,$<strVal>2,yylineno,3,functionvar);
				if(x==NULL){
					printf("failed at line : %d - Exiting the program. \n",yylineno);YYABORT;
				}else {
					$$=lvalue_expr(x);
					//$$.iaddress=currquad;
					emit(funcstart,$$,NULL,NULL,0,yylineno);
					//push(scopeoffsetstack,currscopeoffset());
					enterscopespace();
					resetformalargoffset();
				}
			}
			;

funcargs:	LEFT_PAR idlist RIGHT_PAR{
				printf("\"Grammar\": funcargs | LEFT_PAR idlist RIGHT_PAR\n");
				enterscopespace();
				printf("hey\n");
				resetfunctionlocalsoffset();
				return_in_func++;
			}
			;

funcbody: 	block{
				printf("\"Grammar\": funcbody | block\n");
				$$=currscopeoffset();
				exitscopespace();
				return_in_func--;
				functionvar=0;
			}
			;

funcdef:	funcprefix funcargs funcbody{
									printf("\"Grammar\": funcdef | FUNCTION ID LEFT_PAR idlist RIGHT_PAR block\n");
				exitscopespace();
				//$1.totalLocals=$3;
				//int offset=pop_and_top(scopeoffsetStack);
				//restorecurrscopeoffset(offset);
				$$=$1;
				emit(funcend,$1,NULL,NULL,0,yylineno);
				printf("scopeinfuncdef=%d\n",scope);
				for(int ii=0;ii<returncounter;ii++){
					if(scopeforreturn[ii]==(scope+1))
					{patchlabel(returnflag[ii],currQuad);returnflag[ii]=0;scopeforreturn[ii]=0;printf("scopeinfuncdef=%d\n",scope);}
				}
				/*if(returnflag[returncounter]!=0){
					patchlabel(returnflag[returncounter],currQuad);
					returnflag[returncounter]=0;
					returncounter--;
				}*/
			}
			;
/*
funcdef:	FUNCTION ID{
				functionvar=1;
				struct Entry* x=checkedInsertion(scope,$<strVal>2,yylineno,3,functionvar);
				if(x==NULL){
					printf("failed at line : %d\n",yylineno);}
				} LEFT_PAR idlist RIGHT_PAR {return_in_func++;} block {
					if(return_in_func > 0){
						 return_in_func--;
					} 
					printf("\"Grammar\": funcdef | FUNCTION ID LEFT_PAR idlist RIGHT_PAR block\n");
					functionvar=0;
				}
				|FUNCTION {
					functionvar=1;
					aa=malloc(sizeof(int)+4);
					snprintf(aa,sizeof(int)+4,"$f%d",funcounter++);
					struct Entry* x=checkedInsertion(scope,aa,yylineno,3,functionvar);
					if(x==NULL){
						printf("failed at line : %d\n",yylineno);
					}
				} LEFT_PAR idlist RIGHT_PAR {return_in_func++;} block {
					if(return_in_func > 0){ 
						return_in_func--;
					} 
					printf("\"Grammar\": funcdef | FUNCTION LEFT_PAR idlist RIGHT_PAR block\n");
					functionvar=0;
				}
				;*/

const:	 		INTEGER_C {
					$$=exprNumConst($1);
					printf("\"Grammar\": const | INTEGER_C\n");
				}
				|REAL_C {$$=exprNumConst($1);printf("\"Grammar\": const | REAL_C\n");}
				|STRING {$$=newexpr_conststring($1);printf("\"Grammar\": const | STRING\n");}
				|NIL {$$=newexpr(nil_e);printf("\"Grammar\": const | NIL\n");}//make newexprNULL
				|TRUE {$$=newexpr_constbool(1);printf("\"Grammar\": const | TRUE\n");}
				|FALSE {$$=newexpr_constbool(0);printf("\"Grammar\": const | FALSE\n");}
				;
				

final_idlist:	final_idlist COMMA ID{
					printf("\"Grammar\": final_idlist | final_idlist COMMA ID\n"); 
					if(checkedInsertion(scope,$<strVal>3,yylineno,2,functionvar)==NULL){
						printf("failed at line : %d\n",yylineno);
					}
				}
				|ID{
					printf("\"Grammar\": final_idlist | ID\n");
					if(checkedInsertion(scope,$<strVal>1,yylineno,2,functionvar)==NULL){
						printf("failed at line : %d\n",yylineno);
					}
				}
				;

idlist:			final_idlist{printf("\"Grammar\": idlist | ID\n");}
				| /*empty*/
				;

ifprefix:		IF LEFT_PAR expr RIGHT_PAR{ 
					emit(if_eq,$3,newexpr_constbool(1),NULL,currQuad+3,yylineno);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					ifprefixflag[ifprefixcounter++]=currQuad-1;
				};

elseprefix:		ELSE{
					emit(jump,NULL,NULL,NULL,0,yylineno);
					elseprefixflag[elseprefixcounter++]=currQuad-1;
				};

ifstmt:	 		ifprefix stmt{	
					patchlabel(ifprefixflag[--ifprefixcounter],currQuad+1);
					printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt\n");}
				
				|ifprefix stmt elseprefix stmt{
					patchlabel(ifprefixflag[--ifprefixcounter],elseprefixflag[elseprefixcounter-1]+2);
					patchlabel(elseprefixflag[--elseprefixcounter],currQuad+1);
					printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt\n");
				};
				

loopstart:		/*empty*/{++loopcounter;
				printf("\"Grammar\": loopstart | loopstart\n");
				};

loopend:		/*empty*/{--loopcounter;
				printf("\"Grammar\": loopend | loopend\n");
				};

loopstmt:		loopstart stmt loopend{$$=$2;
				printf("\"Grammar\": loopstmt | loopstmt\n");
				};
				
whilestart:		WHILE{$$=currQuad+1;
				printf("currQUAD:::::::%d\n",currQuad);
				printf("\"Grammar\": whilestart | whilestart\n");
				};

whilecond:		LEFT_PAR expr RIGHT_PAR{
					emit(if_eq,$2,newexpr_constbool(1),NULL,currQuad+3,yylineno);
					$$=currQuad;
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": whilecond | whilecond\n");
				};

whilestmt:		whilestart whilecond{break_in_loop++; con_in_loop++; } loopstmt{
					if(con_in_loop > 0){con_in_loop--;}if(break_in_loop > 0){ break_in_loop--;}
					emit(jump,NULL,NULL,NULL,$1,yylineno);
					patchlabel($2,currQuad+1);
					printf("!!!!!!!!!!!!!11edw to kalo to patch:::::::%d int\n",currQuad);
					//$$=$4;
					patchlist($4->breaklist,currQuad+1);
					patchlist($4->contlist,$1);
					printf("\"Grammar\": whilestmt | whilestart whilecond loopstmt\n");
				};

//whilestmt:		whilee LEFT_PAR expr RIGHT_PAR loopstmt{printf("\"Grammar\": whilee LEFT_PAR expr RIGHT_PAR loopstmt\n");};


//	AUTO EFTIAXNA GIA TI FOR ALLA DEN TO XW PROXWRHSEI !!!!!!!!			DIF
N:			{$$=currQuad;emit(jump,NULL,NULL,NULL,0,yylineno);}

M:			{$$=currQuad+1;}

forprefix:	FOR LEFT_PAR elist SEMICOLON M expr SEMICOLON
			{
				$$=make_prefix();
				$$->test=$5;
				$$->enter=currQuad;
				emit(if_eq,$6,newexpr_constbool(1),NULL,0,yylineno);
			}

forstmt:	forprefix N elist RIGHT_PAR{break_in_loop++; con_in_loop++; } N stmt{
				if(break_in_loop > 0){ break_in_loop--;}if(con_in_loop > 0){con_in_loop--;}
				printf("\"Grammar\": forstmt | FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist LEFT_PAR stmt\n");
			} N {
				patchlabel($1->enter,$6+2);
				patchlabel($2,currQuad+1);
				patchlabel($6,$1->test);
				patchlabel($9,$2+2);

				patchlist($7->breaklist,currQuad+1);
				patchlist($7->contlist,$2+2);
			};


returnstmt:  	 RETURN expr SEMICOLON {
					
					emit(ret,NULL,NULL,$2,0,yylineno);
					returnflag[returncounter]=currQuad;
					scopeforreturn[returncounter++]=scope;
					printf("scopeinreturn=%d\n",scope);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": returnstmt | RETURN expr SEMICOLON\n");
				}
				|RETURN SEMICOLON {
					
					emit(ret,NULL,NULL,NULL,0,yylineno);
					returnflag[returncounter]=currQuad;
					scopeforreturn[returncounter++]=scope;printf("scopeinreturn=%d\n",scope);
					emit(jump,NULL,NULL,NULL,0,yylineno);
					printf("\"Grammar\": returnstmt | RETURN SEMICOLON\n");
				}
				;




%%


/*conclusion*/

int yyerror(char* yaccProvidedMessage){  /*tin parexoume emeis ston yacc*/

	fprintf(stderr,"%s: at line %d, before token %s\n",yaccProvidedMessage,yylineno,yytext);
	fprintf(stderr,"INPUT NOT VALID\n");

}

int main(int argc, char **argv) {

	
	if(argc >1){
		if(!(yyin = fopen(argv[1],"r"))){
			fprintf(stderr,"Cannot read file: %s\n", argv[1]);
			return 1;
		}
	}
	else
	{
		yyin=stdin;
	}
	libfunctions();
	yyparse(); /*parexetai apo yacc*/
	printRes();
	printQuads();
	return 0;
}




