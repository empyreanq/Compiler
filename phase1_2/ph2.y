/*introduction*/

%{
#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>



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
%}

//%define parse.error verbose
//%error-verbose

/*yac definitions*/


%start program


/*dhlwsh termatikwn*/

%token	IF
%token	ELSE
%token	WHILE
%token	FOR
%token	FUNCTION
%token	RETURN 
%token	BREAK
%token	CONTINUE
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
	char* strVal; 
	float fltVal;
	struct Entry* exprNode;
	}

%token<intVal>	INTEGER_C
%token<fltVal>	REAL_C
%token<strVal>	ID

%token<strVal>  STRING

%type<exprNode>   lvalue




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
%nonassoc IF ELSE







%%
/*grammar rules*/

program	:	 stmt_list{printf("\"Grammar\": program | program stmt\n");}
			;

stmt_list 	:	stmt stmt_list
				|/*empty*/
				;

stmt	:	 expr SEMICOLON {printf("\"Grammar\": stmt | expr SEMICOLON\n");}
			|ifstmt {printf("\"Grammar\": stmt | ifstmt\n");}
			|whilestmt {printf("\"Grammar\": stmt | whilestmt\n");}
			|forstmt {printf("\"Grammar\": stmt | forstmt\n");}
			|returnstmt { if(return_in_func == 0){printf("Error, return is not inside function at line %d!\n",yylineno); } printf("\"Grammar\": stmt | returnstmt\n"); }
			|BREAK SEMICOLON {if(break_in_loop == 0){printf("Error, break is used but not in loop at line %d!\n",yylineno);}
			printf("\"Grammar\": stmt | BREAK SEMICOLON\n");}
			|CONTINUE SEMICOLON {if(con_in_loop == 0){printf("Error, continue is used but not in loop at line %d!\n",yylineno);}
			printf("\"Grammar\": stmt | CONTINUE SEMICOLON\n");}
			|block {printf("\"Grammar\": stmt | block\n");}
			|funcdef {printf("\"Grammar\": stmt | funcdef\n");}
			|SEMICOLON {printf("\"Grammar\": stmt | SEMICOLON\n");}
			;

			
expr	:	 assignexpr {printf("\"Grammar\": expr | assignexpr\n");}
			| expr PLUS expr {printf("\"Grammar\": expr | expr PLUS expr\n");}
			| expr MINUS expr {printf("\"Grammar\": expr | expr MINUS expr\n");}
			| expr MULTIPLY expr {printf("\"Grammar\": expr | expr MULTIPLY expr\n");}
			| expr DIVIDE expr {printf("\"Grammar\": expr | expr DIVIDE expr\n");}
			| expr MODULO expr {printf("\"Grammar\": expr | expr MODULO expr\n");}
			| expr GREATER expr {printf("\"Grammar\": expr | expr GREATER expr\n");}
			| expr GREATEREQ expr {printf("\"Grammar\": expr | expr GREATEREQ expr\n");}
			| expr LESS expr {printf("\"Grammar\": expr | expr LESS expr\n");}
			| expr LESSEQ expr {printf("\"Grammar\": expr | expr LESSEQ expr\n");}
			| expr EQUAL expr {printf("\"Grammar\": expr | expr EQUAL expr\n");}
			| expr NOTEQUAL expr {printf("\"Grammar\": expr | expr NOTEQUAL expr\n");}
			| expr AND expr {printf("\"Grammar\": expr | expr AND expr\n");}
			| expr OR expr {printf("\"Grammar\": expr | expr OR expr\n");}
			| term {printf("\"Grammar\": expr | term\n");}
			;

term 	: 	 LEFT_PAR expr RIGHT_PAR {printf("\"Grammar\": term | LEFT_PAR expr RIGHT_PAR\n");}
			|MINUS expr %prec UMINUS {printf("\"Grammar\": term | MINUS expr %prec UMINUS\n");} /*The %prec modifier declares the precedence of a particular rule */
										/*by specifying a terminal symbol whose precedence should be used for that rule. */
										/*It’s not necessary for that symbol to appear otherwise in the rule.*/
			|NOT expr {printf("\"Grammar\": term | NOT expr\n");}
			|PLUSPLUS lvalue {printf("\"Grammar\": term | PLUSPLUS lvalue\n");}
			|lvalue PLUSPLUS {printf("\"Grammar\": term | lvalue PLUSPLUS\n");}
			|MINMIN lvalue {printf("\"Grammar\": term | MINMIN lvalue\n");}
			|lvalue MINMIN {printf("\"Grammar\": term | lvalue MINMIN\n");}
			|primary {printf("\"Grammar\": term | primary \n");}			
			;
			
assignexpr : lvalue ASSIGN expr {printf("\"Grammar\": assignexpr | lvalue\n");}
			;

primary		:	 lvalue {printf("\"Grammar\": primary | lvalue\n");}
				|call {printf("\"Grammar\": primary | call\n");}
				|objectdef {printf("\"Grammar\": primary | objectdef\n");}
				|LEFT_PAR funcdef RIGHT_PAR {printf("\"Grammar\": primary | LEFT_PAR funcdef RIGHT_PAR\n");}
				|const {printf("\"Grammar\": primary | const \n");}
				;



lvalue		:	 ID {printf("\"Grammar\": lvalue | ID\n"); 
					if(scope==0)checkedInsertion(scope,$<strVal>1,yylineno,0,functionvar);
					else checkedInsertion(scope,$<strVal>1,yylineno,1,functionvar); }

				|LOCAL ID {printf("\"Grammar\": lvalue | LOCAL ID\n");checkedInsertion(scope,$<strVal>2,yylineno,1,functionvar);}
				|D_SCOPE ID {printf("\"Grammar\": lvalue | D_SCOPE\n");checkD_Scope($<strVal>2);}
				|member {printf("\"Grammar\": lvalue | MEMBER\n");}
			;

