/*
    Ivan Aram Gonzalez Su
    Jose Manuel Beauregard Mendez
*/

#ifndef FIBNODE_H
#define FIBNODE_H

#include <iostream>

class fibNode{
private:
    int num;
    int call;
public:
    fibNode(){}
    fibNode(int _num, int _call):num(_num),call(_call){}
    int getNum(){ return num; }
    int getCall(){ return call; }
    friend std::ostream& operator<< (std::ostream& stream, const fibNode& node);
};

std::ostream& operator<< (std::ostream& stream, const fibNode& node){
    stream<<"Fib("<<node.call<<") = "<<node.num;
    return stream;
}

#endif
