#include <iostream>
#include <list>

#include "DoubleLinkedList.h"

using namespace std;

int main()
{
	list<int> lst;

	lst.push_front(1);
	lst.push_front(3);
	lst.push_back(2);

	for (int elem : lst)
	{
		cout << elem << ' ';
	}
	cout << endl;

	lst.pop_back();
	
	cout << lst.front() << endl;
	cout << lst.back() << endl;

	list<int> list2(5);
	auto iter = list2.insert(list2.begin(), 3);
	++iter;
	iter = list2.insert(iter, 4);
	list2.erase(iter);

	for (int elem : list2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << list2.empty() << endl;

	list<int> list3(lst);
	for (int elem : list3)
	{
		cout << elem << ' ';
	}
	cout << endl;

	DoubleLinkedList myList;

	myList.push_front(1);
	myList.push_front(3);
	myList.push_back(2);

	for (auto iter = myList.begin(); iter != myList.end(); iter = iter->Next)
	{
		cout << iter->Data << endl;
	}
}