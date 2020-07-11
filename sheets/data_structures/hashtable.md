# HASHTABLE

### https://www.youtube.com/watch?v=0M_kIqhwbFo

## Introduction

Abastract Data Type maintain set of items each with a key (key; item)
in Python => dict

data[key] -> value

basic operations:
	- search(key)
	- insert(key, value)
	- delete(key)

unique index, like an array

## Motivation (why using it)

- building dictionaries (like in python or real dictionaries)
- used in database (database use search tree or hashing)
- compilers & interpreters verify keyword and variables with hashmap
- network router / server use hashmap to associate address and port

## Simple approach

Direct access table, store items in aray by index
array case are whether null of filled

Problems :
	- 1/ Array need integer as key, so we need to hash the key
	- 2/ gigantic memory hog

Solution to problem 1: prehash
	- maps keys to non negative integers
	- in theory, keys are finite and discrete
	hash(x) = hash(y) <=> x = y (if no collision)

Solution to probleme 2 :
	- reduce universe U of all keys (integers) down to reasonable
	size m for table (array)
	hash(prehash(x)) € [0; m-1]

## Chaining

Solution to probleme 2 (previous part) will cause collisions
solution : use linked list in table

## Simple Uniform Hashing

Each key is equally likely to be hashed to any slot of the table
Independent of where other keys hashing

Analysis:
	- expected length of chain :
		for n keys m slots => alpha = "load factor" = n/m

## Hash functions

1/ Division method
	hash(k) = k mod m
	pretty bad in a lot of situations (eg. if k and m are always odd or even)

2/ Multiplication method
	hash(k) = [(a\*k) mod 2^w] >> (w-r)
	w = number of bits of k integer
	a = random number of w bits

3/ Universal hashing -> best method in a lot of situations
	hash(k) = [(a\*k+b) mod p] mod m
	a and b -> random numbers in [0; p-1]
	p = prime number greater than univers U carninality
	p > |U|

### https://www.youtube.com/watch?v=BRO7mVIFt08

## How to choose m ?

idea: 
	start small, m = 8
	grow / shrink as necessary

If n > m : grow table

Grow table: m -> m'
	- make table of size m' => memory allocation
	- build new hash f'
	- rehash
		for item in T: // table
			T'.insert(item) // insert in new table with new hash

m' = 2m => table doubling

Amortization :
	- operation takes "T(n) amortized" if k operations
	take <= k * T(n) time
	- think of meaning "T(n) on average" where average over all operations

## Table doubling

k inserts
take O(k) time
=> O(1) amortized per insert

Also : k insert & deletes take O(k)

## Deletion

if we inserts n items then delete n items, m = max(n)
but array is empty, so we need to resize

Possibility 1 :
	if m = n/2 then shrink -> m/2
Problem: slow

Possibility 2 :
	if m = n/4 then shrink -> m/

## String matching

given two string s & t
does s occur as a substring of t ?

Simple algorithm :
	any (s==t[i:i+len(s)]
		for i in range(len(t)-len(s)))

	eg. s = "yes" "ohyesman"
	ohy == yes
	hye == yes
	yes == yes
	...

	Time : O(|s|*(|t|-|s|)) = O(|s|*|t|)
		=> pretty slow

