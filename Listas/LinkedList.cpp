#include "LinkedList.h"

LinkedList::~LinkedList()
{
    clear();
}

///// INSERT /////

void LinkedList::insertHead(int data)
{
    Node * new_node = new Node(data);
    insertHead(new_node);
}

void LinkedList::insertHead(Node * new_node)
{
    // Make the new node point to the previous head
    new_node->setNext(head);
    // Set the head of the list to the new node
    head = new_node;
    // Increase the size of the list
    length++;
}

void LinkedList::insertTail(int data)
{
    Node * new_node = new Node(data);
    insertTail(new_node);
}

void LinkedList::insertTail(Node * new_node)
{
    // In case of an empty list
    if (head == nullptr)
    {
        head = new_node;
    }
    else
    {
        Node * item = head;
        // Look for the last element in the list
        while (item->getNext() != nullptr)
        {
            item = item->getNext();
        }
        item->setNext(new_node);
    }
    // Increase the size of the list
    length++;
}

void LinkedList::insertAtPosition (int data, int position)
{
    Node * new_node = new Node(data);
    insertAtPosition(new_node, position);
}

void LinkedList::insertAtPosition (Node * new_node, int position)
{
    // Do nothing in case of invalid positions
    if (position < 0 || position > length)
    {
        std::cout << "The positions specified is invalid\n";
        std::cout << "You must provide a positive number less than or equal to " << length << std::endl;
        return;
    }
    // Special cases for the head and tail
    else if(position == 0)
    {
        insertHead(new_node);
    }
    else if (position == length)
    {
        insertTail(new_node);
    }
    else
    {
        Node * item = head;
        for (int i=1; i<position; i++)
        {
            item = item->getNext();
        }
        new_node->setNext(item->getNext());
        item->setNext(new_node);
        length++;
    }
}

void LinkedList::insertOrdered (int data)
{
    Node * new_node = new Node(data);
    insertOrdered(new_node);
}

void LinkedList::insertOrdered (Node * new_node)
{
    if (head == nullptr)
    {
        new_node->setNext(head);
        head = new_node;
    }
    else if(head->getData() > new_node->getData())
    {
        new_node->setNext(head);
        head = new_node;
    }
    else {
        Node * previous = head;
        Node * item = previous->getNext(); 
        while (item != nullptr)
        {
            if(item->getData() < new_node->getData())
            {
                previous = item;
                item = item->getNext();
            }
            else
            {
                if (item == nullptr)
                    previous->setNext(new_node);
                else
                {
                    previous->setNext(new_node);
                    new_node->setNext(item->getNext());
                }
                length++;
                break;
            }
        }
        if (item == nullptr)
            previous->setNext(new_node);
    }
}

///// DELETE /////

Node * LinkedList::deleteHead()
{
    // If the list was empty
    if(head == nullptr)
        return nullptr;
        
    Node * item = head;
    // Update the head in the list
    head = head->getNext();
    // Break the connection to the list
    item->setNext(nullptr);
    // Update the length of the list
    length--;
    return item;
}

Node * LinkedList::deleteTail()
{
     // In case of an empty list
    if (head == nullptr)
    {
        return nullptr;
    }
    // If there is only one element in the list
    else if (head->getNext() == nullptr)
    {
        return deleteHead();
    }
    // A list with more than one element
    else
    {
        Node * previous = head;
        Node * item = previous->getNext();
        // Look for the last element in the list
        while (item->getNext() != nullptr)
        {
            previous = item;
            item = item->getNext();
        }
        // Make 'previous' the new tail
        previous->setNext(nullptr);
        // Decrease the size of the list
        length--;
        return item;
    }
}

Node * LinkedList::deleteFromPosition(int position)
{
    // Do nothing in case of invalid positions
    if (position < 0 || position > length-1)
    {
        std::cout << "The positions specified is invalid\n";
        std::cout << "You must provide a positive number less than or equal to " << length-1 << std::endl;
        return nullptr;
    }
    // Special cases for the head and tail
    else if(position == 0)
    {
        return deleteHead();
    }
    else if (position == length-1)
    {
        return deleteTail();
    }
    else
    {
        Node * previous = head;
        Node * item = previous->getNext();
        for (int i=1; i<position; i++)
        {
            previous = item;
            item = item->getNext();
        }
        // Update the previous node
        previous->setNext(item->getNext());         
        // Disconnect item from the list
        item->setNext(nullptr);
        length--;
        return item;
    }
}

Node * LinkedList::deleteElement(int data)
{
    return nullptr;
}


///// SEARCH /////

int LinkedList::searchIterative(int data)
{
    Node * item = head;
    int counter = 0;
    
    while (item != nullptr && item->getData() != data)
    {
        counter++;
        item = item->getNext();
    }
    if (item == nullptr)
        return -1;
    else
        return counter;
}

int LinkedList::searchRecursive(int data)
{
    return search_recursive(head, data, 0);
}

int LinkedList::search_recursive(Node * _head, int data, int i)
{
    if(_head == nullptr) 
        return -1;
    else if(_head->getData() == data) 
        return i;
    else if(_head->getData() != data)
        return search_recursive(_head->getNext(), data, ++i);

}



///// HELPERS /////

void LinkedList::printList()
{
    Node * item = head;
    int count = 0;
    
    while (item != nullptr)
    {
        std::cout << "Item " << count++ << " = " << item->getData() << std::endl;
        item = item->getNext();
    }
}

void LinkedList::print()
{
    print_recursive(head);
}

void LinkedList::print_recursive(Node * _head)
{
    if (_head == nullptr)
    {
        std::cout << std::endl;
    }
    else
    {
        std::cout << _head->getData() << " ";
        print_recursive(_head->getNext());
    }
}

std::ostream & operator<< (std::ostream & stream, const LinkedList & list)
{
    Node * item = list.head;
    
    stream << "[ ";
    while (item != nullptr)
    {
        stream << item->getData();
        item = item->getNext();
        if (item != nullptr)
            stream << ", ";
        else
            stream << " ";
    }
    stream << "]" << std::endl;
    return stream;
}

void LinkedList::clear()
{
    Node * item = head;
    
    while (item != nullptr)
    {
        head = item->getNext();
        delete item;
        item = head;
    }
    length = 0;
}