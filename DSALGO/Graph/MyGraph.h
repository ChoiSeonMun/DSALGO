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
	// �� ������ �������� Ȯ���Ѵ�.
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

	// ������ ���Ѵ�.
	int			GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);

		return in + out;
	}

	// ���� ������ ���Ѵ�.
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

	// ���� ������ ���Ѵ�.
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

	// ������ �߰��Ѵ�.
	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start][end] = weight;
	}

	// ������ �����Ѵ�.
	void		DeleteEdge(int start, int end)
	{
		_edges[start][end] = 0;
	}

	// ����Ѵ�.
	// ����..
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
	// �� ������ �������� Ȯ���Ѵ�.
	bool		IsAdjacent(int start, int end);

	// ������ ���Ѵ�.
	int			GetDegree(int node)
	{
		int in = GetInDegree(node);
		int out = GetOutDegree(node);
		
		return in + out;
	}

	// ���� ������ ���Ѵ�.
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

	// ���� ������ ���Ѵ�.
	int			GetOutDegree(int node)
	{
		return _edges[node].size();
	}

	// ������ �߰��Ѵ�.
	void		AddEdge(int start, int end, int weight = 1)
	{
		_edges[start].emplace_back(end, weight);
	}

	// ������ �����Ѵ�.
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

	// ����Ѵ�.
	// ����..
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
