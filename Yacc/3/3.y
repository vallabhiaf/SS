%{
    #include <stdio.h>
    #include <stdlib.h>
%}

%token INTEGER NL
%left '+' '-'
%left '*' '/'

%%
stmt :  exp NL { printf ("Value is %d", $1); exit(0);}
	;

exp :   exp '+' exp {$$ = $1 + $3;}
	|exp '-' exp {$$ = $1 - $3;}
	|exp '*' exp {$$ = $1 * $3;}
	|exp '/' exp {$$ = $1 / $3;}
	|'(' exp ')' {$$=$2;}
	|INTEGER {$$ = $1;}
	;
%%
int yyerror(char *msg) {
    printf("Invalid \n");
    exit(0);
}
int main() {
    yyparse();
    return 0;
}
 
