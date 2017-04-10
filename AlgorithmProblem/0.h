#pragma once

#include <iostream>
#include <cassert>

// 0.1
class Comparision
{
public:
	// �ִ밪�� �ּҰ��� ���ϴ� �Լ�
	int max(int value1, int value2);
	int min(int value1, int value2);

	// �迭�� �ִ밪�� ���ϴ� �Լ�
	int maximum(int* arr, int size);
};

// 0.2
class Swap
{
public:
	// �����͸� �̿��� ���� �ٲٴ� �Լ�
	void swapInt(int* value1, int* value2);

	// �迭�� �� ���� �ٲٱ�
	template<typename T>
	void swapArrElem(T value1[], T value2[], int index)
	{
		//assert(value1 && sizeof(value1) / sizeof(T) > index);
		//assert(value2 && sizeof(value2) / sizeof(T) > index);

		T temp = value1[index];
		value1[index] = value2[index];
		value2[index] = temp;
	}
};

// 0.3
class Rotate
{
public:
	// �迭�� �Ϻθ� ���������� 1��ŭ ȸ��
	template<typename T>
	void rotateRight(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::RIGHT);
	}

	// �迭�� �Ϻθ� �������� 1��ŭ ȸ��
	template<typename T>
	void rotateLeft(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::LEFT);
	}

	// ���ڸ� �޾Ƽ� �׸�ŭ ���������� ȸ��
	template<typename T>
	void rotateRightInterval(T arr[], int arrCount, int interval)
	{
		this->rotateInterval(arr, arrCount, interval, eDirect::RIGHT);
	}

	// ���ڸ� �޾Ƽ� �׸�ŭ �������� ȸ��
	template<typename T>
	void rotateLeftInterval(T arr[], int arrCount, int interval)
	{
		this->rotateInterval(arr, arrCount, interval, eDirect::LEFT);
	}

private:
	enum eDirect { RIGHT = 1, LEFT = -1 };

	template<typename T>
	void rotate(T arr[], int startIdx, int count, eDirect direct)
	{
		int arrCount = sizeof(arr) / sizeof(T);

		int endIdx = startIdx + count - 1;
		//assert(arr && arrCount > startIdx && arrCount > endIdx);

		int pivotIdx = direct == eDirect::RIGHT ? endIdx : startIdx;
		int finalIdx = direct == eDirect::RIGHT ? startIdx : endIdx;

		T temp = arr[pivotIdx];

		int idx = pivotIdx;
		while (true)
		{
			idx -= direct;

			arr[idx + direct] = arr[idx];

			if (idx == finalIdx)
			{
				break;
			}
		}

		arr[finalIdx] = temp;
	}

	template<typename T>
	void rotateInterval(T arr[], int arrCount, int interval, eDirect direct)
	{
		if (interval > arrCount)
		{
			interval %= arrCount;
		}

		int startPos = direct == eDirect::RIGHT ? interval : arrCount - interval;
		int splitPos = direct == eDirect::RIGHT ? arrCount - interval : interval;

		T cached[10000];
		for (int i = splitPos; i < arrCount; ++i)
		{
			cached[i - splitPos] = arr[i];
		}

		int idx = splitPos - 1;
		for (int i = arrCount - 1; i >= startPos; --i)
		{
			arr[i] = arr[idx--];
		}
		for (int i = 0; i < startPos; ++i)
		{
			arr[i] = cached[i];
		}
	}
};

// 0.4
// ���࿡�� ����ȣ�� �����ϴ� ���α׷�
// �ڿ��� �Է� : ť�� ����
// 0 �Է� : ť���� ���� ���� ��ٸ� ����ȣ ���
// 0���� ���� �� �Է� : ���α׷� ����
// 0 �Է½� ť�� ������� "queue empty!" ���
// �迭�� ���� ���� �� ���� ���� ���� ���� "queue full!" ���
class BankWaitCounter
{
private:
	static const int queueLength = 8;

	int _queue[queueLength];

	int _startPos, _curPos;

public:
	BankWaitCounter() : _startPos(0), _curPos(0)
	{
		std::fill_n(_queue, queueLength, 0);
	}

	void commend(int i);
};

// 0.5
// ���� ����Ʈ�� ť �����ϱ�
template<typename T>
class PointerQueue
{
public:
	PointerQueue() : _head(nullptr), _tail(nullptr) {}

	void enqueue(T* data)
	{
		Node<T*>* n = new Node<T*>(data);

		if (isEmpty())
		{
			_head = n;
			_tail = n;
		}
		else
		{
			_tail->next = n;
			_tail = n;
		}
	}
	T* dequeue()
	{
		if (isEmpty())
		{
			std::cout << "queue empty!" << std::endl;
			return nullptr;
		}

		Node<T*>* temp = _head;
		_head = temp->next;

		if (_head == nullptr)
		{
			_tail = nullptr;
		}

		T* result = temp->context;
		delete(temp);

		return result;
	}

private:
	bool isEmpty()
	{
		return _head == nullptr && _tail == nullptr;
	}

private:
	template<typename T2>
	struct Node
	{
		Node(T2 con) : next(nullptr), context(con) {}
		Node* next;
		T2 context;
	};

	Node<T*>* _head;
	Node<T*>* _tail;
};