#include <iostream>

#include "../include/queue.hpp"
#include "../include/queuenode.hpp"

int main(void)
{
	Queue<int> q;
	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(42);
	q.enqueue(101);
	q.enqueue(666);

	q.print();

	std::cout << "popping" << std::endl;

	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;
	std::cout << q.dequeue() << std::endl;

	return 0;
}