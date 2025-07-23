%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LINE_LEN 1024
#define returnDollarLEN 200
#define IDLISTSIZE 200
#define IDLEN 200
#define STACKSIZE 500

extern int eol_numbers[MAX_LINES];
extern int line_numbers[MAX_LINES];
extern char *lines[MAX_LINES];
extern FILE *yyin;
extern total_lines;
extern count_newlines(const char *str);
extern printerror;

int countchar;
int printerror =0;
int yyparse();
int line_number1 = 0;
int errlineno = 0 ;
int counts =0;
struct st_func{
	int size;
	char scope_name[IDLEN];
	char idlist[IDLISTSIZE][IDLEN];
};
typedef struct st_func ST;

struct mystack{
	int size;
	ST list[STACKSIZE];
}table;
typedef struct mystack STACK;

void into_scope(char str[]);
void add_id(char str[]);
void out_scope();
void print_current();
int check_sameid(char str[]);
int check_exist(char str[]);
void int_to_3char(int value, char out[3]);
int remove_spaces(char* str);

int sem_def;
void yyerror(const char *str);

static int lineno = 1;

void print_lineno(char str[], int addsemi);
void substr(char str[], int begin, int end);

void func_name(char in[], char out[]);




%}
%union{
	char* s;
	char c;
	float d;
	int i;
}


/* keywords */
%token Identifier
%token COMMENT BOOLEAN BREAK BYTE CASE CHAR CATCH CLASS CONST CONTINUE DEFAULT DO DOUBLE ELSE EXTENDS FALSE2 FINAL FINALLY FLOAT FOR IF IMPLEMENTS INT LONG MAIN NEW PRINT PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRING SWITCH THIS TRUE2 TRY VOID WHILE READ
%token INTEGER REAL ID PPLUS MMINUS SEQUAL BEQUAL EQUAL NEQUAL AND OR EMPTYLINE
%type<s> comment_descr identifier_list_char identifier_list_int COMMENT BOOLEAN BREAK BYTE CASE CHAR CATCH CLASS CONST CONTINUE DEFAULT DO DOUBLE ELSE EXTENDS FALSE2 FINAL FINALLY FLOAT FOR IF IMPLEMENTS INT LONG MAIN NEW PRINT PRIVATE PROTECTED PUBLIC RETURN SHORT STATIC STRING SWITCH THIS TRUE2 TRY VOID WHILE ID type identifier_list assign expr arrinit arrinit_expr method_modifier method_declr compound function func_parem declaration method_declr_parem class_declr class_body simple PPLUS MMINUS SEQUAL BEQUAL EQUAL NEQUAL AND OR prefixOp postfixOp const_expr term factor name READ boolean_expr conditional infixop forinitop forupdate for_parem loop func_return new_obj main_func var_list
%type<i> INTEGER
%type<d> REAL
%type<c> leftcurly rightcurly
%%
printnumber		: printnumber COMMENT {  printf("line %d: \n",lineno++);  }
                | printnumber declaration ';'{ print_lineno($2,1);  }
		    	| printnumber method_declr { print_lineno($2,0);  }
			    | printnumber class_declr { print_lineno($2,0);  }
			    | printnumber simple { print_lineno($2,0);  }
			    | printnumber conditional { print_lineno($2,0); }
			    | printnumber boolean_expr ';' { print_lineno($2,1);  }
			    | printnumber loop { print_lineno($2,0);  }
			    | printnumber EMPTYLINE { printf("line %d: \n",lineno++); }
			    | printnumber main_func { print_lineno($2,0); }
			    | { /*empty*/ }
;
comment_descr :COMMENT {};

declaration	: type identifier_list {
				$$ = (char*)malloc(sizeof(char)*3*returnDollarLEN);				
				sprintf($$,"%s %s",$1,$2);
			}
			| type ID ID {
					$$ = (char*)malloc(sizeof(char)*3*returnDollarLEN);
					 sprintf($$,">@Linexxxx, char: ** , a syntax error at '%s' \n%s %s %s;",$3,$1,$2,$3);

				}
			|CHAR identifier_list_char {
				$$ = (char*)malloc(sizeof(char)*3*returnDollarLEN);				
				sprintf($$,"%s %s",$1,$2);
			}
			|CHAR ID {
				    $$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);		
					if(check_sameid($2)){
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,">@**** '%s' in the next line is a duplicated identifier in the current scope.***\n%s %s",$2,$1,$2);
					}
					else{ 
 						add_id($2);
 						sprintf($$,"%s %s",$1,$2);
 					}				
			}


			| STATIC type identifier_list {
				$$ = (char*)malloc(sizeof(char)*3*returnDollarLEN);	
				sprintf($$,"static %s %s",$2,$3);
			}
			| FINAL type identifier_list {
				$$ = (char*)malloc(sizeof(char)*3*returnDollarLEN);	
				sprintf($$,"final %s %s",$2,$3);
			}
			| new_obj { $$ = $1; }

