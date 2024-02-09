%{
#ifdef WIN32
#define YY_NO_UNISTD_H
int isatty (int i) {return 0;}
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#include "parser.h" /*will be generated from parser.y*/


/*#define YY_DECL int alpha_yylex(void *yylval)  zitaei na orisoume aplha_yylex anti yylex kai kaloume auti anti yylex kai yylval einai pointer stin arxi twn tokens mas*/



int yytokenum=0;
int	nested=0;
int startline=0;
char *c;
char *a;

struct alpha_token_t *alphastart;
int intoAlphaStruct(unsigned int numline,unsigned int numToken,char *content,char *classification,char *type);
int printStruct();

struct alpha_token_t {
  unsigned int     numline;
  unsigned int     numToken;
  char          *content;
  char          *type;
  char			*classification;
  struct alpha_token_t *next;
};


int intoAlphaStruct(unsigned int numline,unsigned int numToken,char *content,char* classification,char *type){
	struct alpha_token_t *tmp=malloc(sizeof(struct alpha_token_t));
	tmp->numline=numline;
	tmp->numToken=numToken;
	tmp->content=strdup(content);
	tmp->classification=strdup(classification);
	tmp->type=strdup(type);
	
	tmp->next=NULL;
	if(alphastart==NULL){
		alphastart=tmp;
	}else{
		struct alpha_token_t *tmp2=alphastart;		
		while(tmp2->next!=NULL){
			tmp2=tmp2->next;
			
		}
		tmp2->next=tmp;
	}
	return 0;
}

int printStruct(){
	struct alpha_token_t *tmp=alphastart;
	if(tmp==NULL){
		printf("List is empty\n");
		return 0;
	}
	while(tmp->next!=NULL){
		if(strcmp(tmp->classification,"STRING")==0||strcmp(tmp->classification,"ID")==0){
			printf("%d:  #%d  \"%s\"  %s  \"%s\" %s\n",tmp->numline,tmp->numToken,tmp->content,tmp->classification,tmp->content,tmp->type);
		}else{
			printf("%d:  #%d  \"%s\"  %s  %s\n",tmp->numline,tmp->numToken,tmp->content,tmp->classification,tmp->type);
		}
		tmp=tmp->next;
	}
	if(strcmp(tmp->classification,"STRING")==0||strcmp(tmp->classification,"ID")==0){
		printf("%d:  #%d  \"%s\"  %s  \"%s\"  %s\n",tmp->numline,tmp->numToken,tmp->content,tmp->classification,tmp->content,tmp->type);
	}else{
		printf("%d:  #%d  \"%s\"  %s  %s\n",tmp->numline,tmp->numToken,tmp->content,tmp->classification,tmp->type);
	}
	return 0;
}



%}

/*Flex options*/
%option noyywrap
%option yylineno


/* Flex macros*/

IF			"if"
ELSE		"else"
WHILE		"while"
FOR 		"for"
FUNCTION	"function"
RETURN		"return"
BREAK		"break"
CONTINUE	"continue"
AND			"and"
OR			"or"
NOT			"not"
LOCAL		"local"
TRUE		"true"
FALSE		"false"
NIL			"nil"

	
PLUSPLUS	"++"
MINMIN		"--"
EQUAL		"=="
NOTEQUAL	"!="
ASSIGN		"="
PLUS		"+"
MINUS		"-"
MULTIPLY	"*"
DIVIDE		"/"
MODULO		"%"
GREATEREQ	">="
LESSEQ		"<="
GREATER		">"
LESS		"<"

LEFT_BR		"{"
RIGHT_BR	"}"
LEFT_SQ  	"["
RIGHT_SQ	"]"
LEFT_PAR	"("
RIGHT_PAR	")"
DOUBLE_DOT	".."
DOT			"."
D_SCOPE		"::"
SCOPE		":"
SEMICOLON	";"
COMMA		","
UNDERSCORE	"_"
NEWLINE		"\n" 
SPACE 		[\r \t \v]

ID   		[a-zA-Z][a-zA-Z0-9_]*

INTEGER_C	[0-9]*
REAL_C		[0-9]*[.][0-9]+
STRING 		"\""





 

%x STRINGG 
%x COMMENT
%x BACKSLASH

