#pragma once

#include <cstddef>

class CircularSingleLinkedList
{
public:
	struct Node
	{
		Node(int data = 0, Node* next = nullptr)
			: Data{ data }, Next{ next } { }
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() = default;

		int		Data = 0;
		Node* Next = nullptr;
	};

public:
	class const_iterator
	{
	public:
		const_iterator(Node* p = nullptr)
			: _p{ p } { }
		~const_iterator() { _p = nullptr; }

		const int& operator*() const { return _p->Data; }
		const int* operator->() const { return &_p->Data; }
		const_iterator& operator++()
		{
			_p = _p->Next;

			return *this;
		}
		const_iterator		operator++(int)
		{
			auto temp = *this;
			_p = _p->Next;

			return temp;
		}
		bool				operator==(const const_iterator& rhs) const
		{
			return _p == rhs._p;
		}
		bool				operator!=(const const_iterator& rhs) const
		{
			return !(*this == rhs);
		}
		bool				operator==(nullptr_t p) const
		{
			return _p == nullptr;
		}
		bool				operator!=(nullptr_t p) const
		{
			return !(*this == nullptr);
		}

	public:
		Node* _p = nullptr;
	};

	class iterator : public const_iterator
	{
	public:
		using const_iterator::const_iterator;

		int& operator*() const
		{
			return const_cast<int&>(const_iterator::operator*());
		}
		int* operator->() const
		{
			return const_cast<int*>(const_iterator::operator->());
		}
		iterator& operator++()
		{
			const_iterator::operator++();
			return *this;
		}
		iterator		operator++(int)
		{
			auto temp = *this;
			const_iterator::operator++();

			return temp;
		}
	};

	// 기본 생성자
	CircularSingleLinkedList() = default;

	// 복사 생성자
	CircularSingleLinkedList(const CircularSingleLinkedList& other);

	// 할당 연산자
	CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs);

	// 소멸자
	~CircularSingleLinkedList();

	// 첫 번째 요소를 반환한다.
	int&			front() { return *head(); }
	const int&		front() const { return *head(); }

	// 마지막 요소를 반환한다.
	int&			back() { return *tail(); }
	const int&		back() const { return *tail(); }

	// 시작 전 요소를 가리키는 반복자를 반환한다.
	iterator			before_head() { return _beforeHead; }
	const_iterator		before_head() const { return _beforeHead; }

	// 끝 전 요소를 가리키는 반복자를 반환한다.
	iterator			before_tail() { return _beforeTail; }
	const_iterator		before_tail() const { return _beforeTail; }

	// 시작 요소를 가리키는 반복자를 반환한다.
	iterator			head() { return _beforeHead->Next; }
	const_iterator		head() const { return _beforeHead->Next; }

	// 끝 요소를 가리키는 반복자를 반환한다.
	iterator			tail() { return _beforeTail->Next; }
	const_iterator		tail() const { return _beforeTail->Next; }

	// pos 다음에 value를 삽입한다.
	// 삽입된 요소를 가리키는 반복자를 반환한다.
	iterator			insert_after(iterator pos, int value);

	// pos 다음 요소를 삭제한다.
	// 삭제된 요소를 가리키는 반복자를 반환한다.
	iterator			erase_after(iterator pos);

	// 시작 요소에 value를 삽입한다.
	void			push_front(int value);

	// 마지막 요소에 value를 삽입한다.
	void			push_back(int value);

	// 시작 요소를 제거한다.
	void			pop_front();

	// 마지막 요소를 제거한다.
	void			pop_back();

	// 컨테이너가 비었는지 판단한다.
	bool			empty() const;

	// 컨테이너를 비워버린다.
	void			clear();

	// 컨테이너에 value가 있는지 확인한다.
	bool			contains(int value) const;
private:
	Node*			_beforeHead = new Node();
	Node*			_beforeTail = _beforeHead;
};

