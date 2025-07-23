%{
/*  Compiler Homework  Author: B112040003 */
#include "B112040003.tab.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LEN 1024
extern int eol_numbers[MAX_LINES];
extern int line_numbers[MAX_LINES];
extern char *lines[MAX_LINES];
extern total_lines;
extern count_newlines(const char *str);
// 陣列儲存每行的行號與文字
int line_numbers[MAX_LINES];
int eol_numbers[MAX_LINES];
char *lines[MAX_LINES];
static current_line = 1;
int total_lines;
/*void print_lineno();*/ /* check if need to print Line no:*/
static int charcnt = 0;

int str_eql(char const * str1, char const * str2){
	if(strcmp(str1,str2) == 0) return 1;
	else return 0;
}
// 換行字元統計用變數
int total_newlines = 0;

// 計算字串中換行字元的個數
int count_newlines(const char *str) {
    int count = 0;
    while (*str) {
		if ( *str == '\n') count++;
		str++;    
	}
    return count;
}


%}

%option yylineno
eol \r|\r\n|\n
emptyline ^\n
comment "/*"[^*]*[*]+([^/][^*]*[*]+)*"/"|"//".*|"//".*[\r][\n]
keyword boolean|break|byte|case|char|catch|class|const|continue|default|do|double|else|extends|false|final|finally|float|for|if|implements|int|long|main|new|print|private|protected|public|return|short|static|String|switch|this|true|try|void|while|read
symbol [.,:;\(\)\[\]\{\}]
operator [+\-*/%=<>!]|"++"|"--"|<=|>=|==|!=|&&|"||"
integer [0-9]+
real [0-9]+\.[0-9]+("e"[+-]{0,1}[0-9]+){0,1}|[0-9]+E[+-]{0,1}[0-9]+
space [ \t]
string \"(\\.|[^\n"\\])*\"
ID [^.,:;\(\)\[\]\{\}+\-*/%=<>! \t\r\n]+
Identifier {IdentifierStart}{IdentifierPart1}*
IdentifierStart [A-Za-z]|_|"\$"
IdentifierPart1 {IdentifierStart}|[0-9]


%%
{emptyline} 	{ 
				  /*printf("line %d:",current_line);*/
                  /*printf("%s",yytext);*/
				  line_numbers[current_line]=2;
				  eol_numbers[current_line]=0;
				  lines[current_line]=strdup(yytext);
				  /*printf("%s\n",lines[current_line]);*/
 	              current_line++;
				  total_lines =  current_line;
	           	/*return(EMPTYLINE);*/ 
	            }
\n  {
	current_line++; 
    total_lines =  current_line;
	}

{comment}		{
	              
				  

				  line_numbers[current_line]=1;
				  lines[current_line]=strdup(yytext);
				  //lines[current_line]=yytext;
				  int count = count_newlines(yytext);
				  eol_numbers[current_line]=0;	
				  /*printf("line %d( %d):",current_line,count);
                  printf("%s\n",lines[current_line]);*/

                  current_line = current_line + count;
                  total_lines =  current_line;
				 /* return (COMMENT);  
				  
				  charcnt+=yyleng;
	              yylval.s = (char*)malloc(sizeof(char)*yyleng);
				  strcpy(yylval.s,yytext); */
				  
				}
{symbol}		{
	/*print_lineno();*/
	charcnt+=yyleng;
	switch(yytext[0]){
		case '.': return('.');
		case ',': return(',');
		case ':': return(':');
		case ';': return(';');
		case '(': return('(');
		case ')': return(')');
		case '[': return('[');
		case ']': return(']');
		case '{':{ eol_numbers[current_line]=1;return('{');}
		case '}':{ return('}');}
	}
}
{space} 		{ ++charcnt; }

