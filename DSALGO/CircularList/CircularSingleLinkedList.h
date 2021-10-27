#pragma once

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
	// �⺻ ������
	CircularSingleLinkedList() = default;

	// ���� ������
	CircularSingleLinkedList(const CircularSingleLinkedList& other);

	// �Ҵ� ������
	CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs);

	// �Ҹ���
	~CircularSingleLinkedList();

	// ù ��° ��Ҹ� ��ȯ�Ѵ�.
	int&			front() { return head()->Data; }
	const int&		front() const { return head()->Data; }

	// ������ ��Ҹ� ��ȯ�Ѵ�.
	int&			back() { return tail()->Data; }
	const int&		back() const { return tail()->Data; }

	// ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			before_head() { return _beforeHead; }
	const Node*		before_head() const { return _beforeHead; }

	// �� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			before_tail() { return _beforeTail; }
	const Node*		before_tail() const { return _beforeTail; }

	// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			head() { return _beforeHead->Next; }
	const Node*		head() const { return _beforeHead->Next; }

	// �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			tail() { return _beforeTail->Next; }
	const Node*		tail() const { return _beforeTail->Next; }

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			insert_after(Node* pos, int value);

	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			erase_after(Node* pos);

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

