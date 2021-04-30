%{
	int yylineno;
	#include "project1.tab.h"
	int yylex(void);
	
%}

digit [0-9]
alpha [a-zA-Z]


%%

[\t]   				 {return(TAB);}
[\n]				 {yylineno = yylineno + 1;}
[ ]                  {}
{digit}+			 {strcpy(yylval.str,yytext); return(NUM);}


if    				 { return(IF);}
elif  				 { return(ELIF);}
else  				 { return(ELSE);}
for   			 	 { return(FOR);}
while 				 { return(WHILE);}
in    				 { return(IN);}
range			 	 { return(RANGE);}
print				 { return(PRINT);}
"#"([a-z]|[0-9]|[A-Z]|" ")*      ;
["]                                {return(DQT);}
{alpha}({alpha}|{digit})*	 {strcpy(yylval.str,yytext);return ID;}
"=="    			 { return(EQ);}
"<="    			 { return(LE);}
"!="    			 { return(NE);}
">"				 	 { return(GT);}
">="    			 { return(GE);}
"<"     			 { return(LT);}
#.*       			 ;
.       			 { return yytext[0];}
%%
