#include <string>
#include <stack>

using namespace std;

class InPostFix
{
public:
	InPostFix(string line, char function);

	void IntoPostFix(string line);

	void PosttoInFix(string line);

	int isOperand(char ch);

	int Prec(char ch);

	void Output(string message);

	string GetExpression();

private:
	string expression;
	stack<char> theStack;
	stack<string> strStack;
	string errormsg;
	int row_count;
	int col_count;
	bool iserrormsg;
	bool quiet;
	bool overwrite;
};
