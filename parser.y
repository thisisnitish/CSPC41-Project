%{
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "lex.yy.c"

void yyerror(const char*);
int yylex();
int yywrap();

void add(char);
void insert_type();
void insert_type_table();
int sym_search(char *);
int search(char *);
void addTo(char i,char *n);

void FOO();
void add_ptr();
void pop();
char temptype(char *,char*);
void type_check(char *,char*);
void printtree(struct node1*);

struct node{ 
	int val;
}x;

struct dataType{
	char * id_name;
	char * data_type;
	char * type;
	int line_no;
	}symbolTable[20];

int ifd=0;						//Label
int eld=20;
char typeStack[10][100];
int typeStack_top = 0;
char type[10];
char count=0;
int nxt=1;						//printed next once
int c=0;						//Temp var count
int q;
extern int countn;
struct node1 { 
	struct node1 *left;
	struct node1 *right;
	char *token;
};
struct node1* mknode(struct node1 *left,struct node1 *right, char *token);
%}

%union { 
	struct var_name {
		char name[100];
		struct node1* nd;
	}nam; 
	
	struct gen_code {
		char tr[10];
		char fal[10];
		struct node1* nd;
	} gen; 
} 

%token <nam> IF ELSE INT FLOAT CHAR 
%token VOID INCLUDE RETURN 
%token <nam> LE GE LT GT EQ NE NUM AND OR TR FL STRLT identifiers printff scanff

%type <gen> B logicalCond
%type <nam> relop Q T F relationalCond assign Arg begin header datatypes normalFuncArg terminate pointerFuncArg arrayFuncArg funcReturn funcCode EL

%start begin

%left '+' '-' '*' '/'
%right '=' '^'


%%

begin : header 																								
	    datatypes																							 
		identifiers 																						{ insert_type_table(); } 
		'(' 																								{ add('t'); }  
		normalFuncArg																						
		')' 																								{ add('t'); } 
		'{'																									{ add('t'); } 
	 	funcCode  																							{ printf("Label next:\n"); }  
	 	funcReturn 
		'}' { 
			$$.nd = mknode(NULL,$12.nd,"start"); 
			printf("#######################################################################################\n");
			printf("\t\t\tSyntax Tree in Inorder traversal\n#######################################################################################\n");
			printtree($$.nd);
			printf("\n\n");
			add('t');
		};

header 	: header header 																						{;} 
		| INCLUDE 																								{ add('H'); };



datatypes 	: INT   																							{ insert_type(); } 
  			| FLOAT 																							{ insert_type(); }
			| CHAR  																							{ insert_type(); } 
			| VOID  																							{ insert_type(); };



normalFuncArg 	: normalFuncArg ',' 																			{ add('t'); } 
				normalFuncArg
				| datatypes pointerFuncArg terminate 
				| pointerFuncArg terminate
				;



terminate 	: ';' 																								{ add('t'); } 
			| 
			;



pointerFuncArg : identifiers 																					{ insert_type_table(); } 
				arrayFuncArg																					{;} 
				| '*' 																							{ add_ptr(); } 
				pointerFuncArg 
				;
 

// this if array function argument
arrayFuncArg	: '[' 																								{ add('t'); } 
					NUM 																							{ add('n'); } 
					']' 
					arrayFuncArg 
				| '[' identifiers ']' arrayFuncArg 
				| '[' { add('t'); } ']' arrayFuncArg 
				|  
				;


funcReturn 	:	 RETURN NUM 																						{ add('n'); } 
				';' 																								{ add('t'); printf("Return\t%s\n",$2.name); } 
			| RETURN identifiers 
			';' 																								{ add('t'); printf("Return\t%s\n",$2.name);}
			| 
			;

