#include "Postfix.h"


/*
   Compare two operators, and return an integer with
   the substraction of the precedence value of the first operator
   minus the precedence value of the second operator.
   If the result is greater than 0, the first operator has higher precedence.
*/
int Postfix::comparePrecedence(char operator_1, char operator_2)
{
    char operators[] =  {'^', '*', '/', '%', '+', '-'};
    int value[] =       { 3,   2,   2,   2,   1,   1 };
    int size = sizeof value / sizeof value[0];
    int value_1, value_2;
    
    for (int i=0; i<size; i++)
    {
        if (operator_1 == operators[i])
            value_1 = value[i];
        if (operator_2 == operators[i])
            value_2 = value[i];
    }
    
    return value_1 - value_2;
}


/* Return the result of applying an operator to two numbers */
int Postfix::compute(int num_1, int num_2, char sign)
{
    switch(sign)
    {
        case '^':
            return pow(num_1, num_2);
        case '*':
            return num_1 * num_2;
        case '/':
            return num_1 / num_2;
        case '%':
            return num_1 % num_2;
        case '+':
            return num_1 + num_2;
        case '-':
            return num_1 - num_2;
        default:
            return 0;
    }
}

void Postfix::convert()
{
    char token;
    Stack<char> conversionStack;
    Node<char> * item;
    
    postfix = "";
    
    for (int i=0; i<infix.length(); i++)
    {
        token = infix[i];
        
        // Case 1: number
        if (token >= '0' && token <= '9')
           postfix += token;
        // Case 2: (
        else if (token == '(')
            conversionStack.push(token);
        // Case 3: )
        else if (token == ')')
        {
            while (conversionStack.top()->getData() != '(')
            {
                item = conversionStack.pop();
                postfix += item->getData();
                delete item;
            }
            // Get rid of the opening parenthesis '('
            item = conversionStack.pop();
            delete item;
        }
        // Case 4: operator
        else if (token == '^' || token == '*' || token == '/' || token == '%' || token == '+' || token == '-')
        {
            // Case 4.1: operator with greater precedence
            if (    conversionStack.isEmpty()                   ||
                    conversionStack.top()->getData() == '('     ||
                    comparePrecedence(token, conversionStack.top()->getData()) > 0
                )
                conversionStack.push(token);
            // Case 4.2: operator with lower prececence
            else
            {
                // Pop the existing operators in the stack with greater or equal precedence
                while ( !conversionStack.isEmpty() &&
                        comparePrecedence(token, conversionStack.top()->getData()) <= 0)
                {
                    item = conversionStack.pop();
                    postfix += item->getData();
                    delete item;
                }
                conversionStack.push(token);
            }
        }
    }
    // Pop any remaining operators in the stack
    while (!conversionStack.isEmpty())
    {
        item = conversionStack.pop();
        postfix += item->getData();
        delete item;
    }
}

int Postfix::evaluate()
{
    char token;
    Stack<T> evaluateStack;
    Node<char> * item;

    int num1, num2, result;

    for (int i = 0; i < postfix.length(); i++)
    {
        token = postfix[i];
        if(token >= '0' && token<= '9')
            evaluateStack.push(token-'0');
        else if (token == '^' || token == '*' || token == '/' || token == '%' || token == '+' ||| token == '-')
        {
            item = evaluateStack.pop();
            num2 = item->getData();
            delete item;
            item = evaluateStack.pop()/;
            num1 = item->getData();
            delete item;

            result = comparePrecedence(num1, num2, token); 
        }
    }
    
    item = evaluateStack.pop();
    result = item->getData();
    delete item;
    return result;
}
