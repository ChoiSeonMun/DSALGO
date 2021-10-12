#include "MyStack.h"

MyStack::MyStack(const MyStack& other)
	: _container{ other._container }
{
}

MyStack& MyStack::operator=(const MyStack& rhs)
{
	if (this != &rhs)
	{
		_container = rhs._container;
	}

	return *this;
}

int& MyStack::top()
{
	return _container.back();
}

const int& MyStack::top() const
{
	return _container.back();
}

bool MyStack::empty() const
{
	return _container.empty();
}

size_t MyStack::size() const
{
	return _container.size();
}

void MyStack::push(int value)
{
	_container.push_back(value);
}

void MyStack::pop()
{
	_container.pop_back();
}
