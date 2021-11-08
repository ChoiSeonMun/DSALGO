#include <iostream>

#include "CircularSingleLinkedList.h"

using namespace std;

int main()
{
	CircularSingleLinkedList list;

	list.push_back(3);
	list.push_front(1);
	list.push_front(2);
	list.push_back(4);

	auto iter = list.head();
	do
	{
		cout << *iter << "->";

		++iter;
	} while (iter != list.head());
	cout << *iter << endl;

	CircularSingleLinkedList list2(list);

	if (list2.contains(4))
	{
		cout << "있음\n";
	}

	auto iter2 = list2.head();
	iter2 = list2.insert_after(iter2, 10);
	++iter2;
	list2.erase_after(iter2);

	iter2 = list2.head();
	do
	{
		cout << *iter2 << "->";

		++iter2;
	} while (iter2 != list2.head());
	cout << *iter2 << endl;
}