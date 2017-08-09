// CSCI 301
// Computer Science 2

// FILE: bag1a.h
//
// CLASS PROVIDED: Bag; a container class for multisets of items.
//
// Note: These comments are substantially the same as the text's
// Figure 3.1 (pp.100-102), with the addition of comments for the
// functions make_empty() and the output operator "<<". Similarly,
// the definition file extends the text's Figure 3.4 (p.113).
//
// TYPEDEF and MEMBER CONSTANTS for the Bag class:
//   static const size_t CAPACITY = _____;
//     Bag::CAPACITY is the maximum number of items that a Bag
//     can hold.
//
//   typedef _____ Item;
//     Bag::Item is the data type of the items in a Bag. It may
//     be any of the C++ built-in types (int, char, etc.) or a
//     class with a default constructor, an assignment operator,
//     and operators to test for equality (==) and inequality (!=).
//
// CONSTRUCTOR for the Bag class:
//   Bag( )
//     Postcondition: The Bag has been initialized as an empty Bag.
//
// MODIFICATION MEMBER FUNCTIONS for the Bag class:
//   void make_empty ( )
//     Postcondition: The Bag has been re-initialized to be empty.
//
//   void insert ( const Item& entry )
//     Precondition: size() < CAPACITY
//     Postcondition: A new copy of entry has been added to the Bag.
//
//   void remove ( const Item& target )
//     Postcondition: If the Bag contained target, then one copy
//     of target has been removed from the Bag; otherwise, the Bag
//     is unchanged.
//
//   void operator += ( const Bag& addend )
//     Precondition: size() + addend.size() <= CAPACITY.
//     Precondition: Each item in the Bag addend has been included
//     in the invoking Bag.
//
// CONSTANT MEMBER FUNCTIONS for the Bag class:
//   size_t size( ) const
//     Postcondition: The return value is the number of items in the Bag.
//
//   size_t occurrences ( const Item& target ) const
//     Postcondition: The return value is the number of times target
//     is in the Bag.
//
// FRIEND FUNCTION for the Bag class:
//   friend ostream& operator << ( ostream& out_s, const Bag& b )
//     Postcondition: The contents of the Bag b have been written
//     to the output stream out_s.
//
// NONMEMBER FUNCTIONS for the Bag class:
//   Bag operator + ( const Bag& b1, const Bag& b2 )
//     Precondition: b1.size() + b2.size() <= CAPACITY.
//     Postcondition: The Bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the Bag class:
//   Assignment and the copy constructor may be used with Bag objects.

#ifndef BAG1_H
#define BAG1_H
#include <cstdlib>                        // Provides size_t
#include <iostream>                       // Provides istream and ostream

namespace csci301_bag_1
{
	class Bag
	{

	public:

		// TYPEDEF and MEMBER CONSTANT
		static const size_t CAPACITY = 100;   // Maximum size of any Bag
		typedef int Item;                     // What can go in a Bag

											  // CONSTRUCTOR
		Bag() { used = 0; }                  // Inline

											 // MODIFICATION MEMBER FUNCTIONS
		void make_empty() { used = 0; }     // Inline
		void insert(const Item& entry);
		void remove(const Item& target);
		void operator += (const Bag& addend);

		// CONSTANT MEMBER FUNCTIONS
		size_t size() const { return used; } // Inline
		size_t occurrences(const Item& target) const;

		// FRIEND FUNCTION
		friend std::ostream& operator << (std::ostream& out_s, const Bag& b);

	private:

		Item data[CAPACITY];                  // An array of Items
		size_t used;                          // How many hold Bag elements
	};

	// NONMEMBER FUNCTION for this class
	Bag operator + (const Bag& b1, const Bag& b2);
}

#endif

