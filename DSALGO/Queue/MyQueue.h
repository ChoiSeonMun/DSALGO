#pragma once

#include "DoubleLinkedList.h"

class MyQueue
{
public:
	// �⺻ ������
	MyQueue() = default;

	// ���� ������
	MyQueue(const MyQueue& other);
	
	// �Ҵ� ������
	MyQueue& operator=(const MyQueue& rhs);

	// �Ҹ���
	~MyQueue() = default;

	// ť�� ù ��° ��ҿ� �����Ѵ�.
	int&			front();
	const int&		front() const;

	// ť�� ������ ��ҿ� �����Ѵ�.
	int&			back();
	const int&		back() const;
	
	// ť�� ������� Ȯ���Ѵ�.
	bool			empty() const;

	// ť�� ũ�⸦ ��ȯ�Ѵ�.
	size_t			size() const;

	// ť�� �����͸� �����Ѵ�.
	void			push(int value);

	// ť���� �����͸� ������.
	void			pop();
private:
	DoubleLinkedList		_container;
};

