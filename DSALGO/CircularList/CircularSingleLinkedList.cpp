#include "CircularSingleLinkedList.h"

#include <utility>

CircularSingleLinkedList::CircularSingleLinkedList(const CircularSingleLinkedList& other)
    : CircularSingleLinkedList()
{
    auto iter = other.head();
    do
    {
        push_back(iter->Data);
        
        iter = iter->Next;
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

CircularSingleLinkedList::Node* CircularSingleLinkedList::insert_after(Node* pos, int value)
{
    Node* newNode = new Node(value);
    newNode->Next = pos->Next;
    pos->Next = newNode;

    // 첫 번째 원소가 삽입될 때
    if (head()->Next == nullptr)
    {
        head()->Next = head();
    }
    // 하나의 원소가 삽입된 상태에서 첫 부분에 삽입될 때
    else if (before_head() == before_tail())
    {
        _beforeTail = head();
        tail()->Next = head();
    }
    // 첫 부분에 삽입될 때
    else if (pos->Next == head())
    {
        tail()->Next = head();
    }
    // 끝에 삽입될 때
    else if (pos == before_tail() || pos == tail())
    {
        _beforeTail = _beforeTail->Next;
    }

    return newNode;
}

CircularSingleLinkedList::Node* CircularSingleLinkedList::erase_after(Node* pos)
{
    if (empty())
    {
        return tail();
    }

    Node* removed = pos->Next;

    // 1. 원소가 하나일 때
    if (before_head() == before_tail())
    {
        before_head()->Next = nullptr;
    }
    // 2. 원소가 2개일 때
    else if (head() == before_tail())
    {
        before_head()->Next = removed->Next;

        _beforeTail = _beforeHead;
    }
    else if (pos == before_head() || pos == tail())
    {
        before_head()->Next = removed->Next;

        tail()->Next = head();
    }
    else if (pos == before_tail())
    {
        before_tail()->Next = removed->Next;

        while (tail()->Next != head())
        {
            _beforeTail = _beforeTail->Next;
        }
    }
    else
    {
        pos->Next = removed->Next;
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
    Node* erased = erase_after(before_head());
    delete erased;
    erased = nullptr;
}

void CircularSingleLinkedList::pop_back()
{
    Node* erased = erase_after(before_tail());
    delete erased;
    erased = nullptr;
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
    const Node* iter = head();
    do
    {
        if (iter->Data == value)
        {
            return true;
        }

        iter = iter->Next;
    } while (iter != head());

    return false;
}
