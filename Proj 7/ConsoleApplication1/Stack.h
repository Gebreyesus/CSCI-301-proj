
#include <cstdlib>    // Provides the type size_t.
#include <string>
using namespace std;


typedef int Item;	//item type def
static const int CAPACITY = 100;//potential to store 100 prime factors
class Stack
	{

	public:
		Stack();				//constructor
		~Stack() { while (used >= 0)  used--; }		//Destructor
		bool is_empty() const; //returns true if stack is empty
		int get_used() const;//returns the number of items in stack
		int get_smallest();//returns the number of items in stack
		Item peek() const;

		void push(const Item entry);
		Item pop();
		bool IsPrime(int);				//checks if number is prime //returns true if prime
		void Prime_Factors(int);	 //prints out the prime number

		friend std::ostream& operator << (std::ostream& Output, Stack& MyStack);  //overloads the '<<' operator	

	private:
		Item data[CAPACITY];
		Item smallest=0;
		int used;
	};



