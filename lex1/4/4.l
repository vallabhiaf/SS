%{
#include<stdio.h>
#include<string.h>
int vowel=0,consonants=0,number=0,sc=0,l=0;
%}
%%
[aeiouAEIOU]	{vowel++;ECHO;}
[a-zA-Z]	{consonants++;ECHO;}
[0-9]+		{number++;ECHO;}
.		{sc++;ECHO;}
\n		{l++;ECHO;}
%%

int yywrap()
{
return 1;
}

void main()
{
yyin=fopen("input.txt","r");
yylex();
printf("vowel: %d\n",vowel);
printf("consonants: %d\n",consonants);
printf("number: %d\n",number);
printf("special characters: %d\n",sc);
printf("lines: %d\n",l);
}
