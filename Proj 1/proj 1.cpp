
//Name : Beteab Gebru
//Class : csci301
//ID : 
//project 1 : Date: 01/15/2017

#include <cstring>
#include <iostream>
#include <locale>

using namespace std;

void user_input(string&, int&);
bool is_palindrome(string&, int&);
bool myassert(string& , int& );

int main()
{
	string phrase=" ";
	int phrase_length=0;

	user_input(phrase, phrase_length);

	if (is_palindrome(phrase, phrase_length))
	{
		cout <<"\n The Sentence entered is a palindrome" << endl;
	}
	else
	{
		cout << "\n The sentence entered doesnt appear to be a plaindrome" << endl;
	}
	cin >> phrase;
}

//user_input() function retrieves user input////////////////////////////////////////
void user_input(string& phrase, int& phrase_length)// getting appropriate inputs for the program
{
	cout << "Hello User: This is palindrome detection program: " << endl;
	cout << "Enter your sentence to confirm if it is a palindrome\n";
	getline(std::cin, phrase);	// getting the input stored in string variable phrase
	phrase_length = phrase.size();//retrieves & stores length of the user input

	while (!myassert(phrase, phrase_length))
	{
		cout << "no user input was captured or input was all non alphanumeric characters" << endl;
		cout << "Enter your sentence again to confirm if palindrome\n";
		getline(std::cin, phrase);
		phrase_length = phrase.size();//retrieves & stores length of the user input
	}
	//the following loop will put all the characters into lower case
	for (int x = 0; x <= phrase_length; x++)
	{
		char s = phrase[x];
		phrase[x] = putchar(tolower(s));
	}

}

//myassert() function to ensure adequate input////////////////////////////////
bool myassert(string& phrase, int& phrase_length)
{
	bool check = false;
	if (phrase == " ")
	{
		return check; 
	}
	
	for (int x = 0; x <= phrase_length; x++)
	{
		if (isalnum(phrase[x]))
			check = true;
	}
	return check;
}

//is_palindrome() function///////////////////////////////////////////////////////
bool is_palindrome(string& phrase, int& phrase_length)
{
	bool Detect = true;//changes to false when !palindrome
	int a = 0, b = phrase_length;//creating looping variables

	while ((a <= b) && (Detect == true))
	{
		while (!isalnum(phrase[a])) //to skip the non alphanumerics for comparison from left side
			a++;
		while (!isalnum(phrase[b])) //to skip non alpha numeric positions from right side
			b--;
			if (phrase[a] == phrase[b])
			{
				Detect = true;
				a++; b--;
			}
			else 
				Detect = false;
	}
	return Detect;
}
