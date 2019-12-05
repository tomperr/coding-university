# STACKS

### https://www.coursera.org/lecture/data-structures/stacks-UdKzQ

Stack : abstract data type with the following operations :

Push(key) : adds key to collection
KeyTop() : returns most recently-added key
KeyPop() : remove last and return it
Bool Empty() : is Empty

Each operation is O(1)

Input : string consisting of '(' , ')' '[' ']'
Output : return whether or not the string's parentheses and square brackets are balanced.

Eg. balanced: ([])[]()
Eg. not balanced: ([]]()

Can be implemented with either arrays or linked lists

LIFO => Last in First out

### https://archive.org/details/0102WhatYouShouldKnow/05_01-usingStacksForLast-inFirst-out.mp4

Java : Stack
Python : Stack (or using lists as stack)
C++ : std::stack (pus/pop operations)