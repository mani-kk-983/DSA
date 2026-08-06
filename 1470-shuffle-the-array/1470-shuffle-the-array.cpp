class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
    vector<int> tong;
        for(int i=0;i<n;i++){
            tong.push_back(nums[i]);
             tong.push_back(nums[i+n]);
        }
        return tong;
        
    }
};