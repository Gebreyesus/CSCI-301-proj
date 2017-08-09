#pragma once

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

typedef string Item;
class BST
{

private:
	struct Node
	{
		Item Data;
		int Count=0;
		Node *Left;
		Node *Right;
	};
	Node *Root;			//the Root node
	int Distinct_Words;//Number of Nodes
//========================================helper functions
	Node* Copy(Node *T);//copy constructor helper
	
	void Help_Insert(Node* &T, const Item& Item);
	void Help_Remove(Node* &T, const Item& Item);
	void Remove_Node(Node* &T);
	void Help_Print(std::ostream& Output, Node *T) const;
 	
public:
	//=========================== Constructors
	BST() { Root = NULL; }
	void BST_Copy(const BST& T) { Root = Copy(T.Root); }//copy construxtor
	//=========================== Destructor
	~BST() { Root = NULL; }
	//===========================  member functions
	int Length();
	void Insert(const Item& Entry);
	void Remove(const Item& Removed);
	bool Empty();
	bool Present(const Item& Entry, Node *Root);
	//int Get_Count(string Word);
	//=========================== Friend functions
	friend ostream& operator << (ostream& Output, BST& Tree);
};