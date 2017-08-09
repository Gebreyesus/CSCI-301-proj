#include "stdafx.h"
#include "Binary_Search_Tree.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <locale>
#include <cassert>
using namespace std;
//Name: Beteab Gebru
//proj 10 - Concordance With a BST
//Due Date : April 27 2017
//CSCI 301: Section 02
//CSCI ID : cs301154

//====================================================================================================================
int main()
{
	BST My_Tree;		    	//declared My_Tree an instance of a linked list class
	string Word ;	char C;		//Word stores a word temporarily && C stores chars temporarily
	int Word_Count = 0;			//stores word count from text
	
	//3 sample text files, with varying data are declared here
	string files[3] = { "Text_1.txt", "Text_2.txt","Text_3.txt" };
		fstream Reader(files[0]);	//selecting test file to use out of the three available
		while (!Reader.eof())
		{
			Reader.get(C);
			//cout << "Character extracted-->" << C << endl;//debuging line
			if (isalpha(C))
			{
				//out << "ALPHABET-->" << C << endl; system("pause"); //debuging line
				C = toupper(C);
				Word = Word + C;
			}
			else //when encountering non alphabet we see if we have a complete word
			{
				//cout << "NON-ALPHA-->" << C <<" Word extracted-->"<< Word<< endl; system("pause"); //debuging line
				if (Word.length() > 8)
					Word = Word.substr(0, 8);
				if (!Word.empty())
				{
					My_Tree.Insert(Word);
					Word = "";		//resseting the variable to store the next character
					Word_Count++;
				}
			}
		}
	cout << "==================A FILE HAS BEEN READ OUT=====================" << endl;
	//================================================================Output the tree data
	
	cout << "Total Word_Count is -->" <<Word_Count<< endl;
	cout << My_Tree << endl;			
	system("pause");

	//=============================================================Testing a removal of a word
	string To_Remove;
	cout << "ENTER A WORD YOU WANT TO REMOVE:" << endl;
	cin >> To_Remove;

	for (int i = 0; i < 8; i++)
	{
		if (i < To_Remove.length())
			To_Remove[i] = toupper(To_Remove[i]);
		else
			i = 9;//once we have all the characters we need we cut loop short here
	}
	cout << "Word to remove is ->" << To_Remove << endl;
	My_Tree.Remove(To_Remove);
	cout << My_Tree << endl;
	system("pause");
	//cout << "==================Finished Reading ALL Files===========================" << endl;

	return 0;
}
