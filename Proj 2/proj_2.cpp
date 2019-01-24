// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//Name : Beteab Gebru
//Class : csci301
//ID : csci3011
//Date : jan-26-2017
//Programing proj 2
//This program will present a menu to manupulate ordered lists

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;
const int capacity = 100;//Size of 
const int Num_of_Programs = 10;//Size of Programs_arrays
bool use_pointer = false; // choice of using or not using pointers to do the operations


class Lists
{
	//----------------------------------------Private MEMBERS-------------------------------------------------------------------
private:
	
	//--------------------------------------------Public MEMBERS-----------------------------------------------------------------
public:
	//-------------------------------------------Set structure data -------------------------------------------------------------
	
	//-------------------------------------------get structure data Data---------------------------------------------------------
	//----------------------------------------------------Constructors and destructors ------------------------------------------

	StudentInfo();   //Deafault Constructor  
	StudentInfo(string, string, int[], const int, int[], const int, int[], const int);  //Constructor with parameters	
	~StudentInfo();  //Desconstructor

};

//-------------------------------------------METHODS TO MODIFY THE OBJECT CLASS---------------------------------------------
StudentInfo::StudentInfo()    //default constructor with no parameters
{
	cout << "We are in the constructor now::The default constructor function allocates object memory" << endl;
}
//the following constructor will do initialisation work on all the datamemebers of the data structure
StudentInfo::StudentInfo(string FirstName, string LastName, int Exams[], const int Num_of_Exams, int Quizes[], const int Num_of_Quizes, int Programs[], const int Num_of_Programs)
{
	Exams[Num_of_Exams];//={ 50,50,50 };//initial values for exams array
	Quizes[Num_of_Quiz];//= {1,2,3,4,5,6,7,8};//initial values for Quiz array
	Programs[Num_of_Programs];//={ 1,2,3,4,5,6,7,8,9,10};//initial values for programs array

	cout << "We are now int the parametered constructor : The datamembers can be initialised in this function" << endl;
	setFirstName("Beteab");
	setLastName("Gebreyesus");
	setExams(Exams, Num_of_Exams);
	setQuizes(Quizes, Num_of_Quizes);
	setPrograms(Programs, Num_of_Programs);
}
StudentInfo::~StudentInfo()  //deconstructor deletes object and members to free up spaces
{
	cout << "The Deconstructor has deleted the object and vacated the memory" << endl;
}
void StudentInfo::setFirstName(string FN)//set first name
{
	FirstName = FN;
}
void StudentInfo::setLastName(string LN)//set last name
{
	LastName = LN;
}
void StudentInfo::setQuizes(int Q[], const int Num_of_Quiz)
{
	int a = 0;
	while (a<Num_of_Quiz)
	{
		Quizes[a] = Q[a];
		a++;
	}
}
void StudentInfo::setPrograms(int P[], const int Num_of_Programs)
{
	int b = 0;
	while (b < Num_of_Programs)
	{
		Programs[b] = P[b];
		b++;
	}
}

void StudentInfo::setExams(int Ex[], const int Num_of_Exams) //set the three exam results
{
	int c = 0;
	while (c<Num_of_Exams)
	{
		Exams[c] = Ex[c];
		c++;
	}
}

string StudentInfo::getFirstName() const//get First Name
{
	return FirstName;
}
string StudentInfo::getLastName() const//get Last Name
{
	return LastName;
}

int StudentInfo::getExam()const//static variable to store index ; function returns 
{
	static int x = 0;
	const int *examPtr = &Exams[x];
	x++;
	return *examPtr;
}

int StudentInfo::getQuizes() const//get quiz scores
{
	static int y = 0; //static variable to store index for get array element calls  return Quizes[index];
	const int *quizPtr = &Quizes[y];
	y++;
	return *quizPtr;
}
int StudentInfo::getPrograms() const//getting program score
{
	static int z = 0;//static variable to store index for get array element calls  return Quizes[x];
	const int *programPtr = &Programs[z];
	z++;
	return *programPtr;
}
double StudentInfo::getExamAverage()const//This method calculates average exam score
{
	int f = 0; int sum = 0;
	while (f<Num_of_Exams)
	{
		sum += Exams[f];
		f++;
	}
	return (sum / Num_of_Exams);
}
double StudentInfo::getQuizAverage()const//This method calculates average Quiz score
{
	int f = 0; int sum = 0;
	while (f<Num_of_Quiz)
	{
		sum += Quizes[f];
		f++;
	}
	return (sum / Num_of_Quiz);
}
double StudentInfo::getProgramsAverage()const//calculates the average Programs score
{
	int f = 0; int sum = 0;
	while (f<Num_of_Programs)
	{
		sum += Programs[f];
		f++;
	}
	return (sum / Num_of_Programs);
}

void show_menu(string&);
int main()
{
	string choice=" ";
	cout << "Dear User: This program will provide you a menu to manipulate ORDERED LISTS" << endl;
	cout << "There are ordered lists N1,N2,N3; this lists are set empty initially" << endl;
	cout << "The menu below has explanatory notes which will assist in input format " << endl;
	cout<<  "we will use integers 0,1,2 to refer to the lists N1,N2,N3 respectively" <<endl;
	show_menu(choice);

		
}

void show_menu(string& choice)
{
	
	cout << "choose a menu item as shown by the examples next to them" << endl;
	cout << "e-n1		--> Re-initialize(e) list 'N1'" << endl;
	cout << "i-v-n1		--> Insert(i) the value 'v' into list 'N1'" << endl;
	cout << "r-v-n1		--> Remove(r) the value 'v' from list 'N1'." << endl;
	cout << "m-n1-n2-n3 --> Merge lists(m) 'N1' and 'N2' and save it to 'N3'."<<endl;
	cout << "l-n1		--> Report the length(l) of list N1." << endl;
	cout << "s-v-n1		--> search(s) value 'v'  in list 'N1' <true/false>" << endl;
	cout << "k-n1		--> Report the value found on kth position in list 'N1'." << endl;
	cout << "w-n1		--> Write(w) out list n1." << endl;
	cout << "q			--> Quit(q) menu" << endl;

	cin >> choice;
}