;
class_declr	:CLASS ID leftcurly class_body rightcurly {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				if(check_sameid($2)) sprintf($$,"%s %s \n{\n>'%s' is a duplicate identifier\n%s\n}",$1,$2,$2,$4);
				else{ 
					add_id($2);
					sprintf($$,"%s %s {\n%s\n}",$1,$2,$4);
				}
			}
			
;
new_obj		: ID ID '=' NEW ID '(' ')' {
				if(strcmp($1,$5)!=0) fprintf(stderr,">'%s' typed do not match with newed type '%s'\n",$1,$5);
				$$ = (char*)malloc(sizeof(char)*returnDollarLEN);	
				/* check if class difined */
				if(check_sameid($2)) sprintf($$,"%s %s = new %s()\n>'%s' is a duplicate identifier",$1,$2,$5,$2);
				else{
					add_id($2);
					sprintf($$,"%s %s = new %s ( )",$1,$2,$5);
				}
			}
;

class_body	: declaration ';' {
				$$ = (char*)malloc(sizeof(char)*returnDollarLEN);	
				sprintf($$,"%s ;",$1);
			}
			
			|simple {
				$$ = (char*)malloc(sizeof(char)*returnDollarLEN);	
				sprintf($$,"%s ;",$1);
			}
			|simple  class_body {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"%s\n %s",$1,$2);
			}	
			| method_declr {
				$$ = $1;
			}
			| main_func {
				$$ = $1;
			}
			| compound {
				$$ = $1;
			}
			| declaration ';' class_body {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"%s ;\n%s",$1,$3);
			}
			| method_declr class_body {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"%s\n%s",$1,$2);
			}
			| main_func class_body {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"%s\n%s",$1,$2);
			}
			| leftcurly compound rightcurly {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"{\n%s\n}",$2);
			}
			| leftcurly compound rightcurly class_body {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				sprintf($$,"{\n%s\n}\n%s",$2,$4);
			}
            | declaration class_body   {
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				printerror = 1;	
				sprintf($$,"%s \n>@Linexxxx, char: 17, statement without semicolon\n%s",$1,$2);
			}


			| error { /* error recovery */ $$ = "ERROR HERE 1"; }
			| error class_body {
					/* error recovery */ 
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					printf("%d\n",errlineno++);
					sprintf($$,"ERROR HERE 2 \n%s",$2);
			}

;
method_declr: type ID '(' method_declr_parem ')' leftcurly compound rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sprintf($$,"%s %s(%s){\n>'%s' is a duplicate identifier\n%s\n}",$1,$2,$4,$2,$7);
				else{
					add_id($2);
					sprintf($$,"%s %s(%s){\n%s\n}",$1,$2,$4,$7);
				}
			}
			| method_modifier type ID '(' method_declr_parem ')' leftcurly compound rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s(%s){\n>'%s' is a duplicate identifier\n%s\n}",$1,$2,$3,$5,$3,$8);
				else{
					add_id($3);
					sprintf($$,"%s %s %s(%s){\n%s\n}",$1,$2,$3,$5,$8);
				}
			}
			| type ID '('  ')' leftcurly compound rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sem_def = 1;
				else{
					add_id($2);
					sprintf($$,"%s %s ( ) {\n%s\n}",$1,$2,$6);
				}
			}
			| method_modifier type ID '(' ')' leftcurly compound rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s(){\n>'%s' is a duplicate identifier\n%s\n}",$1,$2,$3,$3,$7);
				else{ 
					sprintf($$,"%s %s %s ( ) {\n%s\n}",$1,$2,$3,$7);
 					add_id($3);
 				}
			}
			| type ID '(' method_declr_parem ')' leftcurly rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sprintf($$,"%s %s(%s){ }\n>'%s' is a duplicate identifier",$1,$2,$4,$2);
				else{ 
					sprintf($$,"%s %s ( %s ) { }",$1,$2,$4);
 					add_id($2);
 				}
			}
			| method_modifier type ID '(' method_declr_parem ')' leftcurly rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s(%s){ }\n>'%s' is a duplicate identifier",$1,$2,$3,$5,$3);
				else{ 
					sprintf($$,"%s %s %s ( %s ) { }",$1,$2,$3,$5);
 					add_id($3);
 				}
			}
			| type ID '('  ')' leftcurly rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sprintf($$,"%s %s(){ }\n>'%s' is a duplicate identifier",$1,$2,$2);
				else{ 
					sprintf($$,"%s %s ( ) { }",$1,$2);
					add_id($2);
				}
			}
			| method_modifier type ID '(' ')' leftcurly rightcurly { /*function*/
				/* ps compound is things inside function(){ HERE } */
				fprintf(stderr,">Warning: function body in declaration is empty\n");
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s(){ }\n>'%s' is a duplicate identifier",$1,$2,$3,$3);
				else{ 
					sprintf($$,"%s %s %s ( ) { }",$1,$2,$3);
 					add_id($3);
 				}
			}
			| type ID '(' method_declr_parem ')' ';' { /* function declaration */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sprintf($$,"%s %s(%s) ;\n>'%s' is a duplicate identifier",$1,$2,$4);
				else{ 
					sprintf($$,"%s %s ( %s ) ;",$1,$2,$4);
					add_id($2);
				}
			}
			| type ID '(' ')' ';' { /* function declaration */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($2)) sprintf($$,"%s %s() ;\n>'%s' is a duplicate identifier",$1,$2,$2);
				else{ 
					sprintf($$,"%s %s ( ) ;",$1,$2);
 					add_id($2);
 				}
			}
			| type ID '(' ')' type{ /* function declaration */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
                sprintf($$,"%s %s ( ) ;\n>'%s' is a no semicolon",$1,$2,$2);

			}

			| method_modifier type ID '(' method_declr_parem ')' ';' { /* function declaration */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s(%s) ;\n>'%s' is a duplicate identifier",$1,$2,$3,$5,$3);
				else{ 
					sprintf($$,"%s %s %s ( %s ) ;",$1,$2,$3,$5);
 					add_id($3);
 				}
			}
			| method_modifier type ID '(' ')' ';' { /* function declaration */
				$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
				if(check_sameid($3)) sprintf($$,"%s %s %s() ;\n>'%s' is a duplicate identifier",$1,$2,$3,$3);
				else{ 
					sprintf($$,"%s %s %s ( ) ;",$1,$2,$3);
 					add_id($3);
 				}
			}
