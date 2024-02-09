#include "SymbolTable.h"

struct Entry *scopes[100];
int flagg;

int checkIfLibFunction(const char* name){
    const char *x=name;
    if(strcmp(x,"print")==0 || strcmp(x,"input")==0 || strcmp(x,"objectmemberkeys")==0
        || strcmp(x,"objecttotalmembers")==0 || strcmp(x,"objectcopy")==0 || strcmp(x,"totalarguments")==0 
        || strcmp(x,"argument")==0 || strcmp(x,"typeof")==0 || strcmp(x,"strtonum")==0 || strcmp(x,"sqrt")==0
        ||strcmp(x,"cos")==0 || strcmp(x,"sin")==0)
        {
            return 0;
        }else{
            return 1;
        }
}

// MAKE FUNCTION GIA ::X (GLOBAL X) (SLIDE 19)
struct Entry* checkD_Scope(const char* name){
    struct Entry *tmp=lookUpScope(name,0);
    if(tmp!=NULL){
        return tmp;
    }else{
        printf("ERROR::::: no global var with name: %s exists!!\n",name);
        return NULL;
    }
}

struct Entry* checkedInsertionFormal(unsigned int scope,const char* name, unsigned int line,enum SymbolType type){
    if(checkIfLibFunction(name)==0){
        printf("ERROR:::::: Variable with name: %s is a libfunc!!!!!\n",name);
        return NULL;
    }//  LIBFUNC OVERIDE ERROR
    struct Entry *tmp=lookUpScope(name,scope+1);
    if(tmp!=NULL){
        printf("ERROR:::: can't define this formal var with name: %s as it exists as another var\n",name);
        return NULL;
    }else{
        return InsertAtScope(scope+1,name,line,type);
    }
}

struct Entry* checkedInsertionFunction(unsigned int scope,const char* name, unsigned int line,enum SymbolType type){
    if(checkIfLibFunction(name)==0){
        printf("ERROR:::::: Variable with name: %s is a libfunc!!!!!\n",name);
        return NULL;
    }//  LIBFUNC OVERIDE ERROR
    struct Entry *tmp=lookUpScope(name,scope);
    if(tmp==NULL){
        return InsertAtScope(scope,name,line,type);
    }else{
        printf("ERROR:::::  var or func with name: %s already exist in scope : %d\n",name,scope);
        return NULL;
    }
}

//  MAKE FUNCTION GIA LOCAL VAR (SLIDE 19)
struct Entry* checkedInsertionLocalVar(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    struct Entry* x = NULL;
    x=lookUp(name);
    if(checkIfLibFunction(name)==0){
        printf("ERROR:::::: Variable with name: %s is a libfunc!!!!!\n",name);
        return NULL;
    }/*else if(x){
        return x;
    }*/
    return checkedInsertionVariable(scope,name,line,type,isFunction);
}

struct Entry* checkedInsertionVariable(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    struct Entry *tmp;
    struct Entry *global;
    int flag=0;
    int globalFlag=0;
    int i;

    global=lookUpScope(name,0);
    if(global!=NULL){
        globalFlag=1;
    }

    for(i=scope;i>0;i--){
        tmp=lookUpScope(name,i);
        if(i==scope&&type==5&&tmp==NULL){
            return InsertAtScope(scope,name,line,type);
        }
        else if(i==scope&&type==5&&tmp!=NULL){
            return tmp; // uparxei ara epistrefw ton tmp
        }
        if(tmp!=NULL){
            if(tmp->type==5)flag=2;
            else flag=1; // 
            break;
        }
    }
    if(flag==0 && globalFlag==0){
        return InsertAtScope(scope,name,line,type);
    }else if(globalFlag==1){
        return global;//IS GLOBAL VAR DO NOTHING
    }else if(globalFlag==0 && flag==1 && isFunction==1){
        printf("ERROR::::: Variable with name: %s is already in another scope(not global) and we're inside a function\n",name);
        return NULL;
    }else if(globalFlag==0&& flag==2){
        printf("ERROR::::: Variable with name: %s is  already a local var of another scope\n",name);
        return NULL;
    }else if(globalFlag==0 && flag==1 && isFunction==0){
        //return 0;//IS VAR OF ANOTHER SCOPE(AND NO GLOBAL) SO DO NOTHING
    }
}