%%
{IF}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD IF","<-enumerated"); return IF;}
{ELSE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD ELSE","<-enumerated"); return ELSE;}
{WHILE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD WHILE","<-enumerated"); return WHILE;}
{FOR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD FOR","<-enumerated"); return FOR;}
{FUNCTION}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD FUNCTION","<-enumerated"); return FUNCTION;}
{RETURN}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD RETURN","<-enumerated"); return RETURN;}
{BREAK}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD BREAK","<-enumerated"); return BREAK;}
{CONTINUE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD CONTINUE","<-enumerated"); return CONTINUE;}
{AND}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD AND","<-enumerated"); return AND;}
{OR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD OR","<-enumerated"); return OR;}
{NOT}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD NOT","<-enumerated"); return NOT;}
{LOCAL}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD LOCAL","<-enumerated"); return LOCAL;}
{TRUE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD TRUE","<-enumerated"); return TRUE;}
{FALSE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD FALSE","<-enumerated"); return FALSE;}
{NIL}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"KEYWORD NIL","<-enumerated"); return NIL;}

{PLUSPLUS}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR PLUSPLUS","<-enumerated"); return PLUSPLUS;}
{MINMIN}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR MINMIN","<-enumerated"); return MINMIN;}
{EQUAL}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR EQUAL","<-enumerated"); return EQUAL;}
{NOTEQUAL}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR NOTEQUAL","<-enumerated"); return NOTEQUAL;}
{ASSIGN}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR ASSIGN","<-enumerated"); return ASSIGN;}
{PLUS}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR PLUS","<-enumerated"); return PLUS;}
{MINUS}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR MINUS","<-enumerated"); return MINUS;}
{MULTIPLY}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR MULTIPLY","<-enumerated"); return MULTIPLY;}
{DIVIDE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR DIVIDE","<-enumerated"); return DIVIDE;}
{MODULO}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR MODULO","<-enumerated"); return MODULO;}
{GREATEREQ}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR GREATEREQ","<-enumerated"); return GREATEREQ;}
{LESSEQ}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR LESSEQ","<-enumerated"); return LESSEQ;}
{GREATER}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR GREATER","<-enumerated"); return GREATER;}
{LESS}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"OPERATOR LESS","<-enumerated"); return LESS;}

{LEFT_BR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION LEFT_BR","<-enumerated"); return LEFT_BR;}
{RIGHT_BR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION RIGHT_BR","<-enumerated"); return RIGHT_BR;}
{LEFT_SQ}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION LEFT_SQ","<-enumerated"); return LEFT_SQ;}
{RIGHT_SQ}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION RIGHT_SQ","<-enumerated"); return RIGHT_SQ;}
{LEFT_PAR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION LEFT_PAR","<-enumerated"); return LEFT_PAR;}
{RIGHT_PAR}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION RIGHT_PAR","<-enumerated"); return RIGHT_PAR;}
{DOUBLE_DOT}	{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION DOUBLE_DOT","<-enumerated"); return DOUBLE_DOT;}
{DOT}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION DOT","<-enumerated"); return DOT;}
{D_SCOPE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION D_SCOPE","<-enumerated"); return D_SCOPE;}
{SCOPE}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION SCOPE","<-enumerated"); return SCOPE;}
{SEMICOLON}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION SEMICOLON","<-enumerated"); return SEMICOLON;}
{COMMA}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"PUNCTUATION COMMA","<-enumerated"); return COMMA;}

"//".*		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,"","COMMENT LINE_COMMENT","<-enumerated");}    /* to .* simainei oti paei mexri to telos tis grammis logw tou . pou stamataei sto \n kai ektiponei apla to periexomeno*/


{INTEGER_C}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"CONST_INT","<-integer"); yylval.intVal=atoi(yytext); return INTEGER_C;}
{REAL_C}		{yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"REAL_CONST","<-float"); yylval.fltVal=atof(yytext); return REAL_C;}

{ID}        {yytokenum++;intoAlphaStruct(yylineno,yytokenum,yytext,"ID","<-char*"); yylval.strVal=strdup(yytext);  return ID;}




{NEWLINE}  {}
{SPACE}    {}



"/*"					{startline=yylineno;BEGIN(COMMENT);}
<COMMENT>[^*/]*		
<COMMENT>[/]
<COMMENT>"*"+
<COMMENT>"/"+"*"		{nested++;  }
<COMMENT>"*"+"/"		{if(nested > 0) { 
							nested--; 

							a=malloc(sizeof(int));snprintf(a,sizeof(int),"%d",yylineno);

							intoAlphaStruct(yylineno,yytokenum,a,"COMMENT NESTED_BLOCK_COMMENT","<-enumerated");
							free(a);
							BEGIN(COMMENT);}
						else{
						
							yytokenum++; 

							a=malloc(2*sizeof(int)+4);
							snprintf(a,2*sizeof(int)+4,"%d - %d",startline, yylineno);

							intoAlphaStruct(yylineno,yytokenum,a,"COMMENT BLOCK_COMMENT","<-enumerated");
							free(a);
							BEGIN(INITIAL);
						}	
						}

<COMMENT><<EOF>>		{printf("Found error! EOF before comment closed\n");	
						BEGIN(INITIAL); }


{STRING}						{c=(char*)malloc(15);
								strcpy(c,"");
								startline=yylineno;
								BEGIN(STRINGG);}

<STRINGG>"\\"					{BEGIN(BACKSLASH);}

<STRINGG>"\n"					{c=(char*)realloc(c,strlen(c)+3);
									strcat((char*)c,yytext);}

<STRINGG>"\""					{yytokenum++;
									c=(char*)realloc(c,strlen(c)+3);
									strcat((char*)c,"\0");
								intoAlphaStruct(yylineno,yytokenum,c,"STRING","<-char*");
								yylval.strVal=strdup(c);
								strcpy(c,"");
								free(c);
								BEGIN(INITIAL);
								return STRING;
								}

<STRINGG><<EOF>>					{fprintf(stderr, "%s","ERROR, FIND EOF BEFORE STRING TERMINATION\n");
								free(c);
								BEGIN(INITIAL);}

<STRINGG>.						{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,yytext);}

<BACKSLASH>"n"					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\n");BEGIN(STRINGG);}
<BACKSLASH>"t"					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\t");BEGIN(STRINGG);}
<BACKSLASH>"r"					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\r");BEGIN(STRINGG);}
<BACKSLASH>"v"					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\v");BEGIN(STRINGG);}
<BACKSLASH>"\\"					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\\");BEGIN(STRINGG);}
<BACKSLASH>"\""					{c=(char*)realloc(c,strlen(c)+3);strcat((char*)c,"\"");BEGIN(STRINGG);}
<BACKSLASH>.					{fprintf(stderr,"%s","ERROR NOT VALID CHARACTER\n");free(c);exit(0);}


.								{printf("Undefined input %s at line %d\n", yytext, yylineno);}


%%



/*
int main(int argc, char** argv){
	void *yylval;
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
	
	alpha_yylex(yylval);
	printStruct();
	return 0;
}

*/