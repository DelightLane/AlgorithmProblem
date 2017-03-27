#include "0.h"

int main(void)
{
	Rotate r;

	int a[] = {0, 1, 2, 3, 4};

	//r.rotateRightInterval(a, 5, 3);
	r.rotateLeftInterval(a, 5, 3);

	for (int i = 0 ; i < 5 ; ++i)
	{
		std::cout << a[i] << std::endl;
	}

	return 0;
}