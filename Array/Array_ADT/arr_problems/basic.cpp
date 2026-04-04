/*
Basic array problems and their solutions in C++14.
1. Find the maximum and minimum element in an array.
2. Insert an element at end of an array
3. Find the index of a given element in an array (linear search).
4. Check if an array is sorted.
5. Find the sum of all elements in an array.
6. Remove duplicates from an array.
7. Find the second largest element in an array.
8. Insert an element at end of an array.
9. Delete an element from an array.
10. Reverse an array.
11. Rotate an array by one position to the left or right.
12. Rotate an array by a given number of positions.
13. Find the frequency of each element in an array.
14. Find the union and intersection of two arrays.
15. Find the missing number in an array of size n-1 containing numbers from 1 to n.
*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 1. Find the maximum and minimum element in an array.
pair<int, int> findMaxMin(const vector<int>& arr) {
    if (arr.empty()) {
        throw invalid_argument("Array is empty");
    }
    int maxElement = arr[0];
    int minElement = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return {maxElement, minElement};
}   

// 2. Insert an element at end of an array
void insertAtEnd(vector<int>& arr, int element) {
    arr.push_back(element);
}   

// 3. Find the index of a given element in an array (linear search).
int linearSearch(const vector<int>& arr, int element) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == element) {
            return i;
        }
    }
    return -1; // Element not found
}

// 4. Check if an array is sorted.
bool isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i] < arr[i - 1]) {
            return false;
        }
    }
    return true;
}