#include <iostream>
#include <fstream>
#include <string>
#include "InPostFix.h"
#include "InPostFixHelp.h"
#include <getopt.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[])
{
	int opt;
	bool option = false;
	bool quiet = false;
	bool overwrite = false;

	string line;
	string temp;
	char tempchar;
	string overwritearg;
	char* overwritechar;
	
	opterr = 0;

	while((opt = getopt(argc, argv, "hqo")) != -1)
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
				break;
			}
			case 'o':
			{
				overwrite = true;
				break;
			}
			default:
			{
				help();
				return 2;
			}
		}
	}
	if(overwrite)
	{
		if((optind + 1) == argc)
		{
			cout << "\nType existing file name to be overwritten\n\n";
		}
		else
		{
			cout << "\nType 'original' to overwrite: " << argv[optind] << endl
			<< "Type 'pass' to skip overwriting file: " << argv[optind] << endl
			<< "Or\n"
			<< "Type existing file name\n\n";
		}
		while(cin >> overwritearg)
		{
			temp = overwritearg;
			transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			if(temp == "original" || temp == "pass")
			{
				overwritearg = temp;
				break;
			}
			ifstream in(overwritearg.c_str());
			if(!in.is_open())
			{
				if((optind + 1) == argc)
				{
					cout << "\nCould not find file: " << overwritearg
						<< "\nType existing file name to be overwritten\n\n";
				}
				else
				{
					cout << "\nCould not find file: "
					<< overwritearg << ".\nPlease insert existing file "
					<< "name\n"
					<< "Type 'original' to overwrite: " << argv[optind] << endl
					<< "Or\n"
					<< "Type 'pass' to skip overwriting file: " << argv[optind] << endl << endl;
				}
			}
			else break;
		}
	}
	if ((optind + 1) == argc)
        {
		cout << "\nType expression then press 'Enter, Ctrl+D'\n\n";
		while(cin >> temp)
		{
			line.append(temp);
		}
		InPostFix C(line, *argv[argc-1]);
		line = C.GetExpression();
		if(!quiet)
		{
			cout << endl;
			if(overwrite)
			{
				cout << "Overwriting to: " << overwritearg << endl;
			}
			else
			{
				cout << "The converted expression is:\n";
			}
			cout << line << endl << endl;
		}
		if(overwrite)
		{
			ofstream out;
			out.open(overwritearg.c_str(), ofstream::out | ofstream::trunc);
			out << line << endl;
			out.close();
		}
		return 0;
        }
        for (int i = optind; i < argc; i+=2)

        {

                ifstream in(argv[i]);

                if (!in.is_open())

                {
                        cerr <<  argv[i] << ": cannot be opened\n";
			return 1;
                }

                else
                {			
			while (in >> tempchar)
			{
				temp = tempchar;
				line.append(temp);			
                	}
			in.close();
			InPostFix C(line, *argv[i+1]);
			line = C.GetExpression();

			if(!quiet)
			{
				if(overwrite)
				{
					if(overwritearg == "original")
					{
						cout << "Overwritten to " << argv[i] << ":\n";
					}
					else if(overwritearg == "pass")
					{
						cout << "Overwritting did not occur.\n";
					}
					else
					{
						cout << "Overwritten to " << overwritearg << ":\n";
					}				
				}
				cout << line << endl << endl;
			}
			if(overwrite)
			{
				if(overwritearg == "original")
				{
					ofstream out;
					out.open(argv[i], ofstream::out | ofstream::trunc);
					out << line << endl;
					out.close();
				}
				else if(overwritearg == "pass")
				{
				}
				else
				{
					ifstream in(overwritearg.c_str());
					if(!in.is_open())
					{
						cerr << "File " << overwritearg << " cannot be opened\n"
							<< "Cannot overwrite file\n";
						return 1;
					}
					else
					{
						ofstream out;
						out.open(overwritearg.c_str(), ofstream::out | ofstream::trunc);
						out << line << endl;
						out.close();
					}
				}
				if((i+2) != argc)
				{
					cout << "Type 'original' to overwrite the original file: " << argv[i+2] << endl
						<< "Type 'pass' to skip writing data for file: " << argv[i+2] << endl
						<< "Or\n"						
						<< "Type an existing file name to be overwritten.\n\n";
					while(cin >> overwritearg)
					{
						cout << endl;
						temp = overwritearg;
						transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
						if(temp == "original" || temp == "pass")
						{
							overwritearg = temp;
							break;
						}
						ifstream in(overwritearg.c_str());
						if(!in.is_open())
						{
							cout << "\nCould not find file: " << overwritearg
								<< ".\nPlease insert existing file "
								<< "name\n"
								<< "Type 'original' to overwrite: " << argv[optind] << endl
								<< "Or\n"
								<< "Type 'pass' to skip overwriting file: " << argv[optind] << endl
								<< endl;
						}
						else break;
					}
				}
			}
		}
		line.clear();
        }



return 0;
}
