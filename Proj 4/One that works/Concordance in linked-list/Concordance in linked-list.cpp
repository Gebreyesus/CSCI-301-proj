// Concordance in linked-list.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
#include <string>
#include <iostream>

using namespace std;


template<class T>
class Node
{
public:
	Node();
	Node(const T&, Node<T>* ptrnext);
	T value;
	Node<T> * next;
};

template<class T>
Node<T>::Node()
{
	value = "";
	next = NULL;
}
template<class T>
Node<T>::Node(const T& item, Node<T>* ptrnext = NULL)
{
	this->value = item;
	this->next = ptrnext;
}

template<class T>
class LinkedListClass
{
private:
	Node<T> * Front;
	Node<T> * Rear;
	int Count;
public:
	LinkedListClass();
	~LinkedListClass();
	void InsertFront(const T Item);
	void InsertRear(const T Item);
	void PrintList();
};
template<class T>
LinkedListClass<T>::LinkedListClass()
{
	Front = NULL;
	Rear = NULL;
}

template<class T>
void LinkedListClass<T>::InsertFront(const T  Item)
{
	if (Front == NULL)
	{
		Front = new Node<T>();
		Front->value = Item;
		Front->next = NULL;
		Rear = new Node<T>();
		Rear = Front;
	}
	else
	{
		Node<T> * newNode = new Node<T>();
		newNode->value = Item;
		newNode->next = Front;
		Front = newNode;
	}
}

template<class T>
void LinkedListClass<T>::InsertRear(const T  Item)
{
	if (Rear == NULL)
	{
		Rear = new Node<T>();
		Rear->value = Item;
		Rear->next = NULL;
		Front = new Node<T>();
		Front = Rear;
	}
	else
	{
		Node<T> * newNode = new Node<T>();
		newNode->value = Item;
		Rear->next = newNode;
		Rear = newNode;
	}
}
template<class T>
void LinkedListClass<T>::PrintList()
{
	Node<T> *  temp = Front;
	while (temp->next != NULL)
	{
		cout << " " << temp->value << "";
		if (temp != NULL)
		{
			temp = (temp->next);
		}
		else
		{
			break;
		}
	}
}

int main()
{
	LinkedListClass<string> * LList = new LinkedListClass<string>();
	LList->InsertFront("beteab");
	LList->InsertFront("beteab");
	LList->InsertFront("beteab");
	LList->InsertFront("beteab");
	LList->InsertRear("g");
	LList->InsertRear("g");
	LList->InsertRear("g");
	LList->PrintList();
	system("pause");
}