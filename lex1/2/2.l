%{
#include<stdio.h>
#include<string.h>
int var=0,op=0,c=0;
%}

%%
[A-Z]+|[a-zA-Z]+[0-9]+|[a-zA-Z0-9_]*	{var++;printf("variable: ");ECHO;printf("\n");}
"+"|"-"|"*"|"/"|"%" 				{op++;printf("operator: ");ECHO;printf("\n");}
"/*".*"*/"|"//".*				{c++;ECHO;}
"/*".*|\n"*/"					{c++;ECHO;}
%%

int yywrap()
{
return 1;
}

void main()
{
yyin=fopen("input.c","r");
yylex();
printf("identifiers: %d\n",var);
printf("operators: %d\n",op);
printf("comments: %d\n",c);
}
