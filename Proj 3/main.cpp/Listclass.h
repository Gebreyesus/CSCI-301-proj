
#include <string>
using namespace std;
const int MAX_LIST = 10;
typedef string ListItemType;

class List
{

public:
	List();
	bool isEmpty() const;
	int getLength() const;
	void insert(int index, const ListItemType& newItem, bool& success);
	void retrieve(int index, ListItemType& dataItem, bool & success) const;
	void remove(int index, bool& success);
private:
	ListItemType items[10];
	int size;
	int translate(int index) const;
};




// main.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define "Header1.h" 
#include <cstdlib>                        // Provides size_t
#include <iostream>                       // Provides istream and ostream
using namespace std;

//const int capacity = 100;
int main()
{
	int var1 = 1;
	int numberofitems;
	int n = 0;
	int p = 0;
	cout << "Please enter the number of data items:" << endl;
	cin >> numberofitems;
	cout << endl;
	cout << "Please enter the data items, one per line:" << endl;
	int listofitems[10];
	//string mainlistitemptype = "int";
	List myArrayList;
	cout << myArrayList.getLength() << endl;
	if (myArrayList.isEmpty())  // tests before
	{
		cout << "This list is empty \n" << endl;
	}
	else
	{
		cout << "List is not empty! \n" << endl;
	}
	//myArrayList.size(numberofitems);
	bool mainsucc = false;
	int mainarraylistsize = myArrayList.getLength();
	for (int i = 0; i<numberofitems; i++)
	{
		cout << "Enter number " << i + 1 << " : ";
		cin >> listofitems[i];
		myArrayList.insert(listofitems[i], "int", mainsucc);
	}
	for (int i = 0; i<mainarraylistsize; i++)
	{
		cout << myArrayList.retrieve(0, "int", mainsucc);
	}
	return 1;
}


#include "Header1.h"  // header file
#include <iostream>
#include <fstream>

List::List() : size(0)
{
}
bool List::isEmpty() const
{
	return size == 0;
}
int List::getLength() const
{
	return size;
}
void List::insert(int index, const ListItemType& newItem,
	bool& success)
{
	success = (index >= 1) &&
		(index <= size + 1) &&
		(size < MAX_LIST);
	if (success)
	{
		for (int pos = size; pos >= index; --pos)
			items[translate(pos + 1)] = items[translate(pos)];
		items[translate(index)] = newItem;
		++size;  // increase the size of the list by one
	}
}

void List::remove(int index, bool& success)
{
	success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int fromPosition = index + 1;
			fromPosition <= size;
			++fromPosition)
			items[translate(fromPosition - 1)] = items[translate(fromPosition)];
		--size;  // decrease the size of the list by one
	}  // end if

}  // end remove

void List::retrieve(int index, ListItemType& dataItem,
	bool& success) const
{
	success = (index >= 1) && (index <= size);
	if (success)
		dataItem = items[translate(index)];
}

int List::translate(int index) const
{
	return index - 1;
#include "ArrayList.h"  // header file
#include <iostream>
#include <fstream>

	List::List() : size(0)
	{
	}
	bool List::isEmpty() const
	{
		return size == 0;
	}
	int List::getLength() const
	{
		return size;
	}
	void List::insert(int index, const ListItemType& newItem,
		bool& success)
	{
		success = (index >= 1) &&
			(index <= size + 1) &&
			(size < MAX_LIST);
		if (success)
		{
			for (int pos = size; pos >= index; --pos)
				items[translate(pos + 1)] = items[translate(pos)];
			items[translate(index)] = newItem;
			++size;  // increase the size of the list by one
		}
	}

	void List::remove(int index, bool& success)
	{
		success = (index >= 1) && (index <= size);
		if (success)
		{
			for (int fromPosition = index + 1;
				fromPosition <= size;
				++fromPosition)
				items[translate(fromPosition - 1)] = items[translate(fromPosition)];
			--size;  // decrease the size of the list by one
		}  // end if

	}  // end remove

	void List::retrieve(int index, ListItemType& dataItem,
		bool& success) const
	{
		success = (index >= 1) && (index <= size);
		if (success)
			dataItem = items[translate(index)];
	}

	int List::translate(int index) const
	{
		return index - 1;
	}




#pragma once

#include <string>
using namespace std;

const int MAX_LIST = 10;
typedef string ListItemType;

class List
{

public:
	List();
	bool isEmpty() const;
	int getLength() const;
	void insert(int index, const ListItemType& newItem, bool& success);
	void retrieve(int index, ListItemType& dataItem, bool & success) const;
	void remove(int index, bool& success);
private:
	ListItemType items[10];
	int size;
	int translate(int index) const;
};