struct Entry* checkedInsertion(unsigned int scope,const char* name, unsigned int line,enum SymbolType type,int isFunction){
    //if(checkIfLibFunction(name)==0){return -1;}//  LIBFUNC OVERIDE ERROR
    struct Entry* x;
    if(type==1 || type==5 || type==0){
        x=checkedInsertionLocalVar(scope,name,line,type,isFunction);
        return x;
    }else if(type==2){
        x=checkedInsertionFormal(scope,name,line,type);
        return x;
    }else if(type==3){
        x=checkedInsertionFunction(scope,name,line,type);
        return x;
    }else if(type==4){
    }
    return NULL;
}

int checkIfVarORFunc(enum SymbolType type){
    if(type==USERFUNC || type==LIBFUNC){
        return 0; // is Function
    }else{
        return 1;
    }
}

struct Entry* InsertAtScope(unsigned int scope,const char* name, unsigned int line,enum SymbolType type)
{
    int VarFunc;
    struct Entry *temp=lookUpScope(name,scope);
    if(temp!=NULL){
        return temp;// ARA uparxei to nou mas gt epestrefe -1 ara elenxo an insertscope = allready exist 
    }
    temp=(struct Entry *)malloc(sizeof(struct Entry));
    VarFunc=checkIfVarORFunc(type);
    if(VarFunc==1){
        temp->value.varVal=malloc(sizeof(struct Variable));
        temp->value.varVal->scope=scope;
        temp->value.varVal->line=line;
        temp->value.varVal->name=strdup(name);
    }else{  // prepei na pername ta arguments mias sunartisis,an dn exei k eine var dinume argument null
        temp->value.funcVal=malloc(sizeof(struct Function));
        temp->value.funcVal->scope=scope;
        temp->value.funcVal->line=line;
        temp->value.funcVal->name=strdup(name);
    }

    //====  3h fash =============
    if(type==0 || type==1 || type==2 || type==5){
        temp->supersetType=0;
    }else if(type==3){
        temp->supersetType=1;
    }else{
        temp->supersetType=2;
    }
    temp->space=currscopespace();
    temp->offset=currscopeoffset();
    //===========================

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

    return temp;
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
            return tmp;
        }else{
            tmp = tmp->next;
        }
    }
    return NULL;
}

struct Entry* lookUp(const char* name){
    struct Entry *getBack;
    for(int i=0;i<100;i++){
        getBack=lookUpScope(name,i);
        if(getBack)return getBack;
    }
    return NULL;
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
    printf("\n-----------------------------------------------------------------------------\n\t\t\tPrinting syntax analysis\n-----------------------------------------------------------------------------\n");
    for(i=0;i<100;i++){
        tmp=scopes[i];   
        if(tmp!=NULL)printf("----------------   Scope #%d   ----------------\n",i);
        while(tmp!=NULL){
            if(tmp->value.varVal->name[0]=='_'&&tmp->value.varVal->name[1]=='t'){
                tmp=tmp->next;
                continue;
            }
            if(tmp->type==0)printf("\"%s\" [global variable] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==1)printf("\"%s\" [local variable] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==2)printf("\"%s\" [formal argument] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==3)printf("\"%s\" [user function] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==4)printf("\"%s\" [library function] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            else if(tmp->type==5)printf("\"%s\" [local variable] (line %d) (scope %d)\n",tmp->value.varVal->name,tmp->value.varVal->line,tmp->value.varVal->scope);
            tmp=tmp->next;
        }
        
    }
    return;
}