/*
Simple program to test the functionality of our linked list

Gilberto Echeverria
gilecheverria@yahoo.com

Modified by: Jose Manuel Beauregard Mendez A01021716
Compiled in Windows Terminal


*/

#include <iostream>
#include "LinkedList.h"

int main()
{
    LinkedList numbers;

    Node * item = nullptr;
    
    item = new Node(13);
    numbers.insertOrdered(item);
    
    numbers.insertOrdered(6);
    std::cout << numbers << std::endl;
    numbers.insertOrdered(4);
    std::cout << numbers << std::endl;
    numbers.insertOrdered(2);
    std::cout << numbers << std::endl;
    numbers.insertOrdered(1);
    std::cout << numbers << std::endl;
    numbers.insertOrdered(3);
    std::cout << numbers << std::endl;
    numbers.insertOrdered(5);
    std::cout << numbers << std::endl;

    numbers.printList();
    
    numbers.insertAtPosition(5, 2);

    std::cout << "This is the list: " << numbers << std::endl;
    
    std::cout << "Printing recursively: " << std::endl;
    numbers.print();
    
    int num_search = 5;
    std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
     std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search) << std::endl;
    num_search = 9;
    std::cout << "Iterative search for " << num_search << ": " << numbers.searchIterative(num_search) << std::endl;
    std::cout << "Recursive search for " << num_search << ": " << numbers.searchRecursive(num_search) << std::endl;
    
    item = numbers.deleteHead();
    std::cout << "Just removed: " << item->getData() << std::endl;
    delete item;
    item = numbers.deleteTail();
    std::cout << "Just removed: " << item->getData() << std::endl;
    delete item;
    
    std::cout << "This is the list: " << numbers << std::endl;
    
    return 0;
}