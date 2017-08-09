// ConsoleApplication1.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include "Un_List.h"
using namespace std;
//Destructor================================================================================================1
DL_List::DL_List()
{
	first = NULL; last = NULL; 
}

void DL_List::give_Back(Node* first)
{
	if (first != NULL)
	{
		give_Back(first->next);
		delete first;
	}
}

DL_List::~DL_List()
{
	give_Back(first);
}

//add newnode=================================================================================================2
void DL_List::Data_Intake(D_type1 New_Item)//appends new data in new node at the tail of the list//append()
{
	cout << "the item to insert is: " << New_Item << endl; //debuging line
	Node*current = new Node; //a node is declared to house the new_item entry
	if (is_empty())//the list is empty therefpre-->make first and last point to the new_node 
	{
		last = current;	//pointer last is made to point at the newnode
		current->next = NULL;	//memory allocated for new node
		current->back = NULL;	//the very first entry into the list will not have back pointer to first
		current->Data = New_Item;//entry data is placed in the new node
		first = current;			// first is made to point to the very first node we just created
		last = current;				//last will also point to this item since its the only item in the list
		cout << "list just got its first member -->" << New_Item << endl;
	}
	else if (first != NULL) //if the list has existing nodes we simply attach new node 
	{
		Node*current = last;			//local pointer(current) is made to point to the last node
		current->next = new Node;	//memory allocated for new node
		current->next->Data = New_Item;//entry is placed in the new node
		current->next->next = NULL;		// next of the last node points to nothing since its added at end
		current->next->back = current;//new node's back pointer points to the last node

		last = current->next;			//last is made to point to the new node which is the latest_last node
		cout << "list items being filled -->" << New_Item << endl;
	}
	cout << "the first and last nodes are as follows:" << "First->" << first->Data << " Last->" << last->Data << endl;
}

//checks ifListis_empty?==========================================================================================3
bool DL_List::is_empty()//returns true if empty
{
	return (first == NULL);
}

//removes last node in list========================================================================================3
void DL_List::remove_Last()
{
	struct Node* to_delete;//provide temporary node for the node to be deleted
	if (first != NULL)//we remove an item/node only if there are existing nodes to begin with/only remove when the list !empty
	{
		to_delete = last; //the last item is marked to be deleted
		if (last == first)//this adresses->if there exists only one node in the list
		{
			first = NULL;
			last = NULL;
			delete to_delete;	//deleting the node
		}
		else//if list has multiple existing nodes-->we can delete last one 
		{
			to_delete = last;
			last = to_delete->back;	//last is made to point to the item before last--which is new last node
			last->next = NULL;		//making next pointer in last node NULL
			delete to_delete;	//deleting the last item in chain
		}

	}
	system("pause");
	cout << "the first and last nodes are as follows:" << "First->" << first->Data << " Last->" << last->Data << endl;
	system("pause");
}

//friend function=========================================================================================Ov_Load
ostream&  operator << (ostream& out_s, DL_List& Chain)//===========================================================
{
	struct Node* cursor = Chain.first;
	//cout << "we are in the friend function" << endl;
	while (cursor != NULL)//while we are pointing at node we print data
	{
		out_s << '(';
		out_s << cursor->Data << ", ";
		out_s << ')';
		cursor = cursor->next;
	}
	return out_s;
}

