class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int i=0, j=n-1;
        while(i<j){
            int m = i+(j-i)/2;
            
            (nums[m]>nums[m+1])? j=m : i=m+1;
        }
        return i; 
    }
};