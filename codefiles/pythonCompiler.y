%{
    #include<stdio.h>
    #include<string.h>  
	
	int yylineno;

	int yylex();
	void yyerror(char *s);

	char temp[100];
	char temp_no[10]="0";
	//int temp_no=0;
	
	struct ICG
	{
		char op[10];
		char op1[10];
		char op2[10];
		char res[10];
	}ICG[100];
	int ICG_no=0;

	struct sym_tab
	{
		char name[10];
		char type[10];
		char val[10];
	}sym_tab[100];
	int sym_no=0;

	char stk[100][10];
	int top=0;

	char labl[100][10];
	int lab=0;
	
	char label[10]="L";
	char label_no[10]="0";
	
	FILE *fptr;

	void disp_quad();
	void code_assign();
	void code_temp();
	void for1();
	void for2();
	void print();
	void create_quad(char *op, char *op1, char *op2, char *res);
	void create_symtab(char *name, char *type, char *value);
	int searchsymbol(char *var);
	void disp_symtab();
	void ifblock();
	void elseblock();
	void block_exit();
	void loop_incr();
    void slice_str(const char * str, char * buffer, size_t start, size_t end);
	
%}

%token <str> FOR WHILE DQT
%token <str> IF IN RANGE ELIF ELSE PRINT
%token TAB 
%token <str> NUM ID

%right '='
%left '(' ')'
%left AND OR
%left '<' '>' LE GE EQ NE LT GT



%union 
{
    int ival;           
    double dval;
    char str[10];
}
%type <str> Assignment
%%

start:	| Assignment start
		| PrintFunc start
		| IfStmt start
		| ForStmt start
       ;
 

Assignment: ID {  strcpy(stk[++top],$1);} '=' expr { code_assign(); }
	;

expr: ID { strcpy(stk[++top],$1); } '+' expr { strcpy(stk[++top],"+"); code_temp();}
	| ID { strcpy(stk[++top],$1); } '-' expr { strcpy(stk[++top],"-"); code_temp();}
	| ID { strcpy(stk[++top],$1); } '*' expr { strcpy(stk[++top],"*"); code_temp();}
	| ID { strcpy(stk[++top],$1); } '/' expr { strcpy(stk[++top],"/"); code_temp();}
	| NUM { strcpy(stk[++top],$1); } '+' expr  { strcpy(stk[++top],"+"); code_temp();}
	| NUM { strcpy(stk[++top],$1); } '-' expr  { strcpy(stk[++top],"-"); code_temp();}
	| NUM { strcpy(stk[++top],$1); } '*' expr  { strcpy(stk[++top],"*"); code_temp();}
	| NUM { strcpy(stk[++top],$1); } '/' expr  { strcpy(stk[++top],"/"); code_temp();}
	| ID {  strcpy(stk[++top],$1); } LE {strcpy(stk[++top],"<="); } expr 
	| ID {  strcpy(stk[++top],$1); } GE {strcpy(stk[++top],">="); } expr
	| ID {  strcpy(stk[++top],$1); } NE {strcpy(stk[++top],"!="); } expr
	| ID {  strcpy(stk[++top],$1); } GT {strcpy(stk[++top],">"); } expr
	| ID {  strcpy(stk[++top],$1); } LT {strcpy(stk[++top],"<"); } expr
	| ID {  strcpy(stk[++top],$1); } EQ {strcpy(stk[++top],"=="); } expr
	| NUM { strcpy(stk[++top],$1); } LE {strcpy(stk[++top],"<="); } expr
	| NUM { strcpy(stk[++top],$1); } GE {strcpy(stk[++top],">="); } expr
	| NUM { strcpy(stk[++top],$1); } NE {strcpy(stk[++top],"!="); } expr
	| NUM { strcpy(stk[++top],$1); } GT {strcpy(stk[++top],">"); } expr
	| NUM { strcpy(stk[++top],$1); } LT {strcpy(stk[++top],"<"); } expr
	| NUM { strcpy(stk[++top],$1); } EQ {strcpy(stk[++top],"=="); } expr
	| NUM { strcpy(stk[++top],$1); } 
	| ID  { strcpy(stk[++top],$1); }

PrintFunc:  PRINT '('  expr ')' {print();}
          | PRINT '(' DQT expr DQT ')' {print();}
	  | TAB PRINT '('  expr ')' {print();} 
	;
	
ForStmt: FOR  ID{  strcpy(stk[++top],$2); } IN RANGE '(' args')' ':'  TAB blockStmt {loop_incr();}{block_exit();}
         ;
		 
args: expr {for1();}
	|	expr ',' expr {for2();}
				
blockStmt: PrintFunc
		| Assignment 
		
IfStmt: IF '(' expr ')' {ifblock();}':'  TAB blockStmt  ElseStmt {block_exit();}
	;
	
ElseStmt: ELSE ':' TAB {elseblock();}  blockStmt
	  ;
	  
%%

#include "lex.yy.c"
#include<ctype.h>

