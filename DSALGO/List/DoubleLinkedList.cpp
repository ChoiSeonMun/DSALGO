#include "DoubleLinkedList.h"

#include <utility>

DoubleLinkedList::DoubleLinkedList(size_t count)
	: DoubleLinkedList()
{
	for (size_t i = 0; i < count; ++i)
	{
		push_front(0);
	}
}

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& other)
{
	for (auto iter = other.begin(); iter != other.end(); ++iter)
	{
		push_back(*iter);
	}
}

DoubleLinkedList& DoubleLinkedList::operator=(const DoubleLinkedList& rhs)
{
	if (this != &rhs)
	{
		DoubleLinkedList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
		std::swap(_size, temp._size);
	}

	return *this;
}

DoubleLinkedList::~DoubleLinkedList()
{
	clear();

	_head = nullptr;

	delete _end;
	_end = nullptr;
}

int& DoubleLinkedList::front()
{
	return *begin();
}

const int& DoubleLinkedList::front() const
{
	return *begin();
}

int& DoubleLinkedList::back()
{
	return *(--end());
}

const int& DoubleLinkedList::back() const
{
	return *(--end());
}

DoubleLinkedList::iterator DoubleLinkedList::begin()
{
	return iterator(_head);
}

DoubleLinkedList::const_iterator DoubleLinkedList::begin() const
{
	return const_iterator(_head);
}

DoubleLinkedList::iterator DoubleLinkedList::end()
{
	return iterator(_end);
}

DoubleLinkedList::const_iterator DoubleLinkedList::end() const
{
	return const_iterator(_end);
}

DoubleLinkedList::iterator DoubleLinkedList::insert(iterator pos, int value)
{
	Node* where = pos._p;
	Node* newNode = new Node(value);
	Node* prevNode = where->Prev;
	
	where->Prev = newNode;
	if (prevNode)
	{
		prevNode->Next = newNode;
	}
	newNode->Prev = prevNode;
	newNode->Next = where;
	
	if (where == _head)
	{
		_head = newNode;
	}

	++_size;

	return newNode;
}

DoubleLinkedList::iterator DoubleLinkedList::erase(iterator pos)
{
	if (empty())
	{
		return end();
	}

	Node* where = pos._p;
	Node* prev = where->Prev;
	Node* next = where->Next;

	if (prev)
	{
		prev->Next = next;
	}
	if (next)
	{
		next->Prev = prev;
	}

	if (where == _head)
	{
		_head = next;
	}

	delete where;

	--_size;

	return next;
}

void DoubleLinkedList::push_front(int value)
{
	insert(begin(), value);
}

void DoubleLinkedList::push_back(int value)
{
	insert(end(), value);
}

void DoubleLinkedList::pop_front()
{
	erase(begin());
}

void DoubleLinkedList::pop_back()
{
	erase(--end());
}

bool DoubleLinkedList::empty() const
{
	if (_size == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

size_t DoubleLinkedList::size() const
{
	return _size;
}

void DoubleLinkedList::clear()
{
	while (false == empty())
	{
		pop_front();
	}
}

bool DoubleLinkedList::contains(int value) const
{
	for (auto iter = begin(); iter != end(); ++iter)
	{
		if (*iter == value)
		{
			return true;
		}
	}

	return false;
}
