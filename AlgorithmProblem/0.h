#pragma once

#include <iostream>
#include <cassert>

// 0.1
class Comparision
{
public:
	// 최대값과 최소값을 구하는 함수
	int max(int value1, int value2);
	int min(int value1, int value2);

	// 배열의 최대값을 구하는 함수
	int maximum(int* arr, int size);
};

// 0.2
class Swap
{
public:
	// 포인터를 이용해 값을 바꾸는 함수
	void swapInt(int* value1, int* value2);

	// 배열의 두 원소 바꾸기
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
	// 배열의 일부를 오른쪽으로 1만큼 회전
	template<typename T>
	void rotateRight(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::RIGHT);
	}

	// 배열의 일부를 왼쪽으로 1만큼 회전
	template<typename T>
	void rotateLeft(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::LEFT);
	}

	// 인자를 받아서 그만큼 오른쪽으로 회전
	template<typename T>
	void rotateRightInterval(T arr[], int arrCount, int interval)
	{
		this->rotateInterval(arr, arrCount, interval, eDirect::RIGHT);
	}

	// 인자를 받아서 그만큼 왼쪽으로 회전
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
// 은행에서 대기번호를 관리하는 프로그램
// 자연수 입력 : 큐에 저장
// 0 입력 : 큐에서 가장 오래 기다린 대기번호 출력
// 0보다 작은 수 입력 : 프로그램 종료
// 0 입력시 큐가 비었으면 "queue empty!" 출력
// 배열이 가득 차서 더 넣을 수가 없을 때는 "queue full!" 출력
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
// 연결 리스트로 큐 구현하기
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