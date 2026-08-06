class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    // Create a result vector of size 2*n initialized to 0
        vector<int> ans(2 * n);
        
        for (int i = 0; i < n; ++i) {
            ans[2 * i] = nums[i];       // Place x_i at even index
            ans[2 * i + 1] = nums[n + i]; // Place y_i at odd index
        }
        
        return ans;
    }
};