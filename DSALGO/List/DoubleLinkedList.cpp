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
	for (const Node* iter = other.begin(); iter != other.end(); iter = iter->Next)
	{
		push_back(iter->Data);
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
	return begin()->Data;
}

const int& DoubleLinkedList::front() const
{
	return begin()->Data;
}

int& DoubleLinkedList::back()
{
	return end()->Prev->Data;
}

const int& DoubleLinkedList::back() const
{
	return end()->Prev->Data;
}

DoubleLinkedList::Node* DoubleLinkedList::begin()
{
	return _head;
}

const DoubleLinkedList::Node* DoubleLinkedList::begin() const
{
	return _head;
}

DoubleLinkedList::Node* DoubleLinkedList::end()
{
	return _end;
}

const DoubleLinkedList::Node* DoubleLinkedList::end() const
{
	return _end;
}

DoubleLinkedList::Node* DoubleLinkedList::insert(Node* pos, int value)
{
	Node* newNode = new Node(value);
	Node* prevNode = pos->Prev;
	
	prevNode->Next = newNode;
	newNode->Prev = prevNode;
	newNode->Next = pos;
	
	++_size;

	return newNode;
}

DoubleLinkedList::Node* DoubleLinkedList::erase(Node* pos)
{
	Node* prev = pos->Prev;
	Node* next = pos->Next;

	prev->Next = next;
	next->Prev = prev;

	delete pos;
	pos = nullptr;

	--_size;

	return next;
}

void DoubleLinkedList::push_front(int value)
{
	insert(begin()->Next, value);
}

void DoubleLinkedList::push_back(int value)
{
	insert(end()->Prev, value);
}

void DoubleLinkedList::pop_front()
{
	erase(begin());
}

void DoubleLinkedList::pop_back()
{
	erase(end()->Prev);
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
	for (const Node* iter = begin(); iter != end(); iter = iter->Next)
	{
		if (iter->Data == value)
		{
			return true;
		}
	}

	return false;
}
