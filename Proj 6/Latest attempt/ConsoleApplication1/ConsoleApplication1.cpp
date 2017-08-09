#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <fstream>
 
using namespace std;
ifstream inputFile;
 
const int SIZE = 16000;
string parsedText[SIZE];
 
/* Function declarations */
string* ParseFile(istream& inputFile, int &arraySize);
 
/* Single node for linked list*/
struct Concordance
{
	string Word;
	int Count;
	Concordance *next;
};
 
/* Linked List */
class SingleLinkedList
{
	Concordance *start;
public:
	// Constructor and destructor
	SingleLinkedList();
	~SingleLinkedList();
 
	Concordance* CreateConcordance(string word);
	void InsertConcordance(string word);
	void ProcessNewConcordance(string word);
	int GetCount(string word);
	int GetListLength();
	//void Display();
 
	friend ostream& operator<< (ostream& os, SingleLinkedList l);
};
 
// Declare global variable of type of SingleLinkedList
SingleLinkedList sl;
 
int main()
{
	string nWord;
	//start = NULL;
	int arraySize = 0;
 
	char inputFileName[40];
 
	cout << "Please enter the input file name: ";
	cin >> inputFileName;
 
	inputFile.open(inputFileName);
	if (!inputFile)
	{
		cout << "Could not open the input file" << endl;
		return 0;
	}
 
	// Passing the arraySize by reference!
	string* words = ParseFile(inputFile, arraySize);
 
	/*	Loop through the array of words.
	If a concortance node with the given word exists, increment its count.
	Otherwise, create a new concortance node */
	for (int i = 0; i < arraySize; i++)
	{
		sl.ProcessNewConcordance(words[i]);
	}
 
	// Display all nodes in the linked list, starting from the start element, all the way up to ->next == NULL:
	//sl.Display();
	cout << sl;
 
	/**************************************************************************************
	INSERT A WORD FROM USER INPUT
	**************************************************************************************/
	cout << "\nPlease choose a word to insert into the concordance" << endl;
	cin >> nWord;
 
	// Trim each word to up to 8 characters.
	// BEFORE: "somestring"	AFTER: "somestri"
	string substring = nWord.substr(0, 8);
 
	// Remove punctuation
	// BEFORE: "somestr,"	AFTER: "somestr"
	substring.erase(remove_if(substring.begin(), substring.end(), ispunct), substring.end());
 
	// To upper case
	// BEFORE: "somestr"	AFTER: "SOMESTR"
	transform(substring.begin(), substring.end(), substring.begin(), toupper);
 
	sl.InsertConcordance(substring);
 
	/**************************************************************************************
	GET THE COUNT FOR THE WORD FROM USER INPUT
	**************************************************************************************/
	int cnt = sl.GetCount(substring);
 
	cout << "\nThere are " << cnt << " occurrences of the word " << substring << "." << endl;
 
	/**************************************************************************************
	GET THE THE NUMBER OF DISTINCT WORDS
	**************************************************************************************/
	cnt = sl.GetListLength();
 
	cout << "\nThere are " << cnt << " Concordance nodes in the linked list." << endl;
 
	cout << "\nDisplay modified list? (Y or N)" << endl;
	cin >> nWord;
	transform(nWord.begin(), nWord.end(), nWord.begin(), toupper);
 
	if (nWord.compare("Y") == 0)
		//sl.Display();
		cout << sl;
 
	inputFile.close();
	return 0;
}
 
ostream& operator<< (ostream& os, SingleLinkedList l)
{
	struct Concordance *temp;
	if (l.start == NULL)
	{
		os << "The List is Empty" << endl;
		return os;
	}
	temp = l.start;
 
	os << setw(9) << left << "Word" << setw(6) << right << "Count" << endl;
	os << "---------------" << endl;
	while (temp != NULL)
	{
		os << setw(9) << left << temp->Word << setw(6) << right << temp->Count << endl;
		temp = temp->next;
	}
 
	return os;
}
 
SingleLinkedList::SingleLinkedList()
{
	start = NULL;
}
 
SingleLinkedList::~SingleLinkedList()
{
	//delete[] &parsedText;
}
 
int SingleLinkedList::GetCount(string inWord)
{
	struct Concordance *s;
	s = start;
	while (s != NULL)
	{
		// string::compare returns 0 if strings are equal
		if (s->Word.compare(inWord) == 0)
		{
			// Match found.
			return s->Count;
 
			// Exit the while loop:
			break;
		}
	 s = s->next;
	}
	return 0;
}
 
int SingleLinkedList::GetListLength()
{
	struct Concordance *s;
	s = start;
	int cnt = 0;
 
	while (s != NULL)
	{
		cnt++;
		s = s->next;
	}
 
	return cnt;
}
 
string* ParseFile(istream& inputFile, int &arraySize)
{
	const string EMPTY_STRING = "";
	string line;
	int cnt = 0;
 
	while (!inputFile.eof())
	{
		getline(inputFile, line);
 
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
 
			// Incrementing the counter, add each string to the array.
			parsedText[cnt++] = substring;
		}
	}
 
	arraySize = cnt - 1;
 
	// Sort the first (arraySize) elements in the array:
	sort(parsedText, parsedText + cnt);
 
	return parsedText;
}
 
/*	If a concortance node with the given word exists, increment its count.
Otherwise, create a new concortance node */
void SingleLinkedList::ProcessNewConcordance(string newWord)
{
	bool matchFound = false;
 
	struct Concordance *s;
	s = start;
	while (s != NULL)
	{
		// string::compare returns 0 if strings are equal
		if (s->Word.compare(newWord) == 0)
		{
			matchFound = true;
 
			// Increment concordance count:
			s->Count++;
 
			// Exit the while loop:
			break;
		}
		s = s->next;
	}
	if (matchFound)
		return;
 
	// If we have made it that far, then no match is found. Insert a new node:
	sl.InsertConcordance(newWord);
 
}
 
void SingleLinkedList::InsertConcordance(string newWord)
{
	struct Concordance *temp, *s, *nextNode;
	temp = CreateConcordance(newWord);
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
		// If the word to insert is already in the list, just increment its counter:
		if (s->Word.compare(newWord) == 0)
		{
			s->Count++;
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
 
// Create an instance of Concordance structure and iniciate it with the input string:
Concordance *SingleLinkedList::CreateConcordance(string word)
{
	struct Concordance *concordance = new(struct Concordance);
 
	concordance->Word = word;
	concordance->Count = 1;
	concordance->next = NULL;
 
	return concordance;
}