funcCode :	IF 																									{ add('k'); } 
			'(' 
			logicalCond 
			')' 																								{ printf("\nLabel\t%s:\n",$4.tr); }
			'{' 																								{ addTo('{',"Punctuations"); } 
			funcCode 
			'}' 																								
																												{ 
																													addTo ('}',"Punctuations");
																													pop();
																													printf("goto next\n");
																													printf("\nLabel\t%s:\n",$4.fal);} EL {$$.nd=mknode($4.nd,$9.nd,"IF");
																													strcpy($$.name,"IF");
																												}
			| assign 																							{$$.nd=$1.nd;}
			| datatypes identifiers terminate {
				$$.nd=mknode(NULL,NULL,"definition"); 
				int i=sym_search($2.name);
				if(i!=-1)
					{
						if(strcmp($1.name,"int")==0)
						{
							addTo('i',$2.name);
						} else if(strcmp($1.name,"float")==0)
									addTo('f',$2.name);
							else 
								addTo('c',$2.name);
					}
					else { 
						printf("Variable already defined, error at line no: %d\n",yylineno);
						exit(0);
					}
				}
			| funcCode funcCode {
				$$.nd=mknode($1.nd,$2.nd,"statement");
				strcpy($$.name,"STATEMENT");
			}
			| printff  { add('f');} '(' STRLT ')'';' {$$.nd = mknode(NULL,NULL,"printf");}
			| scanff { add('f');}'('STRLT ',''&'identifiers')' ';'{$$.nd = mknode(NULL,NULL,"scanf");}
			| { $$.nd=mknode(NULL,NULL,"EPSILON"); };


EL: 	ELSE 																								{ add('k'); } 
		'{' 																								{ addTo('{',"Punctuations"); } 
		funcCode 
		'}'		
		{
			$$=$5;addTo('}',"Punctuations");
			pop();
			printf("goto next\n");
			printf("\n");}| {printf("goto next\n");
			printf("\n");
		};

Arg : STRLT ;

logicalCond : logicalCond AND B | logicalCond OR B | NE B | B{$$.nd=$1.nd;};

B : 	relationalCond relop relationalCond {
				$$.nd=mknode($1.nd,$3.nd,$2.name);
				int i=search($1.name);
				int j=search($3.name);
				if(i!=0 && j!=0) {
					printf("if %s %s %s goto L%d else goto L%d\n",$1.name,$2.name,$3.name,ifd,eld);
					sprintf($$.tr,"L%d",ifd);
					sprintf($$.fal,"L%d",eld);ifd++;eld++;}   
				else {
					printf(" Variable not declared at line no: %d\n", yylineno);
					exit(0);
					}
				}   
   		| 	identifiers '=' { add('o'); } 
			 	relationalCond { 
						int i=search($1.name);
 						int j=search($4.name);
 						if(i!=0&&j!=0)
						{
						printf("if %s!=0 goto L%d else goto L%d\n",$1.name,ifd,eld);
						sprintf($$.tr,"L%d",ifd);
						sprintf($$.fal,"L%d",eld);ifd++;eld++;} 
						else
							{
								printf(" Variable not declared at line no: %d\n", yylineno);
								exit(0);
							}
					} 
		|	FL { 
				printf("if False  goto L%d\n",eld);
				sprintf($$.tr,"L%d",ifd);
				sprintf($$.fal,"L%d",eld);ifd++;eld++;
				} 
		|	TR {
				printf("if True  goto L%d\n",ifd);
				sprintf($$.tr,"L%d",ifd);
				sprintf($$.fal,"L%d",eld);ifd++;eld++;
				} 
		|	 identifiers { 
					int i=search($1.name);
					if(i!=0)
					{
						printf("if %s!=0  goto L%d else goto L%d\n",$1.name,ifd,eld);
						sprintf($$.tr,"L%d",ifd);
						sprintf($$.fal,"L%d",eld);ifd++;eld++;}    
					else {
						printf(" Variable not declared at line no: %d\n", yylineno);
					exit(0);
					} 
				}
			| NUM {
					add('n');
					printf("if %s!=0  goto L%d else goto L%d\n",$1.name,ifd,eld);
					sprintf($$.tr,"L%d",ifd);
					sprintf($$.fal,"L%d",eld);
					ifd++;eld++;
				};

assign :  identifiers 
					'=' { add('o'); } 
					relationalCond ';' {
						$1.nd = mknode(NULL,NULL,$1.name);
						$$.nd=mknode($1.nd,$4.nd,"=");
						strcpy($$.name,"=");add('t');
						int i=search($1.name);
						int j=search($4.name);
						if(i!=0&&j!=0) 
						{
							type_check($1.name,$4.name);
							printf("= \t %s\t %s \n",$4.name,$1.name);} 
							else {
								printf("Variable not declared at line no: %d\n", yylineno);
								exit(0);
							}
						} 
				| identifiers '(' Arg ')' ';' {add('t');};

