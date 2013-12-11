all: balanced

balanced: InPostFix.o InPostFixConverter.o InPostFixHelp.o
	g++ InPostFix.o InPostFixConverter.o InPostFixHelp.o -o PostfixInfix

balanced.o: InPostFix.cpp
	g++ -c InPostFix.cpp

bracechecker.o: InPostFixHelp.cpp
	g++ -c InPostFixHelp.cpp

option.o: InPostFixConverter.cpp
	g++ -c InPostFixConverter.cpp

clean:
	rm -rf *o PostfixInfix
