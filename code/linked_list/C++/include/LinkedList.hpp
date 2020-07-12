#ifndef FT_LINKEDLIST_HPP
#define FT_LINKEDLIST_HPP

#include <iostream>
#include "../include/LinkedListNode.hpp"

template <class T>
class LinkedList 
{
	private:
		LinkedListNode<T>* ptr_front;
		LinkedListNode<T>* ptr_tail;
		int length;

	public:
		LinkedList(void);
		int size(void);
		bool empty(void);
		T value_at(int index);
		void push_front(T item);
		T pop_front(void);
		void push_back(T item);
		T pop_back(void);
		T front(void);
		T back(void);
		void insert(int index, T item);
		void erase(int index);
		T value_n_from_end(int index);
		void reverse(void);
		void remove_value(T item);
		void print(void);
};

template <class T>
LinkedList<T>::LinkedList(void) {
	this->ptr_front = NULL;
	this->ptr_tail = NULL;
	this->length = 0;
}

template <class T>
int LinkedList<T>::size(void) {
	return this->length;
}

template <class T>
bool LinkedList<T>::empty(void) {
	return this->length == 0;
}

template <class T>
T LinkedList<T>::value_at(int index) {
	return this->ptr_front->value_at(index);
}

template <class T>
void LinkedList<T>::push_front(T item) {
	LinkedListNode<T>* tmp = new LinkedListNode<T>(item);
	tmp->set_next(this->ptr_front);
	if (this->ptr_front == NULL) {
		this->ptr_tail = tmp;
	}
	this->ptr_front = tmp;
	this->length += 1;
}

template <class T>
T LinkedList<T>::pop_front(void) {
	if (this->ptr_front != NULL) {
		LinkedListNode<T>* tmp = this->ptr_front;
		this->ptr_front = tmp->get_next();
		this->length -= 1;
		if (this->ptr_front == NULL) {
			this->ptr_tail = NULL;
		}
		return tmp->get_item();
	} else {
		return 0; // should handle error
	}
}

template <class T>
void LinkedList<T>::push_back(T item) {
	LinkedListNode<T>* tmp = new LinkedListNode<T>(item);
	if (this->ptr_front == NULL) {
		this->ptr_front = tmp;
		this->ptr_tail = tmp;
	} else {
		this->ptr_tail->set_next(tmp);
		this->ptr_tail = tmp;
	}
	this->length += 1;
}

template <class T>
T LinkedList<T>::pop_back(void) {
	LinkedListNode<T>* tmp = this->ptr_front;
	T item;

	if (tmp->get_next() == NULL) { // only one node
		item = tmp->get_item();
		this->ptr_front = NULL;
		this->ptr_tail = NULL;
	} else { // many nodes
		while (tmp->get_next()->get_next() != NULL) {
			tmp = tmp->get_next();
		}
		item = tmp->get_next()->get_item();
		tmp->set_next(NULL);
		this->ptr_tail = tmp;
	}

	this->length -= 1;
	return item;
}

template <class T>
T LinkedList<T>::front(void){
	return this->ptr_front->get_item();
}

template <class T>
T LinkedList<T>::back(void){
	return this->ptr_tail->get_item();
}

template <class T>
void LinkedList<T>::print(void) {
	if (this->ptr_front != NULL) {
		this->ptr_front->print();
	}
}

template <class T>
void LinkedList<T>::insert(int index, T item) {
	if (index <= this->length) {

		if (index == 0) {

			this->push_front(item);

		} else {
			LinkedListNode<T>* tmp = this->ptr_front;
			while (index != 1 && tmp->get_next() != NULL) {
				tmp = tmp->get_next();
				index -= 1;
			}
			LinkedListNode<T>* tail = tmp->get_next();
			LinkedListNode<T>* node = new LinkedListNode<T>(item);
			tmp->set_next(node);
			node->set_next(tail);
			this->length += 1;
		}
		
	} else {
		// index out of range, should handle error
	}
}

template <class T>
void LinkedList<T>::erase(int index) {
	if (index < this->length) {

		if (index == 0) {
			this->pop_front();
		} else {

			LinkedListNode<T>* curr = this->ptr_front;
			while (index != 1) {
				curr = curr->get_next();
				index -= 1;
			}

			curr->set_next(curr->get_next()->get_next());
			this->length -= 1;
		}
		
	} else {
		// out of range, should handle error
	}
}

template <class T>
T LinkedList<T>::value_n_from_end(int index) {
	int index_from_start = this->length - index - 1;
	return this->ptr_front->value_at(index_from_start);
}

template <class T>
void LinkedList<T>::reverse() {
	LinkedListNode<T>* curr = this->ptr_front;
	LinkedListNode<T>* previous = NULL;
	LinkedListNode<T>* next = NULL;

	this->ptr_tail = curr;

	while (curr != NULL) {

		next = curr->get_next();
		curr->set_next(previous);
		previous = curr;
		curr = next;

	}

	this->ptr_front = previous;

}

template <class T>
void LinkedList<T>::remove_value(T item) {
	if (this->ptr_front->get_item() == item) {
		this->ptr_front = this->ptr_front->get_next();
	}

	LinkedListNode<T>* tmp = this->ptr_front;
	while (tmp->get_next() != NULL) {
		if (tmp->get_next()->get_item() == item) {
			tmp->set_next(tmp->get_next()->get_next());
		} else {
			tmp = tmp->get_next();
		}
	}
}

#endif