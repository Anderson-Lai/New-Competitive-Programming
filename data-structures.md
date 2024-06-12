#include <array> or char arr[] = {};

fixed size array
can be created on the stack or the heap
decays into a pointer when passed as a function parameter
can be created on the heap with new / delete

#include <vector>

created on the heap
can push and pop from the back in O(1) time
.erase is O(n)
.erase(iterator to first element, iterator to last element [not inclusive])

#include <list>
#include <forward_list>

list is linked list
can be created on the stack or heap
O(n) random access
O(n) random insertion
O(1) insertion at front or back
doubly-linked list

forward list is singly-linked list
O(1) insertion at the front?
O(n) random access and random insertion

#include <queue>

first in first out
.pop() and .push()
use .front() to get the value before popping

priority queue
O(log(n)) insert time
ensures items are always from highest to lowest priority (by default, 
highest to lowest values)

#include <deque>

double ended queue 
O(1) pushing and popping from front and back
implemented with a doubly-linked list

#include <stack>

last in first out
.pop() and .push()
.back() to get the value before popping

#include <map>
#include <unordered_map>

a dictionary
key-value pairs
good for counting frequencies
if frequencies can only be one, use a set

.erase(key)
will not immediately return memory to the operating system
will pool the memory in an allocator to prevent fragmentation
may eventually return memory to the os

#include <set>
#include <unordered_set>

unordered_set has O(1) random access and .find()
set has O(log(n))
uses a red-black tree

#include <tuple>

std::get<index> name to return the value
can be made up of different types

#include <utility>

std::pair<T, U> name(const T& val, const U& other)