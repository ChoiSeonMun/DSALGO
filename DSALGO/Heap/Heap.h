#pragma once

#include <vector>

using namespace std;

class Heap
{
public:
	Heap()
		: _container(1) { }
	~Heap() = default;

	// 힙의 가장 큰 원소를 반환한다.
	int				top() const;

	// 힙이 비었는지 체크한다.
	bool			empty() const;

	// 힙의 크기를 반환한다.
	size_t			size() const;

	// 힙에 값을 삽입한다.
	void			push(int value);

	// 힙에 
private:
	vector<int>		_container;
};