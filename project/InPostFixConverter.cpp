#include <iostream>
#include <fstream>
#include <string>
#include "InPostFix.h"
#include "InPostFixHelp.h"
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[])
{
	int opt;
	bool option = false;
	bool quiet = false;
	bool overwrite = false;

	while((opt = getopt(argc, argv, "qho:")) != -1)
	{
		switch(opt) 
		{
			case 'h':
			{
				help();
				return 0;
			}
			case 'q':
			{
				quiet = true;
				option = true;
				break;
			}
			case 'o':
			{
				overwrite = true;
				option = true;
				break;
			}
			default:
			{
				help();
				return 3;
			}
		}
	}

	if ((argc <= 2 && !option) || (argc <= 3 && option))

        {
		//InPostFix C(cin,*argv[argc-1],quiet);
		return 0;
        }

	int i;

        if(option)
        {
                i = 2;
        }
        else
        {
                i = 1;
        }
        for (i; i < argc; i+=2)

        {

                ifstream in(argv[i]);

                if (!in.is_open())

                {
                        cerr <<  argv[i] << ": cannot be opened\n";
                }

                else
                {
			string line;
			string temp;
			char tempchar;
			
			while (in >> tempchar)
			{
				temp = tempchar;
				line.append(temp);			
                	}
			InPostFix C(line, *argv[i+1]);
			line = C.GetExpression();
			if(!quiet)
			{
				if(overwrite)
				{
					cout << "Overwritten to " << argv[i] << ":\n";
				}
				cout << line << endl;
			}
			if(overwrite)
			{
				ofstream out;
				out.open(argv[i], ofstream::out | ofstream::trunc);
				out << line << endl;
				out.close();
			}
		}

        }



return 0;
}
