class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int wSum = 0;

        for (int i = 0; i < k; i++) wSum += nums[i];
        int maxS = wSum;

        for (int r = k; r < n; r++) {
            wSum += nums[r]-nums[r-k];
            maxS = std::max(maxS, wSum);
        }

        return (double) (maxS) / k; 
    }
};