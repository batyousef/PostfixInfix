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

	while((opt = getopt(argc, argv, "qh")) != -1)
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
			default:
			{
				help();
				return 3;
			}
		}
	}

	if ((argc <= 2 && !option) || (argc <= 3 && option))

        {
		InPostFix C(cin,*argv[argc-1],quiet);
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
                        InPostFix C(in,*argv[i+1],quiet);
                }

        }



return 0;
}
