%{
    #include "y.tab.h"
%}

%%
[0-9]+ {yylval = atoi(yytext); return INTEGER;}
[ ] {;}
[\n] {return NL;}
. {return yytext[0];}
%%
