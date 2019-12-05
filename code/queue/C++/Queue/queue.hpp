#ifndef QUEUE_HPP_INCLUDED
#define QUEUE_HPP_INCLUDED

#include <iostream>
#include <string>

template <class T>
class Queue
{
    private:
        T item;
        Queue* next;

    public:
        Queue(void);
        Queue(T _item);
        Queue(T _item, Queue* _next);
        void push(T _item);
        T pop(void);
        void print(void);
};

template <class T>
Queue<T>::Queue(void)
{
    this->next = NULL;
    this->item = NULL;
}

template <class T>
Queue<T>::Queue(T _item)
{
    this->next = _item;
    this->item = NULL;
}

template <class T>
Queue<T>::Queue(T _item, Queue* _next)
{
    this->next = _item;
    this->item = _next;
}

template <class T>
void Queue<T>::push(T _item) // push_front
{
    if (this->item == NULL)
    {
        this->item = _item;
    }
    else
    {
        Queue* tmp = new Queue;
        tmp->item = this->item;
        tmp->next = this->next;
        this->next = tmp;
        this->item = _item;
    }
}

template <class T>
T Queue<T>::pop(void)
{
    if (this->next == NULL)
    {
        std::cout << "next" << std::endl;
        T tmp = this->item;
        this->item = NULL;
        return tmp;
    }

    if (this->next->next == NULL)
    {
        std::cout << "next next" << std::endl;
        T tmp = this->item;
        this->next = NULL;
        return tmp;
    }
    else
    {
        std::cout << "go" << std::endl;
        return this->next->pop();
    }

}

template <class T>
void Queue<T>::print(void)
{
    if (this->next != NULL)
    {
        this->next->print();
    }

    if (this->item != NULL)
    {
        std::cout << this->item << std::endl;
    }
}

#endif // QUEUE_HPP_INCLUDED
