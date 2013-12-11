#include "InPostFixHelp.h"
#include <iostream>

using namespace std;

void help()
{
	cout << "Usage: InPostFixConverter [OPTION] [FILE] [FUNCTION]...\n\n"
                << "Options:\n"
                << "-q          suppress normal output\n"
                << "-h          display this help message\n\n"
		<< "Functions:\n"
		<< "1		Infix to Postfix Conversion\n"
		<< "2		Postfix to Infix Conversion\n";

        return;

}
