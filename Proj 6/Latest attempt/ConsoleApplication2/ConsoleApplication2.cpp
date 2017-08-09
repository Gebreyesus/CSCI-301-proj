// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>

using namespace std;

ifstream File_Reader; //input file reader is declared here. it will take input file name as 
const int max_strsize = 1000;//max string size declared at 1000 letters
string parsedText[max_strsize]; // string with 100 array of possible characters is declared here

								//a string pointer is declared:
								//it will to point at an array element mem location--> will point at a char in the string 
string* ParseFile(istream& File_Reader, int &arraySize);//the array size refers to the word size

														//a single node of the linked list containing a word will have the following attributes
struct W_Node
{
	string Word;//will store the word of string type 
	int App_intext;//will record how many times a word appears in the given text
	W_Node *next;// pointer that acts as a link to the next word link
};

//declaration of a linked list class which will have attributes such as length, and pointers to sections of list
class Linked_List
{
	W_Node *start;//will be a pointer to first node in the chain
public:
	// Constructor and destructor
	Linked_List();// list constructor will initilise the class 
	~Linked_List();//list destructor will nulify the list members

	W_Node* get_Node(string word);//creates us new node in the list to store a word from text
	void ProcessNewW_Node(string word);// pre-process to word insertion that checks prescence of the word
	void InsertW_Node(string word);//insert a word into the list in right order
	int GetApp_intext(string word);
	int GetListLength();
	//void Display();

	friend ostream& operator<< (ostream& os, Linked_List l);
};

// Declare global variable of type of Linked_List
Linked_List sl;

int main()
{
	string nWord;
	//start = NULL;
	int arraySize = 0;

	char File_ReaderName[40]="Input_Normal_Text.txt";

	File_Reader.open(File_ReaderName);
	if (!File_Reader)
	{
		cout << "Could not open the input file" << endl;
		return 0;
	}

	// Passing the arraySize by reference!
	string* words = ParseFile(File_Reader, arraySize);

	/*	Loop through the array of words.
	If a concortance node with the given word exists, increment its App_intext.
	Otherwise, create a new concortance node */
	for (int i = 0; i < arraySize; i++)
	{
		sl.ProcessNewW_Node(words[i]);
	}

	// Display all nodes in the linked list, starting from the start element, all the way up to ->next == NULL:
	//sl.Display();
	cout << sl;

	/**************************************************************************************
	INSERT A WORD FROM USER INPUT
	**************************************************************************************/
	//cout << "\nPlease choose a word to insert into the W_Node" << endl;
	cin >> nWord;

	// Trim each word to up to 8 characters.
	// BEFORE: "somestring"	AFTER: "somestri"
	string substring = nWord.substr(0, 8);

	// Remove punctuation
	// BEFORE: "somestr,"	AFTER: "somestr";

	// To upper case
	// BEFORE: "somestr"	AFTER: "SOMESTR"
	transform(substring.begin(), substring.end(), substring.begin(), toupper);

	sl.InsertW_Node(substring);

	/**************************************************************************************
	GET THE App_intext FOR THE WORD FROM USER INPUT
	**************************************************************************************/
	int cnt = sl.GetApp_intext(substring);

	cout << "\nThere are " << cnt << " occurrences of the word " << substring << "." << endl;

	/**************************************************************************************
	GET THE THE NUMBER OF DISTINCT WORDS
	**************************************************************************************/
	cnt = sl.GetListLength();

	cout << "\nThere are " << cnt << " W_Node nodes in the linked list." << endl;

	cout << "\nDisplay modified list? (Y or N)" << endl;
	cin >> nWord;
	transform(nWord.begin(), nWord.end(), nWord.begin(), toupper);

	if (nWord.compare("Y") == 0)
		//sl.Display();
		cout << sl;

	File_Reader.close();
	return 0;
}

ostream& operator<< (ostream& os, Linked_List l)
{
	struct W_Node *temp;
	if (l.start == NULL)
	{
		os << "Nothing in this List check if text file has any dats in it" << endl;
		return os;
	}
	temp = l.start;
	cout << "||=====================================||" << endl;
	os << "||" << setw(8) << left << "The Words" << "                 " << "Concordance" << "||" << endl;
	cout << "||//Name: Beteab Geb                   ||\n||//Due Date : March 14 2017           ||" << endl;
	cout << "||//CSCI 301: Section 02               ||\n||//CSCI ID : cs301154                 ||" << endl;
	cout << "||-------------------------------------||" << endl;

	while (temp != NULL)//while we theres a node we keep printing node data
	{
		os << "|| " << setw(8) << left << temp->Word << "    -------------     " << temp->App_intext << "    :||" << endl;
		temp = temp->next;
	}
	cout << "||" << "=====================================||" << endl;


	return os;
}

