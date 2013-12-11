#include <string>
#include <stack>

using namespace std;

class InPostFix
{
public:
	InPostFix(istream& input, char function, bool q);

	void IntoPostFix(istream& input);

	void PosttoInFix(istream& input);

	int isOperand(char ch);

	int Prec(char ch);

	void Output(string message);

private:
	string expression;
	stack<char> theStack;
	stack<string> strStack;
	string errormsg;
	int row_count;
	int col_count;
	bool iserrormsg;
	bool quiet;
};
