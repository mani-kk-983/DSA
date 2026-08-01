class Solution {
public:
    void sortColors(vector<int>& nums) {
    int l = 0, m = 0;
    int h = nums.size() - 1;
    /* using dutch flag algo : Maintain 3 pointers:
        low → next position for 0  
        mid → current element  
        high → next position for 2

        modified Binary search
    */
    while (m <= h) {
        if (nums[m] == 0) {
            swap(nums[l], nums[m]);
            l++;
            m++;
        }
        else if (nums[m] == 1) {
            m++;
        }
        else { // nums[mid] == 2
            swap(nums[m], nums[h]);
            h--;
        }
    }
    }
};