;
method_declr_parem : type ID {
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,"%s %s",$1,$2);
					}


					| type ID ',' method_declr_parem {
						$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
						sprintf($$,"%s %s , %s",$1,$2,$4);
					}
					| type ID assign{
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,"%s %s %s",$1,$2,$3);
					}
					| type ID assign ',' method_declr_parem {
						$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
						sprintf($$,"%s %s %s , %s",$1,$2,$3,$5);
					}
;
method_modifier	: PRIVATE { $$ = $1; }
				| PROTECTED { $$ = $1; }
				| PUBLIC { $$ = $1; }
;
assign			: '=' expr { 
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"= %s",$2);
				}
;
arrinit			:'[' ']' ID {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($3)) sprintf($$,"[] %s\n>'%s' is a duplicate identifier",$3,$3);
					else{ 
						sprintf($$,"[ ] %s",$3);
 						add_id($3);

 					}
				}
				| ID '[' INTEGER ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);		
					if(check_sameid($1)) sprintf($$,"%s[%d]\n>'%s' is a duplicate identifier",$1,$3,$1);
					else{ 
						sprintf($$,"%s [ %d ]",$1,$3);
 						add_id($1);
 					}
				}
				| '*' ID {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($2)) sprintf($$,"* %s\n>'%s' is a duplicate identifier",$2,$2);
					else{ 
						sprintf($$,"* %s",$2);
 						add_id($2);
 					}
				}
				| '[' INTEGER ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"[%d]",$2);
				}
				| '[' ']' ID '=' NEW type '[' INTEGER ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($3)) sprintf($$,"[] %s = new %s[%d]\n>'%s' is a duplicate identifier",$3,$6,$8,$3);
					else{ 
						sprintf($$,"[ ] %s = new %s [ %d ]",$3,$6,$8);
 						add_id($3);
 					}
				}
				| '*' ID '=' NEW type '[' INTEGER ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($2)) sprintf($$,"*%s = new %s[%d]\n>'%s' is a duplicate identifier",$2,$5,$7,$2);
					else{ 
						sprintf($$,"*%s = new %s [ %d ]",$2,$5,$7);
 						add_id($2);
 					}
				}
				|  ID '[' INTEGER ']' '=' leftcurly arrinit_expr rightcurly {
					$$ = (char*)malloc(sizeof(char)*8*returnDollarLEN);	
					if(check_sameid($1)) sprintf($$,"%s[%d] = {%s}\n>'%s' is a duplicate identifier",$1,$3,$7,$1);
					else{ 
						sprintf($$,"%s [ %d ] = { %s }",$1,$3,$7);
						add_id($1);
					}
				}
				|  ID '[' ']' '=' leftcurly arrinit_expr rightcurly {
					$$ = (char*)malloc(sizeof(char)*8*returnDollarLEN);	
					if(check_sameid($1)) sprintf($$,"%s[] = {%s}\n>'%s' is a duplicate identifier",$1,$6,$1);
					else{ 
						sprintf($$,"%s [ ] = { %s }",$1,$6);
						 add_id($1);
					}
				}


				
