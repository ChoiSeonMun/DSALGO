#pragma once

#include "MyVector.h"

class MyStack
{
public:
	// 기본 생성자
	MyStack() = default;

	// 복사 생성자
	MyStack(const MyStack& other);

	// 할당 연산자
	MyStack& operator=(const MyStack& rhs);
	
	// 소멸자
	~MyStack() = default;

	// 스택의 맨 위 요소에 접근한다.
	int&			top();
	const int&		top() const;

	// 스택이 비었는지 검사한다.
	bool			empty() const;

	// 스택의 크기를 반환한다.
	size_t			size() const;

	// 스택에 데이터를 삽입한다.
	void			push(int value);
	
	// 스택에서 데이터를 제거한다.
	void			pop();
private:
	MyVector		_container;
};

