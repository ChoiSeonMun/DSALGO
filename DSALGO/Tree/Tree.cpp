#include <set>
#include "Set.h"

int main()
{
	std::set<int> set = { 8, 3, 2, 5, 4, 10, 14, 11, 16 };
	for (int data : set)
	{
		cout << data << ' ';
	}
	cout << endl;

	if (set.end() != set.find(2))
	{
		cout << "Found 2\n";
	}

	if (set.end() == set.find(12))
	{
		cout << "Not Found 12\n";
	}

	cout << "Size : " << set.size() << endl;

	cout << boolalpha << set.empty() << endl;

	auto iter = set.begin();
	++iter;
	++iter;

	set.erase(iter);

	cout << "Size : " << set.size() << endl;

	if (set.end() == set.find(4))
	{
		cout << "Not Found 4\n";
	}

	set.clear();

	cout << set.empty() << endl;

	puts("---------------------------");

	Set mySet;

	mySet.insert(8);
	mySet.insert(3);
	mySet.insert(2);
	mySet.insert(5);
	mySet.insert(4);
	mySet.insert(10);
	mySet.insert(14);
	mySet.insert(11);
	mySet.insert(16);

	if (mySet.find(2))
	{
		cout << "Found 2\n";
	}

	if (nullptr == mySet.find(12))
	{
		cout << "Not Found 12\n";
	}

	cout << "Size : " << mySet.size() << endl;

	cout << boolalpha << mySet.empty() << endl;

	mySet.erase(4);

	cout << "Size : " << mySet.size() << endl;

	if (nullptr == mySet.find(4))
	{
		cout << "Not Found 4\n";
	}

	mySet.traverseByPreorder();
	puts("");
	mySet.traverseByInorder();
	puts("");
	mySet.traverseByPostorder();
	puts("");
	mySet.traverseByLevelorder();

	cout << "Height : " << mySet.height() << ' ' << mySet.height2() << endl;
	mySet.clear();

	cout << mySet.empty() << endl;
}