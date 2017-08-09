#include "stdafx.h"
#include "Queue.h"
#include "Server.h"
#include <cstdlib>  
#include <iostream>
using namespace std;

//*************************************************Server Functions***************************************************
//========================================================== CONSTRUCTOR
Server::Server() {
	//cout << "Implement 1" << endl; Availability = true; 
}
//========================================================== DESTRUCTOR
Server::~Server() {}
//========================================================== Teller_Availability?
bool Server::Is_Available() { return Availability; } // reports availability of server
//========================================================== Availability?
void Server::Set_Availability(bool Status) //changes availability of server
{	
	Availability = Status; 
}
void Server::Set_Trans_Time(int Trans_Time) //sets how long a customer will be serviced
{	Transact_Time = Trans_Time;}
int Server::Get_Trans_Time()//returns time a customer has left with the teller
{	return Transact_Time;  }
void Server::CLock_Tick(){Transact_Time = (Transact_Time-1); }//timer for the server to finish servicing a node

//***********************************************QUEUE Fnctions*******************************************************

//========================================================== CONSTRUCTOR
Queue::Queue()
{
	Queue::Head=NULL;
	Queue::Tail=NULL;
	int Count=0;
}
//========================================================== DESTRUCTOR
Queue::~Queue() {  }
//========================================================== MODIFICATION MEMBER FUNCTIONS
void Queue::High_Low_Set(int Wait_Period)
{
	if(Wait_Period > H_Wait)//record higher wait period
	H_Wait = Wait_Period;
	
	if (Wait_Period < L_Wait)//setting new low wait duration
	L_Wait = Wait_Period;
}
void Queue::Enqueue(Item Entry)//,Queue Shortest)
{
	Node * Temp = Queue::Get_Node();
	Temp->Enqueue_T = Entry; //we set the data of the node to show time of arrival at the queue
	if (Head == NULL)//if queue is empty
	 {
		Head = Temp;
		Tail = Temp;//both head and last point to same node
		Tail->Next = NULL;
		Count++;
	 }
	else if (Head != NULL)//we attach the new entry to the tail end of the Queue
	 {
		Tail->Next = Temp;
		Tail = Temp;
		Tail->Next = NULL;
		Count++;
	 }
}

Item  Queue::Dequeue(Item Dequeue_T)//Queue::Node* onto the chain of items
{
	static int a = 0;
	Node* Temp = new Node;
	Temp = Head;
	Head = Head->Next;
	Count--;

	//=====================================handling the wait period statistics
	
	Temp->Wait_Period = (Dequeue_T) - (Temp->Enqueue_T) ;//recording the wait_period to calc average
	if (a != 0)
		Avg_Wait = ((Avg_Wait + ((Temp->Enqueue_T) - (Temp->Dequeue_T))) / 2);

	a++;
	High_Low_Set(Temp->Wait_Period);

	return Temp->Wait_Period;
}
//========================================================== CONSTANT MEMBER FUNCTIONS
int Queue::Size() const//returns the size of the queue
{
	return Queue::Count;
}
bool Queue::Is_Empty() const //returns true when empty
{
	return(Count==0) ;
}
Queue::Node* Queue::Get_Node() const
{
	Node* temp = new Node;
	return  temp;
}
double Queue::Get_Avg_Wait() const
{
	return Avg_Wait;
}
int Queue::Get_Max_Wait() const
{
	return H_Wait;
}
int Queue::Get_Min_Wait() const
{
	return L_Wait;
}

//========================================================== FRIEND FUNCTION
