all:
	flex ph1.l
	bison -dy --defines --output=parser.c ph2.y
	gcc parser.c lex.yy.c SymbolTable.c
	
	
clear:
	rm lex.yy.c
	rm a.out
	rm parser.c 
	rm parser.h
		