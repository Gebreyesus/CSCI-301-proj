#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

typedef string D_type1;		//defines input data type string

//============================================================================================================================
//declaration of a D_linked list ADT with a struct Node ,head & tail  as data members
class L_List
{

private:
	struct Node //a single node of the linked list will have the following attributes
	{
		D_type1 Data;//will store the word of D_type1 type 
		int apearance = 0;//stores number of times a word appears in text
		Node*next; // pointer that acts as a link to the next word link
		Node*prev;
	};
	Node*head;		//will be a pointer to first node in the chain
	Node*tail;		//will be a pointer to last node in the chain
	int Word_Count = 0;//keeps count words (total count)
	int Node_Count=0;		//keeps  track of number of nodes

	L_List::Node* L_List::get_node(D_type1 entry);  //sets Node Data and App to return a node 
	void plug(D_type1 Entry, Node* parser); //plugs a node in right location on the chain
	void give_Back(Node*);				//works recursively to deallocate memory deallocate memory	

public:

	L_List(); //    // inline constructor for class L_List							
	~L_List();		//list destructor will nulify the list members	

	Node* getfirst();	 //returns the value of the private datamember head
	Node* getlast();

	int getLength(Node*);		//returns the legth of the list
	void Data_Intake(D_type1 New_Item);			 //inserts new item in a node and chains it to the end			
	bool is_empty();							 //returns true if head-> is NULL									
	

	bool Present(D_type1 Entry, Node *parser);
	int getCount(Node* head);					//counts the number of distinct words by counting the nodes in the linked list
	//friend functions
	friend std::ostream& operator << (std::ostream& out_s, L_List& Chain);  //overloaded <<operator	
};
#pragma once
