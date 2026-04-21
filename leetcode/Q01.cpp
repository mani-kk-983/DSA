//two sum problem;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp; // hash map to store the value->index
        for(int i=0; i<n; i++)
        {
            /*target = a (nums[i]) + b ; 
            so we know the target <- from user and a <- from nums[] , 
            so b? is missing we need to find the b.*/
            int b = target - nums[i];
            //srching for the c as i seen c before in the hash
            if(mp.find(b) != mp.end())
            return{mp[b],i};
          mp[nums[i]]=i;
        }
        return{};
    }
};
