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

//===============================================================================================================================================================

int main()
{		//char from_File[40];		//array of chars stores characters as they are read from file
	DL_List MyList;
	
	ifstream reader("ReadMe.txt");
	
	for( int a = 0; a <= 100; a=(a+5))	//
	 {
		MyList.Data_Intake(a);
		cout << "inserted: " << a << " :into the link" << endl;
   	 }
	
	cout << "1.--created new list called My_List" << endl;
system("pause");
	cout << "finished with data storing" << endl;
system("pause");
	cout << MyList<<endl;
system("pause");
	

cout << "1.--will delete last 5 items" << endl;
for(int a=0;a<5;a++)
MyList.remove_Last();
cout << "5 items have been deleted " << endl;
cout << "we'll display the rest of the items" << endl;
system("pause");
cout << MyList << endl;
system("pause");
	return 0;
}