;
arrinit_expr	: expr { $$ = $1; }
				| expr ',' arrinit_expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"%s , %s",$1,$3);
				}
;
conditional		: IF '(' boolean_expr ')' simple {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);					
					sprintf($$,"%s ( %s ) %s",$1,$3,$5); 
				}
				| IF '(' boolean_expr ')' leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);					
					sprintf($$,"%s ( %s ) {\n%s\n}",$1,$3,$6);
				}
				| IF '(' boolean_expr ')' simple ELSE simple {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);					
					sprintf($$,"%s ( %s ) %s\n%s %s",$1,$3,$5,$6,$7);
				}
				| IF '(' boolean_expr ')' simple ELSE leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf($$,"%s ( %s ) %s\n%s {\n%s\n}",$1,$3,$5,$6,$8);
				}
				| IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE simple {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf($$,"%s ( %s ) {\n%s\n}\n%s %s",$1,$3,$6,$8,$9);
				}
				| IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);					
					sprintf($$,"%s ( %s ) {\n%s\n}\n%s {\n%s\n}",$1,$3,$6,$8,$10);
				}
				| IF '(' boolean_expr ')' simple ELSE conditional {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf($$,"%s ( %s ) %s\n%s %s",$1,$3,$5,$6,$7);
				}
				| IF '(' boolean_expr ')' leftcurly compound rightcurly ELSE conditional {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);					
					sprintf($$,"%s ( %s ) {\n%s\n}\n%s %s",$1,$3,$6,$8,$9);
				}
				| ELSE {
					$$ = (char*)malloc(sizeof(char)*30*returnDollarLEN);
					sprintf($$,">@******Else Without If at linexxx, char %d******\n%s",strlen($1),$1);
				}

;
boolean_expr	: expr { $$ = $1;}
				| expr infixop expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"%s %s %s",$1,$2,$3);
				}
				| error { /* error recovery */ $$ = "ERROR HERE 3"; }
;
infixop			: EQUAL { $$ = $1; }
				| NEQUAL { $$ = $1; }
				| '<' { $$ = "<"; }
				| '>' { $$ = ">"; }
				| SEQUAL { $$ = $1; }
				| BEQUAL { $$ = $1; }
;
loop		: WHILE '(' boolean_expr ')' simple {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ( %s ) %s",$1,$3,$5);
			}
			| WHILE '(' boolean_expr ')' leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"%s ( %s ) {\n%s\n}",$1,$3,$6);
			}
			| WHILE '(' ')' simple {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ( ) %s ;",$1,$4);
			}
			| WHILE '(' ')' leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf($$,"%s ( ) {\n%s\n}",$1,$5);
			}
			| FOR '(' for_parem ')' simple {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ( %s )\n%s ",$1,$3,$5);
			}
			| FOR '(' for_parem ')' leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"%s ( %s ) {\n%s\n}",$1,$3,$6);
			}
			|	FOR '(' for_parem ')'  {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ( %s ) \n",$1,$3);
			}
            | WHILE '(' '*' '*' '/' ID PPLUS ')'  leftcurly compound rightcurly {
			        $$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);						
                    sprintf($$,">@******Invalid Boolean Expression at line***,char** ******\n%s ( * * / %s ++ ) {\n%s\n}",$1,$6,$10);
			}
;
for_parem	: forinitop ';' boolean_expr ';' forupdate {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ; %s ; %s",$1,$3,$5);
			}
			| ';' boolean_expr ';' forupdate {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$," ; %s ; %s",$2,$4);
			}
			| forinitop ';' ';' forupdate {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ; ; %s",$1,$4);
			}
			| forinitop ';' boolean_expr ';' {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s ; %s ;",$1,$3);
			}
			| ';' ';' forupdate {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$," ; ; %s ",$3);
			}
			| ';' boolean_expr ';' {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$," ; %s ; ",$2);
			}
			| forinitop ';' ';' {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$," %s ; ;",$1);
			}
			| ';' ';' {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$," ; ; ");
			}
			| ID '['INTEGER ']' '=' INTEGER ';' ID '['INTEGER ']' '<' INTEGER ';'	 ID '['INTEGER ']' 	PPLUS	
	    		{  $$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf($$,"%s [ %d ] = %d ; %s [ %d ] < %d ; %s [ %d ] ++ ",$1,$3,$6,$8,$10,$13,$15,$17);} 
;
forinitop	: declaration { $$ = $1; }
			| ID assign { $$ = $1; }
			| declaration ',' forinitop {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s , %s",$1,$3);
			}
			| ID assign ',' forinitop {
					$$ = (char*)malloc(sizeof(char)*2*returnDollarLEN);
					sprintf($$,"%s %s , %s",$1,$2,$4);
			} 
