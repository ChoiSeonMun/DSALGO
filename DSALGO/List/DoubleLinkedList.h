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
	// �⺻ ������
	DoubleLinkedList() = default;

	// count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
	explicit DoubleLinkedList(size_t count);

	// ���� ������.
	DoubleLinkedList(const DoubleLinkedList& other);

	// �Ҵ� ������
	DoubleLinkedList& operator=(const DoubleLinkedList& rhs);

	// �Ҹ���
	~DoubleLinkedList();

	// ù ��° ��Ҹ� ��ȯ�Ѵ�.
	int&			front();
	const int&		front() const;

	// ������ ��Ҹ� ��ȯ�Ѵ�.
	int&			back();
	const int&		back() const;

	// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// ����Ʈ�� ����ִٸ� end()�� ����.
	iterator			begin();
	const_iterator		begin() const;

	// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			end();
	const_iterator		end() const;

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	iterator			insert(iterator pos, int value);

	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
	iterator			erase(iterator pos);

	// ���ۿ� value�� �����Ѵ�.
	void			push_front(int value);

	// ���� value�� �����Ѵ�.
	void			push_back(int value);

	// ���� ��Ҹ� �����Ѵ�.
	void			pop_front();

	// �� ��Ҹ� �����Ѵ�.
	void			pop_back();

	// �����̳ʰ� ������� �Ǵ��Ѵ�.
	bool			empty() const;
	
	// ����Ʈ �ȿ� �ִ� ����� ������ ��ȯ�Ѵ�.
	size_t			size() const;

	// �����̳ʸ� ���������.
	void			clear();

	// �ش� value�� �ִ��� üũ�Ѵ�.
	bool			contains(int value) const;
private:
	Node*			_end = new Node();
	Node*			_head = _end;
	size_t			_size = 0;
};