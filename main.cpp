#include "container.h"

#include <stdio.h>

int main ()
{
	int* numbers = (int*)array(sizeof(long));
	
	allocate (10, numbers);
	
	for (int i = 0; i <	10; ++i)
	{
		int a = i;
		push (&a, numbers);
	}
	
	for (int i = 0; i <	10; ++i)
	{
		int a = numbers[i];
		printf ("%i ", a);
	}
	
	printf ("\n");
	
	return 0;
}
