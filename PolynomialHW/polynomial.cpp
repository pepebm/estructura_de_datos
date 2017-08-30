/*
   Gilberto Echeverria

   Polynomials using lists

   Name: Jose Manuel Beauregard Mendez
    ID number: A01021716
    Compiled in Windows Terminal
*/

#include <iostream>
#include "Polynomial.h"


int main()
{
    Polynomial poly_1;
    Polynomial poly_2;
    Polynomial poly_3;
    double x_val;

    std::cout << "Size of node: " << sizeof (Node<Term>) << std::endl;
    std::cout << "Initial length: " << poly_1.getLength() << std::endl;

    // Ask the user for the value of X to evaluate
    //std::cout << "Enter the value of X: ";
    //std::cin >> x_val;
    x_val = 7;

    // Add the nodes using the method to keep the list ordered
    poly_1.insertOrdered(Term (-6, 2));
    poly_1.insertOrdered(Term (4, 1));
    poly_1.insertOrdered(Term (-3, 4));
    poly_1.insertOrdered(Term (7, 5));
    poly_1.insertOrdered(Term (2, 1));
    poly_1.insertOrdered(Term (8, 2));
    poly_1.insertOrdered(Term (-2, 0));
    poly_1.insertOrdered(Term (4, 4));

    // Show the current polynomial
    std::cout << "This is the polynomial:\n" << poly_1 << std::endl;
    std::cout << "New length: " << poly_1.getLength() << std::endl;
    // Evaluate the list
    std::cout << std::endl << "Evaluated with " << x_val << ": " << poly_1.evaluate(x_val) << std::endl;
    std::cout << "Simplifying... " << std::endl;
    poly_1.simplify();
    std::cout << "This is the new polynomial:\n" << poly_1 << std::endl;
    std::cout << "New length: " << poly_1.getLength() << std::endl;
    // Evaluate the list
    std::cout << std::endl << "Evaluated with " << x_val << ": " << poly_1.evaluate(x_val) << std::endl;

    // Another polynomial

    poly_2.insertOrdered(Term (-5, 5));
    poly_2.insertOrdered(Term (3, 1));
    poly_2.insertOrdered(Term (-8, 2));
    poly_2.insertOrdered(Term (4, 0));
    poly_2.insertOrdered(Term (2, 1));
    poly_2.insertOrdered(Term (-7, 0));

    // Show the current polynomial
    std::cout << "This is the polynomial 2:\n" << poly_2 << std::endl;
    // Evaluate the list
    std::cout << "Simplifying... " << std::endl;
    poly_2.simplify();
    std::cout << "This is the new polynomial 2:\n" << poly_2 << std::endl;

    poly_3 = poly_1 + poly_2;

    // Show the current polynomial
    std::cout << "This is the polynomial 3:\n" << poly_3 << std::endl;

    return 0;
}
