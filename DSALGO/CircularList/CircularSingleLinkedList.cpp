#include "CircularSingleLinkedList.h"

#include <utility>

CircularSingleLinkedList::CircularSingleLinkedList(const CircularSingleLinkedList& other)
    : CircularSingleLinkedList()
{
    if (other.empty())
    {
        return;
    }

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

    Node*& h = _beforeHead->Next;
    Node*& t = _beforeTail->Next;

    // ù ��° ���Ұ� ���Ե� ��
    if (h->Next == nullptr)
    {
        h->Next = h;
    }
    // �� ��° ���Ұ� ���Ե� ��
    else if (before_head() == before_tail())
    {
        _beforeTail = h;
        t->Next = h;
    }
    // before_tail / tail�� ������ ��
    else if (pos == before_tail() || pos == tail())
    {
        _beforeTail = _beforeTail->Next;
    }
    // before_head�� ������ ��
    else if (pos == before_head())
    {
        t->Next = h;
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

    // ���Ұ� �ϳ��� ��
    if (_beforeHead->Next->Next == _beforeHead->Next)
    {
        _beforeHead->Next = nullptr;
    }
    // ���Ұ� �� ���� ��
    else if (before_head() == before_tail())
    {
        _beforeHead->Next = removed->Next;

        _beforeTail = _beforeHead;

        _beforeTail->Next->Next = _beforeHead->Next;
    }
    // tail�� �����Ϸ��� �� ��
    else if (pos == before_tail())
    {
        _beforeTail->Next->Next = removed->Next;

        while (_beforeTail->Next->Next != _beforeHead->Next)
        {
            _beforeTail = _beforeTail->Next;
        }
    }
    // before_tail�� ���ŵ� ��
    else if (removed == _beforeTail)
    {
        where->Next = removed->Next;

        _beforeTail = where;
    }
    // ù �κ��� ���ŵ� ��
    else if (removed == _beforeHead->Next)
    {
        _beforeHead->Next->Next = removed->Next;

        _beforeTail->Next->Next = _beforeHead->Next;
    }
    // �߰� ���Ұ� ���ŵ� ��
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
