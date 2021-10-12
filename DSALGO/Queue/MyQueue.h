#pragma once

#include "DoubleLinkedList.h"

class MyQueue
{
public:
	// 기본 생성자
	MyQueue() = default;

	// 복사 생성자
	MyQueue(const MyQueue& other);
	
	// 할당 연산자
	MyQueue& operator=(const MyQueue& rhs);

	// 소멸자
	~MyQueue() = default;

	// 큐의 첫 번째 요소에 접근한다.
	int&			front();
	const int&		front() const;

	// 큐의 마지막 요소에 접근한다.
	int&			back();
	const int&		back() const;
	
	// 큐가 비었는지 확인한다.
	bool			empty() const;

	// 큐의 크기를 반환한다.
	size_t			size() const;

	// 큐에 데이터를 삽입한다.
	void			push(int value);

	// 큐에서 데이터를 꺼낸다.
	void			pop();
private:
	DoubleLinkedList		_container;
};

