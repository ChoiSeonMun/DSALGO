#include "SingleLinkedList.h"

#include <utility>

SingleLinkedList::SingleLinkedList()
{
	_head->Next = _end;
}

SingleLinkedList::SingleLinkedList(size_t count)
	: SingleLinkedList()
{
	for (size_t i = 0; i < count; ++i)
	{
		insert_after(before_begin(), 0);
	}
}

SingleLinkedList::SingleLinkedList(const SingleLinkedList& other)
	: SingleLinkedList()
{
	Node* inserted = before_begin();
	for (const Node* iter = other.begin(); iter != other.end(); iter = iter->Next)
	{
		inserted = insert_after(inserted, iter->Data);
	}
}

SingleLinkedList& SingleLinkedList::operator=(const SingleLinkedList& rhs)
{
	if (this != &rhs)
	{
		SingleLinkedList temp(rhs);
		std::swap(_head, temp._head);
		std::swap(_end, temp._end);
	}

	return *this;
}

SingleLinkedList::~SingleLinkedList()
{
	clear();
	
	delete _head;
	_head = nullptr;
	
	delete _end;
	_end = nullptr;
}

int& SingleLinkedList::front()
{
	return begin()->Data;
}

const int& SingleLinkedList::front() const
{
	return begin()->Data;
}

SingleLinkedList::Node* SingleLinkedList::before_begin()
{
	return _head;
}

const SingleLinkedList::Node* SingleLinkedList::before_begin() const
{
	return _head;
}

SingleLinkedList::Node* SingleLinkedList::begin()
{
	return _head->Next;
}

const SingleLinkedList::Node* SingleLinkedList::begin() const
{
	return _head->Next;
}

SingleLinkedList::Node* SingleLinkedList::end()
{
	return _end;
}

const SingleLinkedList::Node* SingleLinkedList::end() const
{
	return _end;
}

SingleLinkedList::Node* SingleLinkedList::insert_after(Node* pos, int value)
{
	Node* newNode = new Node(value);
	newNode->Next = pos->Next;
	pos->Next = newNode;

	return newNode;
}

SingleLinkedList::Node* SingleLinkedList::erase_after(Node* pos)
{
	Node* removed = pos->Next;
	
	if (removed == nullptr)
	{
		return end();
	}

	pos->Next = removed->Next;

	return removed;
}

void SingleLinkedList::push_front(int value)
{
	insert_after(before_begin(), value);
}

void SingleLinkedList::pop_front()
{
	Node* removed = erase_after(before_begin());
	delete removed;
}

bool SingleLinkedList::empty() const
{
	if (_head->Next == _end)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SingleLinkedList::clear()
{
	while (false == empty())
	{
		erase_after(before_begin());
	}
}

bool SingleLinkedList::contains(int value) const
{
	return false;
}

SingleLinkedList::Node::Node(int data, Node* next)
	: Data{ data }, Next{ next }
{
}

SingleLinkedList::Node::~Node()
{
	Next = nullptr;
}
