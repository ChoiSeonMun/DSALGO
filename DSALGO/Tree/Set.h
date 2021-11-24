#pragma once

#include <utility>
#include <iostream>
#include <queue>

using namespace std;

class Set
{
	struct Node
	{
		Node(int data = 0, Node* parent = nullptr, Node* left = nullptr, Node* right = nullptr)
			: Data{ data }, Left{ left }, Right{ right }, Parent{ parent }  { }
		Node(const Node&) = delete;
		Node& operator=(const Node&) = delete;
		~Node() { Parent = Left = Right = nullptr; }

		bool	IsLeaf() const { return Left == nullptr && Right == nullptr; }

		int		Data = 0;
		Node*	Parent = nullptr;
		Node*	Left = nullptr;
		Node*	Right = nullptr;
	};

public:
	// 트리의 높이를 구한다.
	int						height() const
	{
		if (empty())
		{
			return -1;
		}

		queue<Node*> q;
		q.push(_root);

		int h = -1;

		while (false == q.empty())
		{
			size_t sz = q.size();
			for (size_t i = 0; i < sz; ++i)
			{
				Node* node = q.front();
				q.pop();

				if (node->Left)
				{
					q.push(node->Left);
				}

				if (node->Right)
				{
					q.push(node->Right);
				}
			}

			++h;
		}

		return h;
	}
	int						height2() const { return heightHelper(_root); }

	// 트리가 비었는지 확인한다.
	bool					empty() const { return _root == nullptr; }

	// 트리의 크기를 반환한다.
	size_t					size() const { return _size; }

	// 트리를 비운다.
	void					clear()
	{
		while (false == empty())
		{
			erase(_root);
		}
	}

	pair<Node*, bool>		insert(int value)
	{
		if (empty())
		{
			_root = new Node(value);
			++_size;

			return make_pair(_root, true);
		}

		Node* curr = _root;
		Node* prev = nullptr;

		while (curr)
		{
			prev = curr;

			if (curr->Data == value)
			{
				return make_pair(curr, false);
			}
			else if (curr->Data < value)
			{
				curr = curr->Right;
			}
			else
			{
				curr = curr->Left;
			}
		}

		curr = new Node(value, prev);

		if (prev->Data < value)
		{
			prev->Right = curr;
		}
		else
		{
			prev->Left = curr;
		}

		++_size;

		return make_pair(curr, true);
	}

	void erase(Node* pos)
	{
		if (empty())
		{
			return;
		}

		if (pos->Parent == nullptr)
		{
			if (pos->Left == nullptr && pos->Right == nullptr)
			{
				_root = nullptr;
				
				delete pos;
				pos = nullptr;

				--_size;

				return;
			}

			if (pos->Left == nullptr)
			{
				_root = pos->Right;
				_root->Parent = nullptr;

				delete pos;
				pos = nullptr;

				--_size;

				return;
			}
			else if (pos->Right == nullptr)
			{
				_root = pos->Left;
				_root->Parent = nullptr;

				delete pos;
				pos = nullptr;

				--_size;

				return;
			}

			Node* successor = pos->Left;
			while (successor->Right)
			{
				successor = successor->Right;
			}

			swap(pos->Data, successor->Data);

			erase(successor);

			return;
		}

		if (pos->IsLeaf())
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = nullptr;
			}
			else
			{
				pos->Parent->Right = nullptr;
			}

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		if (pos->Left == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Right;
			}
			else
			{
				pos->Parent->Right = pos->Right;
			}

			pos->Right->Parent = pos->Parent;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}
		else if (pos->Right == nullptr)
		{
			if (pos->Parent->Left == pos)
			{
				pos->Parent->Left = pos->Left;
			}
			else
			{
				pos->Parent->Right = pos->Left;
			}

			pos->Left->Parent = pos->Parent;

			delete pos;
			pos = nullptr;

			--_size;

			return;
		}

		Node* successor = pos->Left;
		while (successor->Right)
		{
			successor = successor->Right;
		}

		swap(pos->Data, successor->Data);

		erase(successor);
	}

	size_t		erase(int value)
	{
		Node* pos = find(value);
		if (pos == nullptr)
		{
			return 0;
		}

		erase(pos);

		return 1;
	}

	Node* find(int value)
	{
		return const_cast<Node*>(static_cast<const Set&>(*this).find(value));
	}
	const Node*			find(int value) const
	{
		const Node* result = _root;
		
		while (result)
		{
			if (result->Data == value)
			{
				return result;
			}
			else if (result->Data < value)
			{
				result = result->Right;
			}
			else
			{
				result = result->Left;
			}
		}

		return nullptr;
	}

	// 순회
	void		traverseByPreorder() const { cout << "PreOrder : "; preOrderHelper(_root); }
	void		traverseByInorder() const { cout << "InOrder : "; inOrderHelper(_root); }
	void		traverseByPostorder() const { cout << "PostOrder : "; postOrderHelper(_root); }
	void		traverseByLevelorder() const
	{
		if (empty())
		{
			return;
		}

		int level = 0;
		queue<const Node*> q;
		q.push(_root);

		while (false == q.empty())
		{
			cout << "Level " << level << " : ";

			size_t sz = q.size();
			
			for (size_t i = 0; i < sz; ++i)
			{
				const Node* curr = q.front();
				q.pop();

				cout << curr->Data << ' ';

				if (curr->Left)
				{
					q.push(curr->Left);
				}
				if (curr->Right)
				{
					q.push(curr->Right);
				}
			}

			++level;
			cout << '\n';
		}
	}

private:
	void		preOrderHelper(const Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		cout << node->Data << ' ';
		preOrderHelper(node->Left);
		preOrderHelper(node->Right);
	}

	void		inOrderHelper(const Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		inOrderHelper(node->Left);
		cout << node->Data << ' ';
		inOrderHelper(node->Right);
	}

	void		postOrderHelper(const Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		postOrderHelper(node->Left);
		postOrderHelper(node->Right);
		cout << node->Data << ' ';
	}

	int			heightHelper(const Node* node) const
	{
		if (node == nullptr)
		{
			return -1;
		}

		int left = heightHelper(node->Left) + 1;
		int right = heightHelper(node->Right) + 1;

		return max(left, right);
	}

private:
	Node* _root = nullptr;
	size_t _size = 0;
};

