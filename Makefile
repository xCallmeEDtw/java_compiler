 all:
	bison -d --debug B112040003.y
	flex B112040003.l
	gcc -o myjavac  lex.yy.c B112040003.tab.c -lfl 
clean:
	rm -f myjavac lex.yy.c B112040003.tab.c B112040003.tab.h

