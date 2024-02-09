#include "scope_offset.h"


scopespace_t currscopespace(){
	if(scopeSpaceCounter == 1){
		return programvar;
	}else if(scopeSpaceCounter % 2 == 0){
		return formalarg;
	}else{
		return functionlocal;
	}
}

/*krataw offset gia kathe scope space*/
unsigned currscopeoffset(void){
	switch(currscopespace()){
		case programvar: return programVarOffset;
		case functionlocal: return functionLocalOffset;
		case formalarg: return formalArgOffset;
		default: assert(0);
	}
	return -100;
}


/*nea dilwsh metavlitis auksanei to offset tou ekastote scope space*/
void inccurroffset(void){
	switch(currscopespace()){
		case programvar:  ++programVarOffset; break;
		case functionlocal: ++functionLocalOffset; break;
		case formalarg: ++formalArgOffset; break;
		default: assert(0);
	}
}

/*mpainovgainoume se scope */
void enterscopespace(){
	++scopeSpaceCounter;
}

void exitscopespace(){
	assert(scopeSpaceCounter>1);
	--scopeSpaceCounter;
}

void resetformalargoffset(){formalArgOffset=0;}

void resetfunctionlocalsoffset(){functionLocalOffset=0;}

void restorecurrscopeoffset(unsigned n){
	switch(currscopespace()){
		case programvar: programVarOffset=n; break;
		case functionlocal: functionLocalOffset=n; break;
		case formalarg: formalArgOffset=n; break;
		default: assert(0);
	}
}
