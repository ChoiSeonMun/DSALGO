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
	// 기본 생성자
	CircularSingleLinkedList() = default;

	// 복사 생성자
	CircularSingleLinkedList(const CircularSingleLinkedList& other);

	// 할당 연산자
	CircularSingleLinkedList& operator=(const CircularSingleLinkedList& rhs);

	// 소멸자
	~CircularSingleLinkedList();

	// 첫 번째 요소를 반환한다.
	int&			front() { return head()->Data; }
	const int&		front() const { return head()->Data; }

	// 마지막 요소를 반환한다.
	int&			back() { return tail()->Data; }
	const int&		back() const { return tail()->Data; }

	// 시작 전 요소를 가리키는 반복자를 반환한다.
	Node*			before_head() { return _beforeHead; }
	const Node*		before_head() const { return _beforeHead; }

	// 끝 전 요소를 가리키는 반복자를 반환한다.
	Node*			before_tail() { return _beforeTail; }
	const Node*		before_tail() const { return _beforeTail; }

	// 시작 요소를 가리키는 반복자를 반환한다.
	Node*			head() { return _beforeHead->Next; }
	const Node*		head() const { return _beforeHead->Next; }

	// 끝 요소를 가리키는 반복자를 반환한다.
	Node*			tail() { return _beforeTail->Next; }
	const Node*		tail() const { return _beforeTail->Next; }

	// pos 다음에 value를 삽입한다.
	// 삽입된 요소를 가리키는 반복자를 반환한다.
	Node*			insert_after(Node* pos, int value);

	// pos 다음 요소를 삭제한다.
	// 삭제된 요소의 다음 요소를 가리키는 반복자를 반환한다.
	Node*			erase_after(Node* pos);

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

