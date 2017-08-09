#pragma once
#include "stdafx.h"
#include "Queue.h"
#include <iostream>
using namespace std;

typedef int Item;

class Server
{

private:

	bool Availability =true;
	int Transact_Time = 0;	//keeps track of transaction time 
public:	
	
	//========================================================== CONSTRUCTOR
	Server();
	//========================================================== DESTRUCTOR
	~Server();
	//========================================================== Other fuctions
	void Set_Availability(bool status);	//set availability of server
	bool Is_Available();		// reports if server is available
	void CLock_Tick();		//returns the transaction time left on the clock
	void Set_Trans_Time(int Trans_Time); //sets how long a server will be busy with customer
	int Get_Trans_Time(); 
};



