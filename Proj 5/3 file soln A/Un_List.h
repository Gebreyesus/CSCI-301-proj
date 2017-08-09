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
using namespace std;

typedef int D_type1;		//defines input data type


							//===================================================================================================================================================================
							//a struct node is declared here 

struct Node //a single node of the linked list will have the following attributes
{
	D_type1 Data;//will store the word of D_type1 type 
	Node*next; // pointer that acts as a link to the next word link
	Node*back;//back pointer to the previous node
};

//===================================================================================================================================================================
//declaration of a D_linked list ADT with first & last pointers as data members
class DL_List
{

private:

	Node*first;//will be a pointer to first node in the chain
	Node*last;//pointer to last node in chain

public:
	// Constructor and destructor
	DL_List(); //    // inline constructor for class DL_List							
	~DL_List();									 //list destructor will nulify the list members					

												 //Modification functions
	void Data_Intake(D_type1 New_Item);			 //inserts new item in a node and chains it to the end			
	bool is_empty();							 //returns true if first-> is NULL									
	void remove_Last();							 //removes the last node of the chain
	void give_Back(Node*);						 //works recursively to deallocate memory deallocate memory	

												 //friend functions
	friend std::ostream& operator << (std::ostream& out_s, DL_List& Chain);  //overloaded <<operator	
};
#pragma once
