#include "Listclass.h"  // header file
#include <iostream>
#include <fstream>

List::List() : size(0)
{
}
bool List::isEmpty() const
{
	return size == 0;
}
int List::getLength() const
{
	return size;
}
void List::insert(int index, const ListItemType& newItem,
	bool& success)
{
	success = (index >= 1) &&
		(index <= size + 1) &&
		(size < MAX_LIST);
	if (success)
	{
		for (int pos = size; pos >= index; --pos)
			items[translate(pos + 1)] = items[translate(pos)];
		items[translate(index)] = newItem;
		++size;  // increase the size of the list by one
	}
}

void List::remove(int index, bool& success)
{
	success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int fromPosition = index + 1;
			fromPosition <= size;
			++fromPosition)
			items[translate(fromPosition - 1)] = items[translate(fromPosition)];
		--size;  // decrease the size of the list by one
	}  // end if

}  // end remove

void List::retrieve(int index, ListItemType& dataItem,
	bool& success) const
{
	success = (index >= 1) && (index <= size);
	if (success)
		dataItem = items[translate(index)];
}

int List::translate(int index) const
{
	return index - 1;
	#include "ArrayList.h"  // header file
#include <iostream>
#include <fstream>

List::List() : size(0)
{
}
bool List::isEmpty() const
{
	return size == 0;
}
int List::getLength() const
{
	return size;
}
void List::insert(int index, const ListItemType& newItem,
	bool& success)
{
	success = (index >= 1) &&
		(index <= size + 1) &&
		(size < MAX_LIST);
	if (success)
	{
		for (int pos = size; pos >= index; --pos)
			items[translate(pos + 1)] = items[translate(pos)];
		items[translate(index)] = newItem;
		++size;  // increase the size of the list by one
	}
}

void List::remove(int index, bool& success)
{
	success = (index >= 1) && (index <= size);
	if (success)
	{
		for (int fromPosition = index + 1;
			fromPosition <= size;
			++fromPosition)
			items[translate(fromPosition - 1)] = items[translate(fromPosition)];
		--size;  // decrease the size of the list by one
	}  // end if

}  // end remove

void List::retrieve(int index, ListItemType& dataItem,
	bool& success) const
{
	success = (index >= 1) && (index <= size);
	if (success)
		dataItem = items[translate(index)];
}

int List::translate(int index) const
{
	return index - 1;
}




