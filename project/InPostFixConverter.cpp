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
	bool quiet = false;
	bool overwrite = false;
	bool append = false;
	bool oa = false;

	string line;
	string temp;
	string temp2;
	char tempchar;
	string arg;
	
	opterr = 0;

	while((opt = getopt(argc, argv, "hqoa")) != -1)
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
			case 'a':
			{
				append = true;
				break;
			}
			default:
			{
				help();
				return 2;
			}
		}
	}
	if(overwrite && append) oa = true;
	if((optind + 1) == argc)
	{
		if(oa)
		{
			cout << "Do you want to overwrite or append output to a file?\n"
				<< "Type 'overwrite' or 'append'\n\n";
			while(cin >> temp)
			{
				transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
				if(temp == "overwrite")
				{
					overwrite = true;
					append = false;
					break;
				}
				else if(temp == "append")
				{
					overwrite = false;
					append = true;
					break;
				}
				else
				{
					cout << "Do you want to overwrite or append output to a file?\n"
						<< "Type 'overwrite' or 'append'\n\n";
				}
			}
		}
		if(append || overwrite)
		{
			if(overwrite)
			{
				cout << "\nType existing file name to be overwritten\n";
			}
			else if(append)
			{
				cout << "\nType existing file name to be appended\n";
			}
			cout << "OR\n" << "Type a new file name to create\n\n";
			while(cin >> arg)
			{
				ifstream in(arg.c_str());
				if(!in.is_open())
				{
					cout << "\nCould not find file: " << arg << endl
							<< "Would you like to create a new file? (Y or N)\n\n";
					cin >> temp;
					transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
					while(true)
					{
						if(temp == "y")
						{						
							break;
						}
						else if (temp == "n")
						{
							cout << "\nType existing file name\n\n";
							cin >> arg;
							ifstream in(arg.c_str());
							if(in.is_open())
							{
								break;
							}
							else
							{
								cout << "\nCould not find file: " << arg << endl
									<< "Would you like to create a new file? (Y or N)\n\n";
								cin >> temp;
								transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
							}
						}
						else
						{
							cout << "Would you like to create a new file? (Y or N)\n\n";
							cin >> temp;
							transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
						}
		
					}
					break;
				}
				else break;
			}
		}
		cout << "\nType expression then press 'Enter, Ctrl+D'\n\n";
		while(cin >> temp)
		{
			line.append(temp);
		}
		InPostFix C(line, *argv[argc-1]);
		ofstream out;
		if(append || overwrite)
		{
			if(overwrite)
			{
				out.open(arg.c_str(), ofstream::out | ofstream::trunc);
			}
			else if(append)
			{
				out.open(arg.c_str(), ofstream::out | ofstream::app);
			}		
			out << "\n\nOriginal Form:\n\n";
			for(int i = 0; i < line.size(); i++)
			{
				if((i+1) == line.size() && line[i] != '=')
				{
					out << line[i] << " =\n";
				}
				else if(line[i] == '=')
				{
					out << " =\n";
				}
				else
				{
					out << line[i];
				}
			}
			out.close();
		}
		line = C.GetExpression();
		if(!quiet)
		{
			cout << endl;
			if(overwrite)
			{
				cout << "Overwriting to: " << arg << endl;
			}
			else if(append)
			{
				cout << "Appending to: " << arg << endl;
			}
			else
			{
				cout << "The converted expression is:\n";
			}
			cout << line << endl << endl;
		}
		if(overwrite || append)
		{
			out.open(arg.c_str(), ofstream::out | ofstream::app);
			out << "\n\nConverted Form:\n\n" << line;
			out.close();
		}

		return 0;
	}
	else
	{
		for (int i = optind; i < argc; i+=2)

		{
			if(oa)
			{
				cout << "Do you want to overwrite or append output for file: " << argv[i] << "?\n"
					<< "Type 'overwrite' or 'append'\n\n";
				while(cin >> temp)
				{
					transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
					if(temp == "overwrite")
					{
						overwrite = true;
						append = false;
						break;
					}
					else if(temp == "append")
					{
						overwrite = false;
						append = true;
						break;
					}
					else
					{
						cout << "Do you want to overwrite or append output to a file?\n"
							<< "Type 'overwrite' or 'append'\n\n";
					}
				}
			}
			if(overwrite || append)
			{
				if(overwrite)
				{
					cout << "\nType existing file name to be overwritten for file: " << argv[i] << endl;
				}
				else if(append)
				{
					cout << "\nType existing file name to be appended for file: " << argv[i] << endl;
				}
				cout << "OR\n" << "Type a new file name to create\n\n";
				while(cin >> arg)
				{
					ifstream in(arg.c_str());
					if(!in.is_open())
					{
						cout << "\nCould not find file: " << arg << endl
								<< "Would you like to create a new file? (Y or N)\n\n";
						cin >> temp;
						transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
						while(true)
						{
							if(temp == "y")
							{						
								break;
							}
							else if (temp == "n")
							{
								cout << "\nType existing file name\n\n";
								cin >> arg;
								ifstream in(arg.c_str());
								if(in.is_open())
								{
									break;
								}
								else
								{
									cout << "\nCould not find file: " << arg << endl
										<< "Would you like to create a new file? "
										<< "(Y or N)\n\n";
									cin >> temp;
									transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
								}
							}
							else
							{
								cout << "Would you like to create a new file? (Y or N)\n\n";
								cin >> temp;
								transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
							}
		
						}
						break;
					}
					else break;
				}
			}
		        ifstream in(argv[i]);

		        if (!in.is_open())

		        {
		                cerr <<  argv[i] << ": cannot be opened\n";
				return 1;
		        }

		        else
		        {			
				while (in >> temp)
				{
					line.append(temp);			
		        	}
				ofstream out;
				if(append || overwrite)
				{
					if(overwrite)
					{
						out.open(arg.c_str(), ofstream::out | ofstream::trunc);
					}
					else if(append)
					{
						out.open(arg.c_str(), ofstream::out | ofstream::app);
					}		
					out << "\n\nOriginal Form:\n\n";
					for(int i = 0; i < line.size(); i++)
					{
						if((i+1) == line.size() && line[i] != '=')
						{
							out << line[i] << " =\n";
						}
						else if(line[i] == '=')
						{
							out << " =\n";
						}
						else
						{
							out << line[i];
						}
					}
					out.close();
				}
				in.close();
				InPostFix C(line, *argv[i+1]);
				line = C.GetExpression();

				if(!quiet)
				{
					cout << endl;
					if(overwrite)
					{
						cout << "Overwriting to: " << arg << endl;
					}
					else if(append)
					{
						cout << "Appending to: " << arg << endl;
					}
					else
					{
						cout << "The converted expression is:\n";
					}
					cout << line << endl << endl;
				}
				if(overwrite || append)
				{
					out.open(arg.c_str(), ofstream::out | ofstream::app);
					out << "\n\nConverted Form:\n\n" << line;
					out.close();
				}
			}
			line.clear();
		}
	}



	return 0;
}
