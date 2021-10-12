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
		cout << iter->Data << ' ';
	}
	cout << endl;

	myList.pop_back();

	cout << myList.front() << endl;
	cout << myList.back() << endl;

	DoubleLinkedList myList2(5);
	auto iter2 = myList2.insert(myList2.begin(), 3);
	iter2 = iter2->Next;
	iter2 = myList2.insert(iter2, 4);
	myList2.erase(iter2);

	for (auto iter = myList2.begin(); iter != myList2.end(); iter = iter->Next)
	{
		cout << iter->Data << ' ';
	}
	cout << endl;

	cout << boolalpha << myList2.empty() << endl;

	DoubleLinkedList myList3(myList);
	for (auto iter = myList3.begin(); iter != myList3.end(); iter = iter->Next)
	{
		cout << iter->Data << ' ';
	}
	cout << endl;
}