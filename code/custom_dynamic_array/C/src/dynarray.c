#include <stdio.h>
#include <stdlib.h>
#include "../include/dynarray.h"

dynarray dyn_init()
{
	dynarray dyn;
	dyn.capacity = 1;
	dyn.size = 0;
	dyn.arr = malloc(dyn.capacity * sizeof(int));
	return dyn;
}

int dyn_size(dynarray dyn)
{
	return dyn.size;
}

int dyn_capacity(dynarray dyn)
{
	return dyn.capacity;
}

int dyn_is_empty(dynarray dyn)
{
	return dyn.size == 0 ? 1 : 0;
}

void dyn_push(dynarray *dyn, int item)
{
	if (dyn->size == dyn->capacity)
	{
		dyn_increment_capacity(dyn);
	}

	dyn->arr[dyn->size] = item;
	dyn->size += 1;
}

void dyn_print(dynarray dyn)
{
	int i;

	for (i=0; i<dyn.size; i++)
	{
		printf("%d\n", dyn.arr[i]);
	}
}

int dyn_at(dynarray dyn, int index)
{
	if (index < 0 || index >= dyn.size)
	{
		return -1;
	}

	return dyn.arr[index];
}

void dyn_insert(dynarray *dyn, int index, int item)
{
	if (dyn->size == dyn->capacity)
	{
		dyn_increment_capacity(dyn);
	}

	int i;
	for (i=dyn->size-1; i>= index; i--)
	{
		dyn->arr[i+1] = dyn->arr[i];
	}
	dyn->size += 1;

	dyn->arr[index] = item;
}

void dyn_pop(dynarray *dyn)
{
	if (dyn->size > 0)
	{
		dyn->size -= 1;
	}
}

void dyn_prepend(dynarray *dyn, int item)
{
	dyn_insert(dyn, 0, item);
}

void dyn_delete(dynarray *dyn, int index)
{
	if (index >= 0 && index < dyn->size)
	{
		int i;
		for (i=index; i < dyn->size-1; i++)
		{
			dyn->arr[i] = dyn->arr[i+1];
		}
		dyn->size -= 1;
	}
}

void dyn_remove(dynarray *dyn, int item)
{
	int i;
	for (i=0; i<dyn->size; i++)
	{
		if (dyn->arr[i] == item)
		{
			dyn_delete(dyn, i);
			break;
		}
	}
}

int dyn_find(dynarray dyn, int item)
{
	int i;
	for (i=0; i<dyn.size; i++)
	{
		if (dyn.arr[i] == item)
		{
			return i;
		}
	}
	return -1;
}

void dyn_resize(dynarray *dyn, int size)
{
	dyn->arr = (int*) realloc(dyn->arr, size * sizeof(int));
	dyn->capacity = size;
}

void dyn_increment_capacity(dynarray *dyn)
{
	dyn->capacity += 1;
	dyn->arr = (int*) realloc(dyn->arr, dyn->capacity * sizeof(int));
}

void dyn_decrement_capacity(dynarray *dyn)
{
	dyn->capacity -= 1;
	dyn->arr = (int*) realloc(dyn->arr, dyn->capacity * sizeof(int));
}
