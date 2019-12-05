#ifndef FT_QUEUE_HPP
#define FT_QUEUE_HPP

#include <iostream>
#include "../include/queuenode.hpp"

template <class T>
class Queue
{
	private:
		QueueNode<T>* front;
		QueueNode<T>* rear;

	public:
		Queue(void);
		void enqueue(T _item);
		T dequeue(void);
		void print(void);
};

template <class T>
Queue<T>::Queue(void)
{
	this->front = NULL;
	this->rear = NULL;
}

template <class T>
void Queue<T>::enqueue(T _item)
{
	QueueNode<T>* tmp = new QueueNode<T>(_item);
	if (this->front == NULL)
	{
		this->front = tmp;
	}
	if (this->rear != NULL)
	{
		this->rear->set_next(tmp);
	}
	this->rear = tmp;
}

template <class T>
T Queue<T>::dequeue(void)
{
	QueueNode<T>* tmp = this->front;
	T tmp_item = tmp->get_item();
	if (tmp->get_next() != NULL)
	{
		this->front = tmp->get_next();
	}
	else
	{
		this->front = NULL;
		this->rear = NULL;
	}
	return tmp_item;
	
}

template <class T>
void Queue<T>::print(void)
{
	if (this->front != NULL)
	{
		this->front->print();
	}
}

#endif