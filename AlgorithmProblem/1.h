#pragma once
#include <memory>
#include <iostream>
#include <map>

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

// 1.3 ���װ��
class Binomial
{
public:
	long long calc(int total, int pick);

private:
	std::map<std::pair<int, int>, int> _map;
};

// 1.4 �Ǻ���ġ ����
class Fibonacci
{
public:
	// 0�� 1�� �̷���� ���ڿ��ε� 0�� �������� ������ �ʴ�, Ư�� ������ ��� ���ڿ� ������ �����϶�.
	int countUnsequenceZero(int length);
};