int main(int argc, char *argv[])
{
	yyin =fopen(argv[1],"r");
	fptr = fopen("out0.txt","w");
	printf("\n ********* INTERMEDIATE CODE GENERATION *********\n");
	yyparse();
	printf("\n ********* QUADRUPLES *********\n\n");
	disp_quad();
	printf("\n ********* SYMBOL TABLE *********");
	disp_symtab();
	fclose(yyin);
	fclose(fptr);
	return 0;
}
char toks[7][10]={"for","print","if","else","while","range","in"};
void slice_str(const char * str, char * buffer, size_t start, size_t end)
{
    size_t j = 0;
    for ( size_t i = start; i <= end; ++i ) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}
void yyerror(char *s) {
        
	printf("\nError!! %s in line no. %d %s\n", s , yylineno, yytext);
        const size_t len = strlen(yytext);
        char buffer[len + 1];

        for ( size_t start = 0; start < len; ++start ) {
            for ( int end = len - 1; end >= (int) start; --end ) {
               slice_str(yytext, buffer, start, end);
               //printf("%s\n", buffer);
	       for(int j=0;j<7;j++)
	       {
	         if(strcmp(buffer,toks[j])==0)
		 {
		    printf("Error recovery successful!!");
		    printf("\n correct word: %s\n",toks[j]);
		   }
	       }
           }
       }

}  

int yywrap(void) {
        return 1;
}

void disp_quad()
{
	printf("Operator Operand-1 Operand-2 Result\n");
	for(int i=0; i<ICG_no; i++)
	{
		printf("  %s     \t %s \t %s \t %s \n", ICG[i].op,ICG[i].op1,ICG[i].op2, ICG[i].res);
	}
}

void loop_incr()
{
	printf("\n%s = %s + 1 \n", stk[top],stk[top]);
	fprintf(fptr,"\n%s = %s + 1 \n", stk[top],stk[top]);
	create_quad("+", stk[top] , "1" , stk[top] );
	printf("\ngoto %s\n", labl[lab]);
	fprintf(fptr,"\ngoto %s\n", labl[lab]);
}

void ifblock()
{
	//printf("In ifblock");
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s %s %s \n",temp,stk[top-2],stk[top-1],stk[top]);
	fprintf(fptr,"\n%s = %s %s %s \n",temp,stk[top-2],stk[top-1],stk[top]);
	create_quad(stk[top-1], stk[top-2] , stk[top] , temp);

	top-=3;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;	

	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] , " " , temp);

	//top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	
	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);
	strcpy(labl[++lab],label);
	
	//printf("done");
	
}

void elseblock()
{
	//printf("In else block");
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\ngoto %s\n", label);
	fprintf(fptr,"\ngoto %s\n", label);
	strcpy(labl[++lab],label);
	printf("\n%s : \n\n", labl[--lab]);
	fprintf(fptr,"\n%s : \n\n", labl[--lab]);
	//lab-=1;
}

void block_exit()
{
	printf("\n%s : \n\n", label);
	fprintf(fptr,"\n%s : \n\n", label);
	lab-=2;
}

void code_assign()
{
	if(strcmp(stk[top],"ERROR")==0);
	else
	{
		printf("\n%s = %s\n",stk[top-1],stk[top]);
		fprintf(fptr,"\n%s = %s\n",stk[top-1],stk[top]);
		create_quad("=", stk[top] , " " , stk[top-1]);

		int ss1,ss2,a=-1,b=-1,c=9999;
		float d=9999.9;
		char val[10];

		b=atoi(stk[top]);

		if(b==0)
		{
			ss1=searchsymbol(stk[top]);
			if(ss1==-1){
				printf("\nError: %s is Undefined variable \n",stk[top]);
			}
			else{ 
				create_symtab(stk[top-1], sym_tab[ss1].type , sym_tab[ss1].val);
			}
		}
		else
			create_symtab(stk[top-1], "INT" , stk[top]);
	}
	top-=2;
} 

void code_temp()
{
	strcpy(temp,"t");
	strcat(temp,temp_no);
	
	int ss1,ss2,a=-1,b=-1,c=9999,z1,z2;
	double d=9999.9;
	char val[10];
	
	printf("\n%s = %s %s %s\n",temp,stk[top-2],stk[top],stk[top-1]);
	fprintf(fptr,"\n%s = %s %s %s\n",temp,stk[top-2],stk[top],stk[top-1]);
	create_quad(stk[top], stk[top-2] , stk[top-1] , temp);

	z1=atoi(stk[top-1]);
	if (z1!=0){
		b=z1;
	}
	else{
		ss2=searchsymbol(stk[top-1]);

		if(ss2==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-1]);
		else{
			b=atoi(sym_tab[ss2].val);
		}	
	}
	
	
	z2=atoi(stk[top-2]);
	if (z2!=0){
		a=z2;
	}
	else
	{
		ss1=searchsymbol(stk[top-2]);

		if(ss1==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-2]);
		else {
			a=atoi(sym_tab[ss1].val);
		}
	}
	

	char sym_plus[5]="+";
	char sym_min[5]="-";
	char sym_mul[5]="*";
	char sym_div[5]="/";

	if((strcmp(stk[top],sym_plus)==0) && a!=-1 && b!=-1)
	{
		c=a+b;	
	}
	if(strcmp(stk[top],sym_min)==0 && a!=-1 && b!=-1)
	{
		c=a-b;	
	}
	if(strcmp(stk[top],sym_mul)==0 && a!=-1 && b!=-1)
	{
		
		d=a*b;	
	}
	if(strcmp(stk[top],sym_div)==0 && a!=-1 && b!=-1)
	{
		if (b!=0)
			d=a/b;	
		else
			printf("\n Error: Division by zero\n");
	}
	
	if(c!=9999)
	{
		sprintf(val,"%d",c);
		create_symtab(temp, "INT" , val);
	}

	if(c==9999 && d!=9999.9)
	{
		sprintf(val,"%lf",d);
		create_symtab(temp, "FLOAT" , val);
	}

	if(c==9999 && d==9999.9);
	
	top-=3;
	strcpy(stk[++top],temp);
	temp_no[0]++;
} 

