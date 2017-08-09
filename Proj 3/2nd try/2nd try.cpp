// CSCI 301
// Computer Science 2

// FILE: b_test.cxx

// This is an interactive test program for the Bag class as provided by
// bag1a.h. The program responds to commands from the user to exercise
// three instances of the Bag class, and it assumes that those commands
// are correct as described in the menu() function.
#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "Header1.h"
using namespace std;
using namespace csci301_bag_1;

const int BAGS = 3;            // The number of bags the program manipulates

							   // Prototypes for functions in this program:

void menu();
// Postcondition: A menu of commands and instructions for their use has been written to cout.

int main()
{
	char command;                // Each command letter
	int v;                       // Each value in a command
	int n, n1, n2, n3;           // Bag indexes in commands

	Bag b[BAGS];                 // An array of bags

	menu();                      // Show the menu.
	do
	{
		cout << "--> ";            // Issue a prompt.
		cin >> command;            // Read a command letter.
		switch (command)         // Carry out the command.
		{
		case 'e': cin >> n;
			b[n].make_empty();
			break;

		case 'i': cin >> v >> n;
			b[n].insert(v);
			break;

		case 'r': cin >> v >> n;
			b[n].remove(v);
			break;

		case 's': cin >> n;
			cout << "Bag " << setw(1) << n << " contains "
				<< setw(1) << b[n].size() << " items." << endl;
			break;

		case 'o': cin >> v >> n;
			cout << "In bag " << setw(1) << n << ", the value " << setw(1)
				<< v << " occurs " << setw(1) << b[n].occurrences(v)
				<< " times." << endl;
			break;

		case 'u': cin >> n1 >> n2 >> n3;
			b[n3] = b[n1] + b[n2];
			break;

		case 'a': cin >> n1 >> n2;
			b[n2] += b[n1];
			break;

		case 'w': cin >> n;
			cout << "Bag " << setw(1) << n << ": " << b[n] << endl;
			break;

		case 'h': menu();
			break;

		default:;               // Null statement for an incorrect command
		}
	} while (command != 'q');

	return EXIT_SUCCESS;
}

void menu()
{
	cout << endl;
	cout << "This program responds to commands the user enters to" << endl;
	cout << "manipulate " << setw(1) << BAGS << " bags (multisets),"
		<< "  which are initially" << endl;
	cout << "empty. In the following commands, v is any integer, and" << endl;
	cout << "n , n1, n2, and n3 are numbers of bags; they may only be" << endl;
	cout << "integers from 0 to " << setw(1) << BAGS - 1 << '.' << endl << endl;
	cout << "  e n   -- Re-initialize bag n to be empty." << endl;
	cout << "  i v n -- Insert the value v into bag n." << endl;
	cout << "  r v n -- Remove the value v from bag n." << endl;
	cout << "  s n   -- Report the size of bag n." << endl;
	cout << "  o v n -- Report the number of times the value v" << endl
		<< "           occurs in bag n." << endl;
	cout << "  u n1 n2 n3 -- Form the union of bag n1 and bag n2" << endl
		<< "                put the union in bag n3." << endl;
	cout << "  a n1 n2 -- Add the contents of bag n1 to bag n2." << endl;
	cout << "  w n -- Write out the contents of bag n." << endl;
	cout << "  h -- See this menu." << endl;
	cout << "  q -- Quit the program." << endl << endl;
}

