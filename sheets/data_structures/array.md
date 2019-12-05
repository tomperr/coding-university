# ARRAY
###https://www.coursera.org/lecture/data-structures/arrays-OsBSF

## Descriptions

Array : one contiguous are of memory consisting of equal-size elements indexed by contiguous integers.
Constant-time access to read / write

element of address = array_addr + elem_size * (index - 1)

## Multi-dimensional arrays

a is our array
x, y position in array (beginning at 1,1)
array_index = (x - 1) * row_size + (y - 1)
addr = array_index * elem_size

row major: method of representing multi dimensional array in sequential memory.
eg.: [(1,1),(1,2),(1,3),(2,1),...]


column major : row major but sorting by column
eg.: [(1,1),(2,1),(3,1),(1,2),...]

## Times for common operations

|				|	Add		|	Remove	|
|---------------|-----------|-----------|
|	beginning   |	O(size)	|	O(size)	|
|	end			|	O(1)	|	O(1)	|
|	middle		|	O(n)	|	O(n)	|

for beginning operations, we don't want a empty space at first index, so we need to move every value
from index i to i-1

### https://archive.org/details/0102WhatYouShouldKnow/02_06-jaggedArrays.mp4

## Jagged arrays

jagged array: an array containing another array for each index.
can be compared to a multi-dimensional arrays

### https://archive.org/details/0102WhatYouShouldKnow/03_01-resizableArrays.mp4

## Resizable arrays

in java: ArrayList<T>
in Objective-C: NSArray

### https://archive.org/details/0102WhatYouShouldKnow/03_06-usingBinarySearching.mp4

## Binary search

array need to be SORTED
divide and conquer Algorithm

searching value at the middle of array
if value searched is lesser than the one found, let's search in 'left side' array
if value searched id greater than the one found, let's search in 'right side' array

=> recursive algorithm, until value found (or impossible)

### https://www.coursera.org/lecture/data-structures/dynamic-arrays-EwbnV

## Dynamic Arrays

when pushBack, if size > capacity, new memory allocation

Step 1: Alocating new array (with new capacity)
Step 2: Copy previous array to new array
Step 3: Delocate old array

Common implementations
C++: vector
Java: ArrayList
Python: list

### https://archive.org/details/0102WhatYouShouldKnow/04_02-understandingBasicListImplementations.mp4

## List / Linked list

elements in list are not located next to each other, unlike in array

|					|	Arrays 										| 	Linked lists 			|
|-------------------|-----------------------------------------------|---------------------------|
| Direct acccess	| good, fixed time O(1)							| poor, linear time O(n)	|
| Adding / removing	| poor, linear time O(n)						| good, fixed time O(1)		|
| Searching 		| O(n) linear search, O(log n) binary search 	| O(n) linear search 		|

