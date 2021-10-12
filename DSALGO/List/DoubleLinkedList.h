#pragma once

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
	Node*			begin();
	const Node*		begin() const;

	// �� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			end();
	const Node*		end() const;

	// pos ������ value�� �����Ѵ�.
	// ���Ե� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	Node*			insert(Node* pos, int value);

	// pos ���� ��Ҹ� �����Ѵ�.
	// ������ ����� ���� ��Ҹ� ����Ű�� �ݺ��ڸ� ��ȯ�Ѵ�.
	// �ƹ� ��ҵ� ������ end()�� ��ȯ�Ѵ�.
	Node*			erase(Node* pos);

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