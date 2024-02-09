#include "SymbolTable.h"

struct Entry *scopes[100];
int flagg;

int checkIfLibFunction(const char* name){
    const char *x=name;
    if(x=="print" || x=="input" || x=="objectmemberkeys" 
        || x=="objecttotalmembers" || x=="objectcopy" || x=="totalarguments" 
        || x=="argument" || x=="typeof" || x=="strtonum" || x=="sqrt"
        ||x=="cos" || x=="sin")
        {
            printf("ERROR::::::TO ONOMA %s TU ENTRY EINE ONOMA MIAS LIBFUNC!!!!!",name);
            return 0;
        }else{
            return 1;
        }
}

//  MAKE FUNCTION GIA LOCAL VAR (SLIDE 19)
int checkedInsertionLocalVar(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    if(checkIfLibFunction(name)==0){return -1;}//  LIBFUNC OVERIDE ERROR
    checkedInsertionVariable(scope,name,line,type,isFunction);
    return 0;
}

// MAKE FUNCTION GIA ::X (GLOBAL X) (SLIDE 19)
int checkD_Scope(const char* name){
    struct Entry *tmp=lookUpScope(name,0);
    if(tmp!=NULL){
        printf("VRETHIKE H GLOBAL METAVLITI ME NAME : %s",name);
        return 1;
    }else{
        printf("ERROR:::::: ANAFERESE SE GLOBAL VAR POU DEN UPARXEI!!");
        return 0;
    }
}

struct Entry* checkedInsertionFormal(unsigned int scope,const char* name, unsigned int line,enum SymbolType type){
    if(checkIfLibFunction(name)==0){return NULL;}//  LIBFUNC OVERIDE ERROR
    struct Entry *tmp=lookUpScope(name,scope+1);
    if(tmp!=NULL){
        printf("ERROR:::: CAN'T DEFINE THIS FORMAL VAR CAUSE IT EXIST AS OTHER VAR");
        return tmp;
    }else{
        printf("PUT FORMAL VAR IN SCOPE+1 ");
        InsertAtScope(scope+1,name,line,type);
        return tmp;
    }
}

struct Entry* checkedInsertionFunction(unsigned int scope,const char* name, unsigned int line,enum SymbolType type){
    if(checkIfLibFunction(name)==0){return NULL;}//  LIBFUNC OVERIDE ERROR
    struct Entry *tmp=lookUpScope(name,scope);
    if(tmp==NULL){
        printf("VAR OR FUNC NOT EXIST ME NAME : %s  SO WE PUT IT IN THA TABLE" ,name);
        InsertAtScope(scope,name,line,type);
        return tmp;
    }else{
        printf("VAR OR FUNC : %s ALREADY EXIST IN SCOPE : %d",name,scope);
        return tmp;
    }
}

int checkedInsertionVariable(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    struct Entry *tmp;
    struct Entry *global;
    int flag=0;
    int globalFlag=0;
    int i;
    global=lookUpScope(name,0);
    if(global!=NULL){
        globalFlag=1;
        return 1;//UPARXEI K EINE GLOBAL
    }

    for(i=scope;i>0;i--){
        tmp=lookUpScope(name,i);
        if(tmp!=NULL){
            flag=1;
            break;
        }
    }

    if(flag==0 && globalFlag==0){
        InsertAtScope(scope,name,line,type);
        return 1;
    }else if(globalFlag=1){
        return 0;//IS GLOBAL VAR DO NOTHING
    }else if(globalFlag==0 && flag==1 && isFunction==1){
        printf("ERROR:::::  DEN EINE GLOBAL, VRISKOMASTE SE FUNCTION KAI UPARXEI EIDH SE ALLO SCOPE ");
        return -1;
    }else if(globalFlag==0 && flag==1 && isFunction==0){
        return 0;//IS VAR OF ANOTHER SCOPE(AND NO GLOBAL) SO DO NOTHING
    }
}

int checkedInsertion(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    if(checkIfLibFunction(name)==0){return -1;}//  LIBFUNC OVERIDE ERROR
    if(lookUpScope(name,scope)!=NULL){
        printf("VAR : %s ALREADY EXIST IN SCOPE : %d",name,scope);
    }
    if(type==0){
        InsertAtScope(scope,name,line,type);
        return 0;
    }else if(type==1){
        checkedInsertionLocalVar(scope,name,line,type,isFunction);
        return 0;
    }else if(type==2){
        checkedInsertionFormal(scope,name,line,type);
        return 0;
    }else if(type==3){
        checkedInsertionFunction(scope,name,line,type);
        return 0;
    }else if(type==4){
    }
}


