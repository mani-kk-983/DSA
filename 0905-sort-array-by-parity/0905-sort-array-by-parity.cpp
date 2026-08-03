class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
    //Using two pinters partition; we can solve this problem;
    /* Idea is to maintain the two ptr=> l&r;
        l=nxt POS for Even(0) & r= scan the ptr
        if(0)-> swap to l;
    */
    int l = 0;
    for(int r = 0; r < nums.size(); r++){
        if(nums[r] % 2 == 0){
            swap(nums[l], nums[r]);
            l++;
        }
    }

    return nums;
    }
};