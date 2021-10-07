#pragma once

class iterator;
class const_iterator;

class SingleLinkedList
{
public:
	struct Node
	{
		Node(int data = 0, Node* next = nullptr);
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node();

		int		Data = 0;
		Node*	Next = nullptr;
	};

public:
	// �⺻ ������
	SingleLinkedList();

	// count��ŭ�� ��Ҹ� ���� �ִ� �����̳ʸ� ����� ������
	explicit SingleLinkedList(size_t count);

	// ���� ������.
	SingleLinkedList(const SingleLinkedList& other);

	// �Ҵ� ������
	SingleLinkedList& operator=(const SingleLinkedList& rhs);
	
	// �Ҹ���
	~SingleLinkedList();

	// ù ��° ��Ҹ� ��ȯ�Ѵ�.
	int&			front();
	const int&		front() const;

	// ���� �� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			before_begin();
	const Node*		before_begin() const;
	
	// ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			begin();
	const Node*		begin() const;
	
	// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			end();
	const Node*		end() const;

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			insert_after(Node* pos, int value);
	
	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
	Node*			erase_after(Node* pos);

	// ���� ��ҿ� value�� �����Ѵ�.
	void			push_front(int value);
	
	// ���� ��Ҹ� �����Ѵ�.
	void			pop_front();

	// �����̳ʰ� ������� �Ǵ��Ѵ�.
	bool			empty() const;

	// �����̳ʸ� ���������.
	void			clear();
	
	bool			contains(int value) const;
private:
	Node*			_head = new Node();
	Node*			_end = new Node();
};