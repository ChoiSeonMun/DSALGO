#pragma once

#include <vector>

using namespace std;

class Heap
{
public:
	Heap() = default;
	~Heap() = default;

	// 힙의 가장 큰 원소를 반환한다.
	const int& top() const { return _container.front(); }

	// 힙이 비었는지 체크한다.
	bool			empty() const { return _container.empty(); }

	// 힙의 크기를 반환한다.
	size_t			size() const { return _container.size(); }

	// 힙에 값을 삽입한다.
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

	// 힙에서 값을 제거한다.
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