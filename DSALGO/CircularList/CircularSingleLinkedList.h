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

	// �⺻ ������
	CircularSingleLinkedList() = default;

	// ���� ������
	CircularSingleLinkedList(const CircularSingleLinkedList& other);

	// �Ҵ� ������
	CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs);

	// �Ҹ���
	~CircularSingleLinkedList();

	// ù ��° ��Ҹ� ��ȯ�Ѵ�.
	int&			front() { return *head(); }
	const int&		front() const { return *head(); }

	// ������ ��Ҹ� ��ȯ�Ѵ�.
	int&			back() { return *tail(); }
	const int&		back() const { return *tail(); }

	// ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			before_head() { return _beforeHead; }
	const_iterator		before_head() const { return _beforeHead; }

	// �� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			before_tail() { return _beforeTail; }
	const_iterator		before_tail() const { return _beforeTail; }

	// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			head() { return _beforeHead->Next; }
	const_iterator		head() const { return _beforeHead->Next; }

	// �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			tail() { return _beforeTail->Next; }
	const_iterator		tail() const { return _beforeTail->Next; }

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			insert_after(iterator pos, int value);

	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			erase_after(iterator pos);

	// ���� ��ҿ� value�� �����Ѵ�.
	void			push_front(int value);

	// ������ ��ҿ� value�� �����Ѵ�.
	void			push_back(int value);

	// ���� ��Ҹ� �����Ѵ�.
	void			pop_front();

	// ������ ��Ҹ� �����Ѵ�.
	void			pop_back();

	// �����̳ʰ� ������� �Ǵ��Ѵ�.
	bool			empty() const;

	// �����̳ʸ� ���������.
	void			clear();

	// �����̳ʿ� value�� �ִ��� Ȯ���Ѵ�.
	bool			contains(int value) const;
private:
	Node*			_beforeHead = new Node();
	Node*			_beforeTail = _beforeHead;
};

