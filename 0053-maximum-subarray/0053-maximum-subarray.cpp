class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int currS=nums[0];
    int maxS=nums[0];

    for(int i=1; i<n; i++)
    {
        currS=max(nums[i], currS+nums[i]);
        maxS=max(maxS, currS);
    }
    return maxS;
    }
};