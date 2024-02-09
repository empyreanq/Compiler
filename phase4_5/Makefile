all:
	flex ph1.l
	bison -dy --defines --output=parser.c ph2.y
	gcc  temp.c parser.c lex.yy.c SymbolTable.c quads.c scope_offset.c EndingCode.c
	gcc Alpha_VM.c -o vm
	
	
clean:
	rm lex.yy.c
	rm a.out
	rm parser.c 
	rm parser.h
	rm vm
		