#include <iostream>
#include <string>
#include "queue.hpp"

int main()
{
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    queue.pop();
    queue.pop();
    queue.print();

    return 0;
}
