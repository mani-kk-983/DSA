//Search questions
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <stdexcept>
using namespace std;

class Search {
public:

//*************************************************************************************************** */

    // 1. Linear Search
    int linear(const vector<int>& arr, int target) {
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                return i; // Return index of the target
            }
        }
        return -1; // Target not found
    }

    // 2. Count occurrences of a target element
    int cntOccur(const vector<int>& arr, int target) {
        int count = 0;
        for (int num : arr) {
            if (num == target) {
                count++;
            }
        }
        return count;

       int count = count_if(arr.begin(), arr.end(), [target](int num) {
            return num == target;
        });
        return count;
        
    }

    // 3. min and max in an array
    int min(const vector<int>& arr) {
        if (arr.empty()) {
            throw invalid_argument("Array is empty");
        }
        int minElement = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < minElement) {
                minElement = arr[i];
            }
        }
        return minElement;
    }

    int max(const vector<int>& arr) {
        if (arr.empty()) {
            throw invalid_argument("Array is empty");
        }
        int maxElement = arr[0];
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
            }
        }
        return maxElement;
    }

    // 4. check if an array is sorted
    bool isSorted(const vector<int>& arr) {
        for (size_t i = 1; i < arr.size(); ++i) {
            if (arr[i] < arr[i - 1]) {
                return false;
            }
        }
        return true;
    }

    // 5.1 find the first occurrence of a target element
    int firstOccurrence(const vector<int>& arr, int target) {
        
        cout<<" Linear Search approach - O(n) time complexity :";
        for (size_t i = 0; i < arr.size(); ++i) {
            if (arr[i] == target) {
                return i; // Return index of the first occurrence
            }
        }        return -1; // Target not found
    }   

    // 5.2 find the last occurrence of a target element
    int lastOccurrence(const vector<int>& arr, int target) {
        cout<<" Linear Search approach - O(n) time complexity :";
        for (size_t i = arr.size(); i-- > 0; ) {
            if (arr[i] == target) {
                return i; // Return index of the last occurrence
            }
        }
        return -1; // Target not found
    }

    // 5.3 using first and last occurrence to count the number of occurrences of a target element
    int countOccurrences(const vector<int>& arr, int target) {
        int first = firstOccurrence(arr, target);
        int last = lastOccurrence(arr, target);
        
        return last - first + 1; // Count of occurrences
    }

    // 5.4. find the index of the first element greater than a target element
    int firstGreaterThan(const vector<int>& arr, int target) {
        auto it = upper_bound(arr.begin(), arr.end(), target) - arr.begin();
        if (it < arr.size()) {
            return it; // Return index of the first element greater than target
        }
        return -1; // No element greater than target found
    }

    // 5.5. find the index of the last element less than a target element
    int lastLessThan(const vector<int>& arr, int target) {
        auto it = lower_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;
        if (it < arr.size() && it >= 0) {
            return it; // Return index of the last element less than target
        }
        return -1; // No element less than target found
    }

//*************************************************************************************************** */

    // 6. Binary Search (for sorted arrays)
    int binarySearch(const vector<int>& arr, int target) {
        int n=arr.size();
        int i=0, j=n-1;
        while(i<=j){
            int mid = i+(j-i)/2;
            return (arr[mid]==target)? mid :(arr[mid]<target)? i=mid+1 : j=mid-1;
        }
        return -1; // Target not found
    }   

    // 7. Modified Binary Search to find the index of target element in a rotated sorted array
    int rotatedBinarySearch(const vector<int>& arr, int target) {
        int n=arr.size();
        int i=0, j=n-1;
        while(i<=j){
            int m = i+(j-i)/2;
            if(arr[m]==target) return m;
            if(arr[i]<=arr[m]){
                if(arr[i]<=target && target<arr[m]) j=m-1;
                else i=m+1;
            }
            else{
                if(arr[m]<target && target<=arr[j]) i=m+1;
                else j=m-1;
            }
        }       
        return -1; // Target not found
    }

    // 8. Find the minimum element in a rotated sorted array
    int findMinInRotatedSortedArray(const vector<int>& arr) {
        int n=arr.size();
        int i=0, j=n-1;
        while(i<j){
            int m = i+(j-i)/2;
            if(arr[m]>arr[j]) i=m+1;
            else j=m;
        }
        return arr[i]; // Minimum element
    }

    // 9. Peak element in an array
    int findPeakElement(const vector<int>& arr) {
        int n=arr.size();
        int i=0, j=n-1;
        while(i<j){
            int m = i+(j-i)/2;
            if(arr[m]>arr[m+1]) j=m;
            else i=m+1;
        }
        return i; // Peak element
    }

    // 10. Find the square root of a number using binary search
    int sqrt(int x) {
        if (x < 0) {
            throw invalid_argument("Cannot compute square root of a negative number");
        }
        if (x == 0 || x == 1) {
            return x;
        }
        int i=1, j=x/2;
        while(i<=j){
            int m = i+(j-i)/2;
            if(m==x/m) return m;
            else if(m<x/m) i=m+1;
            else j=m-1;
        }
        return j; // Return the integer part of the square root
    }   

    // 11. first bad version (for finding the first bad version in a series of versions)
    /* int firstBadVersion(int n) {
        int i=1, j=n;
        while(i<j){
            int m = i+(j-i)/2;
            if(isBadVersion(m)) j=m;
            else i=m+1;
        }
        return i; // First bad version
    }
        */

};

int main() {
    Search search;
    vector<int> arr = {1, 2, 3, 4, 5, 5, 5, 6, 7, 8, 9};
    int target = 5;

    cout << "Linear Search: Index of " << target << " is " << search.linear(arr, target) << endl;
    cout << "Count Occurrences: " << target << " occurs " << search.cntOccur(arr, target) << " times" << endl;
    cout << "Minimum element: " << search.min(arr) << endl;
    cout << "Maximum element: " << search.max(arr) << endl;
    cout << "Is sorted: " << (search.isSorted(arr) ? "Yes" : "No") << endl;
    cout << "First occurrence of " << target << ": " << search.firstOccurrence(arr, target) << endl;
    cout << "Last occurrence of " << target << ": " << search.lastOccurrence(arr, target) << endl;
    cout << "Count occurrences using first and last occurrence: " << search.countOccurrences(arr, target) << endl;
    cout << "First element greater than " << target << ": Index " << search.firstGreaterThan(arr, target) << endl;
    cout << "Last element less than " << target << ": Index " << search.lastLessThan(arr, target) << endl << endl << endl;

    cout << "Binary Search: Index of " << target << " is " << search.binarySearch(arr, target) << endl;
    cout << "Index of " << target << " in rotated sorted array: " << search.rotatedBinarySearch(arr, target) << endl;
    cout << "Minimum element in rotated sorted array: " << search.findMinInRotatedSortedArray(arr) << endl;
    cout << "Peak element in the array: " << search.findPeakElement(arr) << endl;
    cout << "Square root of 16: " << search.sqrt(16) << endl;
    // cout << "First bad version: " << search.firstBadVersion(100) << endl;

    return 0;
}   