relationalCond :	relationalCond 
		'+' { add('o'); }
		relationalCond { 
				$$.nd=mknode($1.nd,$4.nd,"+");
				strcpy($$.name,"+");
				int i=search($1.name);
				int j=search($4.name);
				sprintf($$.name,"t%d",c);
				c++;
				addTo(temptype($1.name,$4.name),$$.name);
				if(i!=0 && j!=0) {
					printf("%s\t%s\t%s\t%s\n","+",$1.name,$4.name,$$.name);
				}
				else {
					printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
					}
			}

	| relationalCond '-' {add('o');} relationalCond { 
			$$.nd=mknode($1.nd,$4.nd,"-");
			strcpy($$.name,"-");
			int i=search($1.name);
			int j=search($4.name);
			sprintf($$.name,"t%d",c);c++;
			addTo(temptype($1.name,$4.name),$$.name);
			if(i!=0 && j!=0) {
				printf("%s\t%s\t%s\t%s\n","-",$1.name,$4.name,$$.name);
			} 
			else {
				printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
			}
		}
	| F { $$.nd=$1.nd; };
	
	
F :	 F '*' { add('o'); } F {
			$$.nd=mknode($1.nd,$4.nd,"*");
			strcpy($$.name,"*");
			int i=search($1.name);
			int j=search($4.name);
			sprintf($$.name,"t%d",c);c++;
			addTo(temptype($1.name,$4.name),$$.name);
			if(i!=0 && j!=0) {
				printf("%s\t%s\t%s\t%s\n","*",$1.name,$4.name,$$.name);
			}
			else {
				printf(" Variable not declared at line no: %d\n", yylineno);exit(0);
				}
			}

	| F '/' { add('o');} F { $$.nd=mknode($1.nd,$4.nd,"/");
	strcpy($$.name,"/"); 
	int i=search($1.name);
	int j=search($4.name);
	sprintf($$.name,"%d",c);
	strcat($$.name,"t");c++;
	addTo(temptype($1.name,$4.name),$$.name);
	if(i!=0 && j!=0) 
	{
		printf("%s\t%s\t%s\t%s\n","/",$1.name,$4.name,$$.name);
	}
	 else {
		 printf(" Variable not declared at line no: %d\n", yylineno);
	 exit(0);
	 }
	}

	| T {$$.nd=$1.nd;};

	
T :	T '^' { add('o'); } T { 
		$$.nd=mknode($1.nd,$4.nd,"^");
		strcpy($$.name,"^");
		int i=search($1.name);
		int j=search($4.name);
		sprintf($$.name,"%d",c);
		strcat($$.name,"t");c++;
		addTo(temptype($1.name,$4.name),$$.name);
		if(i!=0 && j!=0) {
			printf("%s\t%s\t%s\t%s\n","^",$1.name,$4.name,$$.name);} 
		else {
			printf(" Variable not declared at line no: %d\n", yylineno);
			exit(0);
			}
		}

	| Q {$$.nd=$1.nd;};

	
Q : '(' {add('t');} relationalCond ')' {add('t'); $$=$3;} 
	| identifiers {insert_type_table();} arrayFuncArg {$$.nd=mknode(NULL,NULL,$1.name);strcpy($$.name,$1.name);}
	| NUM{add('n');}{$$.nd=mknode(NULL,NULL,$1.name);
		strcpy($$.name,$1.name);} ;


relop : LE {add('r');} | GE {add('r');}| LT {add('r');} | GT {add('r');}| EQ {add('r');};

%%

int main()
{
	extern int yylineno;
	x.val=10;
	printf("#######################################################################################\n");
	printf("\t\t\tIntermediate code\n");
	printf("#######################################################################################\n");
	yyparse();
	
	printf("\nParsing is Successful\n");	
	printf("#######################################################################################\n");
	printf("\t\t\tSymbol table\n");
	printf("#######################################################################################\n");	
	printf("\nsymbol \t type  \t identify \t line number\n");
	printf("_______________________________________________________________________________________\n");
	int i=0;	
	for(i=0;i<count;i++){
		printf("%s\t%s\t%s\t%d\t\n",symbolTable[i].id_name,symbolTable[i].data_type,symbolTable[i].type,symbolTable[i].line_no);
		
	}
	for(i=0;i<count;i++){
		free(symbolTable[i].id_name);
		free(symbolTable[i].type);
	}
	return 0;
}


