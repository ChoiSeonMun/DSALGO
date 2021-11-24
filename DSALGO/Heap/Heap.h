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

		size_t curr = _container.size();
		size_t parent = curr / 2;

		while (curr > 1 && _container[parent - 1] < _container[curr - 1])
		{
			swap(_container[parent - 1], _container[curr - 1]);

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

		size_t curr = 1;
		size_t child = 2;

		while (child <= _container.size())
		{
			if (child + 1 <= _container.size() && _container[child - 1] < _container[child])
			{
				++child;
			}

			if (_container[curr - 1] >= _container[child - 1])
			{
				break;
			}

			swap(_container[curr - 1], _container[child - 1]);
			curr = child;
			child = curr * 2;
		}
	}
private:
	vector<int>		_container;
};