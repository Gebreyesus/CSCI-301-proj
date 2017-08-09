#pragma once
#include "stdafx.h"
#include <iostream>
#include "Server.h"
using namespace std;

typedef int Item ;

class Queue
{
private:
	//========================================================== DATA MEMBERS
	struct Node	//a customer in a line will be represented by a node
	{
		Item Enqueue_T=0;		//represented by the the time of arrival
		Item Dequeue_T=0;
		Item Wait_Period = 0;
		Node *Next;

	};
	Node *Head;
	Node *Tail;
	int Count=0;//keeps count of customers in line
	double Avg_Wait=0;
	int H_Wait = 0;
	int L_Wait = 0;
public:
	//========================================================== CONSTRUCTOR
	Queue();
	//========================================================== DESTRUCTOR
	~Queue();
	//========================================================== MODIFICATION MEMBER FUNCTIONS
	void High_Low_Set(int Wait_Period);
	void Enqueue(Item entry);	//enques a node at the shortest queue
	Item  Dequeue(Item Dequ_T);	//Returns the value of the dequed item
	//========================================================== CONSTANT MEMBER FUNCTIONS
	int Get_Max_Wait()const;
	int Get_Min_Wait() const;
	int Size() const;
	bool Is_Empty() const;//returns true if queue is empty
	Node* Get_Node()  const;
	double Get_Avg_Wait() const;//returns the average wait period for a queue
};