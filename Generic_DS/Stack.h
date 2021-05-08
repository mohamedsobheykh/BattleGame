#pragma once
#include "Node.h"

template < typename T>
class Stack
{
private:
	Node <T>* Top; // head of the list and the top of the stack

public:
	Stack(); 
	~Stack();
	void push(const T &NewItem);
	void pop();
	T peek();
	bool IsEmpty();
	void DeleteAll();
	int NodesNumber();


};



#include "Stack.h"
#include <iostream>
using namespace std;

template < typename T>
Stack<T> ::Stack() {
	Top = nullptr;
} //Default constructor

template < typename T>
Stack <T>:: ~Stack() {
	DeleteAll();
} // A destructr to delete all the items in the list (stack)

template < typename T>
void Stack <T> ::push(const T& NewItem) { // add new item in the top of the stack
	Node<T>* Item;
	Item = new Node<T>(NewItem);
	// A new node is created and data is set into it

	if (IsEmpty())
		Item->setNext(nullptr);
	else
		Item->setNext(Top);
	Top = Item;
}

template < typename T>
void Stack <T> ::pop() {
	if (IsEmpty())
		cout << "The stack is empty/n";
	else
	{
		Node<T>* Item = Top;
		Top = Top->getNext();
		delete (Item);
		// first node is deleted.
	}


}

template < typename T>
T Stack <T> ::peek() {
	return Top->getItem();
}

template < typename T>
void Stack <T> ::DeleteAll() {
	Node<T>* D = Top;
	while (Top)
	{
		D = Top->getNext();
		delete Top;
		Top = D;
	}
}

template < typename T>
bool Stack<T> ::IsEmpty() {
	return Top == nullptr;
}


template < typename T>
int Stack <T> ::NodesNumber() {
	int count = 0;
	Node <T>* P = Top;
	while ((P)) {
		P = P->getNext();
		count++;
	}
	return count;
}



