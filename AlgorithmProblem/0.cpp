#include "0.h"
#include <stdlib.h>

// 0.1
int Comparision::max(int value1, int value2)
{
	if (value1 > value2)
	{
		return value1;
	}
	else if (value1 < value2)
	{
		return value2;
	}

	assert(0);

	return 0;
}

int Comparision::min(int value1, int value2)
{
	return this->max(value1, value2) == value1 ? value2 : value1;
}

int Comparision::maximum(int* arr, int size)
{
	int max = -1;

	for (int i = 0; i < size; ++i)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}

	return max;
}

// 0.2
void Swap::swapInt(int* value1, int* value2)
{
	int temp = *value1;
	*value1 = *value2;
	*value2 = temp;
}

// 0.4
void BankWaitCounter::commend(int i)
{
	if (i == 0)
	{
		if (_startPos == _curPos)
		{
			if (_queue[_curPos] == 0)
			{
				std::cout << "queue empty!" << std::endl;

				return;
			}
		}

		std::cout << _queue[_startPos] << std::endl;

		_queue[_startPos] = 0;
		_startPos = (_startPos + 1) % queueLength;
	}
	else
	{
		if (i > 0)
		{
			if (_startPos == _curPos)
			{
				if (_queue[_curPos] != 0)
				{
					std::cout << "queue full!" << std::endl;

					return;
				}
			}

			_queue[_curPos] = i;
			_curPos = (_curPos + 1) % queueLength;
		}
		else
		{
			exit(0);
		}
	}
}