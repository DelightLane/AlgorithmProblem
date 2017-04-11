#pragma once
#include <memory>
#include <iostream>

// 1.1
// ���丮�� ����ϱ�
class Factorial
{
public:
	int calc(int i);
};

// 1.2
// ���� ����Ʈ ����ϱ�
class List
{
private:
	class Node
	{
	public:
		Node() : next(nullptr), context(0) {}

		void print()
		{
			std::cout << context << std::endl;
		}

		std::shared_ptr<Node> next;
		int context;
	};


public:
	List() : _head(nullptr), _tail(nullptr) {}

	void push(int i);

	void print();
	void printRevert();

private:
	void printReqursively(std::shared_ptr<Node> n);
	void printRevertReqursively(std::shared_ptr<Node> n);

private:
	std::shared_ptr<Node> _head;
	std::shared_ptr<Node> _tail;
};