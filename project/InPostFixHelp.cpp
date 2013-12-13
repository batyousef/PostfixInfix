#include "InPostFixHelp.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void help()
{
	ifstream in("helpdoc.txt");

		if (!in.is_open())

		{
		        cerr <<  "helpdoc.txt could not be found. Cannot display help message";
		}

		else
		{
			string line;
			cout << endl << endl;
			while(getline(in,line))
			{
				cout << line << endl;
			}
		       
		}

	return;

}
