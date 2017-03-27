#pragma once

#include <iostream>
#include <cassert>

// 0.1
class Comparision
{
public:
	int max(int value1, int value2);
	int min(int value1, int value2);
	int maximum(int* arr, int size);
};

// 0.2
class Swap
{
public:
	void swapInt(int* value1, int* value2);

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
	template<typename T>
	void rotateRight(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::RIGHT);
	}

	template<typename T>
	void rotateLeft(T arr[], int startIdx, int count)
	{
		this->rotate(arr, startIdx, count, eDirect::LEFT);
	}

	template<typename T>
	void rotateRightInterval(T arr[], int arrCount, int interval)
	{
		this->rotateInterval(arr, arrCount, interval, eDirect::RIGHT);
	}

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