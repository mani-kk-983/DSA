/*
Basic array problems and their solutions in C++14.
1. Find the maximum and minimum element in an array.
2. Insert an element at end of an array
3. Find the index of a given element in an array (linear search).
4. Check if an array is sorted.
5. Find the sum of all elements in an array.
6. Remove duplicates from an array.
7. Find the second largest element in an array.
8. Insert an element at a specific index of an array.
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

// 5. Find the sum of all elements in an array.
int sumOfElements(const vector<int>& arr) {
    int sum = 0;
    for (int num : arr) {
        sum += num;
    }
    return sum;
}   
// 6. Remove duplicates from an array.
vector<int> removeDuplicates(const vector<int>& arr) {
    unordered_set<int> seen;
    vector<int> uniqueElements;
    for (int num : arr) {
        if (seen.find(num) == seen.end()) {
            uniqueElements.push_back(num);
            seen.insert(num);
        }
    }
    return uniqueElements;
}

// 7. Find the second largest element in an array.
int secondLargest(const vector<int>& arr) {
    if (arr.size() < 2) {
        throw invalid_argument("Array must have at least two elements");
    }
    int largest = INT_MIN;
    int secondLargest = INT_MIN;
    for (int num : arr) {
        if (num > largest) {
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num != largest) {
            secondLargest = num;
        }
    }
    if (secondLargest == INT_MIN) {
        throw invalid_argument("No second largest element found");
    }
    return secondLargest;
}

// 8. Insert an element at a specific index of an array.
void insertAtIndex(vector<int>& arr, int index, int element) {
    if (index < 0 || index > arr.size()) {
        throw out_of_range("Index out of range");
    }
    arr.insert(arr.begin() + index, element);
}   

// 9. Delete an element from an array.
void deleteElement(vector<int>& arr, int element) {
    arr.erase(remove(arr.begin(), arr.end(), element), arr.end());
}

// 10. Reverse an array.
void reverseArray(vector<int>& arr) {
    reverse(arr.begin(), arr.end());
}   

// 11. Rotate an array by one position to the left or right.
void rotateLeft(vector<int>& arr) {
    if (arr.empty()) return;
    int firstElement = arr[0];
    for (size_t i = 1; i < arr.size(); ++i) {
        arr[i - 1] = arr[i];
    }
    arr[arr.size() - 1] = firstElement;
}

void rotateRight(vector<int>& arr) {
    if (arr.empty()) return;
    int lastElement = arr[arr.size() - 1];
    for (size_t i = arr.size() - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }
    arr[0] = lastElement;
}

// 12. Rotate an array by a given number of positions.
void rotateLeftByK(vector<int>& arr, int k) {
    k = k % arr.size();
    reverse(arr.begin(), arr.begin() + k);
    reverse(arr.begin() + k, arr.end());
    reverse(arr.begin(), arr.end());
}   
void rotateRightByK(vector<int>& arr, int k) {
    k = k % arr.size();
    reverse(arr.end() - k, arr.end());
    reverse(arr.begin(), arr.end() - k);
    reverse(arr.begin(), arr.end());
}

// 13. Find the frequency of each element in an array.
unordered_map<int, int> frequency(const vector<int>& arr) {
    unordered_map<int, int> freqMap;
    for (int num : arr) {
        freqMap[num]++;
    }
    return freqMap;
}   

// 14. Find the union and intersection of two arrays.
vector<int> unionOfArrays(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> unionSet(arr1.begin(), arr1.end());
    unionSet.insert(arr2.begin(), arr2.end());
    return vector<int>(unionSet.begin(), unionSet.end());
}   

vector<int> intersectionOfArrays(const vector<int>& arr1, const vector<int>& arr2) {
    unordered_set<int> set1(arr1.begin(), arr1.end());
    vector<int> intersection;
    for (int num : arr2) {
        if (set1.find(num) != set1.end()) {
            intersection.push_back(num);
        }
    }
    return intersection;
}

// 15. Find the missing number in an array of size n-1 containing numbers from 1 to n.
int findMissingNumber(const vector<int>& arr, int n) {
    int totalSum = n * (n + 1) / 2;
    int arrSum = sumOfElements(arr);
    return totalSum - arrSum;
}


int main() {
    vector<int> arr = {3, 1, 4, 1, 5, 9};
    auto maxMin = findMaxMin(arr);
    cout << "Max: " << maxMin.first << ", Min: " << maxMin.second << endl;

    insertAtEnd(arr, 2);
    cout << "After inserting at end: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    int index = linearSearch(arr, 4);
    cout << "Index of 4: " << index << endl;

    cout << "Is sorted: " << (isSorted(arr) ? "Yes" : "No") << endl;

    int sum = sumOfElements(arr);
    cout << "Sum of elements: " << sum << endl;

    vector<int> uniqueArr = removeDuplicates(arr);
    cout << "After removing duplicates: ";
    for (int num : uniqueArr) {
        cout << num << " ";
    }
    cout << endl;

    try {
        int secondLargestElement = secondLargest(arr);
        cout << "Second largest element: " << secondLargestElement << endl;
    } catch (const invalid_argument& e) {
        cout << e.what() << endl;
    }

    insertAtIndex(arr, 2, 10);
    cout << "After inserting at index 2: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    deleteElement(arr, 1);
    cout << "After deleting element 1: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverseArray(arr);
    cout << "After reversing the array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rotateLeft(arr);
    cout << "After rotating left by one position: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rotateRight(arr);
    cout << "After rotating right by one position: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rotateLeftByK(arr, 2);
    cout << "After rotating left by 2 positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    rotateRightByK(arr, 2);
    cout << "After rotating right by 2 positions: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;   

    unordered_map<int, int> freqMap = frequency(arr);
    cout << "Frequency of elements: ";
    for (const auto& pair : freqMap) {
        cout << pair.first << ": " << pair.second << " ";
    }
    cout << endl;


    vector<int> arr2 = {5, 9, 2, 6};
    vector<int> unionArr = unionOfArrays(arr, arr2);
    cout << "Union of arrays: ";
    for (int num : unionArr) {
        cout << num << " ";
    }
    cout << endl;   

    vector<int> intersectionArr = intersectionOfArrays(arr, arr2);
    cout << "Intersection of arrays: ";
    for (int num : intersectionArr) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> arr3 = {1, 2, 4, 5};
    int missingNumber = findMissingNumber(arr3, 5);
    cout << "Missing number: " << missingNumber << endl;    

    return 0;

}

