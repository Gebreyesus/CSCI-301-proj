// CSCI 301
// Computer Science 2

// FILE: bag1a.cxx
//
// Note: This file is the same as the text's Figure 3.6 (pp.114-115),
// with the addition of a function that overloads the inserter operator
// "<<" to write out a Bag. This file also notes any functions implemented
// in the definition section as inline functions.
//
// CLASS IMPLEMENTED: Bag (See bag1a.h for documentation.)
//
// INVARIANT for the Bag implementation:
//   1. The member variable used holds the number of items in the Bag.
//   2. For an empty Bag, we do not care what is stored in any positions
//      of the array data[]. The Items in a non-empty Bag are stored in
//      positions data[0] through data[used-1], and we do not care about
//      the contents of the remaining positions.

#include <cassert>         // Provides assert()
#include <cstdlib>         // Provides size_t
#include <iostream>
#include <iomanip>         // Provides setw()
#include <fstream>
#include "Header1.h"
using namespace std;


	// The default constructor is an inline function.

	void Bag::insert(const Item& entry)
		// Uses cassert.
	{
		assert(size() < CAPACITY);

		data[used] = entry;
		++used;
	}

	// make_empty() is an inline function.

	void Bag::remove(const Item& target)
		// Uses cstdlib.
	{
		size_t index;       // Where target first appears in data[]

		for (index = 0; (index < used) && (data[index] != target); index++)
			// Empty loop body
			;

		if (index == used)   // target is not in the bag, so return.
			return;

		// Remove target from the bag.
		used--;
		data[index] = data[used];
	}

	void Bag::operator += (const Bag& addend)
		// Uses cassert and cstdlib.
	{
		size_t i, addend_size;

		assert(size() + addend.size() <= CAPACITY);

		addend_size = addend.size();
		for (i = 0; i<addend_size; ++i)
		{
			data[used] = addend.data[i];
			++used;
		}
	}

	// size() is an inline function.

	size_t Bag::occurrences(const Item& target) const
		// Uses cstdlib.
	{
		size_t answer, i;

		answer = 0;
		for (i = 0; i<used; ++i)
			if (data[i] == target)
				++answer;
		return answer;
	}

	ostream& operator << (ostream& out_s, const Bag& b)
		// Uses iomanip.
	{
		out_s << "{ ";
		if (b.used > 1)
			for (int i = 0; i<b.used - 1; ++i)
				out_s << setw(1) << b.data[i] << ", ";
		if (b.used > 0)
			out_s << setw(1) << b.data[b.used - 1] << ' ';
		out_s << "}";

		return out_s;
	}

	Bag operator + (const Bag& b1, const Bag& b2)
		// Uses cassert.
	{
		Bag answer;

		assert(b1.size() + b2.size() <= Bag::CAPACITY);

		answer += b1;
		answer += b2;
		return answer;
	}