;
forupdate	: postfixOp { $$ = $1; }
			| PPLUS ID {
				$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
				sprintf($$,"%s %s",$1,$2);
			}
			| MMINUS ID {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s %s",$1,$2);
			}
			| ID assign {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s %s",$1,$2);
			}
;
type		: BOOLEAN {$$ = $1;} | CHAR {$$ = $1;} | INT {$$ = $1; } | FLOAT {$$ = $1;} | STRING {$$ = $1;} | VOID { $$ = $1; }
;
simple			: name assign ';' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s %s ;",$1,$2);
					else sprintf($$,"%s %s ;\n>'%s' id did not exist1",$1,$2,$1);*/
					sprintf($$,"%s %s ;",$1,$2);
				}
				| PRINT '(' expr ')' ';' { 
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf($$,"%s ( %s ) ;",$1,$3);
				}
				| READ '(' name ')' ';' { 
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($3)) sprintf($$,"%s(%s) ;",$1,$3);
					else sprintf($$,"%s ( %s ) ;>'%s' id did not exist2",$1,$3,$3);
				}
				| name PPLUS ';' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s%s ;",$1,$2);
					else sprintf($$,"%s%s ;>'%s' id did not exist3",$1,$2,$1);*/
					sprintf($$,"%s %s ;",$1,$2);
				}
				| name MMINUS ';' { 
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					/*if(check_exist($1)) sprintf($$,"%s%s ;",$1,$2);
					else sprintf($$,"%s%s ;>'%s' id did not exist4",$1,$2,$1);*/
					sprintf($$,"%s %s ;",$1,$2);
				}
				| expr ';' { 
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s ;",$1);
				}
				| ';' { $$ = ";"; }
;
name			: ID { $$ = $1; }
				| ID '.' ID { 
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s.%s",$1,$3);
				}
				| ID '[' INTEGER ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($1)) sprintf($$,"%s[%d]",$1,$3);
					else sprintf($$,"%s[%d]\n>'%s' id did not exist5",$1,$3,$1);
					
				}
				| ID '[' ID ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($1)) sprintf($$,"%s[%s]",$1,$3);
					else sprintf($$,"%s[%s]\n>'%s' id did not exist6",$1,$3,$1);
					/*$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s [ %s ]",$1,$3);*/
				}
				| ID '[' function ']' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s [ %s ]",$1,$3);
				}
;
identifier_list : ID {	
					if(check_sameid($1)){
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,"%s ;\n>'%s' is a duplicate identifier.",$1,$1);
					}
					else{ 
 						add_id($1);
 						$$ = $1;
 					}
					
				}


				| ID assign {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s\n>'%s' is a duplicate identifier2",$1,$2,$1);
					else{ 
						add_id($1);
						sprintf($$,"%s %s",$1,$2);
					}
				}
				| ID assign ',' identifier_list {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s, %s\n>'%s' is a duplicate identifier3",$1,$2,$4,$1);
					else{ 
						sprintf($$,"%s %s, %s",$1,$2,$4);
 						add_id($1);
 					}
				}
				| ID ',' identifier_list {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s, %s\n>'%s' is a duplicate identifier4",$1,$3,$1);
					else{ 
						sprintf($$,"%s , %s",$1,$3);
 						add_id($1);
 					}
				}

				| arrinit { $$ = $1; }
				| arrinit ',' identifier_list {
					$$ = (char*)malloc(sizeof(char)*8*returnDollarLEN);
					sprintf($$,"%s , %s",$1,$3);
				}
;
identifier_list_int : 
				 ID assign {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s\n>'%s' is a duplicate identifier2",$1,$2,$1);
					else{ 
						add_id($1);
						sprintf($$,"%s %s",$1,$2);
					}
				}
				| ID assign ',' identifier_list_int {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s, %s\n>'%s' is a duplicate identifier3",$1,$2,$4,$1);
					else{ 
						sprintf($$,"%s %s , %s",$1,$2,$4);
 						add_id($1);
 					}
				}
				| ID ',' identifier_list_int {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s, %s\n>'%s' is a duplicate identifier4",$1,$3,$1);
					else{ 
						sprintf($$,"%s , %s",$1,$3);
 						add_id($1);
 					}
				}

				| arrinit { $$ = $1; }
				| arrinit ',' identifier_list_int {
					$$ = (char*)malloc(sizeof(char)*8*returnDollarLEN);
					sprintf($$,"%s , %s",$1,$3);
				}
