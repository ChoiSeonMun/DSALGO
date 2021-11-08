#include "CircularSingleLinkedList.h"

#include <utility>

CircularSingleLinkedList::CircularSingleLinkedList(const CircularSingleLinkedList& other)
    : CircularSingleLinkedList()
{
    auto iter = other.head();
    do
    {
        push_back(*iter);
        
        ++iter;
    } while (iter != other.head());
}

CircularSingleLinkedList& CircularSingleLinkedList::operator=(const CircularSingleLinkedList& rhs)
{
    if (this != &rhs)
    {
        CircularSingleLinkedList temp(rhs);
        std::swap(_beforeHead, temp._beforeHead);
        std::swap(_beforeTail, temp._beforeTail);
    }

    return *this;
}

CircularSingleLinkedList::~CircularSingleLinkedList()
{
    clear();

    delete _beforeHead;
    _beforeHead = nullptr;
    _beforeTail = nullptr;
}

CircularSingleLinkedList::iterator CircularSingleLinkedList::insert_after(iterator pos, int value)
{
    Node* where = pos._p;
    Node* newNode = new Node(value);
    newNode->Next = where->Next;
    where->Next = newNode;

    Node* h = _beforeHead->Next;
    Node* t = _beforeTail->Next;

    // 첫 번째 원소가 삽입될 때
    if (h->Next == nullptr)
    {
        h->Next = h;
    }
    // 하나의 원소가 삽입된 상태에서 첫 부분에 삽입될 때
    else if (before_head() == before_tail())
    {
        _beforeTail = h;
        _beforeTail->Next->Next = h;
    }
    // 첫 부분에 삽입될 때
    else if (where->Next == h)
    {
        t->Next = h;
    }
    // 끝에 삽입될 때
    else if (pos == before_tail() || pos == tail())
    {
        _beforeTail = _beforeTail->Next;
    }

    return newNode;
}

CircularSingleLinkedList::iterator CircularSingleLinkedList::erase_after(iterator pos)
{
    if (empty())
    {
        return tail();
    }

    Node* where = pos._p;
    Node* removed = where->Next;

    // 1. 원소가 하나일 때
    if (before_head() == before_tail())
    {
        _beforeHead->Next = nullptr;
    }
    // 2. 원소가 2개일 때
    else if (head() == before_tail())
    {
        _beforeHead->Next = removed->Next;

        _beforeTail = _beforeHead;
    }
    else if (pos == before_head() || pos == tail())
    {
        _beforeHead->Next = removed->Next;

        Node* h = _beforeHead->Next;
        Node* t = _beforeTail->Next;
        t->Next = h;
    }
    else if (pos == before_tail())
    {
        _beforeTail->Next = removed->Next;

        Node* h = _beforeHead->Next;
        Node* t = _beforeTail->Next;
        while (t->Next != h)
        {
            _beforeTail = _beforeTail->Next;
        }
    }
    else
    {
        where->Next = removed->Next;
    }
    
    removed->Next = nullptr;

    return removed;
}

void CircularSingleLinkedList::push_front(int value)
{
    insert_after(before_head(), value);
}

void CircularSingleLinkedList::push_back(int value)
{
    if (empty())
    {
        push_front(value);
    }
    else
    {
        insert_after(tail(), value);
    }
}

void CircularSingleLinkedList::pop_front()
{
    auto erased = erase_after(before_head());
    delete erased._p;
}

void CircularSingleLinkedList::pop_back()
{
    auto erased = erase_after(before_tail());
    delete erased._p;
}

bool CircularSingleLinkedList::empty() const
{
    if (head() == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void CircularSingleLinkedList::clear()
{
    while (false == empty())
    {
        pop_front();
    }
}

bool CircularSingleLinkedList::contains(int value) const
{
    auto iter = head();
    do
    {
        if (*iter == value)
        {
            return true;
        }

        ++iter;
    } while (iter != head());

    return false;
}
