/*
    Postfix conversion class

    Following these rules to convert from infix to postfix
    
    while there are characters in the input
        1. token is number -> write token to output
        2. token is '(' -> push token
        3. token is ')' -> while top != '(' : write pop to output
                            pop
        4. token is an operator
            4.1. stack is empty or top == '(' or  token > top -> push token
            4.2. while token <= top -> write pop to output
                                       push token
    while stack is not empty -> write pop to output
*/

#ifndef POSTFIX_H
#define POSTFIX_H

#include <string>
#include <cmath>
#include "Stack.h"

class Postfix {
    private:
        std::string infix;
        std::string postfix;
        
        int comparePrecedence(char operator_1, char operator_2);
        int compute(int num_1, int num_2, char sign);
        
    public:
        Postfix () {}
        Postfix(std::string _infix) { setData(_infix); }
        
        void setData(std::string _infix)  { infix = _infix; convert(); }
        void convert();
        int evaluate();
        std::string getInfix() { return infix; }
        std::string getPostfix() { return postfix; }
};

#endif
