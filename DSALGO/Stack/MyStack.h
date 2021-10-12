#pragma once

#include "MyVector.h"

class MyStack
{
public:
	// �⺻ ������
	MyStack() = default;

	// ���� ������
	MyStack(const MyStack& other);

	// �Ҵ� ������
	MyStack& operator=(const MyStack& rhs);
	
	// �Ҹ���
	~MyStack() = default;

	// ������ �� �� ��ҿ� �����Ѵ�.
	int&			top();
	const int&		top() const;

	// ������ ������� �˻��Ѵ�.
	bool			empty() const;

	// ������ ũ�⸦ ��ȯ�Ѵ�.
	size_t			size() const;

	// ���ÿ� �����͸� �����Ѵ�.
	void			push(int value);
	
	// ���ÿ��� �����͸� �����Ѵ�.
	void			pop();
private:
	MyVector		_container;
};

