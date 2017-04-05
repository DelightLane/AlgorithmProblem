#include "0.h"

int main(void)
{
	BankWaitCounter counter;

	counter.commend(0);
	counter.commend(1);
	counter.commend(2);
	counter.commend(3);
	counter.commend(4);
	counter.commend(5);
	counter.commend(6);
	counter.commend(7);
	counter.commend(8);

	counter.commend(9);

	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);

	counter.commend(5);
	counter.commend(6);
	counter.commend(7);
	counter.commend(8);

	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);
	counter.commend(0);

	counter.commend(0);

	return 0;
}