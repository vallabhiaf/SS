# lex1
lex programs
$ lex prog3.l
$ gcc lex.yy.c
$ ./a.out test.txt
c is an operand
+ is an operator
d is an operand
/ is an operator
f is an operand

Valid


#YACC
$ lex prog1.l
$ yacc prog1.y -d
$ gcc lex.yy.c y.tab.c -ll
> Ignore the warning
$ ./a.out
a+b
Valid
$ ./a.out
a++b
Invalid 
