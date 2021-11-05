#pragma once

#include <algorithm>

class DoubleLinkedList
{
public:
	struct Node
	{
		Node(int data = 0, Node* prev = nullptr, Node* next = nullptr)
			: Data{ data }, Next{ next }, Prev{ prev } { }
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() = default;

		int		Data = 0;
		Node*	Next = nullptr;
		Node*	Prev = nullptr;
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
		const_iterator& operator++() { _p = _p->Next; return *this; }
		const_iterator		operator++(int)
		{
			auto temp = *this;
			_p = _p->Next;

			return temp;
		}
		const_iterator& operator--() { _p = _p->Prev; return *this; }
		const_iterator		operator--(int)
		{
			auto temp = *this;
			_p = _p->Prev;

			return temp;
		}
		bool				operator==(const const_iterator& rhs) const { return _p == rhs._p; }
		bool				operator!=(const const_iterator& rhs) const { return !(*this == rhs); }
		bool				operator==(nullptr_t p) const { return _p == nullptr; }
		bool				operator!=(nullptr_t p) const { return !(*this == nullptr); }

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
		iterator& operator--()
		{
			const_iterator::operator--();

			return *this;
		}

		iterator		operator--(int)
		{
			auto temp = *this;
			const_iterator::operator--();

			return temp;
		}
	};
	// 기본 생성자
	DoubleLinkedList() = default;

	// count만큼의 요소를 갖고 있는 컨테이너를 만드는 생성자
	explicit DoubleLinkedList(size_t count);

	// 복사 생성자.
	DoubleLinkedList(const DoubleLinkedList& other);

	// 할당 연산자
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs);

	// 소멸자
	~DoubleLinkedList();

	// 첫 번째 요소를 반환한다.
	int&			front();
	const int&		front() const;

	// 마지막 요소를 반환한다.
	int&			back();
	const int&		back() const;

	// 시작 요소를 가리키는 반복자를 반환한다.
	// 리스트가 비어있다면 end()와 같다.
	iterator			begin();
	const_iterator		begin() const;

	// 끝 다음 요소를 가리키는 반복자를 반환한다.
	iterator			end();
	const_iterator		end() const;

	// pos 다음에 value를 삽입한다.
	// 삽입된 요소를 가리키는 반복자를 반환한다.
	iterator			insert(iterator pos, int value);

	// pos 다음 요소를 삭제한다.
	// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
	// 아무 요소도 없으면 end()를 반환한다.
	iterator			erase(iterator pos);

	// 시작에 value를 삽입한다.
	void			push_front(int value);

	// 끝에 value를 삽입한다.
	void			push_back(int value);

	// 시작 요소를 제거한다.
	void			pop_front();

	// 끝 요소를 제거한다.
	void			pop_back();

	// 컨테이너가 비었는지 판단한다.
	bool			empty() const;
	
	// 리스트 안에 있는 요소의 개수를 반환한다.
	size_t			size() const;

	// 컨테이너를 비워버린다.
	void			clear();

	// 해당 value가 있는지 체크한다.
	bool			contains(int value) const;
private:
	Node*			_end = new Node();
	Node*			_head = _end;
	size_t			_size = 0;
};