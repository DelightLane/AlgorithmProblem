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
	if (n->next != nullptr)
	{
		printRevertReqursively(n->next);
	}

	n->print();

	if (n == nullptr)
	{
		return;
	}
}