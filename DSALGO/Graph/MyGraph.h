#pragma once

#include <iostream>
#include <vector>
#include <utility>

enum class EGraphType
{
	Matrix,
	List
};

template <EGraphType type>
class MyGraph;

template <>
class MyGraph<EGraphType::Matrix>
{
public:
	MyGraph(size_t count)
	{
		_edges.reserve(count);
		for (size_t i = 0; i < count; ++i)
		{
			_edges.emplace_back(count);
		}
	}

	MyGraph(const MyGraph& other)
		: _edges{ other._edges }
	{
		
	}

	MyGraph& operator=(const MyGraph& rhs)
	{
		if (this != &rhs)
		{
			MyGraph temp(rhs);
			std::swap(_edges, temp._edges);
		}

		return *this;
	}

	~MyGraph() = default;

	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start][end] = weight;
	}

	void		DeleteEdge(int start, int end)
	{
		_edges[start][end] = 0;
	}

	void		Print()
	{
		size_t count = _edges.size();

		for (size_t r = 0; r < count; ++r)
		{
			std::cout << "[ ";
			for (size_t c = 0; c < count; ++c)
			{
				std::cout << _edges[r][c] << ' ';
			}
			std::cout << "]\n";
		}
	}

private:
	std::vector<std::vector<int>>		_edges;
};

template <>
class MyGraph<EGraphType::List>
{
public:
	MyGraph(size_t count)
	{
		_edges.reserve(count);
		for (size_t i = 0; i < count; ++i)
		{
			_edges.emplace_back();
		}
	}

	MyGraph(const MyGraph& other)
		: _edges{ other._edges }
	{

	}

	MyGraph& operator=(const MyGraph& rhs)
	{
		if (this != &rhs)
		{
			MyGraph temp(rhs);
			std::swap(_edges, temp._edges);
		}

		return *this;
	}

	~MyGraph() = default;

	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start].emplace_back(end, weight);
	}

	void		DeleteEdge(int start, int end)
	{
		for (auto iter = _edges[start].begin(); iter != _edges[start].end(); ++iter)
		{
			if (iter->first == end)
			{
				_edges[start].erase(iter);

				break;
			}
		}
	}

	void		Print()
	{
		for (size_t r = 0; r < _edges.size(); ++r)
		{
			std::cout << "[ " << r << " ] : ";
			for (const auto& elem : _edges[r])
			{
				std::cout << "(" << elem.first << "," << elem.second << ") ";
			}
			std::cout << std::endl;
		}
	}

private:
	std::vector<std::vector<std::pair<int, int>>>		_edges;
};
