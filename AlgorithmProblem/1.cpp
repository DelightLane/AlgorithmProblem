#include "1.h"
#include <functional>
#include <sstream>

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

// 1.4
int Fibonacci::countUnsequenceZero(int length)
{
	std::map<std::string, bool> counted;

	std::function<int(std::string)> func = [&func, &counted](std::string str)
	{
		if (counted.find(str) != counted.end())
		{
			return 0;
		}
		else
		{
			if (str.find("00") != std::string::npos)
			{
				return 0;
			}

			std::cout << str << std::endl;
			counted.insert(std::map<std::string, int>::value_type(str, true));
		}

		int result = 1;

		int zeroIdx = str.find('0');

		// 0이 없으면
		if (zeroIdx == std::string::npos)
		{
			zeroIdx = -1;
		}

		for (int i = zeroIdx + 1; i < str.length(); ++i)
		{
			std::string copy(str);
			copy[i] = '0';

			result += func(copy);
		}

		return result;
	};

	std::stringstream startStr;
	for (int i = 0; i < length; ++i)
	{
		startStr << '1';
	}

	return func(startStr.str());
}

int Fibonacci::countStairStepKind(int stairFloor)
{
	if (stairFloor < 0)
	{
		return 0;
	}

	if (stairFloor == 0)
	{
		return 1;
	}

	int result = 0;

	if (--stairFloor >= 0)
	{
		result += countStairStepKind(stairFloor);
	}

	if (--stairFloor >= 0)
	{
		result += countStairStepKind(stairFloor);
	}

	return result;
}