;		
identifier_list_char : ID ID {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					 sprintf($$,"%s %s\n>'%s' is no comma ",$1,$2,$1);

				}

				| ID assign {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s\n>'%s' is a duplicate identifier2",$1,$2,$1);
					else{ 
						add_id($1);
						sprintf($$,"%s %s",$1,$2);
					}
				}
				| ID assign ',' identifier_list_char {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s %s, %s\n>'%s' is a duplicate identifier3",$1,$2,$4,$1);
					else{ 
						sprintf($$,"%s %s , %s",$1,$2,$4);
 						add_id($1);
 					}
				}
				| ID ',' identifier_list_char {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_sameid($1)) sprintf($$,"%s, %s\n>'%s' is a duplicate identifier4",$1,$3,$1);
					else{ 
						sprintf($$,"%s , %s",$1,$3);
 						add_id($1);
 					}
				}

				| arrinit { $$ = $1; }
				| arrinit ',' identifier_list_char {
					$$ = (char*)malloc(sizeof(char)*8*returnDollarLEN);
					sprintf($$,"%s , %s",$1,$3);
				}
;	

expr			: term { $$ = $1;}
				| expr '+' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s",$1,$3);
				}
				| expr '-' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s - %s",$1,$3);
				}
				| expr '*' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s - %s",$1,$3);
				}
				| expr '/' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s - %s",$1,$3);
				}
				| term  '+' ID  {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s ",$1,$3);
				}
				| term  '-' ID  {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s ",$1,$3);
				}
				| expr  '+' INTEGER  {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s ",$1,$3);
				}
				| expr  '-' INTEGER  {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s ",$1,$3);
				}
				|  expr PPLUS   {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s --",$1);
				}

				|  expr MMINUS   {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s --",$1);
				}
				
				| ID  '+' expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s + %s",$1,$3);
				}
				| error { /* error recovery */ $$ = "ERROR HERE 4"; }
;
term			: factor { $$ = $1; }
				| factor '*' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s * %s",$1,$3);
				}
				| factor '/' term {
					/*zero divisor*/
					if($3[0]=='0') fprintf(stderr,">zero divisor\n");
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s / %s",$1,$3);
				}
				| factor '%' term {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s \% %s",$1,$3);
				}
;
factor			:  name '+' name  {
	                
					if(check_exist($1)) $$ = $1;
					else{					
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					 sprintf($$,"%s + %s",$1,$3); 
					}
                }
                | name {
					add_id($1);
					if(check_exist($1)) $$ = $1;
					else{
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,"%s\n>'%s' id did not exist5",$1,$1);
					}
				}
				| '!' name {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($2)) sprintf($$,"!%s",$2);
					else{
						sprintf($$,"!%s\n>'%s' id did not exist6",$2,$2);
					}
				}
				| const_expr { $$ = $1;}
				| STRING { $$ = $1; }
				| '(' expr ')' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"( %s )",$2);
				}
				| prefixOp {
					$$ = $1;
				}
				| postfixOp {
					$$ = $1;;
				}
				| function {
					char fname[strlen($1)];
					func_name($1,fname);
					if(check_exist(fname)) $$ = $1;
					else{
						$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
						sprintf($$,"%s\n>'%s' id did not exist7",$1,fname);
					}
				}
;
prefixOp		: PPLUS ID {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"++ %s",$2);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support ++ operator\n");*/
				}
				| MMINUS ID {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"-- %s",$2);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
				| '+' ID {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"+ %s",$2);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
				| '-' ID {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"- %s",$2);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
				| '+' const_expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"- %s",$2);
				}
				| '-' const_expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"- %s",$2);
				}
;
postfixOp		: ID PPLUS {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($1)) sprintf($$,"%s++",$1);
					else sprintf($$,"%s ++\n>'%s' id did not exist8",$1,$1);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support ++ operator\n");*/
				}
				| ID MMINUS {
					/* need implement ID = function or variable */
					/* if ID is variable */
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					if(check_exist($1)) sprintf($$,"%s--",$1);
					else sprintf($$,"%s --\n>'%s' id did not exist9",$1,$1);
					/* if ID is function */
					/*fprintf(stderr,"function name doesn't support -- operator\n");*/
				}
;

const_expr		: INTEGER {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"%d",$1); 
				}
				| REAL {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);					
					sprintf($$,"%g",$1);
				}
;
compound		: declaration ';' {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"%s ;",$1);
				}
			    | declaration ';' compound {
				   $$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
				   sprintf($$,"%s ;\n%s",$1,$3);
			    }
				| simple { $$ = $1; }
				| conditional { $$ = $1; }
				| declaration ';' compound {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"%s\n%s",$1,$3);
				}
				| loop { $$ = $1; }
				| simple compound {
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf($$,"%s\n%s",$1,$2);
				}
				| conditional compound {
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf($$,"%s\n%s",$1,$2);
				}
				| func_return ';' {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s ;",$1);
				}
				| loop compound {
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf($$,"%s\n%s",$1,$2);
				}
				| leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf($$,"{\n%s\n}",$2);
				}
				| leftcurly compound rightcurly compound {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf($$,"{\n%s\n}\n%s",$2,$4);
				}
				| CLASS ID leftcurly compound rightcurly  { 
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);	
					sprintf($$,"%s %s {\n%s\n}",$1,$2,$4);
				}

				| error { /* error recovery */ $$ = "ERROR HERE 5"; }
				| error compound {
					/* error recovery */ 
					$$ = (char*)malloc(sizeof(char)*5*returnDollarLEN);
					sprintf($$,"ERROR HERE 6\n%s",$2);
				}
