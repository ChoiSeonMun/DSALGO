#include <iostream>
#include <queue>

#include "MyQueue.h"

int main()
{
	std::queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);

	std::queue<int> q2(q);
	std::queue<int> q3 = q;

	while (false == q.empty())
	{
		std::cout << q.front() << ' ';

		q.pop();
	}
	std::cout << std::endl;

	while (false == q2.empty())
	{
		std::cout << q2.front() << ' ';

		q2.pop();
	}
	std::cout << std::endl;

	while (false == q3.empty())
	{
		std::cout << q3.front() << ' ';

		q3.pop();
	}
	std::cout << std::endl;

	MyQueue mq;

	mq.push(4);
	mq.push(5);
	mq.push(6);

	MyQueue mq2(mq);
	MyQueue mq3 = mq;

	while (false == mq.empty())
	{
		std::cout << mq.front() << ' ';

		mq.pop();
	}
	std::cout << std::endl;

	while (false == mq2.empty())
	{
		std::cout << mq2.front() << ' ';

		mq2.pop();
	}
	std::cout << std::endl;

	while (false == mq3.empty())
	{
		std::cout << mq3.front() << ' ';

		mq3.pop();
	}
	std::cout << std::endl;
}