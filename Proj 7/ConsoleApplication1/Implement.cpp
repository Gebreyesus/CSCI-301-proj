#include "stdafx.h"
#include <cstdlib>                         // Provides int
#include <iostream>                       // Provides istream and ostream
#include <cassert>						 // Provides assert()
#include "Stack.h"
# include<conio.h>
using namespace std;

//---------------------------------------------------constructor && destructor
Stack::Stack() { used = 0; }		
//----------------------------------------------------------get_used()
int Stack::get_used()  const {	return used; }   //returns number of items on stack
//----------------------------------------------------------es_empty()
bool Stack::is_empty() const { return used == 0  ; }	//returns true if stack is empty
//----------------------------------------------------------getsmallest()
Item Stack::get_smallest() { return smallest;   }//returns the smalles factor
//----------------------------------------------------------peek() 
Item Stack::peek() const
{
	assert(!is_empty());
	return data[used - 1];
}

//-------------------------------------------------------------pop() Function
Item Stack::pop()//returns top most item from stack and reduces used by one
{
	if ((used) < 0)
	{
		cout << "|| stack underflow || stack is empty:: unable to pop stack" << endl;
	}
	else
	used--;
	return data[used];
}

//----------------------------------------------------------isPrime() Function
bool Stack::IsPrime(int number)
{
	bool primality = true;
	int i = 2;
	while (i <= sqrt(number) && primality == true)
	{
		if (number % i == 0)// non-prime number will pass this check
		{
			primality=false;
		}
		i++;
	}
	return primality;
}

//----------------------------------------------------------push() Function
void Stack::push(const Item entry)//pushes in a prime factor onto the stack 
{
	if (used == 0)//the last item
	{
		smallest = entry;
	}
	if (used < CAPACITY)
	{
		data[used] = entry;
		used++;
	}
	else if (used == CAPACITY-1)
	{
		cout << "|| stack overflow || stack is full:: entry will can not be stacked-->" << endl;
	}
}

//-------------------------------------------------------------------Prime_Factors()Function
void Stack::Prime_Factors(int number)
{
	int a = 2; int temp = number;
	int max_prime = sqrt(number);// loss of data occurs here but is acceptable for us
	int product = 1;//keeps track of product of primes to stop early
	

	while (a <= max_prime)
	{
		while (number % a == 0)
		{
			product = product * a;
			push(a);//pushing the first prime factor into the stack
			number = number / a;
		}
		
		if (a == max_prime) //in case theres a prime factor > sqrt(number)-->optimisatio
		{
			if (product < temp && max_prime != temp)
				max_prime = ((temp / product));
			else if (product == temp)
				a = max_prime;//cutting the search short when we have the last one 
		}
		a++;
	}
}

//------------------------------------------------------------------friend function
ostream&  operator << (ostream& Output, Stack& MyStack)
{
	if (MyStack.is_empty())
	{
		Output << "The stack is empty" << endl;
	}
	else 
	{
		while (!MyStack.is_empty())//pop members of current stack until empty
		{
			cout << MyStack.pop();
			if(!MyStack.is_empty())
				cout<< " * ";
		}
		cout << endl;//next line for the next stack output
		cout << "||THE SMALLEST PRIME FACTOR -->" << MyStack.get_smallest()<<endl;
		cout << "||=========================end===================================||" << endl;
	}
	
	return Output;
}






