class Solution {
public:
    bool isPalindrome(int x) {
       string S = to_string(x);
       int n = S.length();
       for (int i=0; i<n/2; i++ )
       {
            if(S[i]!= S[n-i-1])
            return false;
       }
        return true;
    }
};