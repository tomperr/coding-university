#include <stdio.h>
#include "../include/dynarray.h"

int main()
{
	dynarray dyn = dyn_init();
	printf("Hello world!\n");

	dyn_push(&dyn, 666);
	dyn_push(&dyn, 42);
	dyn_push(&dyn, 1337);
	dyn_push(&dyn, 101);

	dyn_remove(&dyn, 1337);

	if (dyn_is_empty(dyn))
	{
		printf("Empty dyn!\n");
	}
	else
	{
		dyn_print(dyn);
	}

	return 0;
}