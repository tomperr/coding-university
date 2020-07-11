# LINKED LIST

### https://www.coursera.org/lecture/data-structures/singly-linked-lists-kHhgK

## Introduction

A linked list is made of nodes containing a key (value) and a pointer to the next node (or null).
Having only a pointer to the head of the list is sufisant, but also having the tail make some operations faster.

Basic operations :
	- PushFront(Key)		-> add to front
	- Key TopFront()		-> return front item
	- Key PopFront()		-> remove front item and return it
	- PushBack(Key)			-> add to back
	- Key TopBack()			-> return back item
	- Key PopBack()			-> remove back item and return it
	- Boolean Find(Key)		-> is key in list?
	- Erase(Key)			-> remove key from list
	- Boolean Empty()		-> empty list?
	- AddBefore(Node, Key)	-> adds key before node
	- AddAfter(Node, Key)	-> adds key after node

## Times for common operations

|				|	With tail	|	Without tail	|
|---------------|---------------|-------------------|
|	PushFront	|	O(1)		|	O(1)			|
|	TopFront	|	O(1)		|	O(1)			|
|	PopFront	|	O(1)		|	O(1)			|
|	PushBack	|	O(1)		|	O(n)			|
|	TopBack		|	O(1)		|	O(n)			|
|	PopBack		|	O(n)		|	O(n)			|
|	Find		|	O(n)		|	O(n)			|
|	Erase		|	O(n)		|	O(n)			|
|	Empty		|	O(1)		|	O(1)			|
|	AddBefore	|	O(n)		|	O(n)			|
|	AddAfter	|	O(1)		|	O(1)			|