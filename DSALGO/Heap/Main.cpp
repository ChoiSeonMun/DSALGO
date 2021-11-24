#include <iostream>
#include <queue>
#include "Heap.h"

int main()
{
	const auto data = { 8, 3, 2, 5, 4, 10, 14, 11, 16 };
	priority_queue<int> q;
	for (int d : data)
	{
		q.push(d);
	}

	while (false == q.empty())
	{
		int d = q.top();
		q.pop();

		cout << d << ' ';
	}
	
	puts("\n---------------------------------");

	Heap h;
	for (int d : data)
	{
		h.push(d);
	}

	while (false == h.empty())
	{
		int d = h.top();
		h.pop();

		cout << d << ' ';
	}
}