{eol}			{ charcnt = 0; }
{operator} 		{
	/*print_lineno();*/
	charcnt+=yyleng;
	if(str_eql(yytext,"+")) return('+');
	else if(str_eql(yytext,"-")) return('-');
	else if(str_eql(yytext,"*")) return('*');
	else if(str_eql(yytext,"%")) return('%');
	else if(str_eql(yytext,"/")) return('/');
	else if(str_eql(yytext,"=")) return('=');
	else if(str_eql(yytext,"<")) return('<');
	else if(str_eql(yytext,">")) return('>');
	else if(str_eql(yytext,"!")) return('!');
	else{
		yylval.s = (char*)malloc(sizeof(char)*yyleng);
		strcpy(yylval.s,yytext);
		if(str_eql(yytext,"++")) return(PPLUS);
		else if(str_eql(yytext,"--")) return(MMINUS);
		else if(str_eql(yytext,"<=")) return(SEQUAL);
		else if(str_eql(yytext,">=")) return(BEQUAL);
		else if(str_eql(yytext,"==")) return(EQUAL);
		else if(str_eql(yytext,"!=")) return(NEQUAL);
		else if(str_eql(yytext,"&&")) return(AND);
		else if(str_eql(yytext,"||")) return(OR);
	}	
}
{integer}		{
	/*print_lineno();*/
	charcnt+=yyleng;
	yylval.i = atoi(yytext);	
	return(INTEGER);
}
{real}			{
	/*print_lineno();*/
	charcnt+=yyleng;
	yylval.d = atof(yytext);	
	return(REAL);
}
{string}		{
	/*print_lineno();*/
	charcnt+=yyleng;
	yylval.s = (char*)malloc(sizeof(char)*yyleng);
	strcpy(yylval.s,yytext);	
	return(STRING);
}
{keyword} 		{
	/*print_lineno();*/
	charcnt+=yyleng;
	yylval.s = (char*)malloc(sizeof(char)*yyleng);
	strcpy(yylval.s,yytext);
	/* return the keyword to the token in parser */
	if(str_eql(yytext,"boolean")) return(BOOLEAN);
	else if(str_eql(yytext,"break")) return(BREAK);
	else if(str_eql(yytext,"byte")) return(BYTE);
	else if(str_eql(yytext,"case")) return(CASE);
	else if(str_eql(yytext,"char")) return(CHAR);
	else if(str_eql(yytext,"catch")) return(CATCH);
	else if(str_eql(yytext,"class")) return(CLASS);
	else if(str_eql(yytext,"const")) return(CONST);
	else if(str_eql(yytext,"continue")) return(CONTINUE);
	else if(str_eql(yytext,"default")) return(DEFAULT);
	else if(str_eql(yytext,"do")) return(DO);
	else if(str_eql(yytext,"double")) return(DOUBLE);
	else if(str_eql(yytext,"else")) return(ELSE);
	else if(str_eql(yytext,"extends")) return(EXTENDS);
	else if(str_eql(yytext,"false")) return(FALSE2);
	else if(str_eql(yytext,"final")) return(FINAL);
	else if(str_eql(yytext,"finally")) return(FINALLY);
	else if(str_eql(yytext,"float")) return(FLOAT);
	else if(str_eql(yytext,"for")) return(FOR);
	else if(str_eql(yytext,"if")) return(IF);
	else if(str_eql(yytext,"implements")) return(IMPLEMENTS);
	else if(str_eql(yytext,"int")) return(INT);
	else if(str_eql(yytext,"long")) return(LONG);
	else if(str_eql(yytext,"main")) return(MAIN);
	else if(str_eql(yytext,"new")) return(NEW);
	else if(str_eql(yytext,"print")) return(PRINT);
	else if(str_eql(yytext,"private")) return(PRIVATE);
	else if(str_eql(yytext,"protected")) return(PROTECTED);
	else if(str_eql(yytext,"public")) return(PUBLIC);
	else if(str_eql(yytext,"return")) return(RETURN);
	else if(str_eql(yytext,"short")) return(SHORT);
	else if(str_eql(yytext,"static")) return(STATIC);
	else if(str_eql(yytext,"String")) return(STRING);
	else if(str_eql(yytext,"switch")) return(SWITCH);
	else if(str_eql(yytext,"this")) return(THIS);
	else if(str_eql(yytext,"true")) return(TRUE2);
	else if(str_eql(yytext,"try")) return(TRY);
	else if(str_eql(yytext,"void")) return(VOID);
	else if(str_eql(yytext,"while")) return(WHILE);
	else if(str_eql(yytext,"read")) return(READ);

}

{ID}			{
	/*print_lineno();*/
	charcnt+=yyleng;
	yylval.s = (char*)malloc(sizeof(char)*yyleng);
	strcpy(yylval.s,yytext);
	return(ID);
}


%%
/*

void print_lineno(){
	if(current_line!=yylineno){
		printf("Line %d: ",yylineno);
		current_line = yylineno;
		total_lines =  current_line;
	}
}*/
