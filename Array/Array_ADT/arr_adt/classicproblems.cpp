#include<iostream>
using namespace std;

// find the missing number in an array of size n containing numbers from 1 to n+1
int missingNumber(vector<int>& nums) {
    int n = nums.size() + 1;

    int xor_all = 0;
    int xor_arr = 0;

    for(int i = 1; i <= n; i++)
        xor_all ^= i;

    for(int x : nums)
        xor_arr ^= x;

    return xor_all ^ xor_arr;
}

// find the duplicate number in an array of size n+1 containing numbers from 1 to n
int findDuplicate(vector<int>& nums) {
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    while (slow != fast);

    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}