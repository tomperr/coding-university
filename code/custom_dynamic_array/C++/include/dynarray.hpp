#ifndef FT_DYNARRAY_HPP
#define FT_DYNARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <string>

template <class T>
class Dynarray
{
	public:
		int size;
		int capacity;
		T* arr;

		Dynarray(void);
		void print(void);
		bool is_empty(void);
		T at(int index);
		void push(T item);
		void insert(T item, int index);
		void prepend(T item);
		void pop(void);
		void del(int index);
		void remove(T item);
		int find(T item);

	private:
		void set_capacity(int _size);
};


template <class T>
Dynarray<T>::Dynarray(void)
{
	this->size = 0;
	this->capacity = 16;
	arr = (T*) malloc(this->capacity * sizeof(T));
}

template <class T>
void Dynarray<T>::print(void)
{
	for (int i=0; i<this->size; i++)
	{
		std::cout << this->arr[i] << std::endl;
	}
}

template <class T>
void Dynarray<T>::set_capacity(int _size)
{
	this->arr->resize(_size);
	this->capacity = _size;
	if (this->size > capacity)
	{
		this->size = _size;
	}
}

template <class T>
bool Dynarray<T>::is_empty(void)
{
	return this->size == 0;
}

template <class T>
T Dynarray<T>::at(int index)
{
	if (index < 0 || index >= this->size)
	{
		return NULL;
	}

	return this->arr[index];
}

template <class T>
void Dynarray<T>::push(T item)
{
	if (this->size == this->capacity)
	{
		this->set_capacity(this->capacity * 2);
	}

	this->arr[this->size] = item;
	this->size += 1;
}

template <class T>
void Dynarray<T>::insert(T item, int index)
{
	if (index > 0 && index <= this->size)
	{
		if (this->size == this->capacity)
		{
			this->set_capacity(this->capacity * 2);
		}

		for (int i=this->size-1; i>=index; i--)
		{
			this->arr[i+1] = this->arr[i];
		}

		this->arr[index] = item;
		this->size += 1;
	}
}

template <class T>
void Dynarray<T>::prepend(T item)
{
	this->insert(item, 0);
}

template <class T>
void Dynarray<T>::pop(void)
{
	if (this->size > 0)
	{
		this->size -= 1;
	}
}

template <class T>
void Dynarray<T>::del(int index)
{
	if (index > 0 && index < this->size)
	{
		for (int i=index; i < (this->size)-1; i++)
		{
			this->arr[i] = this->arr[i+1];
		}
		this->size -= 1;
	}
}

template <class T>
void Dynarray<T>::remove(T item)
{
	for (int i=0; i<this->size; i++)
	{
		if (this->arr[i] == item)
		{
			this->del(i);
		}
	}
}

template <class T>
int Dynarray<T>::find(T item)
{
	for (int i=0; i<this->size; i++)
	{
		if (this->arr[i] == item)
		{
			return i;
		}
	}

	return -1;
}

#endif