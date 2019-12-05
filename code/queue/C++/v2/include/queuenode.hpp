#ifndef FT_QUEUENODE_HPP
#define FT_QUEUENODE_HPP

#include "../include/queue.hpp"

template <class T>
class QueueNode
{
	private:
		T item;
		QueueNode* next;

	public:
		QueueNode(T _item);
		QueueNode(T _item, QueueNode* _next);
		T get_item(void);
		void set_item(T _item);
		QueueNode* get_next(void);
		void set_next(QueueNode* _next);
		void print(void);

};

template <class T>
QueueNode<T>::QueueNode(T _item)
{
	this->item = _item;
	this->next = NULL;
}

template <class T>
QueueNode<T>::QueueNode(T _item, QueueNode* _next)
{
	this->item = _item;
	this->next = _next;
}

template <class T>
T QueueNode<T>::get_item(void)
{
	return this->item;
}

template <class T>
void QueueNode<T>::set_item(T _item)
{
	this->item = _item;
}

template <class T>
QueueNode<T>* QueueNode<T>::get_next(void)
{
	return this->next;
}

template <class T>
void QueueNode<T>::set_next(QueueNode* _next)
{
	this->next = _next;
}

template <class T>
void QueueNode<T>::print(void)
{

	std::cout << this->item << std::endl;

	if (this->next != NULL)
	{
		this->next->print();
	}
}


#endif