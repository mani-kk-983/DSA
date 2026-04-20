/* Two pointer approach is a common technique used to solve problems that involve searching for pairs of elements in a sorted array. 
The idea is to use two pointers, one starting at the beginning of the array and the other starting at the end, and move them towards each other until they meet.

types of two pointer approach:
1. Opposite ends: 
    One pointer starts at the beginning of the array and the other starts at the end. 
    This is commonly used to find pairs of elements that sum up to a specific target
2. Same direction:
    Both pointers start at the same position and move in the same direction.
    This is often used to find subarrays or to remove duplicates from a sorted array.
3. Fast and slow pointers:
    One pointer moves faster than the other, typically used to detect cycles in linked lists or to find the middle of a linked list.
4. Sliding window:
    Two pointers are used to create a window that can expand and contract as needed, often used to solve problems related to subarrays or substrings.
5. Partitioning:
    Two pointers are used to partition an array into two parts based on a condition, often used in quicksort or similar algorithms.

problemslike.... Merging, Binary search, two sum, 3sum, 4sum, etc. are some of the common problems that can be solved using the two pointer approach.

*/
#include <iostream>
#include <vector>
#include <algorithm>    
using namespace std;