;
function		: name '(' ')' {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf($$,"%s()",$1);
				}
				| name '(' func_parem ')' {
					$$ = (char*)malloc(sizeof(char)*10*returnDollarLEN);
					sprintf($$,"%s(%s)",$1,$3);
				}

;
main_func		: MAIN '(' ')' leftcurly compound rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"main ( ) \n{\n%s\n}",$5);
				}
				| type MAIN '(' ')' leftcurly compound  rightcurly {
					$$ = (char*)malloc(sizeof(char)*15*returnDollarLEN);
					sprintf($$,"%s main ( ) {\n%s\n}",$1,$6);
				}
;
func_parem		: expr { $$ = $1; }
				| expr ',' func_parem {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s , %s",$1,$3);
				}
;
func_return		: RETURN expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s %s",$1,$2);
				}
				| RETURN boolean_expr {
					$$ = (char*)malloc(sizeof(char)*returnDollarLEN);
					sprintf($$,"%s %s",$1,$2);
				}
				| RETURN { $$ = $1; }
;
leftcurly 		: '{' {
					into_scope("scope");
					$$ = '{';
				}
;
rightcurly		: '}' {
					/*print_current();*/
					out_scope();				
					$$ = '}';
				}
;
%%

void into_scope(char str[]){
	table.size++;
	table.list[table.size-1].size=0;
	strcpy(table.list[table.size-1].scope_name,str);
}

void add_id(char str[]){
	table.list[table.size-1].size++;
	strcpy(table.list[table.size-1].idlist[table.list[table.size-1].size-1],str);
}

void out_scope(){
	table.list[table.size-1].size = 0;
	table.size--;
}

void print_current(){
	int cur_size = table.list[table.size-1].size, i;
	printf("scope: %s\nid list size: %d\n",table.list[table.size-1].scope_name,cur_size);
	for(i=0;i<cur_size;++i){
		printf("%s\n",table.list[table.size-1].idlist[i]);
	}
}

int check_sameid(char str[]){
	int cur_size = table.list[table.size-1].size, i;	
	for(i=0;i<cur_size;++i){
		if(strcmp(table.list[table.size-1].idlist[i],str)==0) return 1;
	}
	return 0;
}

int check_exist(char str[]){
	int i,j;
	for(j=table.size-1;j>=0;--j){
		for(i=0;i<table.list[j].size;++i){
			if(strcmp(table.list[j].idlist[i],str)==0) return 1;
		}
	}
	return 0;
}

void yyerror(const char *str){
	fprintf(stderr,">%s\n",str);
}

