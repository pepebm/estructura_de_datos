/*
   Polynomial class
   Inherits from a Linked List, using Terms as data

Name: Jose Manuel Beauregard Mendez
    ID number: A01021716
    Compiled in Windows Terminal
*/

#include "LinkedList.h"
#include "Term.h"
#include <cmath>


class Polynomial : public LinkedList<Term> {
    public:
        // Method to compute the results of a polynomial evaluated
        //  with a given value for the variable
        double evaluate(double x);
        // Add up all the terms with equal exponents
        void simplify();
        // Optional: Change the method to insert in decreasing order
        //void insertOrdered(Term data);
        //void insertOrdered(Node<Term> * new_node);
        // Overload the operator to add two polynomials
        Polynomial operator+(const Polynomial & other);

        // Method to print out a polynomial
        friend std::ostream & operator<< (std::ostream & stream, const Polynomial & poly);
};

double Polynomial::evaluate(double x)
{
    // Remember to indicate that the nodes used in this class contain Terms
    Node<Term> * item = head;
    double result = 0;
    while (item != nullptr)
    {
        result += item->getData().getConstant() * pow(x, item->getData().getExponent());
        item = item->getNext();
    }
    return result;
}

void Polynomial::simplify()
{
    if(head != nullptr)
    {
        Node<Term> * previous = head;
        Node<Term> * item = previous->getNext();
        //Node<Term> * takeout = item;
        while (item != nullptr)
        {
            Node<Term> * takeout = item;
            if (previous->getData().getExponent() == item->getData().getExponent())
            {
                previous->setData(previous->getData() + item->getData());
                previous->setNext(item->getNext());
                takeout = nullptr;
                
            }
            previous = item;
            item = previous->getNext();
        }
    }
}

Polynomial Polynomial::operator+ (const Polynomial & other)
{
    Node<Term> * item = other.head;
    Polynomial result = *this;

    while(item != nullptr)
    {
        result.insertOrdered(item->getData());
        item = item->getNext();
    }
    result.simplify();
    return result;
}

std::ostream & operator<< (std::ostream & stream, const Polynomial & poly)
{
    Node<Term> * item = poly.head;
    while(item != nullptr && item->getNext() != nullptr)
    { 
        stream << item->getData() << " + ";
        item = item->getNext();
    }
    stream << item->getData();
    return stream;
}