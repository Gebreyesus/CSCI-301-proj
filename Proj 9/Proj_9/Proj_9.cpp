// Proj_9 Sorting Algorithms
//Name: Beteab Gebru
//Due Date : April 18th 2017
//CSCI 301:  Section 02
//CSCI ID :  cs301154
#include "stdafx.h"
#include <cstdlib>                         // Provides size_t
#include <iostream>                       // Provides istream and ostream
#include <cassert>						 // Provides assert()
#include <iomanip>
using namespace std;

//===============================================Declared the timer variables here for ease of use
int Merge_Counter = 0;
int Insertion_Counter = 0;
int Quick_Counter=0;
int Array_Size=0;
int Seed; 
//===============================================unsorted arrays
int  Unsorted[1000]; //declare array of maximum size

int Merge10[10],	 Insertion10[10],		Quick10[10];		//10 item array
int Merge50[50],	 Insertion50[50],		Quick50[50];		//50 item array
int Merge100[100],	 Insertion100[100],		Quick100[100];		//100 item array
int Merge500[500],	 Insertion500[500],		Quick500[500];		//500 item array
int Merge1000[1000], Insertion1000[1000],	Quick1000[1000];	//1000 array
//===============================================prototypes of utility functions 
void Merge_Sort(int The_Array[], int, int );
void Insertion_Sort(int The_Array[], int );
void Quick_Sort(int The_Array[], int First, int Last);
//auxilary functions
void Merge(int The_Array[], int, int, int);
void Create_Arrays();//producing array of random variables of different sizes

//===================================================================================================
int main()
{
	char Continue = 'Y', Display;
	cout << "Enter the array size to sort :input 10 or 50 or 100 or 500 or 1000 \n -->  " ;//WHICH ARRAY TO SORT
	cin >> Array_Size;
	Create_Arrays();	//create the array of random values to sort

	while (Continue == 'Y')//keep runnning the program until testing is finished
	{
		Merge_Counter = 0, Insertion_Counter = 0, Quick_Counter = 0;//resetting the counters for the next loop
		if (Array_Size == 0)
		{
			cout << "Do you want to continue running the program? : \n -> Y-Yes, N-No       \n ---> " ;   //continue running
			cin >> Continue;  Continue = toupper(Continue);
			cout << "Enter the array size to sort :input 10 or 50 or 100 or 500 or 1000  \n --> ";//WHICH ARRAY TO SORT
			cin >> Array_Size;
		}
		cout << "Do you want to Display the Values in the arrays: \n--> Y-Yes, N-No \n --> ";//Display ARRAY ELEMENTS
		cin >> Display;  Display = toupper(Display);
		cout << "Enter an integer seed value :\n --> " ;
		cin >> Seed;

		//===============================================================================================Sorting occures here

		if (Array_Size == 10)
		{
			Merge_Sort(Merge10, 0, (Array_Size - 1));
			Insertion_Sort(Insertion10, Array_Size);
			Quick_Sort(Quick10, 0, Array_Size - 1);
		}
		else if (Array_Size == 50)
		{
			Merge_Sort(Merge50, 0, Array_Size - 1);
			Insertion_Sort(Insertion50, Array_Size);
			Quick_Sort(Quick50, 0, Array_Size - 1);
		}
		else if (Array_Size == 100)
		{
			Merge_Sort(Merge100, 0, Array_Size - 1);
			Insertion_Sort(Insertion100, Array_Size);
			Quick_Sort(Quick100, 0, Array_Size - 1);
		}
		else if (Array_Size == 500)
		{
			Merge_Sort(Merge500, 0, Array_Size - 1);
			Insertion_Sort(Insertion500, Array_Size);
			Quick_Sort(Quick500, 0, Array_Size - 1);
		}
		else if (Array_Size == 1000)
		{
			Merge_Sort(Merge1000, 0, Array_Size - 1);
			Insertion_Sort(Insertion1000, Array_Size);
			Quick_Sort(Quick1000, 0, Array_Size - 1);
		}
	
		cout << "For Array of size-->" << Array_Size << ": The Number Characteristic Operations needed to sort the arry" << endl;
		cout << "=================================================================================================" << endl;
		//===================================================================================================Merge_Sort @Main O(log N)
		cout << "::Merge-Sort -->" << Merge_Counter << endl;
		//===================================================================================================Insertion_Sort 
		cout << "::Insertion-sort -->" << Insertion_Counter << endl;
		//===================================================================================================Quick_sort 
		cout << "::Quick-Sort -->" << Quick_Counter << endl;

		cout << "------------------------------------END------------------------------------" << endl;
		system("pause");
		
		//===============================================================================================Displaying items
		if (Display == 'Y')
		{
			cout << "===================Items In the Array Before Sorting ===================" << endl;
			for (int x = 0; x < Array_Size; x++)  //Display array elements
			{
				cout << Unsorted[x] << ":";
			}
		}
		if (Display == 'Y')
		{
			cout << "\n======================After Sorting of The Elements=====================" << endl;
			for (int i = 0; i < Array_Size; i++)
			  {
				cout << Quick100[i] << " ";
				if(i%25 == 0 && i!=0)//write 25 items per line 
				cout << endl;
			  }		
		}
		cout << endl<<"=======================================End of Loop==========================================" << endl;
		Array_Size = 0;
	}
	cout  << "--> End <--"<< endl;
	system("pause");
	return 0;
}

