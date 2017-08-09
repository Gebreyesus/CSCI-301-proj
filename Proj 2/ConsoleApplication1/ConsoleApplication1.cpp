// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Name : Beteab Gebru
//Class : csci301-section 02
//ID : csci301154
//Date : jan-26-2017
//Programing proj 2
//This menu-driven program to manupulate ordered lists


#include "List.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;
//----------------------------------------------CONSTANTS-------------------------------------------------------------------
const int size = 3;		// capacity(size) of the array containing list of lists == 3 lists

//---------------------------------------FUNCTION PROTOTYPES----------------------------------------------------------------
void show_menu(char&);

//--------------------------------------------AIN PROGRAM-------------------------------------------------------------------
int main()
{

	char choice;//variable to store the manipulation instruction chosen from menu
	int value; //variable to store value user inputs for implementation
	int lindex;//variables refering to the lists in the array of lists
	int used;//used stores the number of used slots in each array(in other words refers to the last occupied index on the array)
	List n1,n2,n3; //three lists that contain 50 array spaces each;
	
	show_menu(choice); //show menu function is called here to get the user input

	do
	{
		switch (choice)
		{
		case'e': cout << "which list woud u like to make empty(enter list index number)" << endl;
				 cin >> lindex;
				 A[lindex].make_empty();
			break;

		case'i': cout << "PLease input the value you would like to insert" << endl;
				 cin >> value;
				 cout << "which list would you like the value goint into(enter list index number)" << endl;
				 cin >> lindex;
				 A[lindex].insert(value);
			break;

		case'r': cout << "enter list you want to remove value from(enter list index number)" << endl;
				 cin >> lindex; cout << "the list is as follows" << endl;
				 cout << setw(1) << lindex << A[lindex] << endl;
				 cout << "Please input the value you would like removed from the above list" << endl;
				 cin >> value;
				 A[lindex].remove(value);
			break;
		case'm': cout << "Enter destination of your merged lists" << endl;
				 cin >> lindex; 
				 cout << "the two other lists will be merged into --> List"<<lindex<<endl;
				 if (lindex == 0)
					 A[lindex] += (A[1] +=( A[2]));
				 else if(lindex == 1)
					 A[lindex] += (A[0] += (A[2]));
				 else if (lindex == 2)
					 A[lindex] += (A[0], A[1]);
				 cout << "the new list is as follows -->"<< setw(lindex) << lindex << A[lindex] << endl;
			break;
		case'l': cout << "enter list index of the list you want displayed" << endl;
				 cin >> lindex;
				 cout << setw(lindex) << lindex << A[lindex] << endl;

		}
	}

}

void show_menu(char& choice)
{
	cout << "Dear User: This program will provide you a menu to manipulate ORDERED LISTS" << endl;
	cout << "There are ordered lists N1,N2,N3; this lists are set empty initially" << endl;
	cout << "The menu below has explanatory notes which will assist in input format " << endl;
	cout << "we will use integers 0,1,2 to refer to the lists N1,N2,N3 respectively" << endl;
	cout << "choose a menu item from the following options please" << endl;
	do
	{
		cout << "e	--> Re-initialize(e) " << endl;
		cout << "i	--> Insert(i) a value into a list" << endl;
		cout << "r	--> Remove(r) a value from a list." << endl;
		cout << "m  --> Merge lists(m) " << endl;
		cout << "l	--> Report the length(l) a list" << endl;
		cout << "s  --> search(s) for a value in a list /will return<true/false>" << endl;
		cout << "k	--> Report the value found on kth position in a list" << endl;
		cout << "w	--> Write(w) out a list" << endl;
		cout << "q	--> Quit(q) menu" << endl;
		cin >> choice;
		choice=tolower(choice); // convert input char to lower case for comparison
	} 
	while (choice != 'e' || 'i' || 'r' || 'm' || 'l' || 's' || 'k' || 'w' || 'q');
}