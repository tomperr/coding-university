# BIG O NOTATION

### https://www.youtube.com/watch?v=V6mKVRU1evU

Big O notation doesn't say if an algorithm is speed or not, but how it evolves.

45n^3 + 20n^2 + 19 = 84
45n^3 + 20n^2 + 19 = 459 (n=2)
45n^3 + 20n^2 + 19 = 47 019 (n=10)

The reason it's growing fast is n^3
So complexity is O(n^3)

O(1) algorithm spend always same time to execute whatever the data
eg.: adding an item in an Array

O(n) grows with the amount of data
eg.: in a linear search with a n size array, n verification is the worst case

O(n^2) grows with the ammount of data, but faster
eg.: bubble sort

O(log n) : pretty fast, grows slower that O(n^2)
eg.: binary search

O(n log n)
eg.: quick sort
	number of comparisions = log n!
		= log n + log (n-1) ... + log (1)
		= n log n

		