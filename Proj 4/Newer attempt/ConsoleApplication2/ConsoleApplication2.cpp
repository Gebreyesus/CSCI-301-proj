// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// Example program
#include <iostream>
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct student
{
	string name=" ";
	int age=00;
	student *next;
	//student *back;
};
student *first;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
student* get_student(string name, int age, student* link)
{
	student *temp;

	temp = new student;
	temp->name = name;
	temp->age = age;
	temp->next = link;
	return temp;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	student* last;
	last=first = get_student("beteab", 26, NULL);
	last=first->next= get_student("gebru",130, NULL);
	last = first->next->next = get_student("gebreyesus", 80, NULL);

	cout << "first student :: " << "NAme: " << first->name << " : " << "age " << first->age << endl;
	cout << "last student :: " << "NAme: " << last->name << " : " << "age " << last->age << endl;

	/*first->name = "beteab";
	first->age = 25;
	first->next = new student; */
	//first->back = first;
		////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//cout << "FName " << first->name << " Age " << first->age;





	system("pause");
}