void yyerror(const char* s){
	printf("Not accepted\n");
	exit(0);
}


//insert the type into symboltable
void insert_type(){
	strcpy(type,yytext);
	q=search(type);
	if(q==0){
		symbolTable[count].id_name=strdup(yytext);
		symbolTable[count].data_type=strdup("N/A");
		symbolTable[count].line_no = countn;
		symbolTable[count].type=strdup("KEYWORD\t");
		count++;
	}
}


struct node1* mknode(struct node1 *left, struct node1 *right, char *token)
{
  struct node1 *newnode = (struct node1 *)malloc(sizeof(struct node1));
  char *newstr = (char *)malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}


void pop()
{
	int i;
	//printf("count %d\n",count);
	int temp=count-1;
	for(i=temp;i>=0;i--)
	{
		if(strcmp(symbolTable[i].id_name,"{")!=0)
		{
			//printf("$$\n");
			count=count-1;;
		}
		else
		{
			count=count-1;
			break;
		}
	}	
	
}

//add declaration of data to symboltable
void addTo(char i,char *n)
{
	if(i=='i')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="int";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='f')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="float";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='c')
	{
			symbolTable[count].id_name=strdup(n);
			symbolTable[count].data_type="char";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("variable");
			count++;
	}
	else if(i=='{')
	{
			symbolTable[count].id_name=strdup("{");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
	else if(i=='}')
	{
			symbolTable[count].id_name=strdup("}");;
			symbolTable[count].data_type="N/A";
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("punctuation");
			count++;
	}
}


char temptype(char* one,char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if((strcmp(onetype,"float")==0) || (strcmp(twotype,"float")==0))
		return 'f';
	else
		return 'i';
}


void insert_type_table(){
		q=search(yytext);
		if(q==0){
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("IDENTIFIER");
			count++;
		}
	
	
}


void type_check(char* one, char* two)
{
	int y;
	char* onetype;
	char* twotype;
	for(y = 0;y<count;y++)
	{
		if(strcmp(symbolTable[y].id_name,one)==0) onetype=symbolTable[y].data_type;
		if(strcmp(symbolTable[y].id_name,two)==0) twotype=symbolTable[y].data_type;	
	}
	if(strcmp(onetype,twotype)>0){ printf("type error at lineno %d\n",yylineno);exit(0);}
}

//ADD the recent parsed string into symboltable
void add(char c)
{
	q=search(yytext);
	if(q==0){
		if(c=='H')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup(type);
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Header");
			count++;
		}
		else if(c=='t')
		{	
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Punctuation");
			count++;
		}
		else if(c=='o')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Operator");
			count++;
		}
		else if(c=='r')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("Rel Op\t");
			count++;
		}
		else if(c=='k')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("KEYWORD\t");
			count++;
		}
		else if(c=='n')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("int");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("NUMBER\t");
			count++;
		}
		else if(c=='f')
		{
			symbolTable[count].id_name=strdup(yytext);
			symbolTable[count].data_type=strdup("N/A");
			symbolTable[count].line_no = countn;
			symbolTable[count].type=strdup("FUNCTION\t");
			count++;
		}
	}
}


int  sym_search(char *type)
{
	int i;
	for(i=count -1 ;i>=0&&(strcmp(symbolTable[i].id_name,"{")!=0);i--)
	{
		if(strcmp(symbolTable[i].id_name,type)==0)
		{
			return -1;
			break;
		}
	}
	return 0;
}


//Search in the Symbol table whether the parsed String is present in Symbol table already
int  search(char *type) {
	int i;
	for(i=count -1 ;i>=0;i--){
		if(strcmp(symbolTable[i].id_name,type)==0){
			return -1;
			break;
		}
	}
	return 0;
}


void add_ptr(){
	strcat(type,"*");
}


//print the abstract syntax tree
void printtree(struct node1* tree){
  	int i;
  	if (tree->left){
		printtree(tree->left);
	}
 	printf(" %s , ", tree->token);
  	if (tree->right){
		printtree(tree->right);
	}
}
