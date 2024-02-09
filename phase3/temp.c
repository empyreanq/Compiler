#include "temp.h"

int tempcounter=0;

char *newtempname(){
    char *s=malloc(sizeof(int)+4);
    snprintf(s,sizeof(int)+4,"_t%d",tempcounter);
    return s;
}

void resettemp(){tempcounter=0;}

struct Entry* newtemp(int scope){
	char* tmp=newtempname();
	struct Entry *sym =lookUpScope(tmp,scope);
	if(sym==NULL){
		tempcounter++;
		return InsertAtScope(scope,tmp,0,1);
	}
    return sym;
}