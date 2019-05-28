%{
#include<stdio.h>
#include<string.h>
int chars=0,words=0,spaces=0,lines=0,sc=0;
%}
%%
"\n"	{lines++;ECHO;}
" "	{words++; spaces++;ECHO;}
[a-zA-Z0-9]	{chars++;ECHO;}
.	{sc++;ECHO;}
%%
int yywrap(){
return 1;}


void main()
{
	yyin=fopen("input1.txt","r");
	yylex();
	printf("\nCharacters: %d\n",chars);
	printf("Words: %d\n",words+lines);
	printf("Spaces: %d\n",spaces);
	printf("Lines: %d\n",lines);
	printf("Special Characters: %d\n",sc);
}
