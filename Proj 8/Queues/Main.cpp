// Queues.cpp : Defines the entry point for the console application.
#include "stdafx.h"
//Name: Beteab Gebru
//Due Date : April 6th 2017
//CSCI 301:  Section 02
//CSCI ID :  cs301154

#include <cstdlib>                         // Provides size_t
#include <iostream>                       // Provides istream and ostream
#include <cassert>						 // Provides assert()
#include <iomanip>
#include "Queue.h"
#include "Server.h"
using namespace std;

//========================================================== prototypes
int Shortest(Queue Lines[], int Num_Queues);//reports the index to the shortest queue in the array
int Queue_Total(Queue Lines[], int Num_Queues);//reports the total number of customers in Queue
void output(Queue Queue1, Item DequeT);
//============================================================== Main Prog
int main()
{
	const int Num_Queue = 4;
	const int Num_Servers = 4;	//number of Server and Queue pairs
	const int Prob = 80;			//probability customer gets in at the door at every tick/minute
	int Max_Time = 12;		//max time customer could be at the service booth
	int Prog_Duration = 120;	//the length of program simulation run measured in ticks/minutes
	int Rand_Seed;		//a seed number for the random number generator
	int Shortest_Queue=0; //stores the index number of shortest queue in the array of queues
	int Transact_Time = 0;// keeps track of servicing time for the customers/nodes
	int Elapsed_Time = 0;	//keeps track of time/in ticks of a loop

							//=============================================================== Getting user input
	cout << "===============++++++++QUEUEING SIMULATION PROGRAM++++++++++++===============" << endl;
	cout << " PLEASE ENTER THE PROGRAM PARAMETERS BELOW" << endl;
	cout << "The number of queue/server pairs:" << endl;
	//cin >> Num_Servers; Num_Queues = Num_Servers;//matching server-customer pairs
	cout << "Please Enter probability a customer joins a queue every tick of the clock" << endl;
	//cin >> Prob;
	cout << "Maximum duration a customer is at the booth ->in ticks of a clock" << endl;
	//cin >> Max_Time;
	cout << "Duration of the program simulation->in ticks of a clock" << endl;
	//cin >> Prog_Duration;
	cout << "Enter the seed number to start the random number generator" << endl;
	cin >> Rand_Seed;

	//=============================================================== setting values 
	int i = 0;	int x = 0;
	srand(Rand_Seed);//seeding the rand() function
	Queue Lines[Num_Queue];
	Server Tellers[Num_Servers];//declaring array of Queue-Server pairs of user-specified number

								//=============================================================== Enqueueing and Dequeing  Queues/Server
	while (Elapsed_Time < Prog_Duration)
	{
		cout << "==================Time on The Clock-->" << Elapsed_Time << "======================" << endl;
		if (Elapsed_Time > 0)
		{
			x = 0;//resetting counter
			while (x < Num_Servers)//winding down the clocks on transaction time
			{
				Tellers[x].CLock_Tick(); //-- the service time with the teller
				if (Tellers[x].Get_Trans_Time() == 0)
					Tellers[x].Set_Availability(true); //make the transaction==0 available
				x++;
			}
		}
		x = 0;//resetting counter
			  //=============================================================== Enqueueing and Dequeing  Queues/Server
		if ((rand() % 100) < Prob)
		{
			cout << "Enqueueing a customer-->" << Elapsed_Time << " ";
			Shortest_Queue = Shortest(Lines, Num_Servers);//the que index-> where to Enqueue on
			Lines[Shortest_Queue].Enqueue(Elapsed_Time); //enqueue item/time-stamp in right queue
		}
		while (x < Num_Servers)
		{
			if (Tellers[x].Is_Available() && Lines[x].Size() > 0)//dequeue where line !empty and the booth/server is unoccupied
			{
				Transact_Time = ((rand() % Max_Time) + 1);	//setting random duration for service time
				Tellers[x].Set_Trans_Time(Transact_Time);
				Tellers[x].Set_Availability(false);
				Lines[x].Dequeue(Elapsed_Time);

			}
			x++;
		}
	 Elapsed_Time++;  //tick of a clock-->we advance our loop timer here
	}

	std::system("pause");
	std::cout << "||=========================Node Contents================||" << endl;
	int n = 0;
	while (n<Num_Queue)
	{
		cout << "Queue Number # ->" << n << endl;
		output(Lines[n], Prog_Duration);cout << endl;
		n++;
	}
	cout << "||=========================END==========================||" << endl;
	system("pause");

	//cout << count << " customers waited an average of ";
	//cout << wait_sum / count << " ticks." << endl;
	//cout << "The longest time a customer waited was " << wait_time << " ticks." << endl;
	//cout << queue_total(line, num_lines) << " customers remain in the lines." << endl;

	system("pause");
	return 0;
}

//================================================================================= Extra functions

int Shortest(Queue Lines[], int Num_Queues)//reports the index to the shortest queue in the array
{
	int Shortest = 0;
	for (int i = 0; i < Num_Queues; ++i)
	{
		if (Lines[i].Size() < Lines[Shortest].Size())
			Shortest = i;
	}
	return Shortest;
}

int Queue_Total(Queue Lines[], int Num_Queues)//reports the total number of customers in Queue
{
	int Total_in_Queue = 0;
	for (int i = 0; i < Num_Queues; ++i)//counting the customers in all the Queues
		Total_in_Queue += Lines[i].Size();

	return Total_in_Queue;
}

void output(Queue Queue1, Item DequeT)
{
	if (Queue1.Is_Empty())
	{
		cout << ": Now the Queue is empty ::" << endl;
		system("pause");
	}
	cout << "QUEUE SIZE -->" << Queue1.Size() << endl;
	cout << "\t\t";
	while (Queue1.Size() > 0)//writing out the queue nodes data
	{
		cout << Queue1.Dequeue(DequeT) << " : ";
	}
}