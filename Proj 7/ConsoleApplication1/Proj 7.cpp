
//Name: Beteab Gebru
//Due Date : March 28th 2017
//CSCI 301:  Section 02
//CSCI ID :  cs301154

#include "stdafx.h"
#include <cstdlib>                         // Provides size_t
#include <iostream>                       // Provides istream and ostream
#include <cassert>						 // Provides assert()
#include "Stack.h"
#include <conio.h>
using namespace std;


int main()
{
	const int Number_of_Stacks = 8;
	int numbers[Number_of_Stacks] = {1776,6463,349856,352170,726345,36423479,1,0};//stores number inputs for factorisation
	int x = 0;
	Stack My_Stack[Number_of_Stacks];//declaring array of stack objects to store prime factors for each of the 8 factors
		
	while (numbers[x] != 0 && x < Number_of_Stacks)//we'll take numbers and store their prime factors in separate stacks
	 {
				
			My_Stack[x].Prime_Factors(numbers[x]);
			x++;
	 }
//==================================================================displaying My_Stack
	x = 0; //resetting counter
	cout << "||=======================Listing Prime factors====================||" << endl;
	while (x < Number_of_Stacks)
	{
		cout << "Prime factors of:" << numbers[x] << " are--> ";
		cout << My_Stack[x];
		cout << endl;
		x++;
	}
	cout << "||=========================end===================================||" << endl;


//==================================================================for user input testing
	int Num = 1; Stack user_stack;
	while (Num != 0)
	{
		cout << "\n\nenter positive integer numberber to find its prime factors; input zero to close program" << endl;
		cin >> Num;
		user_stack.Prime_Factors(Num);


		//==================================================================displaying user_stack

		cout << "||=======================Listing Prime factors====================||" << endl;
		cout << "Prime factors of:" << Num << " are--> ";
		cout << user_stack;
		cout << endl;
		cout << "||=========================end===================================||" << endl;


	}
	

	system("pause");
}