//===============================================================================================================Auxilary functions

void Create_Arrays()//producing array of random variables of different sizes
{
	srand(Seed);	//seeding our random number genrator
	int x = 0;

	while (x < Array_Size)
	{
			Unsorted[x] = (rand());
			if (x<10)
			{
				Merge10[x]		 =	 Unsorted[x];
				Insertion10[x]	 =	 Unsorted[x];
				Quick10[x]		 =	 Unsorted[x];
			}
			if (x<50)
			{
				Merge50[x] = Unsorted[x];
				Insertion50[x] = Unsorted[x];
				Quick50[x] = Unsorted[x];
			}
			if (x<100)
			{
			
				Merge100[x] = Unsorted[x];
				Insertion100[x] = Unsorted[x];
				Quick100[x] = Unsorted[x];
			}
			if (x<500)
			{
				
				Merge500[x] = Unsorted[x];
				Insertion500[x] = Unsorted[x];
				Quick500[x] = Unsorted[x];
			}
			if (x<1000)
			{
				Merge1000[x] = Unsorted[x];
				Insertion1000[x] = Unsorted[x];
				Quick1000[x] = Unsorted[x];
			}
		x++;
	}

}
//========================================================================Merge_Sort O(nlogn) time O(n) space
void Merge_Sort(int The_Array[], int First, int Last)
{
	if (First < Last)		// Sort each half
	{
		int mid = (First + (Last - First) / 2);   // Index of midpoint
		Merge_Sort(The_Array, First, mid);  	// Sort Left half The_Array[First..mid]
		Merge_Sort(The_Array, mid + 1, Last); 	// Sort Right half The_Array[mid+1..Last]

		Merge(The_Array, First, mid, Last);    // Merge the two halves
	} 
	
}  

void Merge(int The_Array[], int First, int mid, int Last)
{	
	int Temp_Array [1000];		// The sorted array holder
	int First1 = First;        // Beginning of First subarray
	int Last1 = mid;           // End of First subarray
	int First2 = mid + 1;      // Beginning of second subarray
	int Last2 = Last;          // End of second subarray

	// While both subarrays are not empty, copy the smaller of the front items  item into the temporary array							
	int Index = First1;         // Next available location in temporary Array 
	while ((First1 <= Last1) && (First2 <= Last2))   //parse until we hit end of arrays
	{
		Merge_Counter++;//counter
		if (The_Array[First1] <= The_Array[First2])	 
		{
			Temp_Array[Index] = The_Array[First1];
			First1++;
		}
		else
		{
			Temp_Array[Index] = The_Array[First2];
			First2++;
		}  
		Index++;
	}
	while (First1 <= Last1)  //finishing off the first subarray
	{
		Merge_Counter++;//counter
		Temp_Array[Index] = The_Array[First1];
		First1++;
		Index++;
	}  	 
	while (First2 <= Last2)  // Finish off the second subarray,
	{
		Merge_Counter++;//counter
		Temp_Array[Index] = The_Array[First2];
		First2++;
		Index++;
	}  
	//===================================Copy into the original array
	for (Index = First; Index <= Last; Index++)
	{
		The_Array[Index] = Temp_Array[Index]; 
	}
}

//=======================================================================Insertion Sort O(n^2) time O(1) space
void Insertion_Sort(int The_Array[], int Array_Size)
{//handling sorted and unsorted portions toget fully sorted arrays
	int Previous_Number = 0;
	int Cursor = 0;

	for (int index = 1; index < Array_Size; ++index)
	{
		Insertion_Counter++;//counter
		Cursor = The_Array[index];
		Previous_Number = index - 1;
		
		while (Previous_Number >= 0 && The_Array[Previous_Number] > Cursor)
		{
			Insertion_Counter++;//counter
			The_Array[Previous_Number + 1] = The_Array[Previous_Number];
			Previous_Number = Previous_Number - 1;
		}
	 The_Array[Previous_Number + 1] = Cursor;
	}
} 

//========================================================================Quick_Sort   O(nlogn) time O(n) space
void Quick_Sort(int arr[], int Left, int Right) 
{
	int i = Left, j = Right, tmp;
	int pivot = arr[(i + j) / 2]; //selecting random pivot 

	while (i <= j) 
	{
		Quick_Counter++;//counter
		while (arr[i] < pivot) 
		{
			 i++;
			
		}
		while (arr[j] > pivot)
		{
			j--; 
			
		}
		if (i <= j) 
		{
		
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++, j--;
		}
	}
	
	if (Left < j)
	{
		Quick_Sort(arr, Left, j);
		Quick_Counter++;//counter
	}
	if (i < Right)
	{
		Quick_Sort(arr, i, Right);
		Quick_Counter++;//counter
	}
		
}