member		:	 lvalue DOT ID {printf("\"Grammar\": member | lvalue DOT ID\n");}
				|lvalue LEFT_SQ expr RIGHT_SQ {printf("\"Grammar\": member | lvalue LEFT_SQ\n");}
				|call DOT ID {printf("\"Grammar\": member | call DOT ID\n");}
				|call LEFT_SQ expr RIGHT_SQ {printf("\"Grammar\": member | call LEFT_SQ expr RIGHT_SQ\n");}
				;

call 		:	 call LEFT_PAR elist RIGHT_PAR {printf("\"Grammar\": call | call LEFT_PAR elist RIGHT_PAR\n");}
				|lvalue callsuffix {printf("\"Grammar\": call | lvalue callsuffix\n");}
				|LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR {printf("\"Grammar\": call | LEFT_PAR funcdef RIGHT_PAR LEFT_PAR elist RIGHT_PAR\n");}
				;

callsuffix	:	 normcall {printf("\"Grammar\": callsuffix | normcall\n");}
				|methodcall {printf("\"Grammar\": callsuffix | methodcall\n");}
				;

normcall	:	 LEFT_PAR elist RIGHT_PAR {printf("\"Grammar\": normcall | LEFT_PAR elist RIGHT_PAR\n");}
				;

methodcall	:	 DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR {printf("\"Grammar\": methodcall | DOUBLE_DOT ID LEFT_PAR elist RIGHT_PAR\n");}
				;

expression	:	 expression COMMA expr
				|expr
				;



elist		:	 expression {printf("\"Grammar\": elist | expr\n");}
				| /* empty */
				;


objectdef	:	 LEFT_SQ elist RIGHT_SQ {printf("\"Grammar\": objectdef | LEFT_SQ elist RIGHT_SQ\n");}
				|LEFT_SQ indexed RIGHT_SQ {printf("\"Grammar\": objectdef | LEFT_SQ indexed RIGHT_SQ\n");}
				;



indexed_list :	 indexed_list COMMA indexedelem
				|indexedelem
				;

indexed 	:	indexed_list{printf("\"Grammar\": indexed | indexedelem\n");}
				;

indexedelem	:	 LEFT_BR expr SCOPE expr RIGHT_BR {printf("\"Grammar\": indexedelem | LEFT_BR expr SCOPE expr RIGHT_BR\n");}
				;





block		:	 LEFT_BR {scope++;} stmt_list RIGHT_BR {hideScope(scope);scope--; 
				if(return_in_func > 0){ return_in_func--;} 
				if(break_in_loop > 0){ break_in_loop--;} if(con_in_loop > 0){con_in_loop--;}
				printf("\"Grammar\": block | LEFT_BR program RIGHT_BR\n");}
				;
				
funcdef		:	 FUNCTION ID{functionvar=1;checkedInsertion(scope,$<strVal>2,yylineno,3,functionvar);} LEFT_PAR idlist RIGHT_PAR {return_in_func++;} block {printf("\"Grammar\": funcdef | FUNCTION ID LEFT_PAR idlist RIGHT_PAR block\n");functionvar=0;}
				|FUNCTION {functionvar=1;aa=malloc(sizeof(int)+4);snprintf(aa,sizeof(int)+4,"$%d",funcounter++);checkedInsertion(scope,aa,yylineno,3,functionvar);} LEFT_PAR idlist RIGHT_PAR {return_in_func++;} block {printf("\"Grammar\": funcdef | FUNCTION LEFT_PAR idlist RIGHT_PAR block\n");functionvar=0;}
				;


const		:	 INTEGER_C {printf("\"Grammar\": const | INTEGER_C\n");}
				|REAL_C {printf("\"Grammar\": const | REAL_C\n");}
				|STRING {printf("\"Grammar\": const | STRING\n");}
				|NIL {printf("\"Grammar\": const | NIL\n");}
				|TRUE {printf("\"Grammar\": const | TRUE\n");}
				|FALSE {printf("\"Grammar\": const | FALSE\n");}
				;

final_idlist :	final_idlist COMMA ID{printf("\"Grammar\": final_idlist | final_idlist COMMA ID\n"); 
				checkedInsertion(scope,$<strVal>3,yylineno,2,functionvar);}
				|ID{printf("\"Grammar\": final_idlist | ID\n");checkedInsertion(scope,$<strVal>1,yylineno,2,functionvar);}
				;

idlist		:	final_idlist{printf("\"Grammar\": idlist | ID\n");}
				| /*empty*/
				;

				
ifstmt		:	 IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt{printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt ELSE stmt\n");}
				|IF LEFT_PAR expr RIGHT_PAR stmt{printf("\"Grammar\": ifstmt | IF LEFT_PAR expr RIGHT_PAR stmt\n");}
				;
				
whilestmt	:	 WHILE LEFT_PAR expr RIGHT_PAR{break_in_loop++; con_in_loop++; } stmt{printf("\"Grammar\": whilestmt | WHILE LEFT_PAR expr RIGHT_PAR stmt\n");}
				;

forstmt 	:	 FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist RIGHT_PAR{break_in_loop++; con_in_loop++; } stmt{printf("\"Grammar\": forstmt | FOR LEFT_PAR elist SEMICOLON expr SEMICOLON elist LEFT_PAR stmt\n");}
				;


returnstmt :  	 RETURN expr SEMICOLON {printf("\"Grammar\": returnstmt | RETURN expr SEMICOLON\n");}
				|RETURN SEMICOLON {printf("\"Grammar\": returnstmt | RETURN SEMICOLON\n");}
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
	return 0;
}




