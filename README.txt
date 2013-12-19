Infix Postfix Conversion

contributors: grubb2k7, carlb15
url: https://github.com/carlb15/PostfixInfix

The project converts between infix and postfix form for a given equation
from either the command line or a file. The results are printed to
standard out or to a file.

<!-- more -->

Description of the project. 
Takes either a file or command line input to convert an infix equation 
to postfix and vice versa. The results are either printed to a file or 
to the standard output. The modular design makes the infix/postfix 
algorithm the strong single center of the program. The other modules
provide a thin interface wrapper for the algorithm. Finally, the clean
output is simple and easily extensible for adding new modules.

Building the project:
run make command and have g++ downloaded.

Usage: ./PostfixInfix [OPTION] [INPUT FILE] [FUNCTION]...
Options:
-q		suppress normal output
-h		display this help message
-o		overwrites a file designated on run time with input and output
		data of conversion.  If file does not exist user can create
		a new file.
-a		appends the input and output data of conversion to a file
		designated on run time.  If file does not exist user can
		create a new file.

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
 abcd^e-fgh/+^*+i- =
 ab+ =
 ab* =
 AB/ =
 aB^ =
