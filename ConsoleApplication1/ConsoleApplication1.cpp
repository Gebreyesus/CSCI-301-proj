// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <fstream>
#include <iomanip>
#include <locale>
#include <iostream>
using namespace std;
int main()
{
	int num; int cont = 1;
	while (cont)
	{

		cout << "enter base 10 number to convert to base 2" << endl;
		cin >> num;
		int digits[500];
		int x = 0;
		while (num != 0 && x<8)
		{
			digits[x] = num % 2;
			num = num / 2;
			x++;
		}
		int y = x-1;
		while (y >= 0)
		{
			
			cout << digits[y];
			y--;
		}

		cout << "\n\nEnter 1 to continue running the program!!!" << endl;
		cin >> cont;
	}
	
	system("pause");
	return 0;
}