int checkIfVarORFunc(enum SymbolType type){
    if(type==USERFUNC || type==LIBFUNC){
        return 0; // is Function
    }else{
        return 1;
    }
}

int InsertAtScope(unsigned int scope,const char* name, unsigned int line,enum SymbolType type)
{   
        if(lookUpScope(name,scope)!=NULL){
        printf("VAR : %s ALREADY EXIST IN SCOPE : %d\n",name,scope);
        return -1;
    }
    struct Entry *temp=malloc(sizeof(struct Entry));
    int VarFunc=checkIfVarORFunc(type);
    if(VarFunc==1){
        temp->value.varVal=malloc(sizeof(struct Variable));
        temp->value.varVal->scope=scope;
        temp->value.varVal->line=line;
        temp->value.varVal->name=strdup(name);
    }else{
        temp->value.funcVal=malloc(sizeof(struct Function));
        temp->value.funcVal->scope=scope;
        temp->value.funcVal->line=line;
        temp->value.funcVal->name=strdup(name);
    }
    temp->type=type;
    temp->isActive=true;
    temp->next=NULL;

    if(scopes[scope]==NULL){
        scopes[scope]=temp;

    }else{
        struct Entry *tmp2=scopes[scope];
        while(tmp2->next!=NULL){
            tmp2=tmp2->next;
        }
        tmp2->next=temp;
    }
    return 0;
}

void libfunctions(){
    flagg=0;
	InsertAtScope(0,"print",0,4);
	InsertAtScope(0,"input",0,4);
	InsertAtScope(0,"objectmemberkeys",0,4);
	InsertAtScope(0,"objecttotalmembers",0,4);
	InsertAtScope(0,"objectcopy",0,4);
	InsertAtScope(0,"totalarguments",0,4);
	InsertAtScope(0,"argument",0,4);
	InsertAtScope(0,"typeof",0,4);
	InsertAtScope(0,"strtonum",0,4);
	InsertAtScope(0,"sqrt",0,4);
	InsertAtScope(0,"cos",0,4);
	InsertAtScope(0,"sin",0,4);
    flagg=1;
	return;
}

struct Entry* lookUpScope(const char* name,int scope){
    struct Entry *tmp=scopes[scope];
    while(tmp!=NULL){
        if((strcmp(tmp->value.varVal->name,name)==0||strcmp(tmp->value.funcVal->name,name)==0)&& tmp->isActive){
            printf("VRIKAME TO ENTRY ME NAME : %s\n",tmp->value.varVal->name);
            return tmp;
        }else{
            tmp=tmp->next;
        }
    }
    
    return NULL;
}

struct Entry* lookUp(const char* name){
    struct Entry *tmp=scopes[0];
    for(int i=0;i<100;i++){
        if(tmp==NULL){
            tmp=scopes[i+1];
            continue;
        }else{
            struct Entry *getBack=lookUpScope(name,i);
            if(getBack==NULL && getBack->isActive){
                printf("DEN VRE8IKE TO ENTRY ME NAME : %s",name);
                return NULL;
            }else{
                printf("VRIKAME TO ENTRY ME NAME : %s",getBack->value.varVal->name);
                return getBack;
            }
        }
    }
}

void hideScope(int scope){
    struct Entry *tmp=scopes[scope];
    while(tmp!=NULL){
        tmp->isActive=false;
        tmp=tmp->next;
    }
}

void printRes(){
    int i;
    struct Entry *tmp;
    for(i=0;i<100;i++){
        tmp=scopes[i];   
        if(tmp!=NULL)printf("----------------   Scope #%d   ----------------\n",i);
        while(tmp!=NULL){
            if(tmp->type==0)printf("\"%s\" [global variable] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==1)printf("\"%s\" [local variable] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==2)printf("\"%s\" [formal argument] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==3)printf("\"%s\" [user function] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==4)printf("\"%s\" [library function] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            tmp=tmp->next;
        }
        
    }
    return;
}