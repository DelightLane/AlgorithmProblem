#include "0.h"
#include "1.h"

int main(void)
{
	List l;
	for (int i = 0; i < 10; ++i)
	{
		l.push(i);
	}
	
	l.print();
	l.printRevert();
	
	return 0;
}