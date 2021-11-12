#pragma once

#include <iostream>
#include <array>
#include <utility>
#include <vector>

using namespace std;

enum class EGraphType
{
	Matrix,
	List
};

template <EGraphType type, size_t N>
class MyGraph;

template <size_t N>
class MyGraph<EGraphType::Matrix, N>
{
public:
	// 두 정점이 인접한지 확인한다.
	bool		IsAdjacent(int start, int end)
	{
		if (_edges[start][end] != 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// 차수를 구한다.
	int			GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);

		return in + out;
	}

	// 진입 차수를 구한다.
	int			GetInDegree(int node)
	{
		int c = 0;

		for (size_t i = 0; i < _edges.size(); ++i)
		{
			if (_edges[i][node] != 0)
			{
				++c;
			}
		}

		return c;
	}

	// 진출 차수를 구한다.
	int			GetOutDegree(int node)
	{
		int c = 0;

		for (size_t i = 0; i < _edges.size(); ++i)
		{
			if (_edges[node][i] != 0)
			{
				++c;
			}
		}

		return c;
	}

	// 간선을 추가한다.
	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start][end] = weight;
	}

	// 간선을 제거한다.
	void		DeleteEdge(int start, int end)
	{
		_edges[start][end] = 0;
	}

	// 출력한다.
	// 예시..
	// [ 0 1 0 0 0 ]
	// [ 0 0 1 0 0 ]
	// [ 0 0 0 0 1 ]
	// [ 0 1 0 0 0 ]
	// [ 0 0 0 0 0 ]
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
	array<array<int, vertexCount>, vertexCount>		_edges;
};

template <size_t N>
class MyGraph<EGraphType::List, N>
{
public:
	// 두 정점이 인접한지 확인한다.
	bool		IsAdjacent(int start, int end);

	// 차수를 구한다.
	int			GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);
		
		return in + out;
	}

	// 진입 차수를 구한다.
	int			GetInDegree(int node)
	{
		int c = 0;

		for (const auto& elem : _edges)
		{
			for (const auto& edge : elem)
			{
				if (edge.first == node)
				{
					++c;
				}
			}
		}

		return c;
	}

	// 진출 차수를 구한다.
	int			GetOutDegree(int node)
	{
		return _edges[node].size();
	}

	// 간선을 추가한다.
	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start].emplace_back(end, weight);
	}

	// 간선을 제거한다.
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

	// 출력한다.
	// 예시..
	// [ 1 ] : [ (3,1) (4,3) ]
	// [ 2 ] :
	// [ 3 ] :
	// [ 4 ] :
	// [ 5 ] : [ (2, 4) (3, 5) ]
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
	array<vector<std::pair<int, int>>, N>		_edges;
};
