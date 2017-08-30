#include "Stack.h"
#include <string>

class Postfix {
private:
	std::string infix;
	std::string postfix;
	int comparePrecedence(char operator_1, char operator_2);

public:
	Postfix() {}
	Postfix(std::string _infix) { setData(_infix); }
	void setData(std::string _infix) { infix = _infix; convert();}
	void convert();
	std::string getInFix() { return infix; }
	std::String getPostFix() { return postfix; }
};