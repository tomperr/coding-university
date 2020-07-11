#ifndef FT_LINKEDLISTNODE_HPP_HPP
#define FT_LINKEDLISTNODE_HPP_HPP

#include <iostream>

template <class T>
class LinkedListNode
{
	private:
		T item;
		LinkedListNode* next;

	public:
		LinkedListNode(T _item);
		LinkedListNode(T _item, LinkedListNode* _next);
		T get_item(void);
		void set_item(T _item);
		LinkedListNode* get_next(void);
		void set_next(LinkedListNode* _next);
		void print(void);
		T value_at(int index);
};

template <class T>
LinkedListNode<T>::LinkedListNode(T _item) {
	this->item = _item;
	this->next = NULL;
}

template <class T>
LinkedListNode<T>::LinkedListNode(T _item, LinkedListNode* _next) {
	this->item = _item;
	this->next = _next;
}

template <class T>
T LinkedListNode<T>::get_item(void) {
	return this->item;
}

template <class T>
void LinkedListNode<T>::set_item(T _item) {
	this->item = _item;
}

template <class T>
LinkedListNode<T>* LinkedListNode<T>::get_next(void) {
	return this->next;
}

template <class T>
void LinkedListNode<T>::set_next(LinkedListNode* _next) {
	this->next = _next;
}

template <class T>
void LinkedListNode<T>::print(void) {
	std::cout << this->item << std::endl;
	if (this->next != NULL) {
		this->next->print();
	}
}

template <class T>
T LinkedListNode<T>::value_at(int index) {

	if (index == 0) {
		return this->item;
	} else if (this->next != NULL) {
		return this->next->value_at(index-1);
	} else {
		return -1; // should handle error
	}

}


#endif