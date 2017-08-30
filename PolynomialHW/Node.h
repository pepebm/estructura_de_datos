/*
    Node class to store integers in a linked list
    
    Gilberto Echeverria
    gilecheverria@yahoo.com

    Name: Jose Manuel Beauregard Mendez
    ID number: A01021716
    Compiled in Windows Terminal
*/


#ifndef NODE_H
#define NODE_H

template <class T>
class Node {
    private:
        T data;
        Node * next = nullptr;
    public:
        Node () { }
        Node (T _data) { data = _data; }
        ~Node ();
        void setData(T _data) { data = _data; }
        T getData() { return data; }
        void setNext(Node * _next) { next = _next; }
        Node * getNext() { return next; }
};

template <class T>
Node<T>::~Node()
{
    //data.~T();
    next = nullptr;
}

#endif