Linked_List::Linked_List()
{
	start = NULL;
}

Linked_List::~Linked_List()
{
	//delete[] &parsedText;
}

int Linked_List::GetApp_intext(string inWord)
{
	struct W_Node *s;
	s = start;
	while (s != NULL)
	{
		// string::compare returns 0 if strings are equal
		if (s->Word.compare(inWord) == 0)
		{
			// Match found.
			return s->App_intext;

			// Exit the while loop:
			break;
		}
		s = s->next;
	}

	return 0;
}

int Linked_List::GetListLength()
{
	struct W_Node *s;
	s = start;
	int cnt = 0;

	while (s != NULL)
	{
		cnt++;
		s = s->next;
	}

	return cnt;
}

string* ParseFile(istream& File_Reader, int &arraySize)
{
	const string EMPTY_STRING = "";
	string line;
	int cnt = 0;

	while (!File_Reader.eof())
	{
		getline(File_Reader, line);

		// Stream for parsing a string into words:
		istringstream iss(line);

		while (iss)
		{
			string word;
			iss >> word;

			// Skip empty strings "".
			if (word.compare(EMPTY_STRING) == 0)
				continue;

			// Trim each word to up to 8 characters.
			// BEFORE: "somestring"	AFTER: "somestri"
			string substring = word.substr(0, 8);

			// Remove punctuation
			// BEFORE: "somestr,"	AFTER: "somestr"
			substring.erase(remove_if(substring.begin(), substring.end(), ispunct), substring.end());

			// To upper case
			// BEFORE: "somestr"	AFTER: "SOMESTR"
			transform(substring.begin(), substring.end(), substring.begin(), toupper);

			// Incrementing the App_intexter, add each string to the array.
			parsedText[cnt++] = substring;
		}
	}

	arraySize = cnt - 1;

	// Sort the first (arraySize) elements in the array:
	sort(parsedText, parsedText + cnt);

	return parsedText;
}

/*	If a concortance node with the given word exists, increment its App_intext.
Otherwise, create a new concortance node */
void Linked_List::ProcessNewW_Node(string newWord)
{
	bool matchFound = false;

	struct W_Node *s;
	s = start;
	while (s != NULL)
	{
		// string::compare returns 0 if strings are equal
		if (s->Word.compare(newWord) == 0)
		{
			matchFound = true;

			// Increment W_Node App_intext:
			s->App_intext++;

			// Exit the while loop:
			break;
		}
		s = s->next;
	}

	if (matchFound)
		return;

	// If we have made it that far, then no match is found. Insert a new node:
	sl.InsertW_Node(newWord);

}

void Linked_List::InsertW_Node(string newWord)
{
	struct W_Node *temp, *s, *nextNode;
	temp = get_Node(newWord);
	s = start;

	// If start is NULL, then the new node is the very first one in the linked list. Set start node to the new node.
	if (start == NULL)
	{
		start = temp;
		start->next = NULL;
		return;
	}

	// If we made it this far, then the start node was not NULL. Find the very last node in the linked list
	// (that would be the one whose ->next == NULL:
	while (s->next != NULL)
	{
		// If the word to insert is already in the list, just increment its App_intexter:
		if (s->Word.compare(newWord) == 0)
		{
			s->App_intext++;
			return;
		}

		nextNode = s->next;

		// If the word to insert is out of alphabetical order, insert it where it belongs:
		if (nextNode->Word.compare(newWord) > 0)
		{
			temp->next = nextNode;
			s->next = temp;
			return;
		}

		s = s->next;
	}

	// Set new node's ->next to NULL, and previous node's ->next to the new node:
	temp->next = NULL;
	s->next = temp;
}

// Create an instance of W_Node structure and iniciate it with the input string:
W_Node *Linked_List::get_Node(string word)
{
	struct W_Node *W_Node = new(struct W_Node);
	W_Node->Word = word;
	W_Node->App_intext = 1;
	W_Node->next = NULL;

	return W_Node;
}

