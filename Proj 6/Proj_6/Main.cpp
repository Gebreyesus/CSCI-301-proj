#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "Un_List.h"
using namespace std;

//===============================================================================================================================================================
int main()
{
	int counter = 0;
	string file_Name;//string to store file_Name from which we'll read the words
	DL_List MyList;  //declared MyList- an instance of a class doubly linked list
	//ifstream Reader; 
	string word; char T;	//transports words into the nodes once we detetct a complete word
//file name//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//do       //ask for a working file name 3 times otherwise stop program
	//{
	//	if (counter == 0)  //ask for file name
	//	{
	//		cout << "Enter the the name of source text file" << endl;
	//		getline(std::cin, file_Name);//capture the name of the file from which to read words
	//		ifstream Reader(file_Name);
	//	}
	//	else if (counter<4 && counter>0)  // when file name entered is wrong we ask again 
	//	{
	//		cout << "Unable to open file!! \n Please input valid file name :hint-check spelling" << endl;
	//		getline(std::cin, file_Name);//capture the name of the file from which to read words
	//		ifstream Reader(file_Name);   
	//	}
	//	counter++;
	//	//Reader.open(file_Name);
	//}
	//while (!Reader && counter<4);

	//if (counter > 3)//exit program if filename.open was not working >3 times
	//{
	//exit(0);//exits to system cleanly
	//}

	cout << "Enter the the name of source text file" << endl;
	getline(std::cin, file_Name);//capture the name of the file from which to read words
	ifstream Reader(file_Name);

//get words to store/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	counter = 0;//resteting counter for different use
	while (!Reader.eof())
	{
		T = Reader.get();
		cout << "NExt letter in the word-->" << T << endl;
		if (T != ' ')
		{
 			word[counter] = T;//build words letter by letter using char arrays
			counter++;
				//system("pause");
				cout << "Debuging Line  ++the word so far-->" << word[1]<<word[2] << endl;
				system("pause");	
		}
		else if (T == ' ')
		{
			cout << "Detected whitespaces space ahead-->"<<T<<"::word formulated for insertion--> "<<word<< endl;
			MyList.Data_Intake(word);

			word = " ";
			counter = 0;
			//white_spaces++;
		}
					
	} 

	system("pause");
	cout << MyList;//OUtputing the final list of items
	system("pause");
	return 0;
}

