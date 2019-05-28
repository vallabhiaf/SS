%{
#include<stdio.h>
int p=0,n=0,pf=0,nf=0;
%}

%%
"+"?[0-9]+		{p++;ECHO;}
"-"[0-9]+			{n++;ECHO;}
"+"?[0-9]*\.[0-9]+	{pf++;ECHO;}
"-"[0-9]*\.[0-9]+		{nf++;ECHO;}
%%

int yywrap()
{
return 1;
}

void main()
{
printf("enter number:");
//yyin=fopen("input.txt","r");
yylex();
printf("%d %d %d %d",p,n,pf,nf);
}
