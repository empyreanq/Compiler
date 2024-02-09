#ifndef SCOPE_OFFSET_H
#define SCOPE_OFFSET_H
#include "header.h"
#include <assert.h>

extern unsigned programVarOffset;
extern unsigned functionLocalOffset;
extern unsigned formalArgOffset;
extern unsigned scopeSpaceCounter;

scopespace_t currscopespace();

/*krataw offset gia kathe scope space*/
unsigned currscopeoffset(void);

/*nea dilwsh metavlitis auksanei to offset tou ekastote scope space*/
void inccurroffset(void);

/*mpainovgainoume se scope */
void enterscopespace();

void exitscopespace();

void resetformalargoffset();
void resetfunctionlocalsoffset();
void restorecurrscopeoffset(unsigned n);

#endif