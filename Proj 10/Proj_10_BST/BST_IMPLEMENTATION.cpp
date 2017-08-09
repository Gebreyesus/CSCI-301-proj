#include "stdafx.h"
#include <iostream>
#include "Binary_Search_Tree.h"
#include <cassert>
using namespace std;

//=============================================================copy_constructor
//BST::BST_Copy(const BST& T) { Root = Copy(T.Root); }
BST::Node* BST::Copy(Node *T)
{
	Node *R;

	if (T == NULL)
		return NULL;
	else
	{
		R = new Node;
		R->Data = T->Data;
		R->Left = Copy(T->Left);
		R->Right = Copy(T->Right);
		return R;
	}
}

//============================================================Empty()?
bool BST::Empty()
{
	return Root == NULL;
}
//=============================================================Present?
bool BST::Present(const Item& To_Search, Node *Parser)
{
	if(Parser != NULL )//search the path till the last leaf
	{
		if (Parser->Data == To_Search)//if item is found cut the trip short and increase count
		{
			Parser->Count++;//if item is found increase the count
			return true;
		}
		else if(To_Search > Parser->Data && Parser->Data != To_Search)
			Present(To_Search, Parser->Right);
		else if (To_Search < Parser->Data && Parser->Data != To_Search)
			Present(To_Search, Parser->Left);
	}
	else if (Parser == NULL)
	{
		 return false;	
	}
}

//==========================================================Remove Leaf/Node
void BST::Remove(const Item& Target)
{
	if (Present(Target, Root));
		Help_Remove(Root, Target);
}

void BST::Help_Remove(Node* &T, const Item& Target)
{
	if (T->Data == Target)
		Remove_Node(T);
	else if (Target < T->Data)
		Help_Remove(T->Left, Target);
	else   // Target > t->Data
		Help_Remove(T->Right, Target);
}

void BST::Remove_Node(Node* &T)
{
	Node* Ptr;
	Node* Back;

	if (T->Left == NULL && T->Right == NULL)  // leaf
	{
		delete T;
		T = NULL;
	}
	else if (T->Left == NULL)  // has Right child only
	{
		Ptr = T;
		T = T->Right;
		delete Ptr;
	}
	else if (T->Right == NULL)  // has Left child only
	{
		Ptr = T;
	T = T->Left;
		delete Ptr;
	}
	else  // has both children; copy from, then remove
	{// the Leftmost node in the Right subtree.
		Back = T;
		Ptr = T->Right;
		while (Ptr->Left != NULL)
		{
			Back = Ptr;
			Ptr = Ptr->Left;
		}
		T->Data = Ptr->Data;
		if (Back == T)
			Remove_Node(Back->Right);
		else
			Remove_Node(Back->Left);
	}
}

//============================================================Insert Function
void BST::Insert(const Item& Entry)
{
	if(!Present(Entry, Root))
	{
		Help_Insert(Root, Entry);
	}
}

void BST::Help_Insert(Node* &T, const Item& Entry)
{
	if (T == NULL)
	{
		T = new Node;
		T->Data = Entry;
		T->Count++;
		T->Left = NULL;
		T->Right = NULL;
		Distinct_Words++;//when a word is inserted we increase count;
	}
	else if (Entry < T->Data)
			Help_Insert(T->Left, Entry);
	else  // entry > t->Data
		Help_Insert(T->Right, Entry);
}


//============================================================Get count for a target word
int BST::Length()
{
	return Distinct_Words;
}
//================================================================friend Function
ostream& operator << (ostream& Output, BST& Tree)
{
	cout << "||=====================================||" << endl;
	cout << "||//Name: Beteab Geb                   ||\n||//Due Date : April 27 2017           ||" << endl;
	cout << "||//CSCI 301: Section 02               ||\n||//CSCI ID : cs301154                 ||" << endl;
	cout << "|| Num of Distinct Word           -->" << Tree.Distinct_Words << "||" << endl;
	cout << "||-------------------------------------||" << endl;
	Output << "||" << setw(8) << left << "The Words" << "                 " << "Concordance" << "||" << endl;
	cout << "||-------------------------------------||" << endl;
	Tree.Help_Print(Output, Tree.Root);
	cout << "||-------------------------------------||" << endl;
	return Output;
}
void BST::Help_Print(ostream& Output, Node *T) const
{
	if (T != NULL)
	{
		Help_Print(Output, T->Left);
		Output <<setw(5)<<"  "<< setw(26) << T->Data <<left<<T->Count<<endl;
		Help_Print(Output, T->Right);
	}
	
}