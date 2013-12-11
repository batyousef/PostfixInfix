Project Title: Infix Postfix Conversion

contributors: grubb2k7, carlb15
url: https://github.com/carlb15/PostfixInfix

Description of the project. 
Takes either a file or command line input to convert an infix equation 
to postfix and vice versa. The results are either printed to a file or 
to the standard output. 

Building the project:
run make command and have g++ downloaded.

Usage: ./PostfixInfix [OPTION] [FILE] [FUNCTION]...
Options:
-q          suppress normal output
-h          display this help message
Functions:
1		Infix to Postfix Conversion
2		Postfix to Infix Conversion

Files:
Each equation must be separated by '=' signs and use only parentheses for 
grouping terms. The last equation does not need to have '=' at the end.

Only "+, -, /, *, ^" operators allowed.

Example: 
  ./PostfixInfix test.txt 1
  In the test.txt:
  a+b*(c^d-e)^(f+g/h)-i = a+b = a*b =
  A/B
  = a^B

Result: 
  abcd^e-fgh/+^*+i-
  ab+
  ab*
  AB/
  aB^
