#pragma once

#include <vector>

using namespace std;

class Heap
{
public:
	Heap()
		: _container(1) { }
	~Heap() = default;

	// ���� ���� ū ���Ҹ� ��ȯ�Ѵ�.
	int				top() const;

	// ���� ������� üũ�Ѵ�.
	bool			empty() const;

	// ���� ũ�⸦ ��ȯ�Ѵ�.
	size_t			size() const;

	// ���� ���� �����Ѵ�.
	void			push(int value);

	// ���� 
private:
	vector<int>		_container;
};