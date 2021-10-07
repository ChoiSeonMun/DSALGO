﻿#include <iostream>
#include <forward_list>

#include "SingleLinkedList.h"

using namespace std;

int main()
{
	forward_list<int> list;
	forward_list<int> list2(5);

	list.push_front(1);
	list.push_front(2);
	list.push_front(3);
	list.pop_front();

	cout << list.front() << endl;

	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl;

	auto iter = list2.insert_after(list2.begin(), 3);
	++iter;
	iter = list2.insert_after(iter, 4);
	list2.erase_after(iter);

	for (int elem : list2)
	{
		cout << elem << ' ';
	}
	cout << endl;

	cout << boolalpha << list2.empty() << endl;

	forward_list<int> list3(list);

	for (int elem : list)
	{
		cout << elem << ' ';
	}
	cout << endl;

	SingleLinkedList mlist;
	SingleLinkedList mlist2(5);

	mlist.push_front(1);
	mlist.push_front(2);
	mlist.push_front(3);
	mlist.pop_front();

	cout << mlist.front() << endl;

	for (auto iter = mlist.begin(); iter != mlist.end(); iter = iter->Next)
	{
		cout << iter->Data << ' ';
	}
	cout << endl;

	auto iter2 = mlist2.insert_after(mlist2.begin(), 3);
	iter2 = iter2->Next;
	iter2 = mlist2.insert_after(iter2, 4);
	mlist2.erase_after(iter2);

	for (auto iter = mlist2.begin(); iter != mlist2.end(); iter = iter->Next)
	{
		cout << iter->Data << ' ';
	}
	cout << endl;

	cout << boolalpha << mlist2.empty() << endl;

	SingleLinkedList mlist3(mlist);

	for (auto iter = mlist3.begin(); iter != mlist3.end(); iter = iter->Next)
	{
		cout << iter->Data << ' ';
	}
	cout << endl;
}