void print_lineno(char str[], int addsemi){
    
	int errorno;
    line_number1++;

	int lineflag=0;
	int afterflag =0;
	counts=0;

	while (line_numbers[line_number1]!=0){
		counts = count_newlines(lines[line_number1]);
		lineflag=1;
		/*printf("%d\n",counts);*/
	    printf("\nline %3d: ",lineno++);
		char *str = lines[line_number1];
		if (counts >1){
  		    //lineno = lineno + counts ;
		    while (*str) {
		      if ( *str == '\n') 
		    	{printf("\nline %3d: ",lineno++);
				 line_number1++;}
		      else 
		          printf("%c",*str);		      
		      str++;  
			}
			printf("\n");
		}
		else 
		    printf("%s\n",lines[line_number1]);   
	    
	line_number1++;		
	}
    printf("line %3d: ",lineno++);
	//if (lineflag ==1 ) {lineflag=0; line_number1--; lineno--; }
    
	

	/*printf("strlen %d",strlen(str));*/
	/*if(addsemi){
		printf("%s ;\n",str);
		return;
	}*/
	int i,k=0;
	
	for(i=0;i<strlen(str);++i){

		
		if(str[i]=='\n' && (i+1) < strlen(str) && str[i+1]!='>'){
		   line_number1++;

           lineflag=0;
		   while (line_numbers[line_number1]!=0){
			   lineflag++;
			   counts = count_newlines(lines[line_number1]);
			   if (lineflag >1 ) 
			      printf("line %3d: ",lineno++);
			   else
	              printf("\nline %3d: ",lineno++);
			   printf("%s",lines[line_number1]);
		       line_number1++;
			}
			if  (lineflag >=1 ) {
				lineflag=0;
			    if (line_numbers[line_number1-1] !=2 )  printf ("\n");
				printf("line %3d: ",lineno++);
				}
			else 
			    printf("\nline %3d: ",lineno++);
			

		}

		else if (str[i+1] =='>'){
		   line_number1++;	    
           afterflag =1;
		   while (line_numbers[line_number1]!=0 && printerror == 0 ){
			   lineflag++;
			   counts = count_newlines(lines[line_number1]);
			   if (lineflag >1 ) {
			      printf("line %3d: ",lineno++);
				  printf("%s\n",lines[line_number1]);
			      }
			   else{
	              printf("\nline %3d: ",lineno++);
			      printf("%s",lines[line_number1]);
			     }
			    
		       line_number1++;
			}

            line_number1--;

			if  (lineflag >=1 ) {
				lineflag=0;
			    if (line_numbers[line_number1-1] !=2 )  printf ("\n");
				}
			else 
			{
			    printf("\n");
			}
			

		}
		else {
			  if (str[i] =='{' && eol_numbers[line_number1] ==0){
				 printf("\nline %3d: ",lineno++);
		         line_number1++;
			     printf("%c",str[i]);
			  }
			  else	{
			    if (str[i] =='>' && str[i+1] =='@'){
                     i++;
					 i++;
				    if ( str[i] =='L' && str[i+1] =='i' && str[i+2] =='n'  && str[i+3] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						countchar = 12;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);
						str[i+4]=' ' ; 
					    str[i+5]=resultchar[0] ;
					    str[i+6]=resultchar[1] ;
						str[i+7]=resultchar[2] ;
						int_to_3char(countchar , resultchar);
						str[i+16]=resultchar[1] ;
						str[i+17]=resultchar[2] ;

					}
				   	if ( str[i+25] =='l' && str[i+26] =='i' && str[i+27] =='n'  && str[i+28] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);

					    str[i+29]=resultchar[0] ;
					    str[i+30]=resultchar[1] ;
						str[i+31]=resultchar[2] ;

					}
					if ( str[i+36] =='l' && str[i+37] =='i' && str[i+38] =='n'  && str[i+39] =='e'  ){				
				    	char resultchar[3];
						errorno =lineno;
						countchar = 9;
						if (printerror == 1) errorno=lineno-1;
                        int_to_3char(errorno, resultchar);
					    str[i+40]=resultchar[0] ;
					    str[i+41]=resultchar[1] ;
						str[i+42]=resultchar[2] ;
						int_to_3char(countchar, resultchar);
						str[i+48]=resultchar[1] ;
						str[i+49]=resultchar[2] ;

					}		
				}
                if (afterflag ==1 && str[i] ==';') afterflag =0;
				else 
		        printf("%c",str[i]);
			  }	
	    }
	}
	printf("\n");
}


void func_name(char in[], char out[]){
	int i;
	for(i=0;i<strlen(in);++i){
		if ( in[i] != '(' ) out[i] = in[i];
		else{ out[i]='\0'; break; }
	}
}

void print_with_line_numbers(FILE *fp) {
    char line[1024];
    int lineno = 1;
    while (fgets(line, sizeof(line), fp)) {
        printf("line %4d: %s", lineno++, line);
    }
    rewind(fp); // Reset file pointer for parsing
}

void int_to_3char(int value, char out[3]) {
    char temp[4]; // temp buffer to hold up to 3 digits + null terminator
    snprintf(temp, sizeof(temp), "%d", value);

    int len = strlen(temp);
    int pad = 3 - len;

    for (int i = 0; i < pad; i++) {
        out[i] = ' ';
    }
    for (int i = 0; i < len; i++) {
        out[pad + i] = temp[i];
    }
}

int remove_spaces(char* str) {
    int i = 0, j = 0;
    while (str[i]) {
        if (str[i] != ' ') {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0'; // Null-terminate the string
    return j;      // Return new length
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <sourcefile>\n", argv[0]);
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("Cannot open file");
        return 1;
    }	

    //print_with_line_numbers(f);
    yyin = f;
	table.size = 0;
	into_scope("global");
    yyparse();

	while (lineno < total_lines){
        if (lines[lineno] != NULL && strlen(lines[lineno])!=0 ){
	  	    counts = count_newlines(lines[lineno]);
		    char *str = lines[lineno];
		    if (counts >= 1 && line_numbers[lineno]==1 ){  	
				printf("line %3d:",lineno);	
				lineno++;    
		        while (*str) {
		          if ( *str == '\n') {
		    	    printf("\nline %3d:",lineno);
				    lineno++;
					}
		           else 
		             printf("%c",*str);		      
		          str++;				    
			    }
			    printf("\n");
		    }
		   else 
		      printf("line %3d:%s",lineno,lines[lineno]); 
			    	
		}

       
	  lineno++;
    }
	
	//printf ("Total:%d  Current:%d \n",total_lines,lineno);
    fclose(f);
    return 0;
}