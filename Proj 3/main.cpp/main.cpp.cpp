// main.cpp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define Listclass.h 
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
