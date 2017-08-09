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
	
	string file_Name;//string to store file_Name from which we'll read the letters
	DL_List MyList;//declared MyList- an instance of a class doubly linked list
//	ifstream reader(file_Name);
		cout << "Enter the the name of source text file" << endl;
		getline(std::cin, file_Name);//capture the whole line of input from user
		ifstream reader(file_Name);////declare input stream Tell the file reader the name of the file to read 
		char T;
	while (reader.get(T))
	{
		if (T != '#')
		{
			cout << "inserted: " << T << " :into the link" << endl;
			MyList.Data_Intake(T);
		}
		else 
		{
			system("pause");
			cout << "MyList so far-->";cout << MyList;
			system("pause");

			if (! MyList.is_empty())
			MyList.remove_Last();	//removeds the last character added to the list				
			cout << endl;
			cout << "MyList after removal of items-->" << MyList;
			system("pause");//debugging line helps us see the progres
		}
		
   	 }

system("pause");
cout << MyList;//OUtputing the final list of items
system("pause");
	return 0;
}

