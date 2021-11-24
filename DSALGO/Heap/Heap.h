#pragma once

#include <vector>

using namespace std;

class Heap
{
public:
	Heap() = default;
	~Heap() = default;

	// ���� ���� ū ���Ҹ� ��ȯ�Ѵ�.
	const int& top() const { return _container.front(); }

	// ���� ������� üũ�Ѵ�.
	bool			empty() const { return _container.empty(); }

	// ���� ũ�⸦ ��ȯ�Ѵ�.
	size_t			size() const { return _container.size(); }

	// ���� ���� �����Ѵ�.
	void			push(int value)
	{
		_container.push_back(value);

		size_t curr = _container.size() - 1;
		size_t parent = curr / 2;

		while (curr > 0 && _container[parent] < _container[curr])
		{
			swap(_container[parent], _container[curr]);

			curr = parent;
			parent = curr / 2;
		}
	}

	// ������ ���� �����Ѵ�.
	void			pop()
	{
		if (empty())
		{
			return;
		}

		_container[0] = _container[_container.size() - 1];
		_container.pop_back();

		size_t curr = 0;
		size_t child = 1;

		while (child < _container.size())
		{
			if (child + 1 < _container.size() && _container[child] < _container[child + 1])
			{
				++child;
			}

			if (_container[curr] >= _container[child])
			{
				break;
			}

			swap(_container[curr], _container[child]);
			curr = child;
			child = curr * 2;
		}
	}
private:
	vector<int>		_container;
};