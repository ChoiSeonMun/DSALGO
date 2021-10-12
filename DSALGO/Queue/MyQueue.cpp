#include "MyQueue.h"

MyQueue::MyQueue(const MyQueue& other)
	: _container{ other._container }
{
}

MyQueue& MyQueue::operator=(const MyQueue& rhs)
{
	if (this != &rhs)
	{
		_container = rhs._container;
	}

	return *this;
}

int& MyQueue::front()
{
	return _container.front();
}

const int& MyQueue::front() const
{
	return _container.front();
}

int& MyQueue::back()
{
	return _container.back();
}

const int& MyQueue::back() const
{
	return _container.back();
}

bool MyQueue::empty() const
{
	return _container.empty();
}

size_t MyQueue::size() const
{
	return _container.size();
}

void MyQueue::push(int value)
{
	_container.push_back(value);
}

void MyQueue::pop()
{
	_container.pop_front();
}
