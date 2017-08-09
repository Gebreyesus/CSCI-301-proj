//Name: Beteab Gebru
//Due Date : March 14 2017
//CSCI 301: Section 02
//CSCI ID : cs301154
#include "stdafx.h"
#include "Un_List.h"
using namespace std;

//Destructor================================================================================================1
L_List::L_List()
{
	head = NULL;
	tail = NULL;
}

//Destructor======================================================================================
void L_List::give_Back(Node* parsor)//recursive  algorithm to delete the list
{
	Node* temp = parsor; Node* Next ;
	if (temp != NULL)
	{
		Next = parsor->next;
		delete temp;
		give_Back(Next);	
	}
}	
L_List::~L_List()
{
	L_List::give_Back(head);
}
//get list length===================================================================================
int L_List::getLength(Node* trace)
{
	static int Node_Count = 1;
	if (trace->next != NULL)
	{
		Node_Count++;
		L_List::getLength(trace->next);//recursive call to the function to keep counting the nodes
	}
	return Node_Count;
}
//get head  datatmembers===================================================================================
L_List::Node* L_List::getfirst()	 //returns the value of the private datamember head
{
	return L_List::head;
}
L_List::Node* L_List::getlast()	 //returns the value of the private datamember head
{
	return L_List::tail;
}
//Get node===========================================================================================================
L_List::Node* L_List::get_node(D_type1 entry)//encases the item in the node and returns the node for insertion
{
	Node *temp;
	temp = new Node;
	temp->Data = entry;
	temp->apearance++;
	temp->next = NULL;
	temp->prev = NULL;
	Node_Count++;
	return temp;

}
//add newnode=======================================================================================================2
void L_List::Data_Intake(D_type1 Entry)//appends new data in new node at the tail of the list//append()
{
	cout << "3. We are in Data Intake function-->" << Entry << "<---" << endl;
	L_List::Word_Count++;			     //records word count
	Node* Current;// = new Node;			//declaring temporary node pointers to be used in insertion

	if (is_empty())
	{
		cout << "3.A. Item is first Item -->" << Entry << "<---" << endl;
		Current = get_node(Entry);
		Current->next = NULL; Current->prev = NULL;
		head = Current;//head points to the only node in the list
		tail = Current;//attached the tail pointer to the first item
	}
	else
	{
		Node* parser = head;    //declaring temporary node pointers to be used in insertion
		if (!Present(Entry, parser))// == false)
		{
			plug(Entry, parser);
		}
	}
}

//===============================================================================================
void L_List::plug(D_type1 Entry, Node* parser)
{
	cout << "4. We are in Plug function -->" << Entry << "<---" << endl;
	Node* Current;
	if (Entry < head->Data)//if item is smaller than first item
	{
		cout << "4.A. HEAD Plug--> " << Entry <<"::at the begining of list"<< endl;
		Current = get_node(Entry);
		head->prev = Current;
		Current->next = head;
		head = Current;
	}
	else if (Entry > tail->Data)//if item is bigger than last
	{
		cout << "4.B. TAIL Plug--> " << Entry << "::at the END of list" << endl;
		Current = get_node(Entry); 
		tail->next =Current;   //linking the new node to the end of the chain
		Current->prev = tail;//making the new_last_node's prev point to the old last 
		tail = Current; 
	}
	else
	{
		cout << "4.C. Middle Plug--> " << Entry << "<-- into the list" << endl;
		if (Entry > parser->Data )
		{
			plug(Entry, (parser = parser->next));//*************recursive call to Word the right spot for the new word
		}
		else
		{
			Current = get_node(Entry);
			parser->prev->next = Current;
			Current->next = parser;
			Current->prev = parser->prev;
			parser->prev = Current;
		}
	}
}
//==========================================================================================================
bool L_List::Present(D_type1 Entry, Node *parser)
{//parser points to head node initially and traverses the list;appearance++ if item found; else return false

	cout << "5. We are in if_Prsecent()? function and checking for-->" << Entry << "<---" << endl;
	bool found = false;
	while ((parser != NULL) && (!found))
	{
		// cout << "next!=null && !found yet  " << endl;
		if (parser->Data == Entry)//if found 
		{
			cout << "5.A. FOUND therefore app++" << endl;
			found = true;
			parser->apearance++;
		}
		parser = parser->next;
	}

	return (found == true);
}

//checks ifListis_empty?==========================================================================================3
bool L_List::is_empty()	//returns true if empty
{
	return (head == NULL);
}
//==================================================================================================================
int L_List::getCount(Node* head)
{
	//Base case
	if (head == NULL)
		return 0;
	return 1 + getCount(head->next);//*************recursive call to count
}
//==================================================================================================================


//friend function=========================================================================================Ov_Load
ostream&  operator << (ostream& Output, L_List& Chain)//========================================================
{
	if (Chain.head == NULL)
	{
		Output << "6THE TEXT FILE DID NOT HAVE WORD IN IT!! -->List is Empty" << endl;
	}
	else
	{
		L_List::Node *cursor = Chain.head;//declare a local node pointer variable to traverse the list

		cout << "||=====================================||" << endl;
		cout << "||//Name: Beteab Geb                   ||\n||//Due Date : April 27 2017           ||" << endl;
		cout << "||//CSCI 301: Section 02               ||\n||//CSCI ID : cs301154                 ||" << endl;
		cout << "||-------------------------------------||" << endl;
		Output << "||" << setw(8) << left << "The Words" << "                 " << "Concordance" << "||" << endl;
		cout << "||-------------------------------------||" << endl;

		while (cursor != NULL)//while we theres a node we keep printing node data
		{
			Output << "|| " << setw(8) << left << cursor->Data << "    -------------     " << cursor->apearance <<  endl;
			cursor = cursor->next;
		}
		cout << "||" << "=====================================||" << endl;
		cout << "||" << "WORD COUNT----------------------->" << Chain.Word_Count <<  endl;
		cout << "||" << "Number of Nodes in List----------->" << Chain.Node_Count << endl;
		cout << "||=====================================||" << endl;
	}
	return Output;
}
