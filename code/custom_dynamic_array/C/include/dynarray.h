#ifndef FT_DYNARRAY_H
#define FT_DYNARRAY_H

typedef struct{
	int *arr;
	int capacity;
	int size;
} dynarray;

dynarray dyn_init();
int dyn_size(dynarray dyn);
int dyn_capacity(dynarray dyn);
int dyn_is_empty(dynarray dyn);
void dyn_push(dynarray *dyn, int item);
void dyn_print(dynarray dyn);
int dyn_at(dynarray dyn, int index);
void dyn_insert(dynarray *dyn, int index, int item);
void dyn_prepend(dynarray *dyn, int item);
void dyn_pop(dynarray *dyn);
void dyn_delete(dynarray *dyn, int index);
void dyn_remove(dynarray *dyn, int item);
int dyn_find(dynarray dyn, int item);
void dyn_resize(dynarray *dyn, int size);

void dyn_increment_capacity(dynarray *dyn);
void dyn_decrement_capacity(dynarray *dyn);

#endif