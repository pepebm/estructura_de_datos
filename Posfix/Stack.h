#include <iostream>

template <class T>
class Stack{
	private:
		Node<T> * head = nullptr;
		int length = 0;
	public:
	Stack () {}
	Stack (Node<T> * new_node) { head = new_node; tail = new_node; length++; }
	~Stack() { clear(); }

	bool isEmpty() { return head == nullptr; }
	Node<T> * top() { return head; }
	Node<T> * pop();
	void push(T data)
	void push(Node<T> * new_node);
	void clear();
};

template <class T>
Node<T> *Stack<T>::pop()
{
	if(head == nullptr)
		return head;
        
    Node * item = head;
    // Update the head in the list
    head = head->getNext();
    // Break the connection to the list
    item->setNext(nullptr);
    // Update the length of the list
    length--;
    return item;
}


template <class T>
void Stack<T>::push(T data)
{
	Node<T> * new_item = new Node<T>(data);
	push(new_item);
}

template <class T>
void Stack<T>::push(Node<T> * new_node)
{
	if(head == nullptr)
		head = new_node;
	else
	{
		new_node->setNext(head);
		shead = new_node;
	}
	length++;
}

template <class T>
void Stack<T>::clear(){
 	Node * item = head;
    while (item != nullptr)
    {
        head = item->getNext();
        delete item;
        item = head;
    }
    length = 0;
    tail = nullptr;
}