void for1()
{
	printf("\n%s = 0\n",stk[top-1]);
	fprintf(fptr,"\n%s = 0\n",stk[top-1]);
	create_quad("=", "0" , " " , stk[top-1]);

	create_symtab(stk[top-1], "INT" , "0");
	
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	strcpy(labl[++lab],label);

	printf("\n%s :\n",label);
	fprintf(fptr,"\n%s :\n",label);

	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s < %s \n",temp,stk[top-1],stk[top]);
	fprintf(fptr,"\n%s = %s < %s \n",temp,stk[top-1],stk[top]);
	create_quad("<", stk[top-1] , stk[top] , temp);

	top-=1;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;	

	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] , " " , temp);

	top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);

	strcpy(labl[++lab],label);
	lab-=1;
} 

void for2()
{
	printf("\n%s = %s\n",stk[top-2],stk[top-1]);
	fprintf(fptr,"\n%s = %s\n",stk[top-2],stk[top-1]);
	create_quad("=", stk[top-1] , " " , stk[top-2]);

	int ss1,ss2,a=-1,b=-1,c=9999;
	float d=9999.9;
	char val[10];

	b=atoi(stk[top-1]);

	if(b==-1)
	{
		ss1=searchsymbol(stk[top-1]);
		if(ss1==-1)
			printf("\nError: %s is Undefined variable \n",stk[top-2]);
		else{ 
			create_symtab(stk[top-2], sym_tab[ss1].type , sym_tab[ss1].val);
		}
	}
	else
		create_symtab(stk[top-2], "INT" , stk[top-1]);

	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;
	strcpy(labl[++lab],label);

	printf("\n%s :\n",label);
	fprintf(fptr,"\n%s :\n",label);

	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = %s < %s \n",temp,stk[top-2],stk[top]);
	fprintf(fptr,"\n%s = %s < %s \n",temp,stk[top-2],stk[top]);
	create_quad("<", stk[top-2] ,stk[top] , temp);

	top-=2;
	strcpy(stk[++top],temp);
	strcpy(temp,"t");
	strcat(temp,temp_no);
	temp_no[0]++;
	
	printf("\n%s = not %s \n",temp,stk[top]);
	fprintf(fptr,"\n%s = not %s \n",temp,stk[top]);
	create_quad("not", stk[top] ," " , temp);

	top-=1;
	strcpy(label,"L");
	strcat(label,label_no);
	label_no[0]++;

	printf("\nif %s goto %s\n", temp, label);
	fprintf(fptr,"\nif %s goto %s\n", temp, label);

	strcpy(labl[++lab],label);
	lab-=1;
} 

void print()
{
	printf("\nPRINT %s \n", stk[top]);
	fprintf(fptr,"\nPRINT %s \n", stk[top]);
	//printf("\n%s = %s + 1 \n", stk[top],stk[top]);
	create_quad("PRINT", " " , " " , stk[top] );
	//create_quad("+", stk[top] , "1" , stk[top] );
	top-=1;
	//printf("\ngoto %s \n", labl[lab-1]);
	//printf("\n%s : \n\n", labl[lab]);
	//lab-=2;
} 

void create_quad(char *op, char *op1, char *op2, char *res)
{
	strcpy(ICG[ICG_no].op, op);
	strcpy(ICG[ICG_no].op1, op1);
	strcpy(ICG[ICG_no].op2, op2);
	strcpy(ICG[ICG_no].res, res);
	ICG_no++;
} 

void create_symtab(char *name, char *type, char *value)
{
	strcpy(sym_tab[sym_no].name, name);
	strcpy(sym_tab[sym_no].type, type);
	strcpy(sym_tab[sym_no].val, value);
	sym_no++;
} 

int searchsymbol(char *var)
{
	int o=-1;
	for (int i=0; i<sym_no; i++)
	{
		if(strcmp(sym_tab[i].name,var)==0)
			o = i;
	}
	return o;
} 

void disp_symtab()
{
	printf("\n\nNAME   TYPE   VALUE\n");
	for(int i=0; i<sym_no; i++)
	{
		printf("  %s \t %s \t %s \n", sym_tab[i].name,sym_tab[i].type,sym_tab[i].val);
 	}
}


