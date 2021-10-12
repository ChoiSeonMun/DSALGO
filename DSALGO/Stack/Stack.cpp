#include <iostream>
#include <stack>

#include "MyStack.h"

int main()
{
	std::stack<int> st;

	st.push(3);
	st.push(2);
	st.push(1);

	std::cout << "Size : " << st.size() << std::endl;

	std::stack<int> st2(st);
	std::stack<int> st3 = st;

	while (false == st.empty())
	{
		std::cout << st.top() << ' ';

		st.pop();
	}
	std::cout << std::endl;

	while (false == st2.empty())
	{
		std::cout << st2.top() << ' ';

		st2.pop();
	}
	std::cout << std::endl;

	while (false == st3.empty())
	{
		std::cout << st3.top() << ' ';

		st3.pop();
	}
	std::cout << std::endl;

	MyStack myst1;

	myst1.push(4);
	myst1.push(5);
	myst1.push(6);

	std::cout << "Size : " << myst1.size() << std::endl;

	MyStack myst2(myst1);
	MyStack myst3 = myst1;

	while (false == myst1.empty())
	{
		std::cout << myst1.top() << ' ';

		myst1.pop();
	}
	std::cout << std::endl;

	while (false == myst2.empty())
	{
		std::cout << myst2.top() << ' ';

		myst2.pop();
	}
	std::cout << std::endl;

	while (false == myst3.empty())
	{
		std::cout << myst3.top() << ' ';

		myst3.pop();
	}
	std::cout << std::endl;
}