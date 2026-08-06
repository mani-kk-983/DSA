class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> oneafteranother;
        for(int i=0;i<n;i++){
            oneafteranother.push_back(nums[i]);
             oneafteranother.push_back(nums[i+n]);
        }
        return oneafteranother;

    }
};