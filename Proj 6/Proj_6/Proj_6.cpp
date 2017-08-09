#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "Un_List.h"
#include <iomanip>
#include <locale>
using namespace std;
//Name: Beteab Gebru
//Due Date : March 14 2017
//CSCI 301: Section 02
//CSCI ID : cs301154
//===============protoypes of functions
string Format_Word(string);
string get_Word(fstream &Reader);
//====================================================================================================================
int main()
{
	string Word = " ";	//Line stores a space delimited sequence of chars to be processed for linked list storage
	static int Word_Counter = 0;	//counts total number of words
	L_List MyList;		    	//declared MyList- an instance of a linked list class
	string files[3] = { "Text_1.txt", "Text_2.txt","Text_3.txt" };//3 test files are declared here
	static fstream Reader(files[2]);	//selecting test file to use out of the three available
	while (Word != "!")
	{
		Word = get_Word(Reader);//extract word from text
		cout << "Word-->:" << Word << "::" << endl;
		if (Word != "!")//word to be adeed to BST
		{
			MyList.Data_Intake(Word);		//sending the word for storage in the linked list	
			Word_Counter++;
			cout << "Word-->:" << Word << "::" << endl;
		}

	}

	cout << MyList << endl;	//DIsplay list using overload operator
	cout << MyList.getLength(MyList.getfirst()) << endl;//list Length
	system("pause");
	cout << "first" << MyList.getfirst()->Data << endl;//First Node in list
	cout << "last" << MyList.getlast()->Data << endl;	//Lats node in the list
	system("pause");
	return 0;
}


//Extracts word fromtext ==============================================================================================
string get_Word(fstream &Reader)
{
	string Word;
	if (!Reader.eof())
	{
		getline(Reader, Word, ' ');		 //reading in a Word segment from the text file 
		if (!Word.empty())//checks for empty lines
		{
			Word = Format_Word(Word);		//Word is formatted appropriately-->8 chars and all upper case
											//cout << "::Word Extracted-->" << Word << endl;
			size_t first = Word.find_first_not_of(' ');//trimming leading and trailing spaces
			size_t last = Word.find_last_not_of(' ');
			return Word.substr(first, (last - first + 1));
		}
	}

	return "!";//indicating end of text text file
}
//Formatt Word=========================================================================================================
string Format_Word(string A_Word)
{//this function would format the Word to be max length of 8 characters and all in upper case for easy comparison
	string Word = "       ";
	int a = 0; int x = 0;
	int Length = A_Word.length(); //the length of the string we read from text
	Word = Word.substr(0, Length); //declaring string to store 8 characters
	while ((a < Length) && (a < 8))//iterating through the block of characters to find alphabets
	{
		if (isalpha(A_Word[a]))
		{
			Word[x] = A_Word[a];		  //FLEECING OUT A Word FROM THE Line
			Word[x] = toupper(Word[x]);	//converting the characters to upper case
			x++;
		}
		a++;
	}
	return Word;
}
