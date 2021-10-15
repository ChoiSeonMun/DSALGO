#pragma once

#include <utility>

class Set
{
	class iterator;
	class const_iterator;
public:
	iterator				begin();
	const_iterator			begin() const;

	iterator				end();
	const_iterator			end() const;

	bool					empty() const;

	size_t					size() const;

	void					clear();

	std::pair<iterator, bool>		insert(int value);

	iterator						erase(iterator pos);

	iterator						find(int value);
private:

};

