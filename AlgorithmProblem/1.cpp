#include "1.h"

// 1.1
int Factorial::calc(int i)
{
	if (i == 1)
	{
		return 1;
	}

	return this->calc(i - 1) * i;
}

// 1.2
void List::push(int i)
{
	auto n = new Node();
	n->context = i;
	auto con = std::shared_ptr<Node>(n);

	if (_head == nullptr)
	{
		_head = con;
		_tail = _head;

		return;
	}

	_tail->next = con;
	_tail = con;
}

void List::print()
{
	printReqursively(_head);
}

void List::printReqursively(std::shared_ptr<Node> n)
{
	if (n == nullptr)
	{
		return;
	}

	n->print();

	printReqursively(n->next);
}

void List::printRevert()
{
	printRevertReqursively(_head);
}

void List::printRevertReqursively(std::shared_ptr<Node> n)
{
	if (n == nullptr)
	{
		return;
	}

	printRevertReqursively(n->next);

	n->print();
}


// 1.3
long long Binomial::calc(int total, int pick)
{
	if (pick == 0 || total == pick)
	{
		return 1;
	}

	long long value0;
	long long value1;

	auto key = std::pair<int, int>(total - 1, pick - 1);
	auto it = _map.find(key);
	if (it != _map.end())
	{
		value0 = it->second;
	}
	else
	{
		value0 = calc(total - 1, pick - 1);
		_map.insert(std::map<std::pair<int, int>, int>::value_type(key, value0));
	}

	key = std::pair<int, int>(total - 1, pick);
	it = _map.find(key);
	if (it != _map.end())
	{
		value1 = it->second;
	}
	else
	{
		value1 = calc(total - 1, pick);
		_map.insert(std::map<std::pair<int, int>, int>::value_type(key, value1));
	}

	return value0 + value1;
}