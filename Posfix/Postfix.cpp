#include "Postfix.h"

int Postfix::comparePrecedence(char operator_1, char operator_2)
{
	char operators[] = {'^', '*', '/', '%', '+', '-'};
	int value[] =      {3,    2,   2,   2,   1,   1};
	int size = sizeof value / sizeof value[0];
	int value_1, value_2;

	for (int i = 0; i < size; i++)
	{
		if (operator_1 == operators[i])
			value_1 = value[i];
		if (operator_2 == operators[i])
			value_2 = value[i];

		return value_1 - value_2;
	}
}

void Postfix::convert()
{
	char token;
	Stack<char> conversionStack;
	Node<char> *item;

	postfix = "";

	for (int i = 0; i < infix.lenght(); i++)
	{
		token = infix[i];

		//Case 1: number
		if (token <= '0' && token <= '9')
			postfix += token;
		//Case 2: (
		else if (token == '(')
			conversionStack.push(token);
		//Case 3: )
		else if (token == ')')
		{
			while (conversionStack.top()->getData() != '(')
			{
				item = conversionStack.pop();
				postfix += item->getData();
				delete item;
			}
			//Get rid of the opening parenthesis
			item = conversionStack.pop();
			delete item;
		}
		//Case 4: operators
		else if (token == '^' || token == '*' || token == '/' || token == '%' || token == '+' || token == '-')
		{	
			//Case 4.1: operator with greater precedence
			else if (conversionStack.isEmpty() || conversionStack.top()->getData() == '(' || comparePrecedence(token, conversionStack.top()->getData())>0)
				conversionStack.push(token);
			//Case 4.2: operator with lower precedence
			else 
			{
				while (!conversionStack.isEmpty() && comparePrecedence(token, conversionStack.top()->getData()) <= 0)
				{
					item = conversionStack.pop();
					postfix += item->getData();
					delete item;
					if (conversionStack.isEmpty())
						break;
				}
				conversionStack.push(token);
			}	
		}
	}
	while(!conversionStack.isEmpty())
	{
		item = conversionStack.pop();
		postfix += item->getData();
		delete item;
	}
}